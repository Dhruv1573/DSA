//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<int>& height, int ind,vector<int>&dp){
        if(ind==0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int twoStep=INT_MAX;
        int oneStep=helper(height,ind-1,dp)+abs(height[ind]-height[ind-1]);
        if(ind>1)
            twoStep=helper(height,ind-2,dp)+abs(height[ind]-height[ind-2]);
        
        return dp[ind]=min(oneStep,twoStep);
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        return helper(height,n-1,dp);
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
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends