#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int h1, h2, m1, m2;
    char aux;

    fscanf(stdin,"%d %c %d %d %c %d", &h1, &aux, &m1, &h2, &aux, &m2);
    int ht, mt;
    ht = h2 - h1;
    if(m2 < m1)
    {
        ht--;
        mt = m2+60;
        mt = mt - m1;
    }
    else
        mt = m2 - m1;
    fprintf(stdout, "%d horas, %d minutos\n", ht, mt);

    return 0;

}

