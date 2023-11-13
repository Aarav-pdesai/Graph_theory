#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to find and print the Eulerian path using Hierholzer's algorithm
void findpath(vector<vector<int>>& ad_mat, int size_mat) {
    stack<int> path;
    vector<int> circuit;

    int start_vertex = 0;
    for (int i = 0; i < size_mat; ++i) {
        int degree = 0;
        for (int j = 0; j < size_mat; ++j) {
            degree += ad_mat[i][j];
        }
        if (degree % 2 != 0) {
            start_vertex = i;
            break;
        }
    }

    path.push(start_vertex);

    while (!path.empty()) {
        int current_vertex = path.top();
        int next_vertex;

        for (next_vertex = 0; next_vertex < size_mat; ++next_vertex) {
            if (ad_mat[current_vertex][next_vertex] == 1) {
                break;
            }
        }

        if (next_vertex == size_mat) {
            // If no more edges, add to circuit
            circuit.push_back(current_vertex);
            path.pop();
        } else {
            // Remove the edge
            ad_mat[current_vertex][next_vertex] = 0;
            ad_mat[next_vertex][current_vertex] = 0;

            // Move to the next vertex
            path.push(next_vertex);
        }
    }

    // Print the Eulerian path (in reverse order)
    for (int i = circuit.size() - 1; i >= 0; --i) {
        cout << circuit[i] << " ";
    }

    cout << endl;
}



 
int main(){
    int v,n,sum=0,count=0, flag=0;
    cout<<"this program will verfiy if there an eulerian path/cycle exists in the input graph."<<endl;
    cout<<"enter the number of vertices in your graph.";
    cin>>v;
    vector <vector<int>> ad_mat(v, vector<int> (v));//2-d array, with v arrays of size v

    for(int i = 0; i<ad_mat.size(); i++){
        for(int j =0 ; j<ad_mat[i].size(); j++){
            cout<<"enter element: ";
            cin>>n;
            ad_mat[i][j] = n;
        }
    }

    for (vector<int> vect1D : ad_mat){//printing the entered matrix
        for (int x : vect1D){
            cout<< x << " ";
        }
        cout << endl;
    }

    int size_mat = ad_mat.size();

    for(int i = 0; i<ad_mat.size(); i++){
        for(int j =0 ; j<ad_mat[i].size(); j++){
           sum = sum + ad_mat[i][j];
        }
        if (sum%2 != 0){
            count++;
            if (count>2){//if count is greater than 2 or any one row is null, then graph doesn't have eulerian path or cycle.
                cout<<"eulerian path or cycle do not exist."<<endl;
                break;
            }
        }
    
        else if(sum == 0){
            cout<<"eulerian path or cycle do not exist."<<endl;
            break;
        }
        sum = 0;
    }

    if(count == 2){
        cout<<"eulerian path exists, but eulerian cycle does not exist."<<endl;
        findpath(ad_mat,size_mat);
    }
    else if(count == 0){
        cout<<"eulerian cycle exists, but eulerian path does not exist."<<endl;
        findpath(ad_mat,size_mat);
    }
    else{
        cout<<"neither eulerian cycle nor eulerian path exists.";
            }


    return 0;
}
