// FIND IF FRACTIONS ARE EQUIVALENT

#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a%b));
}

int lcm(int a, int b){
    return (a * (b / gcd(a,b)));
}

int main()
{
    int n1, d1, n2, d2;
    while(scanf("%d %d %d %d", &n1, &d1, &n2, &d2), n1 || d1 || n2 || d2)
    {
        int a, b;
        a = gcd(n1,d1);
        b = gcd(n2,d2);
        n1 = n1/a;
        d1 = d1/a;
        n2 = n2/b;
        d2 = d2/b;
        if(n1 == n2 && d1 == d2)
            printf("=\n");
        else
            printf("!=\n");
    }
}
