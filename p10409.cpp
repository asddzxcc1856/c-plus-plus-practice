#include <iostream>
using namespace std;

int n,i;
string str;
 
int main ()
{
	while(cin >> n&&n!=0)
	{
		int f[6] = {1,6,4,3,5,2};
		for (i = 0 ; i < n ; i++)
		{
			cin >> str;
			if(str == "north")
			{
				int temp = f[0];
				f[0] = f[4];
				f[4] = f[1];
				f[1] = f[5];
				f[5] = temp;
				
			}
			else if (str == "south")
			{
				int temp = f[0];
				f[0] = f[5];
				f[5] = f[1];
				f[1] = f[4];
				f[4] = temp;
			}
			else if (str == "west")
			{
				int temp = f[2];
				f[2] = f[1];
				f[1] = f[3];
				f[3] = f[0];
				f[0] = temp;
			}
			else if (str == "east")
			{
				int temp = f[0];
				f[0] = f[3];
				f[3] = f[1];
				f[1] = f[2];
				f[2] = temp;
			}
		}
		cout << f[0] << "\n";
	}
	

    return 0;
}

