/*Language: cpp
ID: 4-20d7065b
QLink:www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/beautiful-numbers-4-20d7065b/
Author: @ellicoder */
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
 
#define f(i,s,e) for(int i=s;i<e;++i)
#define fe(i,s,e) for(int i=s;i<=e;++i)
#define fie(i,s,e,d) for(int i=s;i<=e;i+=d)
 
int num[10000];
int p10[5] = { 1,10,100,1000,10000 };
int maxlen[5] = { 0, 9, 99, 999, 9999 };
int Sum1[10][10];
int Sum2[19][100];
int Sum3[28][1000];
int Sum4[37][10000];
 
int sum(int x) {
	if (x < 10)return x;
	int s = 0;
	while (x > 0) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

void precalc(){
	memset(num, 0, sizeof(num));
	memset(Sum1, 0, sizeof(Sum1));
	memset(Sum2, 0, sizeof(Sum2));
	memset(Sum3, 0, sizeof(Sum3));
	memset(Sum4, 0, sizeof(Sum4));
	fe(x, 0, 9) 
		Sum1[sum(x)][x] +=1;
	fe(s, 0, 9)
		fe(x, 1, 9) Sum1[s][x] += Sum1[s][x - 1];
	fe(x, 0, 99) 
		Sum2[sum(x)][x] += 1;
	fe(s, 0, 18) 
		fe(x, 1, 99) Sum2[s][x] += Sum2[s][x - 1];
	fe(x, 0, 999) 
		Sum3[sum(x)][x] += 1;
	fe(s, 0, 27) 
		fe(x, 1, 999) Sum3[s][x] += Sum3[s][x - 1];
	fe(x, 0, 9999) 
		Sum4[sum(x)][x] += 1;
	fe(s, 0, 36) 
		fe(x, 1, 9999) Sum4[s][x] += Sum4[s][x - 1];
	fe(x, 1, 9)num[x]=Sum1[x][9];
	fe(x, 10, 99)num[x] = Sum2[sum(x)][99];
	fe(x, 100, 999)num[x] = Sum3[sum(x)][999];
	fe(x, 1000, 9999)num[x] = Sum4[sum(x)][9999];
	f(x, 1, 10000)num[x] += num[x - 1];
}
 
int get_len(int x) {
	if (x < 10)return 1;
	int l = 0;
	while (x > 0) {
		x /= 10;
		++l;
	}
	return l;
}
int calc_exact(int x1, int x2, int l) {
	if (l == 1) {
		if (x1 <= x2)return 1;
		return 0;
	}
	int R = 0;
	if (l == 2) 
		return Sum2[sum(x1)][x2];
	if (l == 3) 
		return Sum3[sum(x1)][x2];
	if (l == 4) 
		return Sum4[sum(x1)][x2];
	return R;
}
 
int get_count(int x) {
	if (x == 1000000000)return num[9999];
	if (x < 11)return 0;
	int l = get_len(x);
	if (l & 1) {
		l -= 1;
		return num[maxlen[l / 2]];
	}
	l /= 2;
	int x1 = x / p10[l];
	int R = num[x1 - 1];
	R += calc_exact(x1,x%p10[l],l);
	return R;
}

int solve(int l, int r) {
	return get_count(r) - get_count(l - 1);
}
 
int main() {
	precalc();
	int T;
	scanf("%d", &T);
	f(t, 0, T) {
		int L, R;
		scanf("%d %d", &L,&R);
		int Rs = solve(L,R);
		printf("%d\n", Rs);
	}
	return 0;
}
 