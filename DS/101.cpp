#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	int lo[30];
	for(int i = 0 ; i < 30 ; i++)
	{
		lo[i] = i;
	}
	stack<int> st[30];
	for(int i = 0 ; i < 30 ; i++)
	{
		st[i].push(i);
	}
	string str1,str2;
	int num1,num2;
	while(cin >> str1)
	{
		if(str1 == "quit")
		{
			break;
		}
		else
		{
			cin >> num1 >> str2 >> num2;
			if(lo[num1] == lo[num2] || num1 == num2)
				continue;
			if(str1 == "move")
			{
				if(str2 == "onto")
				{
					while(st[lo[num1]].top() != num1) //a
					{
						st[st[lo[num1]].top()].push(st[lo[num1]].top());
						lo[st[lo[num1]].top()] = st[lo[num1]].top();
						st[lo[num1]].pop();
					}
					while(st[lo[num2]].top() != num2) //b
					{
						st[st[lo[num2]].top()].push(st[lo[num2]].top());
						lo[st[lo[num2]].top()] = st[lo[num2]].top();
						st[lo[num2]].pop();
					}
					st[lo[num2]].push(num1);
					st[lo[num1]].pop();
					lo[num1] = lo[num2];
				}
				else
				{
					while(st[lo[num1]].top() != num1) //a
					{
						st[st[lo[num1]].top()].push(st[lo[num1]].top());
						lo[st[lo[num1]].top()] = st[lo[num1]].top();
						st[lo[num1]].pop();
					}
					st[lo[num2]].push(num1);
					st[lo[num1]].pop();
					lo[num1] = lo[num2];
				}
			}
			else
			{
				if(str2 == "onto")
				{
					stack<int> tmp;
					while(st[lo[num1]].top() != num1) //a
					{
						tmp.push(st[lo[num1]].top());
						st[lo[num1]].pop();
					}
					while(st[lo[num2]].top() != num2) //b
					{
						st[st[lo[num2]].top()].push(st[lo[num2]].top());
						lo[st[lo[num2]].top()] = st[lo[num2]].top();
						st[lo[num2]].pop();
					}
					st[lo[num2]].push(num1);
					st[lo[num1]].pop();
					lo[num1] = lo[num2];
					while(!tmp.empty())
					{
						st[lo[num2]].push(tmp.top());
						lo[tmp.top()] = lo[num2];
						tmp.pop();
					}
				}
				else
				{
					stack<int> tmp;
					while(st[lo[num1]].top() != num1) //a
					{
						tmp.push(st[lo[num1]].top());
						st[lo[num1]].pop();
					}
					st[lo[num2]].push(num1);
					st[lo[num1]].pop();
					lo[num1] = lo[num2];
					while(!tmp.empty())
					{
						st[lo[num2]].push(tmp.top());
						lo[tmp.top()] = lo[num2];
						tmp.pop();
					}
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++)
	{
		cout << i << ":";
		vector<int> v;
		while(!st[i].empty())
		{
			v.push_back(st[i].top());
			st[i].pop();
		}
		for(int i = v.size() - 1; i >= 0 ; i--)
		{
			cout << " " << v[i];
		}
		cout << "\n";
	}
}