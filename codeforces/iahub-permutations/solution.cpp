#include<bits/stdc++.h>

using namespace std;

const int maxn = 2000+10 , mod =1e9 +7;
long long  dp[maxn][maxn] ;
int arr[maxn];
int vis[maxn];

int main ()
{
   int n ;
   cin >> n ;
   for ( int i =1 ; i <= n ; i++)
    {
        dp[i][1]=i-1;
        dp[i][0]=1;
    }
    for ( int i =2 ; i <= n ; i++)
        for ( int j =2 ; j <= i ; j++)
            {
                dp[i][j]=dp[i-1][j-1]*(i-j)%mod;
                dp[i][j]+=(dp[i][j-1] - dp[i-1][j-1] + mod)*(i-j+1)%mod;
                dp[i][j]%=mod;
            }
    for ( int i =1 ; i <=n ; i++)
        cin >> arr[i];
    for ( int i =1 ; i <= n ; i++)
        if(arr[i]>0)
            vis[arr[i]]++;
    for ( int i =1 ; i <=n ; i++)
        if(vis[i]==0 && arr[i]==-1)
            vis[i]=2;
    int t=0  , k=0;
    for ( int i =1 ; i <= n ; i++)
    {
        if(vis[i]==0)
            t++;
        if(vis[i]==2)
            k++;
    }
    long long a = 1;
    for ( int i =2 ; i <= t ; i++)
    {
        a*=i;
        a%=mod;
    }
    cout << dp[t+k][k]*a%mod << endl;
   //cout << t<< " "<< k << " "<<dp[20][20];
    return 0;   
}
