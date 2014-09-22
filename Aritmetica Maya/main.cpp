#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int cases; scanf("%d", &cases);

    while(cases--)
    {
        string digits[4];
        for(int i =0; i < 4; i++)
            cin >> digits[i];

        int sum[4];
        memset(sum, 0, sizeof(sum));

        for(int i =0; i < 4; i++)
        {
            for(int j =0; j < digits[i].size(); j++){
                if(digits[i].at(j) == '-')
                    sum[i] += 5;
                if(digits[i].at(j) == '.')
                    sum[i]++;
                if(digits[i].at(j) == '0')
                    sum[i] = 0;
            }
        }
        int decimal =(sum[0]*20*20*20)+(sum[1]*20*20)+(sum[2]*20)+(sum[3]*1);
        printf("%d\n", decimal);
    }
    return 0;
}
