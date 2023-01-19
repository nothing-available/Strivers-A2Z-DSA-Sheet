//Expected Time Complexity: O(N. log(N))
//Expected Auxiliary Space: O(N)


class Solution{
    public:
    
    typedef long long ll;
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
         long long sum=0;
    priority_queue<int>maxh;
    for(int i=0;i<N;i++){
        maxh.push(A[i]);
    if(maxh.size()>K1){
        maxh.pop();
    }
    }
      priority_queue<int>maxh1;
     for(int i=0;i<N;i++){
        maxh1.push(A[i]);
    if(maxh1.size()>K2){
        maxh1.pop();
    }
    }
    int n1=maxh.top();
    int n2=maxh1.top();
    for(int i=0;i<N;i++){
        if(A[i]>n1 && A[i]<n2){
            sum+=A[i];
        }
    }
    return sum;
    }

    
};
