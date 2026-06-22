#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int CountStudents(vector<int>&nums,int pages){
        int students=1,Initial_pages=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+Initial_pages<=pages){
                Initial_pages+=nums[i];
            }else{
                students++;
                Initial_pages=nums[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &nums, int m)  {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
             if(nums[i]>maxi){
                maxi=nums[i];
             }
             sum+=nums[i];
        }
        /*
           Brute Approach
        for(int i=maxi;i<=sum;i++){
            int value=CountStudents(nums,i);
            if(value==m){
                return i;
            }
        }
        */
        int low=maxi;
        int high=sum;
        //More students than books case
        if(m>nums.size()){
            return -1;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=CountStudents(nums,mid);
            if(val<=m){
                //Search for better option
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        //Opposite polarities concept
        return low;
    }
    /*
      Time Complexity->Brute->O(n*(sum-maxim))
                     ->Optimal->O(n*log(sum-maxim))
      Space Complexity->O(1)
    */
};