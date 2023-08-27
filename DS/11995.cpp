#include <iostream>
#include <queue>
#include <stack>
using namespace std;


int main ()
{
	int n;
	while(cin >> n)
	{
	
		stack<int> st;
		queue<int> q;	
		priority_queue<int> pq;
		bool t1,t2,t3;
		t1 = t2 = t3 = true;
		for(int i = 0 ; i < n ; i++)
		{
			int a,b;
			cin >> a >> b;
			if(t1)//st
			{
				if(a == 1)
				{
					st.push(b);
				}
				else if (st.size() > 0)
				{
					int now = st.top();
					st.pop();
					if(now != b)
					{
						t1 = false;
					}
				}
				else
				{
					t1 = false;
				}
			}
			if(t2)//q
			{
				if(a == 1)
				{
					q.push(b);
				}
				else if (q.size() > 0)
				{
					int now = q.front();
					q.pop();
					if(now != b)
					{
						t2 = false;
					}
				}
				else
				{
					t2 = false;
				}
			}
			if(t3)//pq
			{
				if(a == 1)
				{
					pq.push(b);
				}
				else if (pq.size() > 0)
				{
					int now = pq.top();
					pq.pop();
					if(now != b)
					{
						t3 = false;
					}
				}
				else
				{
					t3 = false;
				}
			}
		}
		if((t1 && t2) || (t2 && t3) || (t1 && t3))
		{
			cout << "not sure\n";
		}
		else if (t1)
		{
			cout << "stack\n";
		}
		else if (t2)
		{
			cout << "queue\n";
		}
		else if (t3)
		{
			cout << "priority queue\n";
		}
		else
		{
			cout << "impossible\n";
		}
	}	
}