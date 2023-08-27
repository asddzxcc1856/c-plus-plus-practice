#include <iostream>
#include <stack>
using namespace std;

int main ()
{
	
	int t; 
	cin >> t;
	string str;
	getline(cin,str);
	for(int k = 1 ; k <= t ; k++)
	{
		getline(cin,str);
		stack<char> st;
		bool ok = true;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == '(' || str[i] == '[')
			{
				st.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if(st.size() > 0 && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					ok = false;
					break;
				}
			}
			else if (str[i] == ']')
			{
				if(st.size() > 0 && st.top() == '[')
				{
					st.pop();
				}
				else
				{
					ok = false;
					break;
				}
			}
		}
		if(st.size() > 0)
			ok = false;
		ok == true ? (cout << "Yes\n") : (cout << "No\n");
	}
}