//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<int, int>ladders_present;
    unordered_map<int, int>snakes_present;
    unordered_map<int, int>dp;
    int getMinMoves(int start, int end){
        // cout<<start<<endl;
        if(start==end)return 0;
        if(dp.find(start)!=dp.end())return dp[start];
        if(ladders_present.find(start)!=ladders_present.end()){
            return getMinMoves(ladders_present[start], end);
        }
        
        int minMoves = INT_MAX;
        for(int i=1; i<=6; i++){
            if(start+i<=30 && snakes_present.find(start+i)==snakes_present.end()){
                minMoves = min(minMoves, 1+getMinMoves(start+i, end));
            }
                
        }
        dp[start]=minMoves;
        return minMoves;
    }
    int minThrow(int N, int arr[]){
        // code here
        for(int i=0; i<N; i++){
            int start = arr[2*i];
            int end = arr[(2*i)+1];
            
            if(start>end){
                snakes_present[start]=end;
            }
            else{
                ladders_present[start]=end;
            }
        }
        // for(auto &x: ladders_present){
        //     cout<<"Ladder from: "<<x.first<<" to "<<x.second<<endl;
        // }
        // for(auto &x: snakes_present){
        //     cout<<"Snake from: "<<x.first<<" to "<<x.second<<endl;
        // }
        return getMinMoves(1, 30);
        // 0 -> 0, 1
        // 1 -> 2, 3
        // 2 -> 4, 5
        // 3 ->
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends