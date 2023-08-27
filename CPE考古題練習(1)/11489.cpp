#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	for(int k = 1; k <= n ; k++)
	{
		string num;
		cin >> num;
		int sum = 0;
		bool now = true;
		vector<int> v0,v1,v2;
		for(int i = 0 ; i < num.length() ; i++)
		{
			int l = (num[i] - '0') % 3;
			if(l == 0)
			{
				v0.push_back(num[i] - 48);
			}
			else if (l == 1)
			{
				v1.push_back(num[i] - 48);
			}
			else
			{
				v2.push_back(num[i] - 48);
			}
			sum += (num[i] - 48);
		}
		while(sum)
		{
			int l = sum % 3;
			if(l == 0)
			{
				if(v0.size() > 0)
				{
					sum -= v0.back();
					v0.pop_back();
			 	} 
			 	else
			 	{
			 		break;
				}
			}
			else if(l == 1)
			{
				if(v1.size() > 0)
				{
					sum -= v1.back();
					v1.pop_back();
				}
				else
				{
					break;
				}
			}
			else if(l == 2)
			{
				if(v2.size() > 0)
				{
					sum -= v2.back();
					v2.pop_back();
				}
				else
				{
					break;
				}
			}
			now = (now == true ? false : true);
		}
		if(now == true)
		{
			cout << "Case " << k << ": T\n";
		}
		else
		{
			cout << "Case " << k << ": S\n";
		}
	}
}