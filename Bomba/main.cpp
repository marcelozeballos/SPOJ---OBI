#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector <vi> vvi;

int BFS_SSSP(int starting, int ending, const vector<vi> &adjList)
{
    queue <int> q;
    vector <int> dist(adjList.size(), -1);
    q.push(starting);
    dist[starting] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)adjList[u].size(); i++)
        {
            int v = adjList[u][i];
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[ending];
}

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

int main()
{
    char maze[15][15];
    int me, key, exit;

    for(int i = 0; i < 10; i++)
        fscanf(stdin, "%s",maze[i]);

    vvi adjList;
    adjList.assign(15*15, vi());

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
        {
            if(maze[i][j] == 'x')
                continue;

            int vertex_id = i*10 + j;
            int ii, jj;
            for(int d = 0; d < 4; d++)
            {
                ii = i+dr[d];
                jj = j+dc[d];
                if(ii >= 0 && ii < 10 && jj >= 0 && jj < 10)
                {
                    if(maze[ii][jj]!= 'x')
                    {
                        int next_vertex_id = ii*10 +jj;
                        adjList[vertex_id].push_back(next_vertex_id);
                    }
                }
            }
            if(maze[i][j] == 'm')
                me = vertex_id;
            else if(maze[i][j] == 'k')
                key = vertex_id;
            else if(maze[i][j] == 'e')
                exit = vertex_id;
        }
    }

    int SSSP_1, SSSP_2, SSSP;

    SSSP_1 = BFS_SSSP(me, key, adjList);
    SSSP_2 = BFS_SSSP(key, exit, adjList);

    SSSP = SSSP_1 + SSSP_2;
    fprintf(stdout, "%d\n", SSSP);

    return 0;
}
