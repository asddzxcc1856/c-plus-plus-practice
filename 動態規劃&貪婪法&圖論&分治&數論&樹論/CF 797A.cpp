#include <iostream>
#include <queue>
using namespace std;



int main ()
{
	int n,k;
	cin >> n >> k;
	queue<int> q;
	for(int i = 2 ; i <= n ; i++)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
			{
				q.push(i);
				n /= i;
			}
			
		}
	}
	if(q.size() >= k)
	{
		while(q.size() > k)
		{
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			q.push(a * b);
		}
		while(!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
	}
	else
	{
		cout << "-1\n";
	}
	
}