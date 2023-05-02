/*
Approach: 
Sort the array in ascending order.
Print the (size of the array -1)th index.

Time Complexity: O(N*log(N))
Space Complexity: O(n) */
  
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
       sort(arr.begin(),arr.end());
       
       return arr[n-1];
    }
};


/* Optimal solution :

Approach: 

Create a max variable and initialize it with arr[0].
Use a for loop and compare it with other elements of the array
If any element is greater than the max value, update max value with the element’s value
Print the max variable.

Time Complexity: O(N)

Space Complexity: O(1) */

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max = arr[0];
        
        for(int i = 0; i < n; i++){
            
            if(arr[i] > max){
                
                max = arr[i];
            }
        }
        return max;
    }
};

// https://takeuforward.org/data-structure/find-the-largest-element-in-an-array/
