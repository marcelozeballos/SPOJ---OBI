#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
using namespace std;

long long dotProduct(int A0, int A1, int B0, int B1, int C0, int C1)
{
    long long AB0, AB1, BC0, BC1;
    AB0 = B0 - A0;
    AB1 = B1 - A1;
    BC0 = C0 - B0;
    BC1 = C1 - B1;

    long long dot = (AB0 * BC0) + (AB1 * BC1);
    return dot;
}

long long crossProduct(int A0, int A1, int B0, int B1, int C0, int C1)
{
    long long AB0, AB1, AC0, AC1;
    AB0 = B0 - A0;
    AB1 = B1 - A1;
    AC0 = C0 - A0;
    AC1 = C1 - A1;

    long long cross = (AB0 * AC1) - (AB1* AC0);
    return cross;
}

double dist(int A0, int A1, int B0, int B1)
{
    int d1 = A0 - B0;
    int d2 = A1 - B1;

    return hypot(d1,d2);
}

double linePointDist(int A0, int A1, int B0, int B1, int C0, int C1, bool isSegment)
{
    double d = (crossProduct(A0, A1, B0, B1, C0, C1))/(dist(A0, A1, B0, B1));
    if(isSegment){
        long long dot1 = dotProduct(A0, A1, B0, B1, C0, C1);
        if(dot1 > 0)
            return dist(B0, B1, C0, C1);
        long long dot2 = dotProduct(B0, B1, A0, A1, C0, C1);
        if(dot2 > 0)
            return dist(A0, A1, C0, C1);
    }
    return abs(d);
}

int main()
{
    int cases, reps = 1; fscanf(stdin, "%d", &cases);

    while(cases--)
    {
        int throws, seeds, cnt = 0;
        fscanf(stdin, "%d %d", &throws, &seeds);

        int x[throws], y[throws], r[throws], dx[throws], dy[throws], t[throws];
        for(int i = 0; i < throws; i++)
            fscanf(stdin, "%d %d %d %d %d %d", &x[i], &y[i], &r[i], &dx[i], &dy[i], &t[i]);

        int sx[seeds], sy[seeds];
        for(int i = 0; i < seeds; i++)
            fscanf(stdin, "%d %d", &sx[i], &sy[i]);

        bool arr[seeds];
        memset(arr, 0,sizeof arr);

        for(int i = 0; i < throws; i++)
        {
            int nx = x[i], ny = y[i], nr = r[i], ndx = dx[i], ndy = dy[i], nt = t[i];
            // calculate the last point of the line with the equation v=d/t.
            // isolated: v*t=d
            int lx = nx, ly = ny;
            lx += (ndx*nt);
            ly += (ndy*nt);
            double compval = -1;
            for(int j = 0; j < seeds; j++)
            {
                if(!arr[j]){
                    compval = linePointDist(nx,ny,lx,ly,sx[j],sy[j],true);
                    if(compval > -1 && compval <= nr){
                        cnt++;
                        arr[j] = true;
                    }
                }
                compval = -1;
            }
        }
        fprintf(stdout, "Caso %d: %d\n", reps, cnt);
        reps++;
    }
    return 0;
}
