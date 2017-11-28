#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
 
const int n = 7;//Rozmiar macierzy incydencji
 
//Funkcja pomocnicza do wizualizacji dzialania//////////////////////////
 
queue<int>VODWIEDZONE;//POmocniczy stos do symulacji odwiedzonych
 
void pokaz_odwiedzone()
{
//Jakie ju� odwiedzili�my
queue<int>kopia = VODWIEDZONE;
printf("Juz odwiedzone: ");
while(!kopia.empty())
{
printf("%d  ",kopia.front());
kopia.pop();
}
}
 
void pokaz_zawartosc_stosu_i_odwiedzone(stack<int> stos)
{
pokaz_odwiedzone();
if(stos.empty())
{
printf("\nStos PUSTY!\n");
return;
}
 
printf("\nZawartosc stosu:\n%d<--------- TOP\n",stos.top());
stos.pop();
while(!stos.empty())
{
printf("%d\n",stos.top());
stos.pop();
}
}
 
void pokaz_zawartosc_kolejki_i_odwiedzone(queue<int> kolejka)
{
pokaz_odwiedzone();
if(kolejka.empty())
{
printf("\nKolejka PUSTA!\n");
return;
}
 
printf("\nZawartosc kolejki: %d",kolejka.front());
kolejka.pop();
while(!kolejka.empty())
{
printf("  %d",kolejka.front());
kolejka.pop();
}
}
////////////////////////////////////////////////////////////////////////
 
//////////////////DFS///////////////////////////////////////////////////
void DFS(int G[n][n],int szukany)
{
stack<int> stos;
bool V[n];
for(int j=0;j<n;++j)V[j] = false;//Wierzcho�ki nie odwiedzone
 
stos.push(szukany);//Wrzucamy startuj�cy wierzcho�ek na stos
 
while(!stos.empty())
{
pokaz_zawartosc_stosu_i_odwiedzone(stos);//Do symulacji
 
 
szukany = stos.top();
stos.pop();//Usuwamy odwiedzany element
 
printf("\nOdwiedzam: %d\n",szukany);
 
VODWIEDZONE.push(szukany);//Do symulacji odwiedzonych
 
V[szukany] = true;//ODwiedzili�my ju� ten
 
for(int j = n-1;j >= 0;--j)
{
if(G[j][szukany] != 0 && V[j] == false)
{
stos.push(j);//Wrzucamy na stos jego s�siad�w
V[j] = true;//Znaznaczamy ,�e go odwiedzimy!(w niedalekiej przysz�o�ci)
//Inaczej b�dziemy mieli np tak� sytuacj� w stosie 2,3,4,2 <-- 2x dw�jka
}
}
}
 
pokaz_zawartosc_stosu_i_odwiedzone(stos);//Do symulacji
}
////////////////////////////////////////////////////////////////////////
 
 
 
//////////////////BFS///////////////////////////////////////////////////
 
void BFS(int G[n][n],int szukany)
{
queue<int> kolejka;
 
bool V[n];
for(int j=0;j<n;++j)V[j] = false;//Wierzcho�ki nie odwiedzone
 
kolejka.push(szukany);//Wrzucamy startuj�cy wierzcho�ek na kolejke
 
while(!kolejka.empty())
{
pokaz_zawartosc_kolejki_i_odwiedzone(kolejka);//Do symulacji
 
 
szukany = kolejka.front();
kolejka.pop();//Usuwamy odwiedzany element
 
printf("\n\nOdwiedzam: %d\n",szukany);
 
VODWIEDZONE.push(szukany);//Do symulacji odwiedzonych
 
V[szukany] = true;//ODwiedzili�my ju� ten
 
for(int j = 0;j < n;++j)
{
if(G[j][szukany] != 0 && V[j] == false)
{
kolejka.push(j);//Wrzucamy na stos jego s�siad�w
V[j] = true;//Znaznaczamy ,�e go odwiedzimy!(w niedalekiej przysz�o�ci)
//Inaczej b�dziemy mieli np tak� sytuacj� w stosie 2,3,4,2 <-- 2x dw�jka
}
}
}
 
pokaz_zawartosc_kolejki_i_odwiedzone(kolejka);//Do symulacji
 
}
////////////////////////////////////////////////////////////////////////
 
int main()
{
//Przyk�ad ze strony: http://www.algorytm.org/algorytmy-grafowe/przeszukiwanie-grafu-wszerz-bfs-i-w-glab-dfs.html
int tab[n][n] = {
{0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 0, 0},
{0, 1, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0},
{0, 0, 1, 1, 0, 1, 0},
{0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0}
};
 
 
printf("DFS\n\n");         
DFS(tab,1);//Odpalamy DFS'a z wierzcho�ka 1
 
while(!VODWIEDZONE.empty())VODWIEDZONE.pop();//Czyszczenie
 
printf("\n\nBFS\n\n"); 
BFS(tab,1);//Odpalamy BFS'a z wierzcho�ka 1
 
return 0;
}