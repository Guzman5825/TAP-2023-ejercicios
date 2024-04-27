#include <bits/stdc++.h>
using namespace std;

//typedef long long intl //despues lo uso y reemplazo

struct cmp {        ///esto es para que el conjunto compare de forma decrececiente
    bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
        // Comparar primero por el primer elemento
        if (lhs.first != rhs.first) {
            return lhs.first > rhs.first;
        }
        // Si los primeros elementos son iguales, comparar por el segundo elemento
        return lhs.second > rhs.second;
    }
};

int main() {
    set<pair<int, int>,cmp> oficinas;      /// el primer dato es la cantidad de alfajores que hubo al inicio, y el segundo dato es las posicion del viaje
    vector<int> empleados(100000);          ///los que comen los empleados que comen alfajores

    int N,M,A;
    cin>>N;
    cin>>M;

    for (int i=0;i<N;i++){
        cin>>A;
        oficinas.insert( {A,i} );  ///{alfojres inicialmente, el viaje para no perder la posicion de impresion en el cout}
    }

    for(int i=0;i<M;i++)
        cin>>empleados[i];

    for(int i=0;i<M;i++){
        pair<int,int> ofiAct = *oficinas.begin(); // Obtener el primer elemento
        //mientras el sea menor al resto
        while(ofiAct.first>=empleados[i]){  ///
            oficinas.erase(oficinas.begin()); // Borrar el primer elemento
            ofiAct.first=ofiAct.first%empleados[i];
            oficinas.insert({ofiAct.first,ofiAct.second});
            ofiAct = *oficinas.begin(); // Obtener el primer elemento
        }

    }

    set<pair<int, int>>ofiOrd;
    for (auto o : oficinas)     ///lo que hace es armar otro conjunto ordenado a partir del anterior conjunto
        ofiOrd.insert({o.second,o.first});

    for (auto o : ofiOrd)       ///imprimo el resultado
        cout<<o.second<<" ";

    return 0;
}
