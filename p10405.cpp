#include <iostream>
#include <map>
using namespace std;

map<char,string> ma;
int n,k,i,j,num[10],cnt[10];
string str,t;

int main ()
{
	ma['c'] = "0111001111";
	ma['d'] = "0111001110";
	ma['e'] = "0111001100";
	ma['f'] = "0111001000";
	ma['g'] = "0111000000";
	ma['a'] = "0110000000";
	ma['b'] = "0100000000";
	ma['C'] = "0010000000";
	ma['D'] = "1111001110";
	ma['E'] = "1111001100";
	ma['F'] = "1111001000";
	ma['G'] = "1111000000";
	ma['A'] = "1110000000";
	ma['B'] = "1100000000";
	cin >> n;
	getline(cin,str);
	for(k = 0 ; k < n ; k++)
	{
		getline(cin,str);
		for(i = 0 ; i < 10 ; i++)
		{
			num[i] = 0;
			cnt[i] = 0;
		}
		for(i = 0 ; i < str.length() ; i++)
		{
			t = ma[str[i]];
			for(j = 0 ; j < t.length() ; j++)
			{
				if(num[j] == 1 && t[j] == '0')
				{
					num[j] = 0;
				}
				else if (num[j] == 0 && t[j] == '1')
				{
					num[j] = 1;
					cnt[j]++;
				}
			}
		}
		for(i = 0 ; i < 9 ; i++)
		{
			cout << cnt[i] << " ";
		}
		cout << cnt[9] << "\n";
	}
	
	
    return 0;
}

