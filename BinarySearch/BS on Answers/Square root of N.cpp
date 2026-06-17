class Solution {
public:
    int floorSqrt(int n)  {
      int low=0,high=n;
      int ans=0;
      //Use sqrt function in large problems
      //int ans=sqrt(n)
      while(low<=high){
          int mid=low+(high-low)/2;
          if(mid*mid <=n){
            ans=mid;
            //removes left part
            low=mid+1;
          }else{
            //removes right part
            high=mid-1;
          }
      }
      //high will always points answer
      //so return high is also correct
      return ans;
    }
    /*
       Time Complexity->Brute->O(n)
                      ->Optimal->O(log n base 2)
       Space Complexity->O(1)
    */
};
