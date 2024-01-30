// recursive soln.


class Solution
{
    public:

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // base conditon
       
       if(n == 0 || W == 0) return 0;
       
       if(wt[n-1] > W) return knapSack(W, wt, val, n-1);
       
       
       else {
           
           return max( val[n-1] + knapSack(W - wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
       }
    }
};

// memoization soln.

// ! Complexity Analysis

// Time Complexity: O(N*W)

// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)

// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).

class Solution
{
    public:
    
    int dp[1001][1001];  //STATICALLY MAKE THE DP MATRIX
    
    int solve(int W, int wt[], int val[], int n) 
    { 
       // base conditon
       
       if(n == 0 || W == 0) return 0;
       
       if(dp[n][W] != -1) {
           
           return dp[n][W];
       }
       
       if(wt[n-1] > W) {
           
           return dp[n][W] =  solve(W, wt, val, n-1);
       }
       
       
       else {
           
           return dp[n][W] =  max( val[n-1] + solve(W - wt[n-1], wt, val, n-1), solve(W, wt, val, n-1));
       }
    }
    
    int knapSack(int W, int wt[], int val[], int n){
        
        memset(dp, -1, sizeof(dp));
        
        return solve(W, wt, val, n);
    }
};


// top down approach

// ! Complexity Analysis
// Time Complexity: O(N*W)

// Reason: There are two nested loops

// Space Complexity: O(N*W)

// Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated.

class Solution
{
    public:
    
    int knapSack(int W, int wt[], int val[], int n) 
    
    { 
        int dp[n+1][W+1];
        
        
        for(int i = 0; i < n+1; i++){
            
            for(int j = 0; j < W+1; j++){
                
                if(i == 0 || j == 0){
                    
                    dp[i][j] = 0;
                }
                
                else if(wt[i - 1] <= j){
                    
                    dp[i][j] = max(val[i - 1] + dp[i-1][j - wt[i -1]], dp[i -1][j]);
                }
                
                else{
                    
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][W];
    }
};

