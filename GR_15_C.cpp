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
#define push_back pb
int a[110];
int b[110];
int f[210];
void solve()
{
    int n,k;
    cin>>n>>k;
    int f[2*n+1]={1};
    for(int i=1;i<=2*n;i++) f[i]=1;
    int fre=2*n;
    
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
        cin>>b[i];
        f[a[i]]=0;
        f[b[i]]=0;
        fre-=2;
    }
    
    int ans=(n-k)*(n-k-1)/2;
    
    for(int i=0;i<k;i++)
    {
        int x=a[i];
        int y=b[i];
        if(y<x) swap(x,y); // y shpuld be greatest
        int cnt=0;
        for(int j=x+1;j<y;j++) cnt+=f[j];
        ans+=min(cnt,fre-cnt);
        
        for(int j=i+1;j<k;j++)
        {
            int u=a[j];
            int v=b[j];
            if((x<u && u<y)^(x<v && v<y)) ans++;
        }
    }
    cout<<ans<<"\n";
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





