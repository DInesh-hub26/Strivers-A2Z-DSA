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

    int countOccurrences(vector<int>& arr, int target) {
        //Using lower bound and upper bound concept
     /*
       auto it1=lower_bound(arr.begin(),arr.end(),target);
       auto it2=upper_bound(arr.begin(),arr.end(),target);
       if(it1!=arr.end() && *it1 == target){
        int first=it1-arr.begin();
        int last=(it2-arr.begin())-1;
        return last-first+1;
       }
        return 0;
        }
        };
        */
    int ans_1=firstOccurence(arr,target);
    if(ans_1==-1){
        return 0;
    }
    int ans_2=lastOccurence(arr,target);
        return ans_2-ans_1+1;
     }
      /*
      (for two methods)
      Time Complexity->Brute->O(n)
                     ->Optimal->O(2*log n base 2)
      Space Complexity->O(1);
      */
       };
