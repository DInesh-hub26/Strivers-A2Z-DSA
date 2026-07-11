#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans;
        for(auto it:s){
              mp[it]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        /*
        Here [](auto &a,auto &b) is comparator which helps 
        to sort aaccording to our needs in this case return
        a.second>b.second means the one having more frequency
        should come first if a.first<b.first the one having less
        key should come first        
        */
          sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second>b.second;
          });
        for(auto it:v){
            for(int i=1;i<=it.second;i++){
            ans+=it.first;
            }
        }
        return ans;
        }
        /*
          Time Complexity->O(n)+O(k)+O(k log k)+O(n)
          Space Complexity->O(k)+O(k)+O(n)
          K is const as it consists of lower case,upper case,digits in this case
        */
};
