#include <iostream>
#include <cstdio>
using namespace std;

char grid[25][25];
int r, c;
int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(int row, int col, char blue)
{
    if(row < 0 || row >= r || col < 0 || col >= c) return 0;
    int salida = 0;
    for(int d = 0; d < 8; d++)
        if(grid[row+dr[d]][col+dc[d]] == 'A')
        salida++;
    return salida;
}
int main()
{
    int cases; scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d", &r, &c);

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> grid[i][j];
        int cnt =-1, x = 0, y =0, aux;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '*'){
                aux = floodfill(i, j, 'A');
                }
                if(aux > cnt && aux >= 3){
                    y = i, x = j;
                    cnt = aux;
                }
            }
        }
        if(x > 0 && y > 0)
            printf("%d %d\n", y+1, x+1);
        else
            printf("0 0\n");
    }
    return 0;
}
