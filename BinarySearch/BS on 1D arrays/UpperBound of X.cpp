#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        //C++ STL for upperBound
        /*
        auto it=upper_bound(nums.begin(),nums.end(),x);
        return it-nums.begin();
        */
        int low=0,high=nums.size()-1;
        int ans=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>x){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};