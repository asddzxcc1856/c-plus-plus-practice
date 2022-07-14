#include <iostream>
#include <stack>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n;
		cin >> n;
		string tmp;
		getline(cin,tmp);
		stack<string> original,required;
		for(int i = 0 ; i < n ; i++)
		{
			getline(cin,tmp);
			original.push(tmp);
		}
		for(int i = 0 ; i < n ; i++)
		{
			getline(cin,tmp);
			required.push(tmp);
		}
		while(!original.empty())
		{
			if(original.top() == required.top())
			{
				original.pop();
				required.pop();
			}
			else
			{
				original.pop();
			}
		}
		while(!required.empty())
		{
			cout << required.top() << "\n";
			required.pop();
		}
		cout << "\n";
	}
}