// PROBLEMA DE LA BOMBA DE DESTRUCCION MASIVA
// ULTIMO PROBLEMA ANHO 2012

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
#define AREA(x,y)abs(x.first-y.first)*abs(x.second-y.second)

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
    int n,casos;
    cin >> casos;
    for(int caso=1; caso<=casos; caso++){
        int area_total=0;
        cin >> n;//CANTIDAD DE BOMBAS
        vector < pair<ii,ii> > rectangulos;//VECTOR QUE CONTIENE A LOS RECTANGULOS
        while(n--){                        //CADA RECTANGULO ESTA FORMADO POR DOS PUNTOS X, Y
            ii a,b;                        //POR LO TANTO SE NECESITA UN VECTOR QUE TENGA DOS PARES
            cin >> a.first >> a.second >> b.first >> b.second;
            area_total+=AREA(a,b);//CALCULO EL AREA DEL TRIANGULO Y LO METO EN EL ACUMULADOR
            rectangulos.pb(make_pair(a,b));
        }
        //EL PASO MAS IMPORTANTE ES ELIMINAR LAS AREAS DE LOS RECTANGULOS QUE ESTAN SUPERPUESTOS
        //POR LO TANTO RECORREMOS POR TODOS LOS RECTANGULOS Y SI ESTAN SUPERPUESTOS
        //CALCULAMOS ESA AREA Y LA ELIMINAMOS
        for(int i=0; i<(int)rectangulos.size();i++){
            for(int j=i+1; j<(int)rectangulos.size(); j++){
                //CALCULAMOS LA ALTURA Y ANCHURA DEL AREA SUPERPUESTA
                //EL RECTANGULO ESTA FORMADO POR DOS PARES DE PARES
                //CADA RECTANGULO TIENE EL PUNTO A(ESQUINA INFERIOR IZQUIERDA) Y EL BUNTO B(ESQUINA SUPERIOR DERECHA)
                pair<ii,ii> rectangulo1=rectangulos[i],rectangulo2=rectangulos[j];
                ii a1,b1,a2,b2;//PUNTOS A1, B1, A2, B2 DEL EJEMPLO
                a1=rectangulo1.first,b1=rectangulo1.second;
                a2=rectangulo2.first,b2=rectangulo2.second;
                //FORMULA PARA CALCULAR LA DISTANCIA ENTRE LA INTERSECCION DE RECTAS
                //          ......................
                //         a2x=a2.first        b2x=b2.first
                //
                //   .....................
                // a1x=a1.first        b1x=b1.first
                //
                // FORMULA Y SU PUTO ANALISIS XD
                // PRIMERO CALCULAR EL LARGO TOTAL, ES DECIR DESDE EL PUNTO a1x HASTA b2x
                // distancia_total=abs(min(a1x,a2x)-max(b1x,b2x))
                // LUEGO OBTENER LA DISTANCIA ENTRE a1x y a2x, LO MISMO para b1x y b2x
                // distancia1=abs(a1x-a2x),distancia2=abs(b1x-b2x)
                // RESTAR A DISTANCIA TOTAL, DISTANCIA 1 Y DISTANCIA 2, ESA ES LA DISTANCIA INTERSECTADA
                // area_sup=distancia_total-(distancia1+distancia2)
                int altura=abs(min(a1.second,a2.second)-max(b1.second,b2.second))-abs((a1.second-a2.second)+(b1.second-b2.second));
                int anchura=abs(min(a1.first,a2.first)-max(b1.first,b2.first))-abs((a1.first-a2.first)+(b1.first-b2.first));
                int area_superpuesta=altura*anchura;
                area_total-=area_superpuesta;
            }
        }
        printf("Caso #%d: %d\n",caso,area_total);
    }
    return 0;
}
