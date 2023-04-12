//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin(), arr.begin()+n/2);
        sort(arr.begin()+(n/2), arr.end());
        int left = n/2-1;
        int right = n-1;
        int count = 0;
        while(left >= 0 && right >= n/2){
            if(arr[left] >= 5*arr[right]){
                count += (right-n/2+1);
                --left;
            }
            else{
                --right;
            }
        }
        return count;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends