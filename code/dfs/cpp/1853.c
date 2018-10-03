/* DEPTH FIRST SEARCH TECHNIQUE */
/* DFS.C */

# include<stdio.h>
# include<conio.h>
# include<malloc.h>

# define size 20
# define T 1
# define F 0

struct Edge
{
	int terminal;
	struct Edge *next;
};
struct Vertex
{
	int visit;
	int vertex_no;
	char info;
	int path_length;
	struct Edge *Edge_Ptr;
};
void Table(int , int matrix [size][size], struct Vertex vert[size]);
struct Edge *Insert_Vertex (int , struct Edge *);
void DFS ( int , int *dist, struct Vertex vert [size]);
void Input(int, int a [size][size]);
void Output(int, int a [size][size]);

struct Edge * Insert_Vertex (int vertex_no, struct Edge *first)
{
	struct Edge *new1, *current;
	new1 = (struct Edge *) malloc(sizeof(struct Edge));
	new1->terminal = vertex_no;
	new1->next = NULL;
	if (!first)
		return (new1);
	for (current = first; current->next; current = current->next);
	current->next = new1;
	return (first);
}

/* Initializing entries */

void Table(int vertex_num, int matrix [size][size],
struct Vertex vert[size])
{
	int i, j;
	for (i = 0; i < vertex_num; i++)
	{
		vert [i].visit = F;
		vert [i].vertex_no = i+1;
		vert [i].info = 'A'+ i;
		vert [i].path_length = 0;
		vert [i].Edge_Ptr = NULL;
	}

	for (i =0; i < vertex_num ; i++)
		for (j =0; j < vertex_num ; j++)
			if (matrix [i][j] > 0)
				vert [i].Edge_Ptr = Insert_Vertex (j, vert [i].Edge_Ptr);
}

/* Computing path length */
void DFS ( int index, int *dist,
struct Vertex vert [size])
{
	struct Edge *Link;
	vert [index].visit = T;
	vert [index].path_length = *dist;
	*dist += 1;
	for ( Link = vert [index].Edge_Ptr; Link; Link = Link->next)
		if (vert [Link->terminal].visit == F)
			DFS (Link->terminal, dist, vert);
}

/* Input function to read adjacency matrix */

void Input(int number, int a [size][size])
{
	int i, j;
	printf("\n Input the adjacency matrix \n");

	for (i =0; i < number; i++)
	{
		for (j=0; j < number; j ++)
		{
			scanf("%d", &a [i][j]);
		}
		printf("\n");
	}
}

/* Output function */
void Output(int number, int a [size][size])
{ 
	int i, j;
	printf("\n Adjacency matrix \n");
	for (i = 0; i < number; i++)
	{
		for (j = 0; j < number; j ++)
		{
			printf("   %d", a [i][j]);
		}
		printf("\n");
	}
}

/* Function main */
void  main()
{ 
	int i;
	int number, index, dist;
	int a [size][size];
	struct Vertex vert [size];
	struct Edge *List;
	clrscr();
	printf("\n Input the number of vertices in the graph: ");
	scanf("%d", &number);
	Input(number, a);
	Output(number, a);

	Table(number, a, vert);
	printf("\n Input the starting vertex 0- %d:", number-1);
	scanf("%d", &index);
	dist = 0;
	DFS (index, &dist, vert);
	printf("\n Path length of the vertex from %c", vert[index].info);
	printf("\n Vertex Length Vertex Connectivity \n ");
	for (i = 0; i < number; i++)
	{
		printf("\n  %c 	%d   ", vert[i].info, vert[i].path_length);
		for (List= vert[i].Edge_Ptr; List; List = List->next)
		{
			printf(" ");
			putchar(List->terminal+'A');
		}
	}
	getch();
}


/*
	algorithm :-
 
DFS (G)
 	-- WHITE - not discovered
-- GRAY - discovered & being explored
-- BLACK - discovered & finished
      	-- Initialize arrays
1	for each vertex u ∈ G.V do
2	   u.color ← WHITE
3	   u.Π ← NIL
4	time ← 0
 	-- Perform depth first search
5	for each vertex u ∈ G.V do
6	    if u.color = WHITE then
7	       DFS-Visit (G, u)


DFS-Visit (G, u)
-- pre: u.color=WHITE
-- post: u.color=BLACK
--     ∀v  u.d<v.d<v.f<u.f, etc.
1      	u.color ← GRAY
2	time ← time + 1
3	u.d ← time
4	for each vertex v ∈ G.Adj[ u ] do
5	   if v.color = WHITE then
6	      v.Π ← u
7	      DFS-Visit (G, v)
8	u.color ← BLACK
9	u.f ← time ← time + 1


*/