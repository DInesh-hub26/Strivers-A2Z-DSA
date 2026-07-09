#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[n-1];
        int mini_size=min(first.size(),last.size());
        for(int i=0;i<mini_size;i++){
            if(first[i]!=last[i]){
                break;
            }
            ans+=first[i];
        }
        return ans;
    }
    /*
      Time Complexity->Optimal->O(nlogn)+O(m)
      Space Complexity->O(1)
      if returning ans space not considered
    */
};