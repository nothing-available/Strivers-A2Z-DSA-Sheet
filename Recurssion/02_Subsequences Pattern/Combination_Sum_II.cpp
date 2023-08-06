class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &currentCombination) {
        // Recursive function to find combinations of elements that sum up to the target.
        // Parameters:
        // - ind: The current index of the array 'arr'.
        // - target: The remaining target sum to achieve.
        // - arr: The input vector containing candidate elements.
        // - ans: A reference to the 2D vector to store the result combinations.
        // - currentCombination: A reference to the vector to store the current combination being processed.

        if (target == 0) {
            // Base case: If the target sum is zero, it means the current combination sums up to the target.
            // Add the current combination 'currentCombination' to the result 'ans'.

            ans.push_back(currentCombination);
            return; // Return to the previous recursion level.
        }

        for (int i = ind; i < arr.size(); i++) {
            // Loop through the elements starting from the current index 'ind'.

            if (i > ind && arr[i] == arr[i - 1]) {
                // Skip duplicates to avoid duplicate combinations.
                continue;
            }

            if (arr[i] > target) {
                // If the current element is greater than the remaining target, break the loop.
                // As the array is sorted, there's no possibility of finding the combination from this point.
                break;
            }

            currentCombination.push_back(arr[i]);
            // Add the current element to the 'currentCombination'.

            // Recursive call to find combinations with the current element included.
            // Reduce the target by the current element value, and move to the next index (i + 1).
            findCombination(i + 1, target - arr[i], arr, ans, currentCombination);

            currentCombination.pop_back();
            // Backtrack: Remove the last added element to explore other combinations
            // without the current element.
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Function to find unique combinations that sum up to the target.
        // It handles duplicates and uses a sorted array for better efficiency.

        sort(candidates.begin(), candidates.end());
        // Sort the candidates array to handle duplicates efficiently.

        vector<vector<int>> ans; // 2D vector to store the result combinations.
        vector<int> currentCombination; // Vector to store the current combination being processed.

        // Call the recursive function to find combinations that sum up to the target.
        findCombination(0, target, candidates, ans, currentCombination);

        return ans; // Return the result containing all valid combinations.
    }
};





/*
Time Complexity:O(2^n*k)

Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

Space Complexity:O(k*x)

Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
*/
