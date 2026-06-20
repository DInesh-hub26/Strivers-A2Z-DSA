#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        //Brute approach
        /*int ans=k;
        for(int i=0;i<n;i++){
        if(arr[i]<=ans){
            ans++;
        }else{
            break;
        }
        }
        return ans;
        } 
        };
        */
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]-(mid+1)<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        /*
           Need to return arr[high]+more
           but for arrays like[3,4,5,6] k=2,arr[high] points towards -ve index
           more=(k-(arr[high]-high-1))
           high+1=low
        */
        return low+k;
        //return ans;
    }
    /*
       Time Complexity->Brute->O(n)
                      ->Optimal->O(log n)
       Space Complexity->O(1)
    */
};