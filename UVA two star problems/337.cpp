#include <iostream>
using namespace std;



int main ()
{
	int n,times = 1;
	string str;
	while(cin >> n)
	{
		getline(cin,str);
		if(n == 0)
			return 0;
		int nr = 1,nc = 1,mod = 2;
		string s[12] = {"+----------+","|          |","|          |","|          |","|          |","|          |","|          |","|          |","|          |","|          |","|          |","+----------+"};
		string s2[12] = {"+----------+","|          |","|          |","|          |","|          |","|          |","|          |","|          |","|          |","|          |","|          |","+----------+"};
		for(int k = 0 ; k < n ; k++)
		{
			getline(cin,str);
			for(int i = 0 ; i < str.length() ; i++)
			{
				if(str[i] == '^')
				{
					i++;
					if(str[i] == '^')
					{
						if(mod == 1)
						{
							for (int j = 10 ; j > nc ; j--)
							{
								s[nr][j] = s[nr][j - 1];
							}
							s[nr][nc] = str[i];
						}
						else if (mod == 2)
						{
							s[nr][nc] = str[i];
						}
						if(nc + 1 <= 10)
						nc+=1;
					}
					else if (str[i] == 'b')//ok
					{
						nc = 1;
					}
					else if (str[i] == 'c')//ok
					{
						for(int i = 0 ; i < 12 ; i++)
						{
							s[i] = s2[i];
						}
					}
					else if (str[i] == 'd')//ok
					{
						if(nr + 1 <= 10)
							nr += 1;
					}
					else if (str[i] == 'e')//ok
					{
						for(int j = nc ; j <= 9 ; j++)
						{
							s[nr][j] = ' ';
						}
					}
					else if (str[i] == 'h')//ok
					{
						nc = 1;
						nr = 1;
					}
					else if(str[i] == 'i')//ok
					{
						mod = 1;
					}
					else if (str[i] == 'l')//ok
					{
						if(nc - 1 >= 1)
							nc -= 1;
					}
					else if (str[i] == 'o')
					{
						mod = 2;
					}
					else if (str[i] == 'r')//ok
					{
						if(nc + 1 <= 10)
							nc += 1;
					}
					else if (str[i] == 'u')//ok
					{
						if(nr - 1 >=1)
							nr -= 1;
					}
					else if ((str[i]>='0' && str[i] <='9') || (str[i+1]>='0' && str[i+1] <='9'))//ok
					{
						nr = str[i] - '0' + 1;
						nc = str[i + 1] - '0' + 1;
						i++;
					}
				}
				else
				{
					if(mod == 1)
					{
						for (int j = 10 ; j > nc ; j--)
						{
							s[nr][j] = s[nr][j - 1];
						}
						s[nr][nc] = str[i];
					}
					else if (mod == 2)
					{
						s[nr][nc] = str[i];
					}
					if(nc + 1 <= 10)
						nc+=1;
				}
			
			}
			
		}
		cout << "Case " << times++ <<"\n";
		for(int w = 0 ; w <= 11 ; w++)
			{
				for (int e = 0 ; e <= 11 ; e++)
				{
					cout << s[w][e]; 
				}
				cout << "\n";
			}
	}
}
