/*.........................*
 *..................___....*
 *.../|...../|...../...\...*
 *../.|..../.|..../........*
 *....|......|...|.........*
 *....|......|..|..___.....*
 *....|......|..|./...\....*
 *....|......|..|/.....\...*
 *....|......|..\...../....*
 *..__|__..._|_..\___/.....*
 *.........................*
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define re return
#define pii pair<int,int>
#define pb push_back
int fun(int mat[][5],int l,int r)
{
    int cnt=0;
    for(int i=0;i<5;i++)
      if(mat[l][i]<mat[r][i]) cnt++;
    
    if(cnt>=3) re l;
    else re r;
}
void solve()
{
    int n;
    cin>>n;
    int mat[n][5];
    vector<int> v;
    int m=n;
    if(n%2==1) m=n-1;
    for(int i=1;i<m;i+=2)
    {
    	for(int j=0;j<5;j++) cin>>mat[i][j];
    	for(int j=0;j<5;j++) cin>>mat[i+1][j];
        int res=fun(mat,i,i+1);
        //cout<<res<<"\n";
        v.pb(res);
    }
    if(n%2)
	{
	  v.pb(n);
	  	for(int j=0;j<5;j++) cin>>mat[n][j];
    }
    if(n<=2)
    {
    	cout<<*v.begin()<<"\n";
    	re;
	}
    while(v.size()>1)
    {
        
        vector<int>::iterator l,r;
        l=v.begin();
        int j=*l;
       // cout<<*l<<'\n';
        v.erase(l);
        r=v.begin();
        int k=*r;
        //cout<<*r<<'\n';
        v.erase(r);
        int res=fun(mat,j,k);
        v.pb(res);
    }
    vector<int>::iterator fn;
    fn=v.begin();
   // cout<<*fn<<"\n";
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
    	int re1=fun(mat,*fn,i);
    	  //cout<<re1<<"\n";
          if(re1!=*fn) 
          {
            flag=false;
            break;
          }
    
    }
    
    if(flag) cout<<*fn<<"\n";
    else cout<<"-1\n";
    //v.clear();
    re;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t-->0)
      solve();
    re 0;  
}





