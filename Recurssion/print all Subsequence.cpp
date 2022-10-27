class Solution {
public:
    // it is use to store answer
    vector<vector<int>> ans;
    
    // solve function for generating answer
    void solve(int i, vector<int>&arr, vector<int>&temp)
    {
        if(i == arr.size()) // if index reaches the size of the array 
        {
            //if we find out a possibility, push it into the answer array
            ans.push_back(temp);
            return;
        }
        
        // taking ith element
        temp.push_back(arr[i]);
        
        // call for the next index
        solve(i + 1, arr, temp);
        
        // not taking ith ele,so first pop that already pushed ele, and then call for next index and generating the next possibility
        temp.pop_back();
        
        // calling for next index
        solve(i + 1, arr, temp);
        
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        ans.clear(); // clear global array
        
        vector<int> temp; // temporary array for generating answer
        solve(0, arr, temp); // generating all possibility
        
        return ans;
    }
};


//Time complexity: (2^n * n) - 2^n because we have 2 choices on every position of an n length array because we are printing a n length array

//Space complexity: O(n) - O(n) because we can have auxiliary stack up to n levels deep (For ex: when we choose all elements of an array)
