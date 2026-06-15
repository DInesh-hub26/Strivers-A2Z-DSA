#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            //avoiding overflow
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                 return mid;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
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