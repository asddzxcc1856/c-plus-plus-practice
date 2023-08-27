#include <iostream>
#include <sstream>
#include <vector>
using namespace std;



int main ()
{
	int n;
	cin >> n;
	string str;
	getline(cin,str);
	getline(cin,str);
	for(int k = 0 ; k < n ; k++)
	{
		if(k > 0)
			cout << "\n";
		vector<int> v;
		vector<int> lis;
		vector<int> dp1;
		
		int num;
			
		while(getline(cin,str))
		{
			if(str == "")
				break;
			stringstream ss(str);
			ss >> num;
			v.push_back(num);
		}
		lis.push_back(v[0]);
		dp1.push_back(1);
		for(int i = 1 ; i < v.size() ; i++)
		{
			if(lis.back() < v[i])
			{
				lis.push_back(v[i]);
				dp1.push_back(lis.size());
			}
			else
			{
				vector<int>::iterator pos = lower_bound(lis.begin(),lis.end(),v[i]);
				*pos = v[i];
				dp1.push_back(pos - lis.begin() + 1);
			}
		}
		int ans = 1;
		int idx = 1;
		for(int i = 0 ; i < dp1.size() ; i++)
		{
			if(dp1[i] > ans)
			{
				ans = dp1[i];
				idx = 1;
			}
		} 
		cout << "Max hits: " << ans << "\n";
		if(idx == 1)
		{
			int start = ans;
			vector<int> t;
			for(int i = dp1.size() - 1 ; i >= 0 ; i--)
			{
				if(start == dp1[i])
				{
					t.push_back(v[i]);
					start--;
				}	
			} 
			for(int i = t.size() - 1 ; i >= 0 ; i--)
				cout << t[i] << "\n";
		}
	}
}