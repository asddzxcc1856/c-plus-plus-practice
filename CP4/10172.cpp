#include <iostream>
#include <queue>
#include <stack>
using namespace std;



int main ()
{
	int s,N,S,Q;
	cin >> s;
	for(int k = 0 ; k < s ; k++)
	{
		cin >> N >> S >> Q;
		queue<int> B[N];
		for(int i = 0 ; i < N ; i++)
		{
			int number;
			cin >> number;
			for(int j = 0 ;j < number ; j++)
			{
				int dest;
				cin >> dest;
				B[i].push(dest);
			}
		}	
		int cost = 0;
		stack<int> ca;
		// 0 1 2 3 4 ... N - 1 is ring
		
		for(int i = 0 ; ; i = (i + 1)%N)
		{
			//unload
			while(((!ca.empty()) && B[i].size() != Q) || (!ca.empty() && ca.top() == i + 1))
			{
				if(ca.top() == i + 1)
				{
					ca.pop();
				}
				else
				{
					B[i].push(ca.top());
					ca.pop();	
				}
				cost++;
			}
			//load
			while(ca.size() != S && (!B[i].empty()))
			{
				ca.push(B[i].front());
				B[i].pop();
				cost++;
			}
			//go
			bool ok = false;
			for(int j = 0 ; j < N ; j++)
			{
				if(!B[j].empty())
				{
					ok = true;
				}
			}
			if(!ca.empty())
			{
				ok = true;
			}
			if(ok == false)
			{
				break;
			}
			cost += 2;
		}
		cout << cost << "\n";
	}	
} 
