#include <iostream>
#include <stack>
using namespace std;

int main ()
{
	int n;
	while(cin >> n)
	{
		if(n == 0)
		{
			return 0;
		}
		else
		{
			int num;
			while(cin >> num)
			{
				if(num == 0)
				{
					break;
				}
				stack<int> st1,st2;
				for(int i = n ; i >= 1 ; i--)
					st1.push(i);
				bool ok = false;
				while(st1.size() > 0 && st1.top() != num)
				{
					st2.push(st1.top());
					st1.pop();
				}
				if(st1.size() > 0 && st1.top() == num)
				{
					ok = true;
					st1.pop();
				}
				if(ok)
				{
					bool ok2 = true;
					for(int i = 1 ; i < n ; i++)
					{
						cin >> num;
						
						if(ok2)
						{
							ok = false;
							if(st2.size() > 0 && st2.top() == num)
							{
								ok = true;
								st2.pop();
							}
							else
							{
								while(st1.size() > 0 && st1.top() != num)
								{
									st2.push(st1.top());
									st1.pop();
								}
								if(st1.size() > 0 && st1.top() == num)
								{
									ok = true;
									st1.pop();
								}	
							}
							
						}
						if(ok == false)
						{
							ok2 = false;
						}
					}
					
					if(ok2)
					{
						cout << "Yes\n";
					}
					else
					{
						cout << "No\n";
					}
				}
				else
				{
					for(int i = 1 ; i < n ; i++)
					{
						cin >> num;
					}
					cout << "No\n";
				}
				
			}
			cout << "\n";
		}
	}
}