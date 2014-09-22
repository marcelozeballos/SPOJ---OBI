// MONDRIAN, TRICKIEST EVER

#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;

int main()
{
    int cases; scanf("%d", &cases);

    while(cases--)
    {
        int col, rows; scanf("%d %d", &col, &rows);
        int reps, cnt = 1; scanf("%d", &reps);
        int mat[rows][col];
        int k,l;
        memset(mat, 0, sizeof(mat));
        vii vec;

        while(reps--){
            ii aux; cin >> aux.first >> aux.second;
            vec.push_back(aux);
        }
        int recor=0,cnt1,cnt2;
        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]==0){
                    int width=vec[recor].first,height=vec[recor].second;
                    for(k=i,cnt1=0; cnt1<height;k++,cnt1++){
                        for(l=j,cnt2=0;cnt2<width; l++,cnt2++)
                            mat[k][l]=cnt;
                    }
                    cnt++,recor++;
                }
            }
        }
        for(int x = 0; x < rows; x++ ){
            for(int z = 0; z < col; z++){
                if(z != 0)
                    printf(" ");
                printf("%d", mat[x][z]);
            }
            printf("\n");
        }
    }
    return 0;
}
