#include <iostream>
#include <cmath>
using namespace std;

int n;
string str;
int sign,xnum,num;
int main ()
{
	cin >> n;
	getline(cin,str);
	for(int k = 0 ; k < n ; k++)
	{
		getline(cin,str);
		sign = 1;
		xnum = 0;
		num = 0;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == '=')
			{
				sign = -1;
			}
			else if(str[i] == 'x' ||str[i] == '-' ||(str[i] >= '0' && str[i] <= '9'))
			{
				int sum = 0;
				bool ne = false;
				if(str[i] == '-')
				{
					ne = true;
					i++;
				}
				for(; i < str.length() && str[i] >= '0' && str[i] <= '9'; i++)
				{
					if(str[i] >= '0' && str[i] <= '9')
						sum = sum * 10 + str[i] - 48;
					else
						break;
				}
						
				if(str[i] == 'x')
				{
					if(sum == 0)
					{
						if(i == 0||(i>1 && str[i - 1] != '0'))	
							sum = 1;
					}
					if(ne == true)
					{
						sum = -sum;
					}
					xnum += sign * sum;
				}
				else
				{
					if(ne == true)
					{
						sum = -sum;
					}
					num += sign * sum;
					i--;
				}
			}
		}
		if(num == 0 && xnum == 0)
		{
			cout << "IDENTITY\n"; 
		}
		else if (num != 0 && xnum == 0)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout <<  (int)floor(-1 * (double)num/xnum) << "\n";
		}
	}
}

