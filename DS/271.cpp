#include <iostream>
#include <stack>
using namespace std;

int main ()
{
	string str;
	while(getline(cin,str))
	{
		stack<char> st;
		bool ok = true;
		for(int i = str.length() - 1 ; i >= 0 ; i--)
		{
			if(str[i] >= 'p' && str[i] <= 'z')
			{
				st.push(str[i]);
			}
			else if (str[i] == 'N')
			{
				if(st.size() >= 1)
				{
					st.pop();
					st.push(str[i]);
				}
				else
				{
					ok = false;
					break;
				}
			}
			else if(str[i] == 'C' || str[i] == 'D' || str[i] == 'E' || str[i] == 'I')
			{
				if(st.size() >= 2)
				{
					st.pop();
					st.pop();
					st.push(str[i]);
				}
				else
				{
					ok = false;
					break;
				}
			}
			else
			{
				ok = false;
				break;
			}
		}
		if(st.size() != 1)
		{
			ok = false;
		}
		
		ok == true ? (cout << "YES\n") : (cout << "NO\n");
	}
}