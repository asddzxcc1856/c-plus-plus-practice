#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	string str;
	int times = 1;
	while(cin >> str)
	{
		if(str == "end")
		{
			break;
		}
		else
		{
			vector<int> st(1);
			st[0] = 1e9;
			for(int i = 0 ; i < str.length() ; i++)
			{
				int idx = -1;
				int minn = 2147483647;
				for(int j = 0 ; j < st.size() ; j++)
				{
					if(st[j] > str[i] && minn > st[j])
					{
						idx = j;
						minn = st[j];
					}
					else if (st[j] == str[i] && minn > st[j])
					{
						idx = j;
						minn = st[j];
					}
				}
				if(idx == -1)
				{
					st.push_back(str[i]);
				}
				else
				{
					st[idx] = str[i];
				}
			}
			cout << "Case " << times++ << ": " << st.size() << "\n";
		}
	}
}
