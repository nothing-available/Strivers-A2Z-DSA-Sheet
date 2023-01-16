class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>> maxh;
        int n = arr.size();

        for(int i = 0 ; i < n; i++){

            maxh.push({abs(arr[i] - x), arr[i]});

            if(maxh.size() > k){
                maxh.pop();
            }
        }

        vector<int> ans;
        while(maxh.size() != 0){

            ans.push_back(maxh.top().second);
            maxh.pop();
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};






// gfg
//Expected Time Complexity: O(logN + K)
//Expected Auxiliary Space: O(1)

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int> ans;
        priority_queue<pair<int,int>> maxh;
        
        for(int i=0; i < n; i++){
            
            if((arr[i] - x) != 0){
                maxh.push({-1 * abs(arr[i]-x), arr[i]});
            }
        }
        
        for(int i=0;i<k;i++){
            
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        
        return ans;
    }
};

