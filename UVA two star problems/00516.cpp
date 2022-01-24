#include <iostream>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;

bool isp(int n)
{
	if(n == 2)
		return true;
	else
	{
		for(int i = 2 ; i * i <= n ; i++)
		{
			if(n%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main ()
{
	int p[5000],maxl = 0;
	for(int i = 2 ; i < 32767 ; i++)
	{
		if(isp(i))
		{
			p[maxl++] = i;
		}
	}
	string str;
	while(getline(cin,str)&&str != "0")
	{
		stack<int> st;
		stringstream ss(str);
		int num;
		int sum = 1;
		while(ss >> num)
		{
			st.push(num);
			if(st.size() == 2)
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				sum *= pow(num2,num1);
			}
		}
		sum -= 1;
		for(int i = maxl - 1 ; i >= 0 ; i--)
		{
			if(p[i]>sum)
				continue;
			else if (sum%p[i] == 0)
			{
				int times = 0;
				while(sum%p[i] == 0)
				{
					sum/=p[i];
					times++;	
				}
				cout << p[i] << " " << times;
				if(sum != 1)
					cout << " ";
			}
		}
		cout << "\n";
	}
}
