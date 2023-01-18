// Expected Time Complexity : O(klogN)
// Expected Auxilliary Space : O(N)

class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> ans;

        for(auto it : nums){
            mpp[it]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minh;

        for(auto it1 : mpp){
            minh.push(make_pair(it1.second, it1.first));

            if(minh.size() > k){
                minh.pop();
            }
        }

        while(minh.size() != 0){

            ans.push_back(minh.top().second);
            minh.pop();
        }

        return ans;
    }
};
