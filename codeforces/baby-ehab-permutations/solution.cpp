#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxk = 210 , mod = 1e9 +7;
long long f[2*maxk] , dp[maxk*2][maxk] , ans;
vector<ll> v;


long long power(long long b , int e)
{
    if(e==0)
        return 1;
    else if (e%2==0)
        return power(b*b%mod , e/2)%mod;
    else  
        return power(b*b%mod , e/2)*b%mod;
}
long long en( int r , int n )
{
    if(r>n)
        return 0;
    ll a=1;
    for ( int i =n-r+1 ; i <= n ; i++)
    {
        a*=i;
        a%=mod;
    }
    return a*power(f[r] , mod-2)%mod;
}

int main ()
{
    int n , k;
    cin >> n >> k;
    f[0]=1;
    for ( int i =1 ; i < 2*maxk ; i++)
        f[i]=f[i-1]*i%mod;
    for ( int i =0 ; i < 205 ; i++)
        if(i%2)
            dp[2][i]=1;
    for ( int i =3 ; i <= 410 ; i++)
        for ( int j =1 ; j <= 200 ; j++)
        {
            //if(i==2)
              //   dp[i][j]=(i-1)*(dp[i-2][j-1]+dp[i-1][j-1]+1)%mod;
          // else    
             dp[i][j]=(i-1)*(dp[i-2][j-1]+dp[i-1][j-1])%mod;
        }
    for ( int j =1 ; j <= k ; j++)
    {
        ans=0;
        for ( int i =2 ; i<=2*j ; i++)
        {
            ans+=(dp[i][j])*en(i , n)%mod;
            ans%=mod;
        }
        if(j%2==0)
            ans++;
        ans%=mod;
        v.push_back(ans);
    }
    for ( int i =0 ; i < v.size() ; i++)
        cout << v[i]<< " ";
    return 0;
}
