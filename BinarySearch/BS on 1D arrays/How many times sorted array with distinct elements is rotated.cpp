#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /*
    Finding index of minimum element in rotated sorted
    arry gives answer
    Apply similar logic to rotated sorted array with 
    duplicates(low ++,high -- logic)
    */
    int findKRotation(vector<int> &nums)  {
        int low=0,high=nums.size()-1;
        int mini=INT_MAX;
        int index=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high]){
               if(nums[low]<mini){
                mini=nums[low];
                index=low;
               }
                break;
            }
            if(nums[low]<=nums[mid]){
               if(nums[low]<mini){
                mini=nums[low];
                index=low;
               }
                low=mid+1;
            }
            else{
                if(nums[mid]<=nums[high]){
                    if(nums[mid]<mini){
                        mini=nums[mid];
                        index=mid;
                    }
                    high=mid-1;
                }
            }
        }
        return index;
    }
    /*
      Time Complexity->Brute->O(n)
                     ->Space Complexity->O(log n base 2)
      Space Complexity->O(1)
    */
};