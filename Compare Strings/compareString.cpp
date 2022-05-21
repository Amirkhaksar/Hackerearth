/*
	lan: cpp
	QLink: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/compare-strings-1-1cb66e03/
	id: 147
	author: Amir Aghazadeh
*/


#includebitsstdc++.h

using namespace std;

int main()

{

     ios_basesync_with_stdio(false);

cin.tie(NULL);cout.tie(NULL);

    int n,q,i;

    cinnq;

    string a,b;

    cina;

    cinb;

    vectorintv;

    int counta=0,countb=0;

    for(i=0;in;i++)

    {

        

        if(b[i]=='1')

countb++;

        if(a[i]=='1')

        counta++;

    }

    while(q--)

    {

        int k;

cink;

        if(b[k-1]=='0')

        {

            b[k-1]='1';

            countb++;

        }

        if(countb=counta)

        coutYESn;

        else

        coutNOn;

    }

}