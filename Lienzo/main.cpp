//FLOOD FILL EXAMPLE 3

#include <cstdio>
using namespace std;

int r, c, a;
int df[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
int mat[105][105];

int flood_fill(int fil, int col, int color)
{
    if(fil < 0 || fil > r || col < 0 || col > c)
        return 0;
    if(mat[fil][col] != color)
        return 0;
    mat[fil][col]=0;
    int salida = 1;
    for(int i = 0; i < 8; i++){
        salida += flood_fill(fil+df[i],col+dc[i],color);
    }
    return salida;
}

int main()
{
    while(scanf("%d %d %d", &r, &c, &a), r || c || a)
    {
        int cnt = 0;
        for(int i = 0; i< r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d", &mat[i][j]);

        for(int i = 0; i< r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] != 0 && mat[i][j] != a){
                    flood_fill(i,j,mat[i][j]), cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
