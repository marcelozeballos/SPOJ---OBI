#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int cases; fscanf(stdin, "%d", &cases);

    while(cases--)
    {
        int grid_size, moves, ans = 0;

        fscanf(stdin, "%d %d", &grid_size, &moves);
        int arrx[moves], arry[moves];

        for(int i = 0; i < moves; i++)
            fscanf(stdin, "%d %d", &arrx[i], &arry[i]);

        bool grid[200][200];
        memset(grid, 0, sizeof grid);
        grid[1][1] = true;

        ans++;

        queue<int> qx;
        queue<int> qy;

        qx.push(1);
        qy.push(1);
        int x, y, xx, yy;
        while(!qx.empty())
        {
            x = qx.front();
            qx.pop();

            y = qy.front();
            qy.pop();

            for(int it = 0; it< moves; it++)
            {
                xx = x+arrx[it];
                yy = y+arry[it];

                if(yy >= 1 && xx >= 1 && yy <= grid_size && xx <= grid_size && !grid[yy][xx])
                {
                    qx.push(xx);
                    qy.push(yy);
                    grid[yy][xx] = true;
                    ans++;
                }
            }
        }

        fprintf(stdout, "%d\n", ans);
    }
    return 0;
}
