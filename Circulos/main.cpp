#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <sstream>
using namespace std;
#define inttochar(x) (char(x+'0'))

string turn(long long n)
{
    string ans;
    while(n > 0)
    {
        int dig = n%10;
        ans += inttochar(dig);
        n /= 10;
    }
    return ans;
}

long long gcd(long long a, long long b){
    return (b == 0 ? a : gcd(b, a%b));
}

int main()
{
    int circles; fscanf(stdin, "%d", &circles);

    long long x1[circles], y1[circles], x2[circles], y2[circles], x3[circles], y3[circles];
    for(int i = 0; i < circles; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> x3[i] >> y3[i];
    map<string,int> counter;
    for(int i = 0; i < circles; i++)
    {
        long long nx1 = x1[i], ny1 = y1[i], nx2 = x2[i], ny2 = y2[i], nx3 = x3[i], ny3 = y3[i];

        long long num;
        num = (((nx2-nx1)*(nx2-nx1))+((ny2-ny1)*(ny2-ny1)))*(((nx2-nx3)*(nx2-nx3))+((ny2-ny3)*(ny2-ny3)))*(((nx3-nx1)*(nx3-nx1))+((ny3-ny1)*(ny3-ny1)));

        long long den;
        den = 2*(abs((nx1*ny2)+(nx2*ny3)+(nx3*ny1)-(nx1*ny3)-(nx2*ny1)-(nx3*ny2)));
        long long ans;
        ans = den*den;

        long long a;
        a = gcd(num,ans);
        num = num/a;
        ans = ans/a;

        string n;
        string aux1;
        aux1 = turn(num);
        string aux2;
        aux2 = turn(ans);
        n = aux1 + '/' + aux2;
        counter[n]++;
    }
    int maximum = -1;
    map<string,int>::iterator it;
    for(it = counter.begin(); it != counter.end(); ++it)
        maximum = max(it->second,maximum);

    fprintf(stdout, "%d\n", maximum);

    return 0;
}
