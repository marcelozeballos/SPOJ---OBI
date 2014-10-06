#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int pos,tam;
string cadena;
bool isEmpty,primero,ultimo;

int contar(){
    int c=0,i=pos+1;
    while(i<tam){
        if(cadena[i]=='P'){isEmpty=false;break;}
        else c++;
        i++;
    }
    pos=i;
    return c;
}

int main() {
    int t,cont,salida;
    cin >>t;
    while(t--){
        cin >> cadena;
        tam=(int)cadena.size();
        pos=-1;
        isEmpty=true,primero=true,ultimo=false;
        salida=0;
        cont=0;
        while(pos<tam){
            cont=contar();
            if(pos>=tam)ultimo=true;
            if(isEmpty){
                salida+=(cont/3);
                if(cont%3!=0)salida++;
            }else{
                if(primero || ultimo){
                    if(primero)primero=false;
                    cont--;
                    if(cont>=1){
                        salida+=(cont/3);
                        if(cont%3!=0)salida++;
                    }
                }else{
                    cont-=2;
                    if(cont>=1){
                        salida+=((cont)/3);
                        if((cont)%3!=0)salida++;
                    }
                }

            }
        }
        fprintf(stdout,"%d\n",salida);
    }
    return 0;
}
