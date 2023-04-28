//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        int count = 0;
        for(int i=0;i<s2.size();i++){
            int l1 = s2[i].length();
            
            for(int j=0;j<s1.size();j++){
                int l2 = s1[j].length();
                int f = s1[j].find(s2[i]);
                
                int x = 0;
                
                if(f!=-1){
                    if(f==0 || f==l2-l1){
                        x=1;count++;break;
                    }
                    else{
                        while(f!=-1 && f<l2-l1){
                            f = s1[j].find(s2[i],f+1);
                            if(f==l2-l1){x=1; count++; break; }
                        }
                    }
                }
                if(x==1) break;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends