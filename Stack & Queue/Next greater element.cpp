/*
https://takeuforward.org/data-structure/next-greater-element-using-stack/
*/
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans;
        stack<long long> st;
        for(int i=arr.size()-1; i>=0; i--){
            if(st.empty()){
                ans.push_back(-1);
                st.push(arr[i]);
            }
            else{
                if(st.top()>arr[i]){
                    ans.push_back(st.top());
                    st.push(arr[i]);
                }
                else if(st.top()<=arr[i]){
                    while(!st.empty() && st.top()<=arr[i]){
                        st.pop();
                    }
                    if(!st.empty()) ans.push_back(st.top());
                    else ans.push_back(-1);
                    st.push(arr[i]);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }   
};

// tc - o(n)
// sc - o(n)
