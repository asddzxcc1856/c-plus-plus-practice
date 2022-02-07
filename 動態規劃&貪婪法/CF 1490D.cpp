#include <iostream>
#include <vector>
using namespace std;

struct point{
	int val;
	int index;
};

point p[105];
vector<int> v;
void cnt(int l , int r,int depth)
{
	if(l>r)
		return;
	int maxn = -2147483648,maxni;
	for(int i = l ; i <= r ; i++)
	{
		if(p[i].val > maxn)
		{
			maxn = p[i].val;
			maxni = i;
		}
			
	}
	
	
	
	
	cnt(l,maxni - 1,depth + 1);
	v.push_back(depth);
	cnt(maxni + 1,r,depth + 1);
	
	
	
}

int main ()
{
	
	int t,n;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		cin >> n;
		v.clear();
		for(int i = 0 ; i < n ; i++)
		{
			cin >> p[i].val;
			p[i].index = i;
		}
		cnt(0,n - 1,0);
		for(int i = 0 ; i < v.size() - 1; i++)
			cout << v[i] << " ";
		cout << v[v.size() - 1] << "\n"; 
	}
	
}
