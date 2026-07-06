#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        //Hypothetically assuming 2D as 1D array
        int low=0,high=(m*n)-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            //Converts into 2D coordinates
            int row=mid/n;
            int column=mid%n;
            if(matrix[row][column]==target){
                return true;
            }else if(matrix[row][column]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
    /*
      Time Complexity->Brute->O(m*n)
                     ->Better->O(m)+O(log n base 2)
                     ->Optimal->O(log (m*n) base 2)
      Space Complexity->O(1)
    */
};