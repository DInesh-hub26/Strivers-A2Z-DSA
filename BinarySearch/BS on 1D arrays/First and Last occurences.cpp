#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int firstOccurence(vector<int>&nums,int target){
        int low=0,high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return first;
    }

    int lastOccurence(vector<int>&nums,int target){
        int low=0,high=nums.size()-1;
        int last=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //Using lower and upper bound concept
        /*
       auto it1=lower_bound(nums.begin(),nums.end(),target);
       auto it2=upper_bound(nums.begin(),nums.end(),target);
       if(it1!=nums.end() && *it1 == target){
        int first=it1-nums.begin();
        int last=(it2-nums.begin())-1;
       return {first,last};
       }
       else{
        return {-1,-1};
       }
       return {};
       }
       */
    int ans_1=firstOccurence(nums,target);
    if(ans_1==-1){
        return {-1,-1};
    }
    int ans_2=lastOccurence(nums,target);
        return {ans_1,ans_2};
    }
    /*
      (for two methods)
      Time Complexity->Brute->O(n)
                     ->Optimal->O(2*log n base 2)
      Space Complexity->O(1);
      */
};