/*
Language: C++
ID: prime-game-1-2604365b
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/prime-game-1-2604365b/
Author: AmirZoyber
*/

#include<bits/stdc++.h>
 
std::vector< int >num ;
int dp[20][20][2] ; 
 
long long int powerOf(long long int a, long long int n, long long int p)
{
    long long int res = 1;a = a % p;
    while (n > 0){
        if (n & 1LL)
            res = (res*a) % p;
        n = n>>1LL;
        a = (a*a) % p;}
    return res;
}
 
int isPrime( int l , int r ){
    long long val = 0 ;
    for( int i = l ; i <= r ; i++ ){
        val = val*10 + num[i] ;}
 
    if( val == 1 || val == 0 ){
        return 0 ;}
 
    if( val <= 3 ){
        return 1 ;}
    return powerOf(6,val-1,val) == 1 ;
}

int find_ans( int start , int end , int isAliceChance ){
    if( isPrime(start, end) ){
        if( isAliceChance == 1 ){return 1 ;}
        else{return 0 ;}
    }
    if( dp[start][end][isAliceChance] != -1 ){
        return dp[start][end][isAliceChance] ;}
    int ans = 0 ;
    
    if( isAliceChance == 1 ){
        return dp[start][end][isAliceChance] = std::max( find_ans(start+1, end, 1-isAliceChance), 
                    find_ans(start, end-1, 1-isAliceChance)) ;}
    else{
        return dp[start][end][isAliceChance] = std::min( find_ans(start+1, end, 1-isAliceChance), 
                    find_ans(start, end-1, 1-isAliceChance)) ;}
}

//main
int main(){
    int t;
    std::cin>>t ;
    while(t--){
        long long int x ;
        std::cin>>x ;
        memset(dp, -1 , sizeof(dp)) ;
        while( x != 0 ){
            num.push_back(x%10);x = x/10;}
        reverse( num.begin(), num.end() );
        int isAliceWins = find_ans(0, num.size()-1 , 1) ;
        if( isAliceWins == 0 ){std::cout<<"Bob\n" ;
        }else{std::cout<<"Alice\n" ;}
        num.clear() ;
    }
}