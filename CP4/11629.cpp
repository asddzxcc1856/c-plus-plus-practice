#include <iostream>
#include <map>
using namespace std;

int main ()
{
	int p,g;
	while(cin >> p >> g)
	{
		map<string,int> ma;
		ma.insert({"+",0});
		for(int i = 0 ; i < p ; i++)
		{
			string tmp1;
			double tmp2;
			cin >> tmp1 >> tmp2;
			ma.insert({tmp1,tmp2*10});
		}
		for(int i = 0 ; i < g ; i++)
		{
			string tmp1;
			int sum = 0;
			int num;
			while(cin >> tmp1)
			{
				if(tmp1 == "<" || tmp1 == "<=" || tmp1 == ">=" || tmp1 == ">" || tmp1 == "=")
				{
					cin >> num;
					if(tmp1 == "<")
					{
						if(sum < num * 10)
						{
							cout << "Guess #" << i + 1 << " was correct.\n";
						}
						else
						{
							cout << "Guess #" << i + 1 << " was incorrect.\n";
						}
					}
					else if (tmp1 == "<=")
					{
						if(sum <= num * 10)
						{
							cout << "Guess #" << i + 1 << " was correct.\n";
						}
						else
						{
							cout << "Guess #" << i + 1 << " was incorrect.\n";
						}
					}
					else if (tmp1 == ">=")
					{
						if(sum >= num * 10)
						{
							cout << "Guess #" << i + 1 << " was correct.\n";
						}
						else
						{
							cout << "Guess #" << i + 1 << " was incorrect.\n";
						}
					}
					else if (tmp1 == ">")
					{
						if(sum > num * 10)
						{
							cout << "Guess #" << i + 1 << " was correct.\n";
						}
						else
						{
							cout << "Guess #" << i + 1 << " was incorrect.\n";
						}
					}
					else if (tmp1 == "=")
					{
						if(sum == num * 10)
						{
							cout << "Guess #" << i + 1 << " was correct.\n";
						}
						else
						{
							cout << "Guess #" << i + 1 << " was incorrect.\n";
						}
					}
					break;
				}
				else
				{
					sum += ma[tmp1];
				}
			}
			
		}
	}
}
