#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int quant;

    while(fscanf(stdin, "%d", &quant), quant)
    {
        map<int,int> Map;

        for(int i = 0; i < quant; i++){
            int aux; fscanf(stdin, "%d", &aux);
            Map[aux]++;
        }

        int maximum = -1;
        map<int,int>::iterator it;
        for(it = Map.begin(); it != Map.end(); ++it){
            int aux = it->second;
            maximum = max(maximum, aux);
        }

        int reps = 0;
        map<int,int>::iterator ite;
        for(ite = Map.begin(); ite != Map.end(); ++ite){
            int aux = ite->second;
            if(aux == maximum)
                reps++;
        }

        if(reps == Map.size() && Map.size() > 1)
            fprintf(stdout, "-1\n");
        else if(Map.size() == 1){
            map<int,int>::iterator i;
            for(i = Map.begin(); i != Map.end(); ++i)
                fprintf(stdout, "%d\n", i->first);
        }
        else{
            map<int,int>::iterator iter;
            for(iter = Map.begin(); iter != Map.end(); ++iter){
                int aux = iter->second;
                int aux2 = iter->first;
                if(aux == maximum)
                    fprintf(stdout, "%d\n", aux2);
            }
        }
    }
    return 0;
}
