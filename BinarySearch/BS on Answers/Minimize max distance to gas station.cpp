#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int CountGas(vector<int>&arr,long double ans){
        int gas=0;
        for(int i=0;i<arr.size()-1;i++){
            int count=(arr[i+1]-arr[i])/ans;
            //Exactly integer case
            if((arr[i+1]-arr[i])/ans==ans*count){
                count--;
            }
            gas+=count;
        }
        return gas;
    }

    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n=arr.size();
        long double maxi=0.0;
        //vector<int>temp(n-1,0);
        /*
            BRUTE APPROACH
       for(int gas=1;gas<=k;gas++){
          long double maximum_diff=-1;
           int maximum_ind=-1;
           for(int i=0;i<n-1;i++){
              long double diff=arr[i+1]-arr[i];
              long double Section_Length=diff/(long double)(temp[i]+1);
                if(Section_Length>maximum_diff){
                    maximum_diff=Section_Length;
                    maximum_ind=i;
                }
           }
           temp[maximum_ind]++;
       }
       long double ans=-1;
       for(int i=0;i<n-1;i++){
           long double Adjacent_diff=(long double)(arr[i+1]-arr[i])/(long double)(temp[i]+1);
           ans=max(ans,Adjacent_diff);
       }
       return ans;
       */

       /*
          Better Approach
       priority_queue<pair<long double,int>>pq;
       for(int i=0;i<n-1;i++){
         pq.push({arr[i+1]-arr[i] , i});
       }
       for(int gas=1;gas<=k;gas++){
          int Max_Index=pq.top().second;
          pq.pop();
          temp[Max_Index]++;
          long double Initial_diff=arr[Max_Index+1]-arr[Max_Index];
          long double New_diff=Initial_diff/(long double)(temp[Max_Index]+1);
          pq.push({New_diff,Max_Index});
       }
       return pq.top().first;
       */
       for(int i=0;i<n-1;i++){
           maxi=max((long double)(arr[i+1]-arr[i]),maxi);
       }
       long double low=0.0;
       long double high=maxi;
       //For long double BS approach
       while(high-low > 1e-6){
        long double mid=low+(high-low)/2.0;
        int val=CountGas(arr,mid);
        if(val>k){
            low=mid;
        }else{
            high=mid;
        }
       }
       return high;
    }
    /*
      Time Complexity->Brute->O(n*k)
                     ->Better->O(log n *k)
                     ->Optimal->O(log (max adj diff) * n)
      Space Complexity->Brute->O(n-1)(temp array)
                      ->Better->O(n-1)+O(n-1)(array & priority_queue)
                      ->Optimal->O(1)
    */
};