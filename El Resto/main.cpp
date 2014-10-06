#include <cstdio>
using namespace std;

int main()
{
    int fibx, num;

    while(fscanf(stdin, "%d %d", &num, &fibx), num || fibx)
    {
        int fn = 0, first = 1, second= 1;

        if(fibx == 0 || fibx == 1)
            fn = 1;
        else{
            for(int i = 1; i < fibx; i++){
                fn = (first%num + second%num)%num;
                first = second;
                second = fn;
            }
        }
        fprintf(stdout, "%d\n", fn);
    }
    return 0;
}
