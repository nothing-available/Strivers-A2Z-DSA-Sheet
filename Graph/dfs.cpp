/*
https://takeuforward.org/data-structure/depth-first-search-dfs/
*/

class Solution {
    private:
    void dfs(int node,vector<int> adj[],int vis[],vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        // for traverse in graph
        for(auto it : adj[node]){
            if(!vis[it]){ //check
                dfs(it,adj,vis,ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0}; //
        int start = 0;
        
        vector<int> ans;
        dfs(start,adj,vis,ans);
        return ans;
    }
};

// Time complexity: O(V+E) (For traversing the adjacency list)
// Space complexity: O(V+E) + O(V) + O(V) [For adj. list, visited array and recursion stack]
