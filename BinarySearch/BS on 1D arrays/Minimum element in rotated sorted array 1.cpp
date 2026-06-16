#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int mini=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            //search space is sorted 
            if(nums[low]<=nums[high]){
                mini=min(nums[low],mini);
                break;
            }
            //Checks if left portion is sorted
            if(nums[low]<=nums[mid]){
                mini=min(nums[low],mini);
                //Eliminates left portion
                low=mid+1;
            //Right portion is sorted
            }else{
                mini=min(nums[mid],mini);
                //Eliminates right portion
                high=mid-1;
            }
        }
        return mini;
    }
    /*
       Time Complexity->Brute->O(n)
                      ->Optimal->O(log n base 2)
       Space Complexity->O(1)
    */
};