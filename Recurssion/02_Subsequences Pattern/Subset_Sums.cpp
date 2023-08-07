
class Solution
{
public:
    
    void findSubsetSums(int ind, int sum, vector<int> &arr, int N, vector<int> &subsetSums){
        
        if(ind == N){
            
            subsetSums.push_back(sum);
            
            return;
        }
        
        // pick the element
        
        findSubsetSums(ind + 1, sum + arr[ind], arr, N, subsetSums);
        
        //notpick
        
        findSubsetSums(ind + 1, sum, arr, N, subsetSums);
    }
    
    vector<int> subsetSums(vector<int> arr, int N){
        
        vector<int> subsetSums;
        
        findSubsetSums(0, 0, arr, N, subsetSums);
        
        sort(subsetSums.begin(), subsetSums.end());
        
        return subsetSums;
        
    }
};

/*
Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it.
So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

*/

