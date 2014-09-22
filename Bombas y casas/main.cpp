#include <cstring>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <cmath>

using namespace std;

#define VISITADO 1
#define NOVISITADO -1
#define MEDIO 2
#define inttochar(x)(char(x+'0'))
#define chartoint(x)(int(x-'0'))
#define mod1097 1000000007
#define pb push_back
#define ROUND(x)int(double(x)+0.5)
#define DISTANCE(x,y)sqrt(((x.first-y.first)*(x.first-y.first))+((x.second-y.second)*(x.second-y.second)))

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef vector< bool > vb;
typedef vector<string> vs;
typedef map<string,int>msi;
typedef map<int,int>mii;
typedef vector< vi > grafoSP;
typedef vector< vii > grafoCP;//GRAFO CON PESO, FIRST=NODO,SECOND=PESO
typedef unsigned long long int ull;

//UNION FIND DISJOINT SET
vi pset;
void initSet(int n){pset.assign(n,0);for(int i=0; i<n; i++)pset[i]=i;}
int findSet(int i){return (pset[i]==i)?i:(pset[i]=findSet(pset[i]));}
bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
void unionSet(int i,int j){pset[findSet(i)]=findSet(j);}

int main(){
    int n,casos,x,y,r;
    ii aux;
    cin >> casos;
    while(casos--){
        cin >> n;//NUMERO DE CASAS PROTOS
        vii casas;//VECTOR DE PARES QUE CONTIENE LAS CASAS DE LOS PROTOS
        while(n--){
            cin >> aux.first >> aux.second;
            casas.pb(aux);
        }
        cin >> x >> y >> r;//COORDENADAS DE LA BOMBA
        int contador=0;
        for(int i=0; i<(int)casas.size(); i++)//RECORRO POR TODAS LAS CASAS
            if(DISTANCE(ii(x,y),casas[i])<=r)//COMPRUEBO QUE LA DISTANCIA ENTRE LA BOMBA Y LA CASA
                contador++;                  //SEA MENOR O IGUAL AL RADIO, DISTANCE() RECIBE DOS PARES DE ENTEROS
        cout << contador << endl;
    }
    return 0;
}
