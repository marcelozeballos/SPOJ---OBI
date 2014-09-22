#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int hours, minutes; fscanf(stdin, "%d %d", &hours, &minutes);

    int angleh, anglem;
    if(hours < 12)
        angleh = hours*30;
    else
        angleh = (hours-12)*30;

    anglem = minutes*6;

    fprintf(stdout,"%d %d\n", angleh, anglem);

    return 0;
}
