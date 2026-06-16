#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            //Checks if Left portion is sorted
            if(nums[low]<=nums[mid]){
                //Checks if target is present in left portion
                if(target>=nums[low] && target<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            else{
            //checks if Right portion is sorted
                if(nums[mid]<=nums[high]){
                    //Checks if target is present in right portion
                    if(target>=nums[mid] && target<=nums[high]){
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }
            }
        }
        return -1;
    }
    /*
      Time Complexity->Brute->O(n)
                     ->Optimal->O(log n base 2)
      Space Complexity->O(1)
    */
};