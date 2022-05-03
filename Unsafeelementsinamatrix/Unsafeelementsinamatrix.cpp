/*Language: cpp
ID: 7ddc9719
QLink: www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/kshitiz-and-matrix-7ddc9719/
Author: @ellicoder */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   int t;
   cin >> t;
   
   while(t--)
   {
       int n, m;
       cin >> n >> m;
       int mini = INT_MAX, maxi = INT_MIN;
       int arr[n][m];
       
       for(int i = 0; i < n; i++)
       {
		    for(int j = 0; j < m; j++)
           {
               cin >> arr[i][j];
               mini = min(mini,arr[i][j]);
               maxi = max(maxi,arr[i][j]);
           }
       }
	   set<int> row,col;
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < m; j++)
           {
               if(arr[i][j] == mini || arr[i][j] == maxi)
               {
                   row.insert(i);
                   col.insert(j);
               }
           }
       }
	   int count = 0;
       for(int i = 0; i < n; i++)
           if(row.find(i) == row.end())
               for(int j = 0; j < m; j++)
                   if(col.find(j) == col.end())
                       count++;
                       
       cout << count << endl;
   }
}