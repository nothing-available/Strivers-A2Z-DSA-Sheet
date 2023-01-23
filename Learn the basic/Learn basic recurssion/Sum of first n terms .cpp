// Expected Time Complexity:O(1)
// Expected Auxillary Space:O(1)

class Solution {
  public:
    long long sumOfSeries(long long N) {
        // code here
        long long sum = 0;
        
        sum = (N*(N+1)/2); // cal sum of the no.
        
        return sum * sum;
    }
};
