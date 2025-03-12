#include<iostream>
#include<vector>
using namespace std;

string LCS(string st1,string st2,int a,int b){
       // string st="";
    if(a>=st1.size() || b>=st2.size())
      // return 0;
      return "";
   if(st1[a]==st2[b]){
   // st+=st1[a];
    return st1[a]+ LCS(st1,st2,a+1,b+1);
           
   }
   string news=LCS(st1,st2,a+1,b);
   string news2= LCS(st1,st2,a,b+1);
//     if(news>news2) return news;
//    else return news2;   //logical error
  return  news.size()>news2.size()? news:news2; 
}

int main(){

    string one="dipokk";
    string two ="eipok";
    if(one>two) cout<<"one";
    else if(one==two) cout<<" ok";
    else cout<<"two";

    string str1,str2;
    cin>>str1>>str2;
    cout<<LCS(str1,str2,0,0);

}