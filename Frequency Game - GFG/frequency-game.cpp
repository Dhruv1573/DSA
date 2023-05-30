//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int,int> mapping;
        sort(arr,arr+n);
        for(int i = 0 ; i< n;i++){
            mapping[arr[i]]++;
        }
        int maximum = arr[n-1];
        for(int i = n-1; i>=0 ; i--){
            if(mapping[arr[i]] < mapping[maximum]){
                maximum = arr[i];
            }
        }
        return maximum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends