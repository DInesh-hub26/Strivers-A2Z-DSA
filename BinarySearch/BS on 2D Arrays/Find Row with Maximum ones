#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:   
  int Lower_Bound(vector<int>&arr,int n,int x){
         int low=0;
         int high=n-1;
         //For a row with no 1 we need to get cnt=0
         int ans=n;
         while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                 ans=mid;
                 high=mid-1;
            }else{
                low=mid+1;
            }
         }
         return ans;
  }
  int rowWithMax1s(vector < vector < int >> & mat) {
        int m=mat.size();
        int n=mat[0].size();
        //To return -1 for mat without having 1
        int Max_count=0;
        int ind=-1;
        for(int i=0;i<m;i++){
            int cnt=n-Lower_Bound(mat[i],n,1);
            if(cnt>Max_count){
                Max_count=cnt;
                ind=i;
            }
        }
        return ind;
  }
  /*
    Time Complexity->Brute->O(m*n)
                   ->Optimal->O(m*log n base 2)
    Space Complexity->O(1)
  */
};