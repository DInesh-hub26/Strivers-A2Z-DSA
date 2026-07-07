#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    //In question given m & n both are odd
    //Use standard upperbound fn or return ind of first element greater than mid instead of count
    int Find_Upper_Bound(vector<int>&mat,int mid){
        int low=0;
        int high=mat.size()-1;
        int count=0;
        while(low<=high){
            int midd=low+(high-low)/2;
            if(mat[midd]<=mid){
                count+=(midd-low)+1;
                low=midd+1;
            }else{
                high=midd-1;
            }
        }
        return count;
    }
    //Finds How many elements are <= mid in every row
    int Black_Box(vector<vector<int>>&matrix,int m,int n,int mid){
        int sum=0;
        for(int i=0;i<m;i++){
           sum+=Find_Upper_Bound(matrix[i],mid);
        }
        return sum;
    }
    int findMedian(vector<vector<int>>&matrix) {
      int m=matrix.size();
      int n=matrix[0].size();
      int low=INT_MAX;
      int high=INT_MIN;
      for(int i=0;i<m;i++){
        if(matrix[i][0]<low){
            low=matrix[i][0];
        }
        if(matrix[i][n-1]>high){
            high=matrix[i][n-1];
        }
      }
      while(low<=high){
        int mid=low+(high-low)/2;
        int LessThanMid=Black_Box(matrix,m,n,mid);
        if(LessThanMid<=(m*n)/2){
            low=mid+1;
        }else{
            high=mid-1;
        }
      }
      return low;
    }
    /* 
      Time Complexity->Brute->O(m*n)+O(m*n (log(m*n)))
                     ->Optimal->O(log(high-low)*m*log n)
      Space Complexity->Brute->O(m*n)
                      ->Optimal->O(1)
    */
};