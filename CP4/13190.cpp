#include <iostream>
#include <queue>
using namespace std;

struct node{
	string name;
	int val;
	int val2;
	int op;
	bool operator<(const node &b)const {
		if(val != b.val)
			return val > b.val;
		else
			return op > b.op;
	}
};

int main ()
{
	int t;
	cin >> t;
	for(int K = 0 ; K < t ; K++)
	{
		int n,k;
		cin >> n >> k;
		priority_queue<node> pq;
		priority_queue<node> pq2;
		for(int i = 0 ; i < n ; i++)
		{
			string str;
			int tmp;
			cin >> str >> tmp;
			node p;
			p.name = str;
			p.val = tmp;
			p.val2 = tmp;
			p.op = i;
			pq.push(p);
		}	
		int now = 0;
		int minn = pq.top().val;
		now += minn;
		int i = 0;
		while(!pq.empty() && i < k)
		{
			node p = pq.top();
			
			p.val -= minn;
			if(p.val != 0)
			{
				minn += p.val;
				now += p.val;
			}
			//cout << "minn" << minn << "\n";
			cout << now << " " << p.name << "\n";
			p.val = p.val2 + now;	
			pq.push(p);
			i++;
			pq.pop();
		}
	}	
} 
