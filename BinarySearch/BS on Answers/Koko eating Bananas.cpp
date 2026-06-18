#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int MaxOfArray(vector<int>&piles,int n){
        //Finds Maximum element in the array
        int Maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>Maxi){
                Maxi=piles[i];
            }
        }
        return Maxi;
    }
    long long FindTotalHours(vector<int>&piles,int mid,int n){
        long long TotalHours=0;
        for(int i=0;i<n;i++){
             TotalHours+=ceil((double)piles[i]/mid);
             /*
               Can use integer arithmetic instead
               ToatlHours+=(piles[i]+mid-1)/mid;
             */
        }
        return TotalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=MaxOfArray(piles,n);
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long val=FindTotalHours(piles,mid,n);
            if(val<=h){
                ans=mid;
                //Search for better one by eliminating right
                high=mid-1;
            }else{
                //Eliminates left portion
                low=mid+1;
            }
        }
        return ans;
    }
    /*
      Time Complexity->Brute->O(N*(Max of array))
                     ->Optimal->O(N*(log (Max of array) base 2))
      Space Complexity->O(1)
    */
};