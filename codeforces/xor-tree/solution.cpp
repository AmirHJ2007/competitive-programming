/*
Codeforces - Xor-tree

We are given a tree where each node has an initial value (0/1)
and a target value.

Operation:
Selecting a node flips its value and values of nodes at
even distance from it.

Idea:
Perform DFS from the root and track flip effects that
propagate through the tree.

When visiting a node, determine its current value considering
previous flips. If it differs from the goal value, perform
an operation on that node.

Time Complexity: O(n)
*/

#include<bits/stdc++.h>

using namespace std ;

const int f = 1e5 +10;
vector <int> vec[f]  , al;
int lz[f] , a[f] ;
bool vis[f];
void dfs(int v)
{

	vis[v]=1;
	if ( (a[v]==0 && lz[v]%2==0) || (a[v]==1 && lz[v]%2==1))
	{
		for ( int i =0 ; i < vec[v].size();i++)
		{
			if(vis[vec[v][i]]==0)
			{
				for ( int j =0 ; j < vec[vec[v][i]].size() ; j++)
					if(vis[vec[vec[v][i]][j]]==0)
						lz[vec[vec[v][i]][j]] = lz[v];
			}
		}
		for ( int i =0 ; i <vec[v].size();i++)
		{
			if(vis[vec[v][i]]==0)
				dfs(vec[v][i]);
		}	
	}
	else
	{
		al.push_back(v);
		lz[v]++;
		for ( int i =0 ; i < vec[v].size();i++)
		{
			if(vis[vec[v][i]]==0)
			{
				for ( int j =0 ; j < vec[vec[v][i]].size() ; j++)
					if(vis[vec[vec[v][i]][j]]==0)
						lz[vec[vec[v][i]][j]] = lz[v];
			}
		}
		for ( int i =0 ; i < vec[v].size();i++)
		{
			if(vis[vec[v][i]]==0)
				dfs(vec[v][i]);
		}
	}
	return ;
}
int main ()
{
	int n ;
	cin >> n;
	for ( int i =0 ; i < n-1 ; i++)
	{
		int x , y;
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for ( int i =1 ; i <= n ; i++)
		cin >> a[i];
	for( int i =1 ; i <= n ; i++)
	{
		int x;
		cin >> x ;
		a[i]= a[i]^x;
	}
	dfs(1);
	cout << al.size()<< endl;
	for ( int i =0 ; i < al.size(); i++)
		cout << al[i]<< endl;
	
	return 0;
}	
