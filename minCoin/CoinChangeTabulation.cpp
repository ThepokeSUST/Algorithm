#include<iostream>
#include<vector>
using namespace std;


void Tabulation(vector< vector<int>> &DP,int n,int cost,vector<int> & coins){
            

    for(int i=1;i<=n;i++){
          
        for(int j=1;j<=cost;j++){
            if(j<coins[i-1])
               DP[i][j]=DP[i-1][j];
            else
               DP[i][j]= min(DP[i-1][j],1+DP[i][j-coins[i-1]]);
        }
    }
}
int main(){


    int n;
    cin>>n;

    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];

    int cost;
    cin>>cost;
    vector< vector<int> > DP(n+1, vector<int> (cost+1,0));

    for(int i=1;i<=cost;i++) DP[0][i]=1e9;
    
    Tabulation(DP,n,cost,vec);
    cout<<DP[n][cost];
     
}