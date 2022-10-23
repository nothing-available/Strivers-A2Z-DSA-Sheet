/*There are N stones, numbered 1, 2, . . , 2, N. For each i(1 <i< N), the height of Stone i is hi.
There is a frog who is initially on Stone 1. Не will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone i, jump to one of the following: Stone i + 1,i + + K. Here, a cost of hi i-hjl is incurred,
      where j is the stone to land on.
 Find the minimum possible total cost incurred before the frog reaches Stone N.
 */

/*Recursion
TC - O(k^N) - There are N stones and at (almost) every stone we have $K$ options.
SC - O(N) - Stack space

code
*/
int func(int n, vector<int>& heights, int k)
{
    if(n == 0)  return 0;
    int minimum = INT_MAX;
    for(int i=1; i<=k; i++)
    {
        if(n-i >= 0)
        {
            int jump = func(n-i, heights, k) + abs(heights[n] - heights[n-i]);
            minimum = min(minimum, jump);
        }       
    }
    return minimum; 
}

/* Memoization
TC - O(K*N) - N because we move to N and k because we check from 1 till k 
SC - O(N)+O(N) - recursion stack spce and dp array 
 */
int func(int n, vector<int>& heights, vector<int>& dp, int k)
{
    if(n == 0)  return 0;
    if(dp[n] != -1)     return dp[n];
    int minimum = INT_MAX;
    for(int i=1; i<=k; i++)
    {
        if(n-i >= 0)
        {
            int jump = func(n-i, heights, dp, k) + abs(heights[n] - heights[n-i]);
            minimum = min(minimum, jump);
        }       
    } 
   return dp[n] = minimum; 
}

/* Tabulation
TC - O(K*N) 
SC - O(N)
*/
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n, height, dp, k);
}

// detail sol - https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/
