#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //Find Row number of maximum element in given column
    int Find_Row_of_max_in_col(vector<vector<int>>&mat,int m,int n,int mid){
          int maxi=INT_MIN;
          int Row=-1;
          for(int i=0;i<m;i++){
            if(mat[i][mid]>maxi){
                maxi=mat[i][mid];
                Row=i;
            }
          }
          return Row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=Find_Row_of_max_in_col(mat,m,n,mid);
            int left=(mid-1>=0?mat[row][mid-1]:-1);
            int right=(mid+1<n?mat[row][mid+1]:-1);
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }else if(mat[row][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {};
    }
    /*
      Time Complexity->Brute->O(4*m*n)
                     ->Better->O(m*n)
                     ->Optimal->O(log n base 2 * m)
      Space Complexity->O(1)
    */
};