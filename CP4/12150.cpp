#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n,n)
	{
		vector<int> v(n);
		bool ok = false;
		for(int i = 0 ; i < n ; i++)
		{
			int a,b;
			cin >> a >> b;
			if(i + b >= 0 && i + b < n && v[i + b] == 0)
				v[i + b] = a;
			else
				ok = true;
		}
		if(ok)
		{
			cout << "-1\n";
		}
		else
		{
			for(int i = 0 ; i < n - 1; i++)
			{
				cout << v[i] << " ";
			}
			cout << v[n - 1] << "\n";
		}
	}
} 
