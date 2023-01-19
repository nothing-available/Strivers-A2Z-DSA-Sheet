class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>> maxh;

        vector<vector<int>> ans;

        for(int i = 0;i < points.size(); i++){

            int x = points[i][0];

            int y = points[i][1];

            int dis = (x * x + y * y);

            maxh.push({dis,i});

            if(maxh.size() > k){

                maxh.pop();
            }

        }

        while(maxh.size() != 0){

            vector arr = points[maxh.top().second];

            ans.push_back(arr);

            maxh.pop();
        }

        return ans;

    }
};
