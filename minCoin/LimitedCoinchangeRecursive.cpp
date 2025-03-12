#include<iostream>
#include<vector>
using namespace std;

int minCoin( vector<int> &vec,int idx,int wage){
       
    if(wage==0) return 0;
    
       if(idx>=vec.size()|| wage<0) return 1e9;

      
       
       cout<<idx<<endl;
       int take=1e9;
       take= minCoin(vec,idx+1,wage-vec[idx]);
       if(take!=1e9) take++;

       int noTake= minCoin(vec,idx+1,wage);

       return min(take,noTake);

}

int main(){
  
    int n;
    cin>>n;
    vector<int> vec(n);

    for(int i=0;i<n;i++) cin>>vec[i];
     int wage;
     cin>>wage;

     cout<<minCoin(vec,0,wage);

}