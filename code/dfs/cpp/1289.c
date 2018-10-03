/*
	dfs => (Depth-first Search - busca em profundidade)
*/


#include "dfs.h"

int main()
{
	Grafo *G = new Grafo();
	stack<Vertice*> PilhaVertices;
	Vertice *v;
	register unsigned int i, j;
	
	G->leGrafo();
	
	// busca por vértices não visitados
	while ( ( v = G->busca( false ) ) != NULL )
	{
		// empilha v
		PilhaVertices.push( v );

		while ( ! PilhaVertices.empty() )
		{
			v = PilhaVertices.top();
			//PilhaVertices.pop();

			// exibe visita ao vértice
			if ( ! v->isVisitado() )
			{
				v->exibir();
				cout << " ";
			}
			
			v->setVisitado( true );
			
			list<Vertice*> vizinhos = G->buscaVizinhos( G, *v );

			if ( vizinhos.size() > 0 )
			{
				while ( ! vizinhos.empty() )
				{
					Vertice *w = vizinhos.front();

					vizinhos.pop_front();

					if ( ! w->isVisitado() )
					{
						//cout << "setando " << w->getNome() << " como visitado" << endl;
						//w->setVisitado( true );
						PilhaVertices.push( w );
						G->matrizAdjacencia[ v->getNome() ][ w->getNome() ].setTipoArvore( true );
						G->matrizAdjacencia[ w->getNome() ][ v->getNome() ].setTipoArvore( true );
						break;
					}
				}
			}
			else
			{
				PilhaVertices.pop();
			}
		}
	}

	cout << endl;

	for ( i = 1; i <= G->getNumVertices(); i++ )
	{
		for ( j = 1; j < i; j++ )
		{
			if ( G->matrizAdjacencia[i][j].isAresta() )
			{
				if ( G->matrizAdjacencia[i][j].isTipoArvore() )
				{
					cout << CHAR_ARVORE;
				}
				else
				{
					cout << CHAR_NAOARVORE;
				}

				cout << " " << i << " " << j << endl;
			}
		}
	}

	return 0;
}
