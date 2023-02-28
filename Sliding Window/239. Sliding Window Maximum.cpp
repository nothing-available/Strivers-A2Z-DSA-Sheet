// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(k)


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans; // to store the maximum element of each window
        list<int> ls; // to store the elements of the current window

        int i = 0, j = 0; // i is the start of the window, j is the end

        while(j < nums.size()){ // iterate over the array

            while(ls.size() > 0 and ls.back() < nums[j]) // remove elements smaller than the new element
                ls.pop_back();
            
            ls.push_back(nums[j]); // add the new element to the list

            if(j - i + 1 < k) j++; // if the window is not yet of size k, move j to the right

            else if(j - i + 1 == k){ // if the window is of size k

                ans.push_back(ls.front()); // add the maximum element to the result

                if(nums[i] == ls.front()) ls.pop_front(); // remove the first element if it is the maximum

                i++; // move i to the right
                j++; // move j to the right
            }

        }

        return ans; // return the result
    }    
};


