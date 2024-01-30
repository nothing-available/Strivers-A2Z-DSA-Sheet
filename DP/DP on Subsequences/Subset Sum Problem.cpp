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

