#include <iostream>
#include <queue>
using namespace std;

vector<pair<int,int>> v[10005];
int dis[10005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int L,U,R;
int main ()
{
	int times = 1;
	while(cin >> L >> U >> R)
	{
		if(L == 0 && U == 0 && R == 0)
		{
			return 0;
		}
		//build path
		for(int i = 0 ; i < 10005 ; i++)
		{
			v[i].clear();
		}
		for(int i = 0 ; i < R ; i++)
		{
			int num;
			cin >> num;
			for(int j = 0 ; j <= 9999 ; j++)
			{
				v[j].push_back({1,(j + num) >= 10000 ? (j + num - 10000) : (j + num)});
			}
		}
		//Dijkstra's algorithm
		for(int i = 0 ; i < 10005 ; i++)
		{
			dis[i] = 1e9;
		}
		pq.push({0,L});
		dis[L] = 0;
		while(!pq.empty()){
			pair<int,int> p = pq.top();
			pq.pop();
			for(pair<int,int> nxt : v[p.second]){
				if(dis[nxt.second] > dis[p.second] + nxt.first){
					dis[nxt.second] = dis[p.second] + nxt.first;
					pq.push({dis[nxt.second],nxt.second});
				}
			}
		}
		if(dis[U] != 1e9)
			cout << "Case " << times++ << ": " << dis[U] << "\n";
		else
			cout << "Case " << times++ << ": " << "Permanently Locked\n";
	}
}