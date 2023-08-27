#include <iostream>
#include <queue>
using namespace std;

struct node{
	int num;
	int sec;	
};
struct cmp{
	bool operator()(node a,node b){
		if(a.sec != b.sec)
			return a.sec > b.sec;
		else
			return a.num > b.num;
	}
};

int main ()
{
	priority_queue<node,vector<node>,cmp> pq,pq2;
	int num,sec,id[3001];
	string str;
	while(cin >> str)
	{
		if(str == "#")
		{
			break;
		}
		cin >> num >> sec;
		node tmp;
		tmp.num = num;
		tmp.sec = sec;
		id[num] = sec;
		pq.push(tmp);
	}
	int n,cnt = 0;
	cin >> n;
	while(cnt != n)
	{
		int minn = pq.top().sec;
		while(!pq.empty())
		{
			if(pq.top().sec == minn)
			{
				cout << pq.top().num << "\n";
				node tmp = pq.top();
				tmp.sec = id[tmp.num];
				pq2.push(tmp);
				pq.pop();
				cnt++;
			}
			else
			{
				node tmp = pq.top();
				tmp.sec -= minn;
				pq2.push(tmp);
				pq.pop();
			}
			
		}
		while(!pq2.empty())
		{
			pq.push(pq2.top());
			pq2.pop();
		}
	}
} 
