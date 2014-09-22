#include <cstdio>

using namespace std;

int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
int main()
{
    int number;
    while(scanf("%d", &number), number)
    {
        int answer, cnt = 1;
        while(answer < number){
            answer = power(number,cnt);
            answer = answer/number;
            cnt++;
        }
        printf("%d\n", answer);
    }
}
