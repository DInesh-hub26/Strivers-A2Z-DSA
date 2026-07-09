#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size()){
            return false;
        }
        if(s==goal){
            return true;
        }
        /*
             BRUTE APPROACH
        string temp=s;
        int count=1;
        
         // for(int i=0;i<n;i++){
           // rotate=s.substr(i)+s.substr(0,i);
          //  if(rotate==goal){
            //       return true;
           //        }
           //    }
        
        while(count==1){
            char first=temp[0];
            for(int i=1;i<n;i++){
                temp[i-1]=temp[i];
            }
            temp[n-1]=first;
            if(temp==goal){
                return true;
            }
            if(temp==s){
                count++;
            }
        }
        return false;
        */
    //OPTIMAL APPROACH
      string double_s=s+s;
    //If goal is not found it returns some long integer which is standard string::npos
    //like in maps mpp.find()!=mpp.end();
      if(double_s.find(goal)!=string::npos){
        return true;
      }
      return false;
    }
    /*
      Time Complexity->Brute->O(n*n)
                     ->Optimal->O(n)
      Space Complexity->Brute->O(n)
                      ->Optimal->O(n)
    */
};