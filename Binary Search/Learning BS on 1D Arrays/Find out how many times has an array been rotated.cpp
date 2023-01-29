//Expected Time Complexity: O(logN)
//Expected Auxiliary Space: O(1)

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    
	    if(n == 1){
	        return 0;
	    }
	    
	    int start = 0;
	    int end = n-1;
	    
	    while(start <= end){
	        
	        if(arr[start] <= arr[end]){//array is already sorted
	            return start;
	        }
	        
	        int mid = start + (end - start) / 2;
	        
	        int next = (mid + 1) % n;
	        int prev = (mid + n - 1) % n;
	        
	        if((arr[mid] <= arr[next]) && arr[mid] <= arr[prev]){
	            return mid;
	        }
	        
	        else if(arr[start] <= arr[mid]){
	            start = mid + 1;
	        }
	        
	        else{
	            end = end - 1;
	        }
	    }
	    return 0;
	}

};
