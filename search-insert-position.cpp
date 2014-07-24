class Solution {
public:

    int binary_search(int A[], int low, int high, int target) {
        
        /*if ( low > high)
           return -1;*/
        
        int mid = (low + high)/2;
        
        if ( A[mid] == target)
           return mid;
           
        if ( target < A[low] && low == 0)
           return 0;
       
        if ( target < A[low])
            return low-1;
        
        if ( target > A[high])
            return high+1;
            
        if ( low+1 == high)
            return low+1;
            
        else if (A[mid] > target )    
           binary_search(A, low, mid, target);
        else if ( A[mid] < target)
           binary_search(A, mid, high, target) ;    
        
    }

    int searchInsert(int A[], int n, int target) {
        
        if ( n == 0)
            return -1;
       
      return binary_search(A, 0, n-1, target);
        
    }
};
