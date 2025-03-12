#include<iostream>
#include<vector>
using namespace std;
void tabulation(vector<vector<int> > &DP,int n,int m,string st1,string st2){
      
    for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              
            if(st1[i-1]==st2[j-1])
              DP[i][j]=DP[i-1][j-1]+1;
            else  
              DP[i][j]=max(DP[i-1][j],DP[i][j-1]);  
          }
    }
}

int main(){

    string str1,str2;
    cin>>str1>>str2;
    
    int n=str1.size();
    int m= str2.size();

    vector< vector<int> > DP(n+1,vector<int> (m+1,0));

    tabulation(DP,n,m,str1,str2);
    cout<<DP[n][m];
}