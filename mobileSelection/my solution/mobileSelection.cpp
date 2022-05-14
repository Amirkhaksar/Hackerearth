//language: c++
//ID: 151
//Qlink:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/mobile-selection-acc2cf2b/
//author: @mahdimma -- MohammadMahdi Abbasi

#include <iostream>
#include <vector>
#include <algorithm>
 
 
#define VECT5 vector <pair <pair < pair<int, int>, int>, pair<int, int>>>
#define SYS first.first.first
#define RAM first.first.second
#define MEM first.second
#define PRICE second.first
#define RATE second.second
#define SYSEQULE(i) vect[i].SYS == ques[qI].SYS
#define RAMEQULE(i) vect[i].RAM == ques[qI].RAM
#define MEMEQULE(i) vect[i].MEM == ques[qI].MEM
#define SYSGREATER(i) vect[i].SYS < ques[qI].SYS
#define RAMGREATER(i) vect[i].RAM < ques[qI].RAM
#define MEMGREATER(i) vect[i].MEM < ques[qI].MEM
 
using namespace std;
 
int binarySearchMaxRate(VECT5, VECT5, int);
 
int main()
{
 
	//     0-    1-      2-  3-   3--   2--   1-- 2-   2--
	VECT5 vect;
	int N;
	cin >> N;
	string sysIn;
	int sysi, rami, memi, pricei, ratei;
	for (int i = 0; i < N; i++)
	{
		cin >> sysIn;
		if (sysIn == "windows")
		{
			sysi = 1;
		}
		else if (sysIn == "android")
		{
			sysi = 2;
		}
		else
		{
			sysi = 3;
		}
		cin >> rami >> memi >> pricei >> ratei;
		vect.push_back(make_pair(make_pair(make_pair(sysi, rami), memi), make_pair(pricei,ratei)));
	}
	sort(vect.begin(), vect.end());
	int G;
	cin >> G;
	VECT5 ques;
	for (int i = 0; i < G; i++)
	{
		cin >> sysIn;
		if (sysIn == "windows")
		{
			sysi = 1;
		}
		else if (sysIn == "android")
		{
			sysi = 2;
		}
		else
		{
			sysi = 3;
		}
		cin >> rami >> memi >> pricei;
		ques.push_back(make_pair(make_pair(make_pair(sysi, rami), memi), make_pair(pricei,0)));
		cout << binarySearchMaxRate(vect, ques, i) << endl;
 
	}
	return 0;
 
}
//return rate
int binarySearchMaxRate(VECT5 vect, VECT5 ques, int qI)
{
	int	low = 0, high = int(vect.size()) - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (SYSEQULE(mid) && RAMEQULE(mid) && MEMEQULE(mid))
		{
			int i = mid;
			int maxRate = 0;
			while (i != low && SYSEQULE(i - 1) && RAMEQULE(i - 1) && MEMEQULE(i - 1))
			{
				i--;
			}
			while (i <= high && SYSEQULE(i) && RAMEQULE(i) && MEMEQULE(i))
			{
				if (vect[i].PRICE > ques[qI].PRICE)
				{
					i++;
					continue;
				}
				if (vect[i].RATE > maxRate)
				{
					maxRate = vect[i].RATE;
				}
				i++;
			}
			return maxRate;
		}
		else if ((SYSGREATER(mid)) || (SYSEQULE(mid) && RAMGREATER(mid)) || (SYSEQULE(mid) && RAMEQULE(mid) && MEMGREATER(mid)))
		{
			low = mid + 1;
			continue;
		}
		else
		{
			high = mid - 1;
			continue;
		}
	}
	return -1;
}