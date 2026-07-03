#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
     int x=a.size();
     int y=b.size();
     /*
      BETTER CODE
     int i=0,j=0;
     int count=0;
     while(i<x && j<y){
        if(a[i]<=b[j]){
            if(count==k-1){
                return a[i];
            }
            count++;
            i++;
        }
        else{
            if(count==k-1){
                return b[j];
            }
            count++;
            j++;
        }
     }
     while(i<x){
           if(count==k-1){
            return a[i];
           }
           count++;
           i++;
     }
     while(j<y){
           if(count==k-1){
            return b[j];
           }
           count++;
           j++;
     }
     return -1;
     */
    //OPTIMAL CODE
     if(x>y){
        return kthElement(b,a,k);
     }
     int low=0;
     int high=x;
     while(low<=high){
        int mid1=low+(high-low)/2;
        int mid2=k-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<x){
            r1=a[mid1];
        }
        if(mid2<y){
            r2=b[mid2];
        }
        if(mid1-1>=0){
            l1=a[mid1-1];
        }
        if(mid2-1>=0){
            l2=b[mid2-1];
        }
        if(l1<r2 && l2<r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=mid1-1;
        }else{
            low=mid1+1;
        }
     }
     return -1;
    }
     /*
       Time Complexity->Brute->O(n1+n2)
                      ->Better->O(n1+n2)
                      ->Optimal->O(log(n1+n2))
       Space Complexity->Brute->O(n1+n2)
                       ->Better->O(1)
                       ->Optimal->O(1)
     */
};