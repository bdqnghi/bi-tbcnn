#include <stdio.h>

#define N 10
int heap[N] = {5, 12, 1, 14, 2, 8, 4, 10, 13, 9};

void sift(int n, int x)
{ 
  int s;

  if (x<<1<n) { 
    s = x<<1;
    if (x<<1<n-1 && heap[(x<<1)+1]>heap[(x<<1)])
      s++;
    if (heap[s]<=heap[x]) 
      s=0;
  }
  else s=0;
  
  while (s)
    { 
      heap[x]=(heap[x]^heap[s])^(heap[s]=heap[x]);
      x=s;

      if (x<<1<n)
        { 
	  s = x<<1;
          if (x<<1<n-1 && heap[(x<<1)+1]>heap[(x<<1)])
            s++;
          if (heap[s]<=heap[x])
	    s=0;
        }
        else s=0;
    }
}


void create_heap(){
  for (int i=N>>1; i+1; sift(N, i--));
}


void sort()
{  
  for (int i=N-1; i>=1; i--)
    { 
      heap[0]=(heap[0]^heap[i])^(heap[i]=heap[0]);
      sift(i, 0);
    }
}


void print()
{ 
  for (int i=0; i<N; i++)
    printf("%d ", heap[i]);
  printf("\n");
}


int main(void)
{
  create_heap();
  print();
  sort();
  print();
}
