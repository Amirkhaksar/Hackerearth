/*
#Language:C++
#ID:Specialty of a sequence
#QLink:hhttps://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/lex-finds-beauty-0d0bc1b6/
#All Accepet
#Author:Amirkhaksar
*/



#include<iostream>
#include<algorithm>


int main()
{

    std::ios_base::sync_with_stdio(0);

    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;

    int A[n], sum = 0;

    for (int i = 0; i < n; i++)
        std::cin >> A[i];

    std::sort(A, A + n, std::greater<int>());

    for (int i = k; i < n; i++) {

        sum += A[i];

    }

    std::cout << sum << std::endl;

    return 0;

}