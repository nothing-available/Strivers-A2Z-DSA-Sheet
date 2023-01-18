//Expected Time Complexity: O(NLogN).
//Expected Auxiliary Space: O(N). 



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        unordered_map<int,int> mp;
       
       for(int i = 0; i < n; i++)
       {
           mp[arr[i]]++;   
       }
       
       priority_queue<pair<int,int>> pq;
       
       for(auto it: mp)
       {
           pq.push(make_pair(it.second , -1*it.first)); 
           //using -1 because if there is same frequency then it will check it.second
       }
       
       vector<int> ans;
       
       while(!pq.empty())
       {
           for(int i = 0; i < pq.top().first; i++)
               ans.push_back(-1*pq.top().second);
           
           pq.pop();
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends
