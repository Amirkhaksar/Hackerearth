/*Language: cpp
ID: 2e1df6ef
QLink:www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/minimum-cost-path-in-a-grid-2-2e1df6ef/
Author: @ellicoder */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define infinity 1 << 30

int n, m;
const int maxSize = 1001;
const int maxNumber = 1e5 + 1;
int primes[maxNumber] = {0};
int countOfFactors[maxNumber] = {0};
int currentValue[maxNumber];

void sieve(){
    for (int i = 0; i < maxNumber; ++i)
        currentValue[i] = i;
    for (int i = 2; i < maxNumber; ++i){
        if (!primes[i]){
            countOfFactors[i] = 1;
            for (int j = i + i; j < maxNumber; j += i){
                primes[j] = 1;
                while (currentValue[j] % i == 0){
                    currentValue[j] /= i;
                    countOfFactors[j]++;
                }
            }
        }
    }
}

int dp[maxSize][maxSize];
int graph[maxSize][maxSize];

bool isValid(int i, int j){
    if (i >= 1 && i <= n && j >= 1 && j <= m)
        return true;
    return false;
}

int travel(int i, int j){
    if (!isValid(i, j))
        return infinity;
    if (dp[i][j] != -1)
        return dp[i][j];
 
    int currentCost = countOfFactors[graph[i][j]];
    if (i == n && j == m)
        return dp[i][j] = currentCost;
    int right = travel(i, j + 1);
    int down = travel(i + 1, j);
    return dp[i][j] = min(right, down) + currentCost;
}

int main(){
    int t;
    cin >> t;
    sieve();
    while (t--){
        cin >> n >> m;
 
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> graph[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = -1;
        cout << travel(1, 1) << endl;
    }
    return 0;
}