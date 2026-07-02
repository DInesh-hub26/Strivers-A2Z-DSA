#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a=nums1.size();
        int b=nums2.size();
        if(a>b){
             return findMedianSortedArrays(nums2,nums1);
        }
        int left=(a+b)/2;
        int low=0;
        int high=a;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<a){
                r1=nums1[mid1];
            }
            if(mid2<b){
                r2=nums2[mid2];
            }
            if(mid1-1>=0){
                l1=nums1[mid1-1];
            }
            if(mid2-1>=0){
                l2=nums2[mid2-1];
            }
            if(l1<=r2 && l2<=r1){
                if((a+b)%2==0){
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }else{
                    return min(r1,r2);
                }
            }
            else if(l1>r2){
                high=mid1-1;
            }
            else{
                low=mid1+1;
            }
        } 
        return -1;
    }
    /*
      Time Complexity->Brute->O(n1+n2)
                     ->Better->O(n1+n2)
                     ->optimal->O(log(n1+n2))
      Space complexity->Brute->O(n1+n2)
                      ->Better->O(1)
                      ->optimal->O(1)
    */
};