#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int FindNoOfDays(vector<int>&weights,int mid,int n,int days){
        int Req_days=1,load=0;
        for(int i=0;i<n;i++){
            if(load+weights[i] > mid){
                //Move to new day and add loads
                Req_days+=1;
                load=weights[i];
            }else{
                //Add load to same day
                load+=weights[i];
            }
        }
        if(Req_days<=days){
            return 1;
        }else{
            return 0;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
              if(weights[i]>maxi){
                maxi=weights[i];
              }
              sum+=weights[i];
        }
        int low=maxi;
        int high=sum;
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=FindNoOfDays(weights,mid,n,days);
            if(val==1){
                //ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        //return ans;
        //returning low by Opposite polarities concept
        return low;
    }
    /*
      Time Complexity->Brute->O(n*(sum of all - maxi in array))
                     ->Optimal->O(n*(log (sum of all-maxi in array)) base 2)
      Space Complexity->O(1)
    */
};