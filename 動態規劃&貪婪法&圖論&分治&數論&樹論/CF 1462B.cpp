#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for(int w = 0 ; w < t ; w++)
	{
		int len;
		cin >> len;
		string str;
		cin >> str;
		bool f = false;
		for(int i = 0 ; i < str.length() - 3 ; i++)
		{
			if(str[i] == '2')
			{
				for(int j = i + 1 ; j < str.length() - 2 ; j++)
				{
					if(str[j] == '0')
					{
						for(int k = j + 1 ; k < str.length() - 1; k++)
						{
							if(str[k] == '2')
							{
								for(int q = k + 1 ; q < str.length() ; q++)
								{
									if(str[q] == '0')
									{
										int cnt = 0;
										if(i + 1 > 1)
											cnt++;
										if(j - i > 1)
											cnt++;
										if(k - j > 1)
											cnt++;
										if(q - k > 1)
											cnt++;
										if(str.length() - q > 1)
											cnt++;
										if(cnt <= 1)
										{
											f = true;						
										}
									}
								}
							}
						}	
					}	
				}	
			}	
		} 
		if(f)
			cout << "YES\n";
		else
			cout << "NO\n"; 
	}	
} 
