class Solution {
   private:
      void findSubsets(int ind, vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans) {
         ans.push_back(ds);
         // Push the current combination 'ds' into the result 'ans' (all subsets).

         for (int i = ind; i < nums.size(); i++) {
            // Iterate through the elements of 'nums' starting from index 'ind'.

            if (i != ind && nums[i] == nums[i - 1])
               continue;
            // Skip duplicates to avoid duplicate subsets.

            ds.push_back(nums[i]);
            // Add the current element to the current combination 'ds'.

            findSubsets(i + 1, ds, nums, ans);
            // Recursive call to find subsets including the current element.

            ds.pop_back();
            // Backtrack: Remove the last added element to explore other subsets
            // without the current element.
         }
      }
   public:
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> ans; // 2D vector to store subsets.
         vector<int> ds; // Vector to store the current subset being processed.

         sort(nums.begin(), nums.end());
         // Sort the input 'nums' to handle duplicates efficiently.

         findSubsets(0, ds, nums, ans);
         // Call the recursive function to find all subsets.

         return ans; // Return the result containing all subsets.
      }
};


/*
Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
*/
