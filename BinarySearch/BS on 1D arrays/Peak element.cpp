#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        //Check seperately for 1st and last elements and for single element array
        int low=1,high=nums.size()-2;
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        else if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            //Rising slope so peak should lie in right half
            else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            //Decreasing slope so peak should lie in left half
            else if(nums[mid]>nums[mid+1]){
                high=mid-1;
            }
            //Condition when array has multiple peaks for array like[1,5,1,2,1]
            else{
                high=mid-1;
                //or low=mid+1 both are ok
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