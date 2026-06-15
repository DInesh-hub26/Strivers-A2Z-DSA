#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x)
     {
        //Floor
       int low=0,high=nums.size()-1;
       int floor=-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]<=x){
            floor=nums[mid];
            low=mid+1;
        }else{
            high=mid-1;
        }
       }
       //Ceil
       int l=0,h=nums.size()-1;
       int ceil=-1;
       while(l<=h){
        int m=l+(h-l)/2;
           if(nums[m]>=x){
            ceil=nums[m];
            h=m-1;
           }else{
            l=m+1;
           }
       }
       return {floor,ceil};
    }
};