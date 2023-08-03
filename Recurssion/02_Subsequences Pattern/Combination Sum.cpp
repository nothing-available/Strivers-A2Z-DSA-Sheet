class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &stored) {
        // Recursive function to find combinations of elements that sum up to the target.
        // Parameters:
        // - ind: The current index of the array 'arr'.
        // - target: The remaining target sum to achieve.
        // - arr: The input vector containing candidate elements.
        // - ans: A reference to the 2D vector to store the result combinations.
        // - stored: A reference to the vector to store the current combination being processed.

        if (ind == arr.size()) {
            // Base case: If the current index 'ind' is equal to the size of the array,
            // we have reached the end of the array. Check if the target sum is achieved.

            if (target == 0) {
                // If the target sum is zero, it means the current combination sums up to the target.
                // Add the current combination 'stored' to the result 'ans'.

                ans.push_back(stored);
            }
            return; // Return to the previous recursion level.
        }

        // Pick the element from the candidates array.

        if (arr[ind] <= target) {
            // If the current element 'arr[ind]' is less than or equal to the remaining target,
            // we can include this element in the current combination.

            stored.push_back(arr[ind]); // Add the current element to the 'stored' combination.

            // Recursive call to find the combinations with the current element included.
            // Reduce the target by the current element value, and move to the next index (ind).
            findCombination(ind, target - arr[ind], arr, ans, stored);

            stored.pop_back();
            // Backtrack: Remove the last added element to explore other combinations
            // without the current element.
        }

        // Recursive call to find combinations without including the current element.
        // Move to the next index (ind + 1) to explore the next element.
        findCombination(ind + 1, target, arr, ans, stored);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // 2D vector to store the result combinations.
        vector<int> stored; // Vector to store the current combination being processed.

        // Call the recursive function to find combinations that sum up to the target.
        findCombination(0, target, candidates, ans, stored);

        return ans; // Return the result containing all valid combinations.
    }
};




/*
Time Complexity: O(2^t * k) where t is the target, k is the average length

Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

Why not (2^n) but (2^t) (where n is the size of an array)?

Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

Space Complexity: O(k*x), k is the average length and x is the no. of combinations
*/
