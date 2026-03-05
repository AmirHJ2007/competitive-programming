/*
Codeforces - Games on a CD

Idea:
The CD contains a cyclic string of length n*k.

We compute rolling hashes for all cyclic substrings
of length k.

Each game name is hashed as well.

By matching substring hashes with game hashes,
we find candidate matches.

We group matches by starting offset modulo k and
check if we can obtain n distinct games.

Double hashing is used to avoid collisions.

Time Complexity: O(nk log g)
*/

#include<bits/stdc++.h>
 
using namespace std ;
 
typedef long long ll;
 
ll  mod = 1e9 + 7  , mod1 = 1e9 + 9, prime = 37;
const ll maxn = 1e6 + 10;
pair <pair<ll , ll> , pair< int , int> > hc[maxn]  ;
pair <pair<ll , ll> , int > hq[maxn];
string arr[maxn];
vector <pair <int , int >> vec[maxn];
 
ll power (ll b , ll e)
{
	return e? power(b * b % mod , e >> 1) * (e & 1? b :1) % mod: 1;
}
ll power1 (ll b , ll e)
{
	return e? power1(b * b % mod1 , e >> 1) * (e & 1? b :1) % mod1: 1;
}
 
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n , k , g;
	cin >> n >> k >> arr[0] >> g ;
	for ( int i =1 ; i <= g ; i++)
		cin >> arr[i];
	for ( int i = 0 ; i < k ; i++)
	{
		hc[0].first.first += power(prime , i)*(arr[0][i] -'a'+1)%mod;
		hc[0].first.first %= mod;	
		hc[0].first.second += power1(prime , i)*(arr[0][i] -'a'+1)%mod1;
		hc[0].first.second %= mod1;
	}
	hc[0].second.first = 0;
	hc[0].second.second = 0;
	ll a1 , a2 , a3 , a4;
	a1=power(prime , mod -2);
	a2 = power(prime , k-1);
	a3 = power1(prime , mod1 -2);
	a4=power1(prime , k-1);
	for ( int i =1 ; i < arr[0].size() ; i++)
	{	
		int x = i+k-1 ;
		if(x>arr[0].size()-1)
			x = x % k;
		hc[i].second.second = i;
		hc[i].second.first = i%k;
		hc[i].first.first = ((hc[i-1].first.first-(arr[0][i-1] - 'a'+1) + mod)*a1%mod
		 + (arr[0][x] - 'a' +1)*a2%mod)%mod;
		 hc[i].first.second = ((hc[i-1].first.second-(arr[0][i-1] - 'a'+1) + mod1)*a3%mod1
		 + (arr[0][x] - 'a' +1)*a4%mod1)%mod1;
	}
	for( int i = 1; i <= g ; i++)
	{
		hq[i-1].second = i;
		for ( int j = 0 ; j < k ; j++)
		{
			hq[i-1].first.first += power(prime , j)*(arr[i][j] - 'a' +1)%mod;	
			hq[i-1].first.first %= mod;
			hq[i-1].first.second += power1(prime , j)*(arr[i][j] - 'a' +1)%mod1;
			hq[i-1].first.second %= mod1;
		}
	}
	sort(hq , hq + g);
	sort(hc , hc+int(arr[0].size()));
	hc[arr[0].size()].second.first = k+1;
	int l = 0 , r=0 ;
	while (l < arr[0].size() && r < g)
	{
		if ( hc[l].first.first == hq[r].first.first && hc[l].first.second == hq[r].first.second 
		 && hc[l+1].first.first == hq[r].first.first && hc[l+1].first.second == hq[r].first.second && hc[l].second.first != hc[l+1].second.first)
		{
			pair<int , int> p;
			p.first=hc[l].second.second;
			p.second = hq[r].second;
			vec[hc[l].second.first].push_back(p);
			l++;
		}
		else if ( hc[l].first.first == hq[r].first.first && hc[l].first.second == hq[r].first.second
		 && (hc[l+1].first.first != hq[r].first.first || hc[l+1].first.second != hq[r].first.second))
		{
			pair<int , int> p;
			p.first=hc[l].second.second;
			p.second = hq[r].second;
			vec[hc[l].second.first].push_back(p);
			l++;
		}
		else if (hc[l].first > hq[r].first )
			r++;
		else 
			l++;

	}
	
	for ( int i =0 ; i < k ; i++)
	{
		if(vec[i].size()>=n)
		{
			sort(vec[i].begin() , vec[i].end());
			cout << "YES"<< endl;
			for ( int j=0 ; j < vec[i].size(); j++)
				cout << vec[i][j].second << " ";
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
