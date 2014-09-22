#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

long long binary(long long num)
{
    long long rem, i = 1, bin =0;
    while(num != 0)
    {
        rem = num%2;
        num /= 2;
        bin +=rem*i;
        i *= 10;
    }
    return bin;
}

int main()
{
    long long number;
    while(cin >> number)
    {
        long long answer;
        answer = binary(number);

        stringstream temp;
        temp << answer;
        string aux = temp.str();

        cout << aux.size() << endl;

    }
}
