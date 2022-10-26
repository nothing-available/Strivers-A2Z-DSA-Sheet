class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        
        vector<vector<int>> ans(V,{0});
        for(int i=0;i<V;i++){
            ans[i][0] = i;
            for(int V : adj[i]){
                ans[i].push_back(V);
            }
        }
        return ans;
    }
};
