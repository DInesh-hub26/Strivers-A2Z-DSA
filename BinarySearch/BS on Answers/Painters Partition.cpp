#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //Same logic and code as Books partition and Split array
    int Count_Painters(vector<int>&C,int ans,int B){
        int Painters=1,initial_time=0;
        for(int i=0;i<C.size();i++){
            if(initial_time+(B*C[i])<=ans){
                initial_time+=(B*C[i]);
            }else{
                Painters++;
                initial_time=(B*C[i]);
            }
        }
        return Painters;
    }
    int paint(int A, int B, vector<int>& C) {
       int n=C.size();
       int Maxi=INT_MIN;
       int sum=0;
       for(int i=0;i<n;i++){
          if((B*C[i])>Maxi){
            Maxi=B*C[i];
          }
          sum+=(B*C[i]);
       }
       int low=Maxi;
       int high=sum;
       while(low<=high){
        int mid=low+(high-low)/2;
          int val=Count_Painters(C,mid,B);
          if(val<=A){
             high=mid-1;
          }else{
            low=mid+1;
          }
       }
       return low % 10000003;
    }
    /*
      Time Complexity->Brute->O(n*2*(sum-maxim))
                     ->Optimal->O(n*log(2*(sum-maxim)))
      Space Complexity->O(1)
    */
};