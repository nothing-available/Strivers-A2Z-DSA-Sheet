/*

https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/

*/

vector<int> bfsOfGraph(int v, vecto<int> ad[])
{
  int vis[V] = {0}; //make vis array & mark evry thing 0
  vis[0] = 1; // mark initial as visited
  queue<int> q; 
  queue.push(0); //pushing the starting node
  vector<int> bfs;
  
  while(!q.empty())
  {
    int node = q.front(); // jo bhi node likle ga front karo
    q.pop();
    bfs.push(node); //store that node
    
    for(auto it : adj[node]) //for checking vis or not
    {
      if(!vis[it])
      {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
  return bfs;
}

// Time complexity: O(N + E) [For traversing the adjacency list]
// Space complexity: O(N + E) + O(N) + O(N) [For adj. list, visited array and queue]
  
