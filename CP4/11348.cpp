#include <iostream>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

map<int,int> ma;


int main ()
{
	int K;
	cin >> K;
	for(int k = 1 ; k <= K ; k++)
	{
		int N,st[51][51];
		cin >> N;
		for(int i = 0 ; i < N ; i++)
		{
			int M;
			cin >> M;
			st[i][0] = M;
			set<int> s;
			for(int j = 1 ; j <= M ; j++)
			{
				int tmp;
				cin >> tmp;
				if(s.find(tmp) == s.end())
				{
					s.insert(tmp);
					ma[tmp]++;
					st[i][j] = tmp;
				}
				else
					st[i][j] = -1;
			}
		}
		int ans[51] = {};
		int all = 0;
		for(int i = 0 ; i < N ; i++)
		{
			int M = st[i][0];
			for(int j = 1 ; j <= M ; j++)
			{
				if(st[i][j] != -1 && ma[st[i][j]] == 1)
				{
					ans[i]++;
					all++;
				}
			}
		}
		cout << "Case " << k << ":";
		for(int i = 0 ; i < N ; i++)
		{
			cout << " " << fixed << setprecision(6) << (double)ans[i] / all * 100 << "%";
		}
		cout << "\n";
		ma.clear();
	}
}
