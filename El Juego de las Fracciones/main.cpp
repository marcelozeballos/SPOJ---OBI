#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <vector>
using namespace std;

long long _sieve_size;
bitset<10000010> bs;
vector <int> primes;

void sieve(long long upperbound)
{
    _sieve_size = upperbound;
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i <= _sieve_size; i++) if(bs[i]){
        for(long long j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

int main()
{
    sieve(100);

    int quant;
    while(fscanf(stdin, "%d", &quant), quant)
    {
        int a, b; a = b = quant;

        int cnta = 0, cntb = 0;

        while(a--)
        {
            string aux, num1, num2; cin >> aux;
            int n1, n2;
            bool dash = false;
            for(int i = 0; i < (int)aux.size(); i++)
            {
                if(!dash && aux[i] !='/')
                    num1 += aux[i];
                if(aux[i] == '/')
                    dash = true;
                if(dash && aux[i] != '/')
                    num2 += aux[i];
            }

            stringstream sso1(num1);
            sso1 >> n1;
            stringstream sso2(num2);
            sso2 >> n2;

            bool divisible = false;
            for(int i = 0; i < primes.size(); i++){
                if(n1%primes[i] == 0 && n2%primes[i] == 0){
                    divisible = true;
                    break;
                }
            }
            if(!divisible)
                cnta++;
        }

        while(b--)
        {
            string aux, num1, num2; cin >> aux;
            int n1, n2;
            bool dash = false;
            for(int i = 0; i < (int)aux.size(); i++)
            {
                if(!dash && aux[i] !='/')
                    num1 += aux[i];
                if(aux[i] == '/')
                    dash = true;
                if(dash && aux[i] != '/')
                    num2 += aux[i];
            }

            stringstream sso1(num1);
            sso1 >> n1;
            stringstream sso2(num2);
            sso2 >> n2;

            bool divisible = false;
            for(int i = 0; i < primes.size(); i++){
                if(n1%primes[i] == 0 && n2%primes[i] == 0){
                    divisible = true;
                    break;
                }
            }
            if(!divisible)
                cntb++;
        }
        if(cnta > cntb)
            fprintf(stdout, "Alice\n");
        if(cntb > cnta)
            fprintf(stdout, "Bob\n");
        if(cnta == cntb)
            fprintf(stdout, "=\n");
    }
    return 0;
}
