vector<int> v;
    int low=0;
    int high=n-1;
    int res=-1;
    while(low<= high)
    {
        int mid= low+ (high-low)/2;  // Finding mid
        if(x==arr[mid])
        {
            res=mid;
            high= mid-1;
        }
        else if(x<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low= mid+1;
        }
    }
    v.push_back(res); //Puting the first occurence in the vector
    
    // Finding the last Occurence
    low= 0;
    high= n-1;
    while(low<= high)
    {
        int mid= low+ (high-low)/2;
        if(x==arr[mid])
        {
            res=mid;
            low= mid+1;
        }
        else if(x<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low= mid+1;
        }
    }
    v.push_back(res);
    return v;

// by using STL

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(),nums.end(),target);

        auto high = upper_bound(nums.begin(), nums.end(), target);

        if(low == nums.end() || *low != target)   
            return {-1,-1};

        int first = low - nums.begin();

        int last = high - nums.begin() - 1;

        

        return {first, last};
    }
};
