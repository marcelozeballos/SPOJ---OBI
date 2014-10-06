#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string name; cin >> name;
    int len = name.size();
    if(len%2 == 0)
        fprintf(stdout, "Es Genial\n");
    else
        fprintf(stdout, "No es Genial\n");

    return 0;
}
