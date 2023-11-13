#include <iostream>
using namespace std;

int main()
{
    int v;
    cout << "enter number of vertices in your graph: ";
    cin >> v;
    int ad_mat[v][v];
    int colors[v];
    for (int i = 0; i < v; i++)
    {
        colors[i] = -1;
    }
    cout<<"enter adjacency matrix: "<<endl;
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v ; j++){
            cout<<"enter element "<<i<<","<<j<<" :";
            cin>> ad_mat[i][j];
        }
    }

    for(int i=0; i<v ; i++){
        for(int j = 0; j<v ; j++){
            if(j==0){
                colors[i] = 1;
            }
            if(ad_mat[i][j]==1){//j = 1 implies edge exists between i and j
                if(colors[j]==colors[i]){
                    colors[i]=colors[i]+1;
                }
            }
        }
    }

    for(int i =0; i<v ; i++){
        cout<<"color of vertex "<<i+1<<" is: "<<colors[i]<<endl;
    }

    return 0;
}