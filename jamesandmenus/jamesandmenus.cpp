/*Language: cpp
ID: 48359fe4
QLink: www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/howie-and-the-menus-2-48359fe4/
Author: @ellicoder */
#include <iostream>
using namespace std;
int main() {
  int n,m;
  cin >> n>>m;
  long long int p[n][m],max,sum=0,sum2=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>p[i][j];
    }
  }
  int good[n]={0},k;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(j==0){
        max=p[j][i];
        k=j;
      }  
      if(max<p[j][i]){
        max=p[j][i];
        k=j;
      }
    }
    good[k]++;
  }
  max=0;
  for(int i=0;i<n;i++){
    if(good[i]>max){
      max=good[i];
      k=i;
    }
    if(good[i]==max){
      for(int j=0;j<m;j++){
        sum += p[i][j];
        sum2 += p[k][j];
      }
      if((float)sum/m > (float)sum2/m){
        max=good[i];
        k=i;
      }
    }
  }
  cout << k+1 ;  
}