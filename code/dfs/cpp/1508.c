// ALGO : Depth First Search ; SOURCE : Coreman ;

// 0 is assumed as source vertex ; for n nodes & m edges

// Tested, Working. :)

// For any clarifications, contact me at osinha6792@gmail.com

#include <cstdio>
#include <vector>

#define MAX 10010

using namespace std ;

/* Attributes of a node of graph
  color : visited / non-visted status of a vertex
  d : discovered timestamp ( color : 0 -> 1 )
  f : finished timestamp ( color : 1 -> 2 )
  pre : predecessor of a vertex
*/
struct node
{
  int color , d , f , pre ;
} ;

vector< node > vec( MAX ) ;
vector< int > adj[MAX] ; 

int n , time = 0 ;

void dfs( ) ;
void dfs_visit( int u ) ;

int main( )
{
	int i , u , v , m , j ;

	scanf("%d %d",&n,&m) ;

	for( i = 0 ; i < m ; i++ )
	{
		scanf("%d %d",&u,&v) ;
		adj[u].push_back( v ) ;
		adj[v].push_back( u ) ;
	}

	printf("Adjacency List\n\n") ;
	for( i = 1 ; i <= n ; i++ )
	{
		m = adj[i].end( ) - adj[i].begin( ) ;

		printf("%d : ",i) ;
		for( j = 0 ; j < m ; j++ )
			printf("%d ",adj[i][j]) ;
		printf("\n") ;
	}
	printf("\n\n") ;

	dfs( ) ;

	vec.clear( ) ;
	for( i = 1 ; i <= n ; i++ )
		adj[i].clear( ) ;

	return 0 ;
}

inline void dfs( )
{
	int i ;

	for( i = 1 ; i <= n ; i++ )
		vec[i].color = vec[i].pre = 0 ;

	for( i = 1 ; i <= n ; i++ )
	{
		if( !vec[i].color )
			dfs_visit( i ) ;
	}
}

inline void dfs_visit( int u )
{
	int i , v , last = adj[u].end( ) - adj[u].begin( ) ;

	vec[u].d = ++time ;
	vec[u].color = 1 ;

	printf("%d ",u) ;
	
	for( i = 0 ; i < last ; i++ )
	{
		v = adj[u][i] ;

		if( !vec[v].color )
		{
			vec[v].pre = u ;
			dfs_visit( v ) ;
		}
	}
	
	vec[u].color = 2 ;
	vec[u].f = ++time ;
}
