//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
         map<int,int>mp;
        for(auto &it:arr) mp[it]++;
        int ans=0;
        unordered_set<int>st;
        for(int i=0;i<N;i++){
            if(st.find(arr[i])!=st.end()) {ans++;continue;}
            for(auto &it:mp){
                if(it.first>arr[i]) break;
                if(arr[i]%(it.first)==0 && it.first!=arr[i]) {ans++,st.insert(arr[i]);break;}
                if((it.second>1) && it.first==arr[i]) {ans++,st.insert(arr[i]);break;}
            } 
        }
        return ans; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends