//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int> ans;
        for(auto a : arr)
        {
            if(ans.empty())
            {
                ans.push(a);  // empty
            }
            else if((ans.top() >=0 && a >= 0) || (ans.top() <0 && a<0))
            {
                ans.push(a); //sign is same.  OK
            }
            else
            {
                ans.pop(); //sign is not same REMOVE.
            }
        }
        vector<int> fi;
        while(!ans.empty())
        {
            fi.push_back(ans.top()); 
            ans.pop();
        }
        reverse(fi.begin() , fi.end());
        return fi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends