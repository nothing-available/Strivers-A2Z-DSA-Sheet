// Tc - O(2N)
// Sc - 
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    
	    int max = arr[0];
	    
	    int sec_max = -1; 
	    
	    // first pass for finding max
	    for(int i = 0; i< n ;i++){
	        
	        if(arr[i] > max){
	            
	            max = arr[i];
	        }
	    }
	    
	    // sec pass for finding second max
	    for(int i = 0; i < n; i++){
	        
	        if(arr[i] > sec_max && arr[i] != max){
	            
	            sec_max = arr[i];
	        }
	    }
	    
	    return sec_max;
	}
};


// optimal sol
// Time Complexity: O(N), Single-pass solution

// Space Complexity: O(1)

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    
	    int largest = arr[0];
	    int sec_largest = -1;
	    
	    for(int i = 0; i< n; i++){
	        
	        if(arr[i] > largest){
	            
	            sec_largest = largest;
	            
	            largest = arr[i];
	        }
	        
	        else if(arr[i] < largest && arr[i] > sec_largest){
	            
	            sec_largest = arr[i];
	        }
	    }
	    
	    return sec_largest;
	}
};
