#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main ()
{
	int n;
	
	while(cin >> n,n)
	{
		int stop = 1;
		while(stop)
		{
			queue<int> q;
			stack<int> st;
			for(int i = 0 ; i < n ; i++)
			{
				int num;
				cin >> num;
				if(num == 0)
				{
					stop = 0;
					break;
				}
				q.push(num);
			}
			if(stop == 0)
			{
				break;
			}
			for(int i = 1 ; i <= n ; i++)
			{
				
				st.push(i);
				while(st.size() > 0 && q.front() == st.top())
				{
					st.pop();
					q.pop();
				}
			}
			if(q.size() == 0)
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
		cout << "\n";
	}	
} 
