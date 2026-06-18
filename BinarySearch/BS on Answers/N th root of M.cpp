class Solution {
public:
  int FindPow(int mid,int N,int M){
    long long ans=1;
    //Returns 0 if ans >M
    //1 if ans ==M and 2 if <M
    //If we use power function there can be overflow
       for(int i=1;i<=N;i++){
           ans=ans*mid;
           if(ans>M){
            return 0;
           }
       }
     if(ans==M){
        return 1;
     }else{
        return 2;
     }
  }
  int NthRoot(int N, int M) {
       int low=0,high=M;
       while(low<=high){
        int mid=low+(high-low)/2;
        int val=FindPow(mid,N,M);
        if(val==1){
            return mid;
        }
        else if(val==0){
            high=mid-1;
        }else{
            low=mid+1;
        }
       }
       return -1;
    }
    /*
       Time Complexity->Brute->O(M*N)
                      ->Better(for above code)->O(N*log M base 2)
                      ->Optimal->O(log M base 2 *log N base 2)
                      (by binary exponentiation)
       Space Complexity->O(1)
    */
};
