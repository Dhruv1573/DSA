//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<string> st;
            int n = s.size();
            string sg;
            for(int i=0; i<n; i++){
                if(s[i] >= '0' && s[i] <= '9'){
                    sg = sg + s[i];
                } 
                else{
                    st.push(sg);
                    sg = "";
                    sg = sg + s[i];
                    st.push(sg);
                    sg = "";
                }
            }
            st.push(sg);
            string sn;
            while(!st.empty()){
                sn = sn + st.top();
                st.pop();
            }
            return sn;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends