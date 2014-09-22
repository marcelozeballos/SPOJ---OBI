// DICCIONARIO DE ANAGRAMAS. VER QUE PALABRAS SON ANAGRAMAS
// ANAGRAMA ES UN ORDEN DIFERENTE DE LETRAS, PERO QUE HACEN LA
// MISMA PALABRA

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int cases; scanf("%d", &cases);
    while(cases--)
    {
        int len; scanf("%d", &len);
        string vecs[len];
        for(int i = 0; i < len; i++){
            cin >> vecs[i];
            sort(vecs[i].begin(), vecs[i].end());
        }

        int vec[len];
        memset(vec, 0, sizeof(vec));

        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                if(i != j){
                    if(vecs[i] == vecs[j])
                        vec[i]++;
                }
            }
        }
        bool first = true;
        for(int i = 0; i < len; i++){
            if(first){
                printf("%d", vec[i]);
                first = false;
            }
            else
                printf(" %d", vec[i]);
        }
        printf("\n");
    }
}
