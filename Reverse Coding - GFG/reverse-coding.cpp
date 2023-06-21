//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const long long int mod = 1e9 + 7;
    int sumOfNaturals(int n) {
        // code here
        int sum = 0;
        long long int xx = ((((n % mod) * ((n + 1) % mod)) % mod) / 2) % mod;
        return xx % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends