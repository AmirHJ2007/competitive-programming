/*
Codeforces - The Number of Pairs

Idea:
Let g = gcd(a,b). Write a = g*u and b = g*v where gcd(u,v)=1.

Then:
c * lcm(a,b) - d * gcd(a,b) = x
=> c * g * u * v - d * g = x
=> c*u*v = x/g + d

Let k = x/g + d.
If k % c == 0 then uv = k/c.

Number of coprime pairs (u,v) with uv = m equals 2^(number of prime factors of m).

We precompute number of distinct prime factors for all numbers.

Time Complexity:
Precomputation: O(N log log N)
Each test: O(sqrt(x))
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e7 +10 , mod = 1e9 +7;
int p[maxn] , x , c , d , t;
bool vis[maxn];
vector <ll> v;

ll power(ll b , ll e)
{
    if(e==0)
        return 1;
    if(e%2)
        return power(b*b%mod , e/2)*b%mod;
    return power(b*b%mod , e/2)%mod;
}

int main ()
{
    for ( int i =2 ; i < maxn ; i++)
        if(vis[i]==0)
        {
            for ( int j =i ; j < maxn ; j+=i)
            {
                vis[j]=1;
                p[j]++;
            }
        }
    cin >> t;
    while(t--)
    {
        ll ans=0;
        cin >> c >> d >> x;
        for ( int i =1 ; i*i<=x ; i++)
        {
            if(i*i==x)
            {
                v.push_back(i+d);
            }
            else
            {
                if(x%i==0)
                {
                    v.push_back(i+d);
                    v.push_back(x/i+d);
                }
            }
        }
        for ( int i =0 ; i < v.size() ; i++)
            if(v[i]%c==0)
            {
                ans+=power(2 , p[v[i]/c]);
                ans%=mod;
            }
        v.clear();
        cout << ans << endl;
    }
}
