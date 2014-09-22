#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int cases; scanf("%d", &cases);

    while(cases--)
    {
        string str; cin >> str;
        int len  =str.size();
        if(str[0] == '*')
        {
            if(str[4] == '*')
            {
                if(str[len-1] == '#')
                {
                    bool control1 = true;
                    for(int i = 1; i < 4; i++){
                        if(str[i] >= '0' && str[i] <= '9')
                            control1 = true;
                        else{
                            control1 = false;
                            break;
                        }
                    }
                    if(control1)
                    {
                        bool control2 = true;
                        for(int j = 5; j < len-1; j++){
                            if(str[j] >= '0' && str[j] <= '9')
                                control2 = true;
                            else{
                                control2 = false;
                                break;
                            }
                        }
                        if(control2)
                            printf("bien\n");
                        else
                            printf("mal\n");
                    }
                    else
                        printf("mal\n");
                }
                else
                    printf("mal\n");
            }
            else
                printf("mal\n");
        }
        else
            printf("mal\n");
    }
    return 0;
}
