#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nc,c,n,precio,aux;
    int vec[7];
    scanf("%i",&nc);
    while(nc--)
    {
        scanf("%i %i",&c,&n);
        for(int d=0;d<6;d++)
            c%7 > d ? vec[d]=c/7 +1 : vec[d]=c/7 ;
        vec[6]=c/7;
        precio=0;
        while(n>0)
        {
            aux=n;
            if (vec[2]>0) {n-=vec[2];if (n<0) n=0; precio+=(aux-n)*10;vec[2]=0;}
            else if (vec[0]>0) {n-=vec[0];if (n<0) n=0; precio+=(aux-n)*20;vec[0]=0;}
            else if (vec[1]>0) {n-=vec[1];if (n<0) n=0; precio+=(aux-n)*20;vec[1]=0;}
            else if (vec[3]>0) {n-=vec[3];if (n<0) n=0; precio+=(aux-n)*20;vec[3]=0;}
            else if (vec[4]>0) {n-=vec[4];if (n<0) n=0; precio+=(aux-n)*20;vec[4]=0;}
            else if (vec[5]>0) {n-=vec[5];if (n<0) n=0; precio+=(aux-n)*30;vec[5]=0;}
            else if (vec[6]>0) {n-=vec[6];if (n<0) n=0; precio+=(aux-n)*30;vec[6]=0;}
        }
        printf("%i\n",precio);

        //cout<<lu<<" "<<ma<<" "<<mi<<" "<<ju<<" "<<vi<<" "<<sa<<" "<<dom<<endl;
    }
    return 0;
}
