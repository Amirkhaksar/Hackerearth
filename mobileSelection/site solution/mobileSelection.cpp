//language: c++
//ID: 151
//Qlink:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/mobile-selection-acc2cf2b/
//author: site author

#include <bits/stdc++.h>
using namespace std;

string os[]=  { "windows", "android", "ios"};
int ram[] = {2, 4, 8};
int mem[] = {32,64,-1};
vector<pair<pair<int,int>,int> > v[20];





int getIndex(string a , int b, int c)
{
    int x,y,z;
    
    for(int i=0;i<3;i++)
    {
        if(a == os[i])
        x =i;
        if(b==ram[i])
        y=i;
        if(c==mem[i])
        z =i;
    }
    return x*6 + y*2 + z ; 
    
    
}

int solve(string a , int b, int c,int budget){
    
    int x = getIndex(a,b,c);
    
    if(v[x].size()==0)
    return -1;
    if(v[x][0].first.first> budget)
    return -1;
    
   
    int ans = 0;
    
    int low = 0;
    int high= v[x].size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[x][mid].first.first<=budget)
        {
           ans= mid;
           low = mid+1;
        }
        else
        high = mid-1;
    }
   
    return v[x][ans].second;
    
    
    
    
    
    
}

int main()
{
    
    int n,a,b,c,d;
    string str;
    cin>>n;
    assert(1<=n && 1000000 >= n );
    for(int i=0;i<n;i++)
    {
        cin>>str>>a>>b>>c>>d;
        assert(str=="windows" || str =="android" || str=="ios");
        assert(a==2|| a==4 || a==8);
        assert(b==32 || b==64);
        assert(c>=1 && c<=1000000000);
        assert(d>=1 && d<=1000000000);
        int x = getIndex(str,a,b);
        v[x].push_back({{c,d},d});
        
        
        
    }
    for(int i=0;i<18;i++)
    sort(v[i].begin(),v[i].end());
    for(int i=0;i<18;i++)
    {
        for(int j=1;j<v[i].size();j++)
        {
            v[i][j].second = max(v[i][j-1].second,v[i][j].second);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>str>>a>>b>>c;
        assert(str=="windows" || str =="android" || str=="ios");
        assert(a==2|| a==4 || a==8);
        assert(b==32 || b==64);
        assert(c>=1 && c<=1000000000);
        
        cout<<solve(str,a,b,c)<<"\n";
        
    }
    
}