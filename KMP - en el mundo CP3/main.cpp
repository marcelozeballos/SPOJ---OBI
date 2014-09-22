#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kmpTable;

void kmpPreprocess(string str, int len)
{
    int i = 0, j = -1; kmpTable.push_back(-1);

    while(i < len)
    {
        while(j >= 0 && str[i] != str[j])
            j = kmpTable[j];

        i++; j++;
        kmpTable.push_back(j);
    }
}

int main()
{
    int cases; cin >> cases;
    int cnt = 1;
    while(cases--)
    {
        string str; cin >> str;
        int len = str.size();

        kmpPreprocess(str, len);

        cout << "Caso " << cnt << ":" << endl;
        for(int i = 0; i < (int)kmpTable.size(); i++)
        {
            if(kmpTable[i] > 0)
                cout << i << ": " << kmpTable[i] << endl;
        }
    }
    return 0;
}
