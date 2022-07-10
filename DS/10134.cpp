#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	string str;
	getline(cin,str);
	getline(cin,str);
	for(int k = 1 ; k <= t ; k++)
	{
		int t1 = 0,t2 = 0,t3 = 0,fish = 0,bait = 0; 
		//t1 for bait 2 a round
		//t2 for (1)fish 3 a round
		//t3 for (2)fish 6 a round 
		
		while(getline(cin,str))
		{
			if(str == "")
				break;
			if(str == "fish")
			{
				if((bait >= 1 && fish >= 1 && t2 >= 2 && t3 >= 6)||(bait >= 1 && fish == 0))
				{
					fish++;
					bait--;
					t2 = 0;
					t3 = 0;
				}
				else if (bait >= 1 && fish >= 1)
				{
					t2++;
					t3++;
				}
				else if (fish >= 1)
				{
					t3++;
				}
			}
			else if (str == "bait")
			{
				if(bait < 3)
				{
					if(t1 == 1)
					{
						bait++;
						t1 = 0;
						if (fish >= 1)
						{
							t3++;
						}
					}
					else
					{
						t1++;
						if (fish >= 1)
						{
							t3++;
						}
					}
				}
				else if (fish >= 1)
				{
					t3++;
				}
			}
			else if (str == "lunch")
			{
				if (fish >= 1)
				{
					t3++;
				}	
			}
		}
		cout << fish << "\n";
		if(k != t)
			cout << "\n";
	}
}