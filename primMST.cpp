// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. 

#include <bits/stdc++.h>
using namespace std;

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[], int ver)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < ver; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int** graph, int vert)
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < vert; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int** graph, int n)
{
	// Array to store constructed MST
	int parent[n];

	// Key values used to pick minimum weight edge in cut
	int key[n];

	// To represent set of vertices included in MST
	bool mstSet[n];

	// Initialize all keys as INFINITE
	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first
	// vertex.
	key[0] = 0;

	// First node is always root of MST
	parent[0] = -1;

	// The MST will have n vertices
	for (int count = 0; count < n - 1; count++) {
		
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet, n);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < n; v++)

			// graph[u][v] is non zero only for adjacent
			// vertices of m mstSet[v] is false for vertices
			// not yet included in MST Update the key only
			// if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// Print the constructed MST
	printMST(parent, graph, n);
}

int main()
{
	//adjacency matrix graph[i][j] is taken as input,
	//where each input element is weight between
	//vertices i and j.
    int n;
    cout<<"enter the number of vertices in your graph: ";
    cin>>n;

    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"enter weight of edge between "<<i<<" and "<<j<<": ";
            cin>> graph[i][j];
        }
    }
		
	primMST(graph,n);
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;

	return 0;
}


