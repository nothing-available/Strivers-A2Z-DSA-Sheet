// https://www.geeksforgeeks.org/search-almost-sorted-array/

// TC - O(logn)
// SC - O(1)

int binarySearch(int arr[], int l, int r, int x){
  
  while(l <= r){
   
    int mid = l + (r - l) / 2;
    
    if(arr[mid] == x)
      
      return mid;
    
    if(mid > l && arr[mid - 1] == x) // checking because segmentation error
      
      return (mid - 1);
    
    if(mid < r && arr[mid + 1] == x) // same reason
      
      return (mid + 1);
    
    if(arr[mid] > x){
      
      r = mid - 2;
    }
    else{
      
      l = mid + 2;
    }
    
    return -1;
  }
    
}
