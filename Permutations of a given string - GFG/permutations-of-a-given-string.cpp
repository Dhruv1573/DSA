//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    int factorial(int n)
        {
            return (n==1 || n==0) ? 1: n * factorial(n - 1); 
        }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		     sort(s.begin(),s.end());
            int n=s.size();
            n=factorial(n);
            set<string>res;
            do{
               res.insert(s);
               next_permutation(s.begin(),s.end());
               n--;
            }while(n>=1);
            
            vector<string>ans;
            for(auto i:res){
                ans.push_back(i);
            }
            return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends