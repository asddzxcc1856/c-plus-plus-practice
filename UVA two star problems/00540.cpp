#include <iostream>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

int main ()
{
	int n;
	int times = 1;
	int inteam[1005];
	while(cin >> n,n)
	{
		cout << "Scenario #" << times++ << "\n";
		queue<int> team,in[1005];
		map<int,int> m;
		memset(inteam,0,sizeof(inteam));
		for(int i = 0 ; i < n ; i++)
		{
			int num;
			cin >> num;
			for(int j = 0 ; j < num ; j++)
			{
				int num2;
				cin >> num2;
				m[num2] = i;
			}
		}
		string str;
		while(cin >> str && str != "STOP")
		{
			if(str == "ENQUEUE")
			{
				int num3;
				cin >> num3;
				if(inteam[m[num3]] == 0)
				{
					team.push(m[num3]);
					inteam[m[num3]] = 1;
				}
					
				in[m[num3]].push(num3);
			}
			else if (str == "DEQUEUE")
			{
				cout << in[team.front()].front() << "\n";
				in[team.front()].pop();
				if(in[team.front()].size() == 0)
				{
					inteam[team.front()] = 0;
					team.pop();
					
				}
					
			}
		}
		cout << "\n";
	}
	
}
