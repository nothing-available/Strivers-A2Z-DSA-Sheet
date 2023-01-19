Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)


class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here

        priority_queue<long long, vector<long long>, greater<long long>> minh;
        
        long long ans = 0;
        
        if(n == 1){
            return 0;
        }
        
        for(int i = 0; i < n; i++){
            
            minh.push(arr[i]);
        }
        
        while(minh.size() > 1){
            
            long long a = minh.top();
            
            minh.pop();
            
            long long b = minh.top();
            
            minh.pop();
            
            ans = ans + a + b;
            
            minh.push(a + b);
        }
        
        return ans;
    }
};
