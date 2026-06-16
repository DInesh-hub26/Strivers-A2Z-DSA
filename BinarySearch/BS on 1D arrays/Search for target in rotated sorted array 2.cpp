#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[low]==nums[mid] && nums[low]==nums[high]){
                low++;
                high--;
                continue;
            }
            //Checks if left is sorted
            if(nums[low]<=nums[mid]){
                //Checks if target lies in left half
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            else{
                //Checks if right is sorted
                if(nums[mid]<=nums[high]){
                    //Checks if target lies in right half
                    if(nums[mid]<=target && target<=nums[high]){
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }
            }
        }
        return false;
    }
    /*
       Time Complexity->Brute->O(n)||O(n/2)
                      ->Optimal->O(log n base 2)
       Space Complexity->O(1)
    */
};