#include <bits/stdc++.h>

#define MAXIMO(a,b) ((a)>(b)? (a):(b))
using namespace std;

int main()
{
    int N,num;
    vector<vector<int> > A(1001, vector<int> (1001, 0));
    vector<pair<int, int>> pos(1000001); //la primera posicion guarda su posicion horizontal, y la segudna su posicion en vertical
    //vector<int> dpH(1000),dpV(1000); //horinzontal y vertical, first
    int dpH[1000][2],dpV[1000][2];
    cin>>N;

    for(int i=0;i<N;i++){
        dpH[i][0]=0;
        dpH[i][1]=0;
        dpV[i][0]=0;
        dpV[i][1]=0;
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin>>num;
            A[i][j]=num;
            pos[num].first=i;
            pos[num].second=j;
        }

    for(int i=1;i<=N*N;i++){
        //cout<<"num:"<<i<<" x:"<<pos[i].first<<" y:"<<pos[i].second<<endl;
        dpH[pos[i].first][1]= MAXIMO( dpH[pos[i].first][0] ,dpV[pos[i].second][0]+1);
        dpV[pos[i].second][1]= MAXIMO( dpV[pos[i].second][0], dpH[pos[i].first][0]+1);


        dpH[pos[i].first][0]=dpH[pos[i].first][1];
        dpV[pos[i].second][0]=dpV[pos[i].second][1];
        //cout<<"i:"<<i<<"-x:"<<pos[i].first<<"-y:"<<pos[i].second<<endl;
        //cout<<"modificado X:"<<dpH[pos[i].first]<<"-Y:"<<dpV[pos[i].second]<<endl;
    }

    int puntajeMaximo=0;

    for(int i=0;i<N;i++){
        if(dpH[i][0]>puntajeMaximo)
            puntajeMaximo=dpH[i][0];
        if(dpV[i][0]>puntajeMaximo)
            puntajeMaximo=dpV[i][0];

    }

    cout<<puntajeMaximo;


    return 0;
}
