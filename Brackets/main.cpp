#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;

    string brackets;
    for(int i = 0; i < n; i++)
        brackets += '(';
    for(int i = 0; i < n; i++)
        brackets += ')';
    cout << brackets << endl;
    while(next_permutation(brackets.begin(),brackets.end()))
        cout << brackets << endl;
}
