#include <assert.h>
#include <getopt.h>
#include <limits.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "timer.h"


#define DEFAULT_DURATION                10000
#define DEFAULT_INITIAL                 256
#define DEFAULT_NB_THREADS              1
#define DEFAULT_RANGE                   0xFFFF
#define DEFAULT_SEED                    0
#define DEFAULT_UPDATE                  20

#define XSTR(s)                         STR(s)
#define STR(s)                          #s

/* ################################################################### *
 * GLOBALS
 * ################################################################### */

#include "tm.h"

#define VAL_MIN                         INT_MIN
#define VAL_MAX                         INT_MAX

typedef struct node {
	long val;
	struct node *next;
} node_t;

typedef struct intset {
	node_t *head;
} intset_t;

intset_t* set;

static volatile int stop;

node_t *new_node(long val, node_t *next) {
  node_t *node = (node_t *)TM_MALLOC(sizeof(node_t));
  node->val = val;
  node->next = next;
  return node;
}

node_t *new_node_seq(long val, node_t *next) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node->val = val;
  node->next = next;
  return node;
}

int set_seq_add(long val)
{
	int result;
	node_t *prev, *next;

	prev = set->head;
	next = prev->next;
	while (next->val < val) {
		prev = next;
		next = prev->next;
	}
	result = (next->val != val);
	if (result) {
		prev->next = new_node_seq(val, next);
	}
	return result;
}

intset_t *set_new() {
  intset_t *set = (intset_t *)malloc(sizeof(intset_t));
  node_t *min, *max;
  max = new_node_seq(VAL_MAX, NULL);
  min = new_node_seq(VAL_MIN, max);
  set->head = min;

  return set;
}

int set_size(intset_t *set)
{
  int size = 0;
  node_t *node;

  /* We have at least 2 elements */
  node = set->head->next;
  while (node->next != NULL) {
    size++;
    node = node->next;
  }

  return size;
}

long set_add(TM_ARGDECL long val)
{
    int res = 0;
	node_t *prev, *next;
	long v;

	int ro = 0;
	TM_BEGIN(0);
		prev = set->head;
		next = FAST_PATH_SHARED_READ_P(prev->next);
		while (1) {
			v = FAST_PATH_SHARED_READ(next->val);
			if (v >= val)
				break;
			prev = next;
			next = FAST_PATH_SHARED_READ_P(prev->next);
		}
		res = (v != val);
		if (res) {
			FAST_PATH_SHARED_WRITE_P(prev->next, new_node(val, next));
		}
	TM_END();

    return res;
}

int set_remove(TM_ARGDECL long val)
{
    int res = 0;

	node_t *prev, *next;
	long v;
	node_t *n;

	int ro = 0;
	TM_BEGIN(1);
		prev = set->head;
		next = FAST_PATH_SHARED_READ_P(prev->next);
		while (1) {
			v = FAST_PATH_SHARED_READ(next->val);
			if (v >= val)
				break;
			prev = next;
			next = FAST_PATH_SHARED_READ_P(prev->next);
		}
		res = (v == val);
		if (res) {
			n = FAST_PATH_SHARED_READ_P(next->next);
			FAST_PATH_SHARED_WRITE_P(prev->next, n);
			FAST_PATH_FREE(next);
		}
	TM_END();

    return res;
}

long set_contains(TM_ARGDECL long  val)
{
    long res = 0;
	node_t *prev, *next;
	long v = 0;

	int ro = 1;
	TM_BEGIN_EXT(2, 1);
        	prev = set->head;
	        next = FAST_PATH_SHARED_READ_P(prev->next);
        	while (1) {
        		v = FAST_PATH_SHARED_READ(next->val);
	        	if (v >= val)
        			break;
        		prev = next;
	        	next = FAST_PATH_SHARED_READ_P(prev->next);
        	}
    	TM_END();
    return (v == val);
}

#include <sched.h>
  long range;
  int update;
  unsigned long nb_add;
  unsigned long nb_remove;
  unsigned long nb_contains;
  unsigned long nb_found;
  unsigned long nb_aborts;
  unsigned int nb_threads;
  unsigned int seed;
  long operations;

void *test(void *data)
{

  TM_THREAD_ENTER();

  unsigned int mySeed = seed + sched_getcpu();

  long myOps = operations / nb_threads;
  long val = -1;
  int op;

  while (myOps > 0) {
    op = rand_r(&mySeed) % 100;
    if (op < update) {
      if (val == -1) {
        /* Add random value */  
        val = (rand_r(&mySeed) % range) + 1;
// printf("Inserting: %ld", val);
        if(set_add(TM_ARG val) == 0) {
          val = -1;
// printf("\tdid not insert!");
        }
// printf("\n");
      } else {
        /* Remove random value */
        int res = set_remove(TM_ARG  val);
// printf("removed: %ld ? %d\n", val, res);
        val = -1;
      }
    } else {
      /* Look for random value */
      long tmp = (rand_r(&mySeed) % range) + 1;
      set_contains(TM_ARG tmp);
    }

    myOps--;
  }

  TM_THREAD_EXIT();
  return NULL;
}

# define no_argument        0
# define required_argument  1
# define optional_argument  2

MAIN(argc, argv) {
    TIMER_T start;
    TIMER_T stop;


  struct option long_options[] = {
    // These options don't set a flag
    {"help",                      no_argument,       NULL, 'h'},
    {"duration",                  required_argument, NULL, 'd'},
    {"initial-size",              required_argument, NULL, 'i'},
    {"num-threads",               required_argument, NULL, 'n'},
    {"range",                     required_argument, NULL, 'r'},
    {"seed",                      required_argument, NULL, 's'},
    {"buckets",                   required_argument, NULL, 'b'},
    {"update-rate",               required_argument, NULL, 'u'},
    {NULL, 0, NULL, 0}
  };

  int i, c;
  long val;
  operations = DEFAULT_DURATION;
  unsigned int initial = DEFAULT_INITIAL;
  nb_threads = DEFAULT_NB_THREADS;
  range = DEFAULT_RANGE;
  update = DEFAULT_UPDATE;

  while(1) {
    i = 0;
    c = getopt_long(argc, argv, "hd:i:n:b:r:s:u:", long_options, &i);

    if(c == -1)
      break;

    if(c == 0 && long_options[i].flag == 0)
      c = long_options[i].val;

    switch(c) {
     case 0:
       /* Flag is automatically set */
       break;
     case 'h':
       printf("intset -- STM stress test "
              "(linked list)\n"
              "\n"
              "Usage:\n"
              "  intset [options...]\n"
              "\n"
              "Options:\n"
              "  -h, --help\n"
              "        Print this message\n"
              "  -d, --duration <int>\n"
              "        Test duration in milliseconds (0=infinite, default=" XSTR(DEFAULT_DURATION) ")\n"
              "  -i, --initial-size <int>\n"
              "        Number of elements to insert before test (default=" XSTR(DEFAULT_INITIAL) ")\n"
              "  -n, --num-threads <int>\n"
              "        Number of threads (default=" XSTR(DEFAULT_NB_THREADS) ")\n"
              "  -r, --range <int>\n"
              "        Range of integer values inserted in set (default=" XSTR(DEFAULT_RANGE) ")\n"
              "  -s, --seed <int>\n"
              "        RNG seed (0=time-based, default=" XSTR(DEFAULT_SEED) ")\n"
              "  -u, --update-rate <int>\n"
              "        Percentage of update transactions (default=" XSTR(DEFAULT_UPDATE) ")\n"
         );
       exit(0);
     case 'd':
       operations = atoi(optarg);
       break;
     case 'i':
       initial = atoi(optarg);
       break;
     case 'n':
       nb_threads = atoi(optarg);
       break;
     case 'r':
       range = atoi(optarg);
       break;
     case 's':
       seed = atoi(optarg);
       break;
     case 'u':
       update = atoi(optarg);
       break;
     case '?':
       printf("Use -h or --help for help\n");
       exit(0);
     default:
       exit(1);
    }
  }

  if (seed == 0)
    srand((int)time(0));
  else
    srand(seed);

  SIM_GET_NUM_CPU(nb_threads);
  TM_STARTUP(nb_threads,42);
  P_MEMORY_STARTUP(nb_threads);
  thread_startup(nb_threads);

  set = set_new();

  /* Populate set */
  printf("Adding %d entries to set\n", initial);
  for (i = 0; i < initial; i++) {
    val = (rand() % range) + 1;
    set_seq_add(val);
  }

printf("Initial size: %d\n",   set_size(set));

  seed = rand();
  TIMER_READ(start);
  GOTO_SIM();

  thread_start(test, NULL);

  GOTO_REAL();
  TIMER_READ(stop);

  puts("done.");
  printf("\nTime = %0.6lf\n", TIMER_DIFF_SECONDS(start, stop));
PRINT_STATS();
  fflush(stdout);

printf("Final size: %d\n",   set_size(set));

  TM_SHUTDOWN();
  P_MEMORY_SHUTDOWN();
  GOTO_SIM();
  thread_shutdown();
  MAIN_RETURN(0);
}
