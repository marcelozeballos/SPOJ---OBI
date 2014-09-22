#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int cases; cin >> cases;int caso=1;
    while(cases--)
    {
        string str; cin >> str;
        cout << "Caso " << caso << ":" << endl;
        caso++;
        for(int i = 0; i < (int)str.size(); i++)
        {
            string nueva(str,0,i+1);
            string suffix, prefix;
            int cnt = 0;
            for(int j = 0,k=(int)nueva.size()-1; j < (int)nueva.size()-1; j++,k--)
            {
                suffix = suffix+nueva[j];
                prefix = nueva[k]+prefix;
                if(suffix == prefix){
                    cnt = suffix.size();
                }
            }
            if(cnt!=0)
                printf("%d: %d\n",i+1,cnt);
        }
    }
    return 0;
}
