#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int FindTotalCount(int mid,vector<int>&nums,int threshold,int n){
         int sum=0;
         for(int i=0;i<n;i++){
            sum+=(nums[i]+mid-1)/mid;
            //Arithmetic option than using ceil((double)nums[i]/mid)
            //To avoid overflow 1+(nums[i]-1)/mid;
         }
         if(sum<=threshold){
            return 1;
         }else{
            return 0;
         }
    }
    int FindMaxi(vector<int>&nums,int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
           if(nums[i]>maxi){
             maxi=nums[i];
           }
        }
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        /*
        Min thresold value should be n to have answer
        if(threshold<n){
        return -1;
        }
        */
        int low=1;
        int high=FindMaxi(nums,n);
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=FindTotalCount(mid,nums,threshold,n);
            if(val==1){
                //ans=mid;
                //Search for better option
                high=mid-1;
            }
            else{
                //Eliminates left portion
                low=mid+1;
            }
        }
        //return ans;
        return low;
    }
    /*
      Time Complexity->Brute->O(n* maxim in array)
                     ->Optimal->O(n*log(maxim in array) base 2)
      Space Complexity->O(1)
    */
};