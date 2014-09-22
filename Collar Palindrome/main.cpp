// COLLAR PALINDROME.
// SPINNING A VECTOR OR STRING

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int cases; fscanf(stdin, "%d", &cases);

    while(cases--)
    {
        int len; fscanf(stdin, "%d", &len);

        string str;
        for(int i = 0; i < len; i++)
        {
            char aux; cin >> aux;
            str += aux;
        }
        int lenp; fscanf(stdin, "%d", &lenp);

        int reps = len;
        bool found = false;
        while(reps--)
        {
            for(int i = 0; i <= len-lenp; i++)
            {
                string help1, help2;
                help1 = str.substr(i,lenp);
                help2 = help1;
                reverse(help2.begin(), help2.end());

                if(help1 == help2)
                {
                    found = true;
                    cout << "SI" << endl;
                    goto Salir;
                }
            }
            str.push_back(str[0]);
            str.erase(str.begin());
        }
        Salir:
        if(!found)
            fprintf(stdout, "NO\n");
    }
    return 0;
}
