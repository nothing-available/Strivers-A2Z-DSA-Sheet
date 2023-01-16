

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> minh;
        
        for(int i =0;i<n;i++){
            minh.push(arr[i]);
            
            if(minh.size() > k){
                minh.pop();
            }
        }
        while(minh.size() !=  0){
            int num = minh.top();
            ans.push_back(num);
            minh.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
