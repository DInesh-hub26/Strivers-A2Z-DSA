#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        //Same code for Palindrome check
        //Need to Compare s and ans at last
        int n=s.size();
        //Brute Approach
        /*
        string Word="";
        vector<string>Words={};
        string ans="";
        for(auto it:s){
            if(it!=' '){
                Word.push_back(it);
            }
           else if(!Word.empty()){
                Words.push_back(Word);
                Word="";
           }
        }
        if(!Word.empty()){
              Words.push_back(Word);
        }
        reverse(Words.begin(),Words.end());
        for(int i=0;i<Words.size();i++){
            ans+=Words[i];
            if(i!=Words.size()-1){
              ans.push_back(' ');
            }
        }
        return ans;
        */
       //Optimal
        int i=n-1;
        int j;
        string ans="";
        while(i>=0){
            while(i>=0 && s[i]==' '){
                i--;
            }
            if(i<0){
                break;
            }
            int end=i;
            while(i>=0 && s[i]!=' '){
                i--;
            }
            int start=i;          //start,length
            //string word=s.substr(start+1,end-start);
            if(!ans.empty()){
                ans+=' ';
            }
            for(int k=start+1;k<=end;k++){
                ans+=s[k];
            }
            //ans+=word;
        }  
        return ans;
    }
    /*
      Time Complexity->Brute->O(n)
                     ->Optimal->O(n)
      As we dont need to change original s we need to create duplicate one to return ans
      so returning ans is not included in space complexity
      Space Complexity->Brute->O(n)
                      ->Optimal->O(1)
    */
};