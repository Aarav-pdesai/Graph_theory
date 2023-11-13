#include <iostream>
using namespace std;

int main(){
    int v,i,j,flag=0;
    cout<<"enter the number of vertices in the graph: ";
    cin>>v;
    int path[v][v];
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            cout<<"enter element: ";
            cin>>path[i][j];
        }
    }

    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(path[i][j]==0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }

    if(flag==0){
        cout<<"the graph is strongly connected.";
        return 0;
    }

    //checking if unilaterally connected
    bool uppertri = true;
 
    // Traverse the path matrix
    for (int i = 0; i < v; i++) {
 
        for (int j = 0; j < v; j++) {
 
            // If uppertriangle elements
            // are 0 then break out of the
            // loop and check the elements
            // of lowertriangle matrix
            if (i > j && path[i][j] == 0) {
                uppertri = false;
                break;
            }
        }
 
        // Break out of the loop if false
        if (!uppertri) {
            break;
        }
    }
 
    // If true then print unilaterally
    // connected and return
    if (uppertri) {
        cout << "Unilaterally Connected";
        return 0;
    }
 
    // Check lowertraingle elements
    bool lowertri = true;
 
    // Traverse the path matrix
    for (int i = 0; i < v; i++) {
 
        for (int j = 0; j < v; j++) {
 
            // If lowertraingle elements
            // are 0 then break cause
            // 1's are expected
            if (i < j && path[i][j] == 0) {
                lowertri = false;
                break;
            }
        }
 
        // Break out of the loop if false
        if (!lowertri) {
            break;
        }
    }
 
    // If true then print unilaterally
    // connected and return
    if (lowertri) {
        cout << "Unilaterally Connected";
        return 0;
    }
 
    // If elements are in random order
    // unsynchronized then print weakly
    // connected and return
    else {
        cout << "Weakly Connected";
    }
 
    return 0;

}