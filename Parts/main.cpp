#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

unsigned long long int factorial(unsigned long long int x)
{
    if(x == 0) return 1;
    else return factorial(x-1)*x;
}

int main()
{
    unsigned long long int num;

    int cases; fscanf(stdin, "%d", &cases);

    while(cases--)
    {
        cin >> num;
        num = num%1000000007;
        unsigned long long int rans = 0, n = 0, ans = 0, cpy = num;
        rans = factorial(num-1);

        while(n <= (num-1))
        {
            ans += cpy*(rans/(factorial(n)*factorial((num-1)-n)));
            cpy--;
            n++;
        }
        cout << ans << endl;
    }

    return 0;
}
