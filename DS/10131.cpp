#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct elephant{
	int weight;
	int IQ;
	int idx;
};

bool cmp(elephant a,elephant b)
{
	if(a.IQ == b.IQ && a.weight == b.weight)
		return a.idx < b.idx;
	else if (a.weight == b.weight && a.IQ != b.IQ)
		return a.IQ > b.IQ;
	else if (a.weight != b.weight && a.IQ == b.IQ)
		return a.weight < b.weight;
	else
		return a.weight < b.weight;
}

int pre[100005];
int dp[100005];
int res;
int p;
vector<elephant> E;

void cnt(int n);

int main ()
{
	
	int a,b,index = 1;
	while(cin >> a >> b)
	{
		elephant e = {a,b,index++};
		E.push_back(e);
	}
	sort(E.begin(),E.end(),cmp);
	for(int i = 0 ; i <= E.size() ; i++)
	{
		dp[i] = 1;
	}
	res = 0; 
	for(int i = 0 ; i < E.size() ; i++)
	{
		for(int j = 0 ; j < i ; j++)
		{
			if(E[i].weight > E[j].weight && E[i].IQ < E[j].IQ)
			{
				if(dp[i] < dp[j] + 1)
				{
					pre[i] = j;
					dp[i] = dp[j] + 1;
				}
				
			}
		}
		if(res < dp[i])
		{
			res = dp[i];
			p = i;
		}
		
	}
	cout << res << "\n";
	cnt(p);
	return 0;
}

void cnt(int n)
{
	if(res--)
	{
		cnt(pre[n]);
		cout << E[n].idx << "\n";
	}
}