//TRICKY AS WELL, CUANDO VER PELICULAS.

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int cases; fscanf(stdin, "%d", &cases);

    while(cases--)
    {
        int days, movs; fscanf(stdin, "%d %d", &days, &movs);

        int prices[] = {20,20,10,20,20,30,30};
        if(days > 2)
            sort(prices,prices+7);
        int arr[7];
        memset(arr,0,sizeof arr);

        int it = 0;
        while(days != 0)
        {
            arr[it]++;
            it++;
            days--;
            if(it == 7)
                it = 0;
        }
        int sum =0;
        it = 0;
        while(movs--)
        {
            sum += prices[it];
            arr[it]--;
            if(arr[it] == 0)
                it++;
        }
        fprintf(stdout, "%d\n", sum);
    }
    return 0;
}
