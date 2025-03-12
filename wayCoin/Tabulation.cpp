#include<iostream>
#include<vector>
using namespace std;

int tabulation(vector<int> &coins,int n,int cost,vector< vector<int> > &DP){
           
    for(int i=1;i<=n;i++){
          
        for(int j=1;j<=cost;j++){
            if(j-coins[i-1]<0){
              DP[i][j]= DP[i-1][j];
            }
            else{
              DP[i][j]= DP[i-1][j]+DP[i][j-coins[i-1]];
            }
        }
    }

    return DP[n][cost];
}
int main(){

    int n;
    cin>>n;

    vector<int> coins(n);

    for(int i=0;i<n;i++) cin>>coins[i];
    
    int cost;
    cin>>cost;
    
    vector< vector<int>> DP(n+1, vector<int> (cost+1));

    for(int i=0;i<=n;i++) DP[i][0]=1;
    cout<< tabulation(coins,n,cost,DP);

}