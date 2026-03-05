/*
Codeforces - Bessie's Birthday Cake (Hard)

Idea:
Sort the chosen vertices and analyze the gaps between them
in the circular polygon.

Each gap contributes potential triangles.

Odd gaps can produce an additional triangle if we spend
some of the allowed extra vertices (y).

We greedily use the smallest odd gaps first.

Time Complexity: O(x log x)
*/

#include<bits/stdc++.h>
 
using namespace std ;


const int maxx = 2e5 +10 ;

int arr[maxx] , brr[maxx];


int main ()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int t ;
	cin >> t;
	while(t--)
	{
		int n , x , y;
		cin >> n >> x >> y;
		for ( int i =0 ; i < x ; i++)
			cin >> arr[i];
		for ( int i =0 ; i < x ; i++)
			arr[i]--;
		sort(arr , arr+x);
		int ans = x-2 , j=0;
		int k =0;
		for ( int i =0 ; i < x-1 ; i++)
		{
			if(arr[i+1]-arr[i]-1<2)
			{
				
			}
			else if((arr[i+1]-arr[i]-1)%2==1)
			{
				brr[j]=(arr[i+1]-arr[i]-1)/2;
				j++;
				k+=(arr[i+1]-arr[i]-1)/2;
			}
			else
			{
				k+=(arr[i+1]-arr[i]-1)/2;
			}
		}
			if(n-(arr[x-1]-arr[0]+1)<2)
			{
				
			}
			else if((n-(arr[x-1]-arr[0]+1))%2==1 )
			{
				brr[j]=(n-(arr[x-1]-arr[0]+1))/2;
				j++;
				k+=(n-(arr[x-1]-arr[0]+1))/2;
			}
			else
			{
				k+=(n-(arr[x-1]-arr[0]+1))/2;
			}
			sort(brr , brr+j);
			long long sum=0;
			for (int i=0 ; i < j ; i++)
			{
				if(sum + brr[i] <=y)
				{
					ans++;
					sum+=brr[i];
				}
			}
			ans += 2* min(y , k);
			for ( int i =0 ; i < x ; i++)
			{
				int z = (arr[i]+2)%n;
				if(z==arr[(i+1)%x] )
					ans++;
			}
		
		
		cout << ans << endl;
		
	}
	return 0;
	
}
