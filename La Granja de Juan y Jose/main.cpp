#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    unsigned long long int x, y;
    while(cin >> x >> y, x || y)
    {
        unsigned long long int cows = 0, hens = 0;
        if(x == y){
            cout << setprecision(0) << fixed << -1 << endl;
            continue;
        }
        cows = ((y-(2*x))/2);
        hens = x - cows;

        if((cows+hens) == x && ((cows*4 + hens*2) == y))
            cout << setprecision(0) << fixed << hens << " " << cows << endl;
        else
            cout << setprecision(0) << fixed << -1 << endl;
    }
    return 0;
}
