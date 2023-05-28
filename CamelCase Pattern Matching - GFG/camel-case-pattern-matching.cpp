//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dict, string pattern) {
        // code here
        vector<string> ans;
       for(int i=0; i<Dict.size(); i++)
       {
           string s=Dict[i];
           if(s.length()<pattern.length())
           continue;
          
           int j=0,k=0;
           while(j<s.length() && k<pattern.length())
           {
               if(s[j]>='A' && s[j]<='Z')
               {
                   if(s[j]==pattern[k])
                   {
                       j++;
                       k++;
                       
                   }
                   else
                   break;
               }
               else
               j++;
           }
           
           if(k==pattern.length())
           ans.push_back(s);
       }
       if (ans.empty()) {
        ans.push_back("-1");
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends