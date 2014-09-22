#include <algorithm>
#include <cstdio>
using namespace std;

bool compare(int a, int b){
    return abs(a) > abs(b);
}
int main()
{
    int cases; scanf("%d", &cases);

    while(cases--)
    {
        int len; scanf("%d", &len);

        int vec[len];
        for(int i = 0; i < len; i++)
            scanf("%d", &vec[i]);

        sort(vec,vec+len,compare);
        int minimum = 1000000000;
        for(int i = 0; i < len-1; i++){
            int aux = vec[i] + vec[i+1];
            if(abs(aux) <= abs(minimum)){
                if(abs(aux) == abs(minimum)){
                    minimum = min(aux, minimum);
                }
                else
                    minimum = aux;
            }
        }
        printf("%d\n", minimum);
    }
    return 0;
}
