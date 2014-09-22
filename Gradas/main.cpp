#include <cstdio>
using namespace std;

int main()
{
    int n;

    while(scanf("%d", &n), n > -1)
    {
        int lines = (n*2)+1;
        printf("%d\n", lines);
    }
    return 0;
}
