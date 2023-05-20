//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int g, vector<int> &hand) {
        // code here
        unordered_map<int,vector<int>>ump;
        if(N%g!=0)return false;
        vector<int>temp=hand;
        sort(temp.begin(),temp.end());
        for(int i=0 ; i<hand.size() ; i++){
            ump[temp[i]].push_back(i);
        }
        for(int i=0 ; i<N ; i++){
            if(temp[i]==-1)continue;
            else{
                int t=temp[i];
                for(int i=0 ; i<g-1 ; i++){
                    if(ump.find(t+1)==ump.end()){
                        return false;
                    }
                    else{
                        // first find the length of that vector containing that element;
                        int l=ump[t+1].size();
                        temp[ump[t+1][l-1]]=-1;
                        ump[t+1].pop_back();
                        t++;
                    }
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends