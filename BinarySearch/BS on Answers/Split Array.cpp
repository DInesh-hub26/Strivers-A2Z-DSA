#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //Same logic and code as Book Partition problem
    int CountValueOfK(vector<int>&nums,int ans){
        int SubArrays=1,initial_sum=0;
        for(int i=0;i<nums.size();i++){
            if(initial_sum+nums[i]<=ans){
                initial_sum+=nums[i];
            }else{
                SubArrays++;
                initial_sum=nums[i];
            }
        }
        return SubArrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            sum+=nums[i];
        }
        int low=maxi;
        int high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=CountValueOfK(nums,mid);
            if(val<=k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
    /*
      Time Complexity->Brute->O(n*(sum-maxim))
                     ->Optimal->O(n*log(sum-maxim))
      Space Complexity->O(1)
    */
};