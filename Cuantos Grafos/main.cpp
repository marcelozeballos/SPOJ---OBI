#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#define pb push_back
using namespace std;

typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector < ii > vii;
vector <vi> graph;
map <int,int> mapa;
vi visitados;
void DFS(int nodo)
{
    visitados[nodo] = 1;
    for(int i = 0; i < graph[nodo].size(); i++)
        if(visitados[graph[nodo][i]] == 0)
            DFS(graph[nodo][i]);
}

bool test(int number)
{
    bool m[number+1];
    m[0] = false;
    m[1] = false;
    for(int i = 2; i <= number; ++i)
        m[i] = true;

    for(int i = 2; i*i <= number;  ++i){
        if(m[i]){
            for(int h = 2; i*h <= number; ++h)
                m[i*h] = false;
        }
    }
    return m[number];
}
int main()
{
    int a, b;
    while(cin >> a >> b, a || b)
    {
        int cantnodos = b-a+1;
        graph.assign(cantnodos,vi());
        visitados.assign(cantnodos, 0);
        int cnt = 0;
        for(int i = a; i <= b; i++)
            mapa[i] = cnt,cnt++;
        for(int i = a; i <= b; i++)
        {
            for(int j = a; j <= b; j++){
            if( i != j && test(i+j))
                graph[mapa[i]].pb(mapa[j]);
            }
        }
        cnt = 0;
        for(int i = 0; i < cantnodos; i++)
            if(visitados[i] == 0)
                DFS(i), cnt++;

        cout << cnt << endl;
    }
}
