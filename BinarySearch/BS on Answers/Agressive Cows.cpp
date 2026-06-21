#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool FindIfPossible(vector<int>&nums,int dist,int k){
        int count_cows=1,last=nums[0];
        for(int i=1;i<nums.size();i++){
              if(nums[i]-last>=dist){
                count_cows++;
                last=nums[i];
              }
              if(count_cows==k){
                return true;
              }
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        /*
           Brute Approach
           for(int i=1;i<=nums[n-1]-nums[0];i++){
           if(FindIfPossible(nums,i,k)==true){
               ans=i;
           }
               else{
                    break;
                      }
           }
        */
        int low=1,high=nums[n-1]-nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(FindIfPossible(nums,mid,k)==true){
                ans=mid;
                //Search for maximum
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    /* 
       Time Complexity->Brute->O(nlogn)+O(n*(maxm -minm))
                      ->Optimal->O(nlogn)+O(n*log(maxm-minm))
       Space Complexity->O(1)
    */
};