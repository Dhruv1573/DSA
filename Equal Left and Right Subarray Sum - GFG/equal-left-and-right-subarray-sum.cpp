//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        // code here
        vector<int>prefixSum(N+1),suffixSum(N+1);
        prefixSum[0]=A[0];
        for(int i=1;i<N;i++){
            prefixSum[i]=prefixSum[i-1]+A[i];
        }
        suffixSum[N-1]=A[N-1];
        for(int i=N-2;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]+A[i];
        }
        for(int i=0;i<N;i++){
            if(prefixSum[i]==suffixSum[i])
                return i+1;
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends