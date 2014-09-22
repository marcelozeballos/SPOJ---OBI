#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int d1, d2, d3, d4, d5;

    while(scanf("%d %d %d %d %d", &d1, &d2, &d3, &d4, &d5), d1 > 0 || d2 > 0 || d3 > 0 || d4 > 0 || d5 > 0)
    {
        int cnt = 1;
        bool found =  false;
        for(int i =0; i < 5; i++)
        {
            int vec[6] = {d1,d2,d3,d4,d5,10};
            vec[i] = 7 - vec[i];
            sort(vec, vec+6);

            for(int j = 0; j < 5; j++)
            {
                if(vec[j] == vec[j+1])
                    cnt++;
                if(vec[j] != vec[j+1])
                    cnt = 1;
                if(cnt == 4)
                    break;
            }
            if(cnt == 4){
                found = true;
                break;
            }
            else
                cnt = 1;
        }
        if(found)
            printf("Poquer de huevo\n");
        else
            printf("No\n");
    }
    return 0;
}
