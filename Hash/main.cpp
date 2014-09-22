#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    string line;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while(getline(cin,line))
    {
        int elements = 0, pos = 0, key = 0;

        for(int i = 0; i < (int)line.size(); i++){
            if(line[i] != ' '){
                int aux = alphabet.find(line[i]);
                key += (aux + elements + pos);
                pos++;
            }
            else{
                elements++;
                pos = 0;
            }
        }
        fprintf(stdout, "%d\n", key);
    }
    return 0;
}
