#include <cstdio>
using namespace std;

int sum_of_divs(int n)
{
    int sum = 0;
    for(int i = 1; i <= n/2; i++)
        if(n%i == 0)
            sum += i;
        if(sum == 0) return -1;
        else
            return sum;
}

int main()
{
    int num;
    while(fscanf(stdin, "%d", &num) != EOF)
    {
        int aux1 = sum_of_divs(num);
        int aux2 = sum_of_divs(aux1);
        if(aux2 == num)
            fprintf(stdout, "%d\n", aux1);
        else
            fprintf(stdout, "-1\n");
    }
}
