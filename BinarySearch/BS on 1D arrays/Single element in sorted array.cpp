#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Need to check seperately for 1st and last element and for single element array
        int n=nums.size();
        int low=1,high=nums.size()-2;
        if(n==1){
            return nums[0];
        }
        else if(nums[0]!=nums[1]){
            return nums[0];
        }
        else if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        while(low<=high){
             int mid=low+(high-low)/2;
             //Checks if single is mid
             if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
             }
             else if(nums[mid]==nums[mid-1]){
                //(odd,even) so single lies in left portion so eliminates right part
                if((mid-1)%2 !=0){
                    high=mid-1;
                }else{
                //(even,odd) so eliminates left part
                    low=mid+1;
                }
             }
             else{
                //(even,odd) eliminates left part
                if(mid%2 ==0){
                    low=mid+1;
                }else{
                //(odd,even) eliminates right part
                    high=mid-1;
                }
             }
        }
        return 0;
    }
    /*
      Time complexity->Brute->O(n)
                     ->Optimal->O(log n base 2)
      Space Complexity->O(1)
    */
};