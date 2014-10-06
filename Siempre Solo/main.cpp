#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

int main()
{
    int quant;

    while(fscanf(stdin, "%d", &quant), quant)
    {
        char str[1005];
        map <char,int> Map;
        fscanf(stdin, "%s", str);
        for(int i = 0; i < (int)strlen(str); i++){
            Map[str[i]]++;
        }
        map <char,int>::iterator it;
        int cnt = 0;
        char tofind;
        for(it = Map.begin(); it != Map.end(); ++it)
        {
            int aux = it->second;
            if(aux == 1){
                tofind = it->first;
                break;
            }
        }
        for(int i = 0; i < (int)strlen(str); i++){
            if(str[i] == tofind){
                fprintf(stdout, "%d\n", i+1);
                break;
            }
        }
    }
    return 0;
}
