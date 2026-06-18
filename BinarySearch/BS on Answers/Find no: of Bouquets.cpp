#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //Finds no: of bouquets possible at given day
    int Find_Bouquets(vector<int>&bloomDay,int day,int m,int k,int n){
        int count=0;
        int NoOfBouquets=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                count++;
            }else{
                NoOfBouquets+=(count/k);
                //adjacent flowers completed so restart count
                count=0;
            }
        }
        NoOfBouquets+=(count/k);
        return NoOfBouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=INT_MAX;
        int high=INT_MIN;
        int ans=-1;
        long long val_1=(long long)m*k;
        if(val_1 > n){
            return -1;
        }
        //Finds Min and Max possible answers in search space
        for(int i=0;i<n;i++){
            if(bloomDay[i]<low){
                low=bloomDay[i];
            }
            if(bloomDay[i]>high){
                high=bloomDay[i];
            }
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int val_2=Find_Bouquets(bloomDay,mid,m,k,n);
            if(val_2>=m){
                ans=mid;
                //Search for better option
                high=mid-1;
            }
            else{
                //Eliminates left half
                low=mid+1;
            }
        }
            return ans;
    }
    /*
       Time Complexity->Brute->O(n*(high-low))
                      ->Optimal->O(n*log((high-low)) base 2)
       Space Complexity->O(1)
    */
};