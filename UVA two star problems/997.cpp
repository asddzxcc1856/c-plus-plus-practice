#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

string str;
int num;
stack<char> st2;
stack<int> st1;
bool first;
int c[55],t[55];

int main ()
{
	while(cin >> str)
	{
		cin >> num;
		while(!st2.empty())
		{
			st2.pop();
		}
		while(!st1.empty())
		{
			st1.pop();
		}
		first = true;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == ']')
			{
				if(first)
				{
					int sum = st1.top();
					st1.pop();
					for(int j = 0 ; j < num ; j++)
					{
						c[j] = sum;						
					}
					first = false;
				}
				else if(st2.top() == '+')
				{
					int sum = st1.top();
					st1.pop();
					st2.pop();
					t[0] = sum;
					for(int j = 1 ; j < num ; j++)
					{
						t[j] = t[j - 1] + c[j - 1];						
					}
					for(int j = 0 ; j < num ; j++)
					{
						c[j] = t[j];
					}
				}
				else if(st2.top() == '*')
				{
					int sum = st1.top();
					st1.pop();
					st2.pop();
					t[0] = sum * c[0];
					for(int j = 1 ; j < num ; j++)
					{
						t[j] = t[j - 1] * c[j];						
					}
					for(int j = 0 ; j < num ; j++)
					{
						c[j] = t[j];
					}
				}
			}
			else if(str[i] == '+' || str[i] == '*')
			{
				st2.push(str[i]);
			}
			else if(str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			{
				int sign = 1;
				int sum = 0;
				if(str[i] == '-')
				{
					sign = -1;
					i++;
				}
				for(; i < str.length() ; i++)
				{
					if(str[i] >= '0' && str[i] <= '9')
					{
						sum = sum * 10 + str[i] - 48;
					}
					else
					{
						break;
					}
				}
				i--;
				st1.push(sign * sum);
			}
		}
		for(int j = 0 ; j < num - 1 ; j++)
		{
			cout << c[j] << " ";	
		}	
		cout << c[num - 1] << "\n";
	}
}
