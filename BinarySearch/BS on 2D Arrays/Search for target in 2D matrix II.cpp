#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row=0,column=n-1;
        //int row=m-1,column=0;
        while(row<m && column>=0){
            //row>=0 && column<n
            if(matrix[row][column]==target){
                return true;
            }else if(matrix[row][column]>target){
                column--;
                //row--;
            }else{
                row++;
                //column++;
            }
        }
        return false;
    }
    /*
      Time Complexity->Brute->O(m*n)
                     ->Better->O(m*log n base 2)
                     ->Optimal->O(m+n)
      Space Complexity->O(1)
    */
};