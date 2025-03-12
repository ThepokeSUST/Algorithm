// #include<iostream>
// #include<vector>

// using namespace std;

// int way(vector<int> &coins,int idx,int cost){
//      if(idx>=coins.size() || cost<0) return 0;
//      if(cost==0) return 1;
     
//      return way(coins,idx,cost-coins[idx])+way(coins,idx+1,cost);

// }

// int main(){
//     int n;
//     cin>>n;

//     vector<int> coins(n);
//     for(int i=0;i<n;i++) cin>>coins[i];
//     int cost;
//     cin>>cost;
//    cout<<way(coins,0,cost);
// }


//from back size......
// C++ program for coin change problem
// using recursion
#include <bits/stdc++.h>
using namespace std;

// Returns the count of ways we can
// sum coins[0...n-1] coins to get sum "sum"
int countRecur(vector<int>& coins, int n, int sum) {
  
    // If sum is 0 then there is 1 solution
    // (do not include any coin)
    if (sum == 0) return 1;

    // 0 ways in the following two cases
    //for one based index......
    if (sum < 0 || n == 0) return 0;

    // count is sum of solutions (i)
    // including coins[n-1] (ii) excluding coins[n-1]
    return countRecur(coins, n, sum - coins[n - 1]) + 
            countRecur(coins, n - 1, sum);
}

int count(vector<int> &coins, int sum) {
    return countRecur(coins, coins.size(), sum);
}

int main() {
    vector<int> coins = {1,2};
    int sum =10;
    cout << count(coins, sum);
    return 0;
}
