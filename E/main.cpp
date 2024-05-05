#include <bits/stdc++.h>
using namespace std;

#define MAXIMO(a,b) ( (a)>(b)?(a):(b) )

typedef long long intl;

void solucion_Si_S_mayor_R(intl A,intl S,intl L,intl R)
{//intl sumPar[11];

    vector<intl> sumPar(200001); //sumatorias parciales
    sumPar[0]=0; //caso base

    int dMax;
    if(S>R)
        dMax=MAXIMO(A-L,R-A);
    else
        dMax=S-A;
    if(dMax==0){    //caso borde
        if(S==A)
            cout<<1;
        else
            cout<<0;
        return ;
    }

    int difIzq=A-L;
    int cantSoluciones=0;

    for(intl D=1;D<=dMax;D++){
        int incremento=((int)(difIzq/D))*(-1) ; // se busca el menor ingremento posible
        int i=1;
        intl numAct=A+D*incremento;
        while(numAct<=R){   // esto es para rellenar nuestro vector
            sumPar[i]=sumPar[i-1]+numAct;
            i++;
            incremento++;
            numAct=A+D*incremento;
        }
        int posA=(difIzq/D)+1;  //posicion en donde se encontraria A
        int posL=0;  //posicion en donde enpesaria a contar L
        int posR=posA;   //posicion en donde enpezaria a contar R
        int cantElem= ((A-L)/D)+((R-A)/D)+1 ;
        while(posL<posA && posR<=cantElem){
            if( sumPar[posR]-sumPar[posL]==S){
                cantSoluciones++;
                posL++;
            }else{
                if(sumPar[posR]-sumPar[posL]<S)    //aumento algun valor que me aproxime a S
                    posR++;
                else
                    posL++;
            }



        }
    }

    cout << cantSoluciones << endl;
    return ;
}


int main()
{
    intl A,S,L,R;
    cin>>A>>S>>L>>R;

    if(S>=A && A>=L && A<=R)
        solucion_Si_S_mayor_R(A,S,L,R);
    else
        cout<<0;
    return 0;
}
