//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  bool fnc(int idx,int k,int target, vector<int>&coins,vector<vector<int>>&dp){
        if(k==0){
            return target==0;
        }
        if(idx==coins.size())return 0;
        if(dp[target][k]!=-1)return dp[target][k];
        bool op1=false;
        if(coins[idx]<=target)op1=fnc(idx,k-1,target-coins[idx],coins,dp);
        bool op2=fnc(idx+1,k,target,coins,dp);
        return dp[target][k]=op1||op2;
    }
    bool makeChanges(int N, int k, int target, vector<int> &coins) {
        // code here
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(target+1,vector<int>(k+1,-1));
        
        return fnc(0,k,target,coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends