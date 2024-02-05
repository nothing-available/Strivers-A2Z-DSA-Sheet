// recursive soln.

class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int sum){
        
        int n = arr.size();
        
        return subsetSum(arr, n, sum);
    }
    
    bool subsetSum(vector<int> arr, int n, int sum){
        
        //base condition
        
        if(sum == 0) return true;
        
        if(n == 0) return false;
        
        if(arr[n-1] <= sum){
            
            return subsetSum(arr, n-1, sum - arr[n-1]) or subsetSum(arr, n-1, sum);
        }
        
        else{
            
            return subsetSum(arr, n-1, sum);
        }
        
        
    }
    
    
};

//memoization soln.

class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int sum){
        
        int n = arr.size();
        
        vector<vector<int>>dp (n+1, vector<int>(sum+1, -1));
        
        return subsetSum(arr, n, sum, dp);
    }
    
    bool subsetSum(vector<int> arr, int n, int sum, vector<vector<int>>& dp){
        
        //base condition
        
        if(sum == 0) return true;
        
        if(n == 0) return false;
        
        if(dp[n-1][sum] != -1) return dp[n-1][sum];
        
        if(arr[n-1] <= sum){
            
            return dp[n-1][sum] = subsetSum(arr, n-1, sum - arr[n-1], dp) or subsetSum(arr, n-1, sum, dp);
        }
        
        else{
            
            return dp[n-1][sum] = subsetSum(arr, n-1, sum, dp);
        }
            
    }
    
};

//tabulation soln.


