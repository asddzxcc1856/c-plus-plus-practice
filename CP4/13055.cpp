#include <iostream>
#include <stack>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	stack<string> st;
	string tmp;
	string name;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> tmp;
		if(tmp == "Sleep")
		{
			cin >> name;
			st.push(name);
		}
		else if (tmp == "Kick")
		{
			if(!st.empty())
				st.pop();
		}
		else if (tmp == "Test")
		{
			if(!st.empty())
				cout << st.top() << "\n";
			else
				cout << "Not in a dream\n";
		}
		
	}
}
