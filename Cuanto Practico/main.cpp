#include <iostream>
#include <string>
using namespace std;

int tam,puentes;
string cadena,copia;

void colorear(int fila,char buscado,char cambiar){
    if(fila<0 || fila>=tam)return;
    if(copia[fila]!=buscado)return;
    if(copia[fila]==buscado)cadena[fila]=cambiar,copia[fila]=cambiar;
    colorear(fila-1,buscado,cambiar);
    colorear(fila+1,buscado,cambiar);
}

int contar(int fila,char buscado){
    if(fila<0 || fila>=tam)return 0;
    if(cadena[fila]!=buscado)return 0;
    cadena[fila]='1';
    int salida=1;
    salida=salida+contar(fila-1,buscado);
    salida=salida+contar(fila+1,buscado);
    return salida;
}

void recorrer(int pos){
    int fin=-1;
    for(int i=pos; i<tam ;i++){
        if(copia[i]!='C'){fin=i;break;}
    }
    if(fin=-1)fin=tam-1;
    if(pos-1<0 || copia[pos-1]=='P'){
        if(fin+1>=tam || copia[fin+1]=='P'){
            ///SIRVE
            ///colorear(pos,'C','-');
        }else{
            ///NO TIENE PUENTE A LA DERECHA, POR LO TANTO LO COLOCO
            cadena[fin+1]='P';
            copia[fin+1]='P';
            puentes++;
        }
    }else{
        ///NO TIENE PUENTE A LA IZQUIERDA
        cadena[pos-1]='P';
        puentes++;
        if(fin+1>=tam || copia[fin+1]=='P'){
            ///TIENE PUENTE
        }else{
            cadena[fin+1]='P';
            copia[fin+1]='P';
            puentes++;
        }
    }
}

int main() {
    int t;
    cin >>t;
    while(t--){
        cin >> cadena;
        copia=cadena;
        tam=(int)cadena.size();
        ///SI TODOS SON PUNTOS
        bool iguales=true;
        for(int i=0; i<tam; i++){
            if(cadena[i]!='.'){iguales=false;break;}
        }
        ///ENCUENTRO ACERAS Y LAS AISLO SINO LO ESTAN
        for(int i=0; i<tam; i++){
            if(copia[i]=='C'){
                recorrer(i);
            }
        }
        ///COLOREAR PUENTES
        for(int i=0; i<tam; i++){
            if(copia[i]=='P'){
                if(i>=1)cadena[i-1]='-';
                if(i+1<tam)cadena[i+1]='-';
            }
        }
        int salida=0;
        if(iguales){
            salida+=(tam/3);
            salida+=(tam%3!=0)?1:0;
        }else{
            ///CONTAMOS LOS PUNTOS
            int contador;
            for(int i=0; i<tam; i++){
                if(cadena[i]=='.'){
                    contador=contar(i,'.');
                    salida+=(contador/3);
                    salida+=(contador%3!=0)?1:0;
                }
            }
        }
        cout << salida << endl;
    }
    return 0;
}

