#include <iostream>
#include <set>
using namespace std;

string str;
int ans2;

void cnt(int l,int r,char now,int ans)
{
	//cout << l << " " << r << "\n";
	if(l>=r)
	{
		if(l == r)
			if(now != str[l])
			{
				ans++;
				//cout << now << "\n";
			}
		ans2 = min(ans2,ans);
		return;
	}
	int mid = (l + r) >> 1;
	int temp1 = ans;
	for(int i = l ; i <= mid; i++)
	{
		if(str[i] != now)
		{
			temp1++;
				//cout << l << " " << r << " " << now << "\n";
		}
	}
		
	int temp2 = ans;
	cnt(mid + 1,r,now + 1,temp1);
	for(int i = mid + 1 ; i <= r; i++)
	{
		if(str[i] != now)
		{
			temp2++;
			//cout << l << " " << r << " " << now << "\n";
		}
	}
	cnt(l,mid,now + 1,temp2);
}

int main ()
{
	int t,len;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		cin >> len;
		cin >> str;
		ans2 = 2147483647;
		cnt(0,len - 1,'a',0);
		cout << ans2 << "\n";
	}
	
}
