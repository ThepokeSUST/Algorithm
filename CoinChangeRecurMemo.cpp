#include<iostream>
#include<vector>

using namespace std;

int minCoin(vector<int> &vec,int idx,int wage,vector< vector<int> >  &DP){
        
    if(idx>=vec.size() || wage<0) return 1e9;

    if(wage==0) return 0;

   if(DP[idx][wage]!=-1) return DP[idx][wage];
    int take=1e9;
    take= minCoin(vec,idx,wage-vec[idx],DP);
    if(take!=1e9) take++;

    int noTake= minCoin(vec,idx+1,wage,DP);

    return DP[idx][wage]= min(take,noTake);
}


int main(){
    int n;
    cin>>n;

    vector<int> vec(n);

    for(int i=0;i<n;i++) cin>>vec[i];
   int wage;
   cin>>wage;
    vector< vector<int> > DP(n, vector<int> (wage+1,-1));

   cout<<minCoin(vec,0,wage,DP);
}


