#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
	if ( x <= 1 ) return false;
	if ( x == 2 ) return true;
	if ( x%2 == 0 ) return false;
	int lim = floor(sqrt(x));
	for(int i = 3; i <= lim; i += 2)
		if ( x%i == 0 ) return false;
	return true;
}

int main()
{
    int len; fscanf(stdin, "%d", &len);
    int arr[len];

    for(int i = 0; i < len; i++)
        fscanf(stdin, "%d", &arr[i]);

    int me, pos; fscanf(stdin, "%d", &me);

    for(int i = 0; i < len; i++){
        if(arr[i] == me){
            pos = i;
            break;
        }
    }

    if(pos == 0 || pos == (len-1))
        fprintf(stdout, "No\n");
    else
    {
        if(isPrime(arr[pos+1]) && isPrime(arr[pos+1]))
            fprintf(stdout, "Yes\n");
        else
            fprintf(stdout, "No\n");
    }
    return 0;
}
