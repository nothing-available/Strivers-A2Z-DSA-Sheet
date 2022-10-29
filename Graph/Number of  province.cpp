/*
https://takeuforward.org/data-structure/number-of-provinces/
*/

class Solution {
    private:
    // dfs traversal function
    void dfs(int node ,vector<int> adjLS[],int vis[]){
        vis[node] = 1;
        for(auto it : adjLS[node]){
            if(!vis[it]){
                dfs(it,adjLS,vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // change adjacency matrix to adjacency list
        vector<int> adjLS[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                //there is a node and u donot have sel nodes
                if(adj[i][j] == 1 and i != j){ 
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }
        int vis[V] ={0};//visited matrix
        int count = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++; // count no. of proviences
                dfs(i,adjLS,vis);
            }
        }
        return count;
    }
};

//Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 

//Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.
