#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int rows, col; fscanf(stdin, "%d %d", &rows, &col);
    int grid[rows][col];

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < col; j++)
            cin >> grid[i][j];

    bool zigzag = true;
    bool increase = true;

    int x = 0, y =0;
    while(y < col)
    {
        if(grid[x][y] == 0){
            zigzag = false;
            break;
        }
        if(x == (rows-1))
            increase = false;
        else if(x == 0)
            increase = true;

        if(increase)
            x++;
        else if(!increase)
            x--;

        y++;
    }
    if(zigzag)
        fprintf(stdout, "YES\n");
    else
        fprintf(stdout, "NO\n");
}
