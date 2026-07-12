#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            //Map is intialised here because for every substring new counts required
            unordered_map<char,int>freq;
            for(int j=i;j<n;j++){
               freq[s[j]]++;
                int mini=INT_MAX;
                int maxi=INT_MIN;
               for(auto it:freq){
                 mini=min(mini,it.second);
                 maxi=max(maxi,it.second);
               }
               ans+=(maxi-mini);
            }
        }
        return ans;
    }
    /*
      Time Complexity->O(n*n)
      Space Complexity->O(1)
    */
};