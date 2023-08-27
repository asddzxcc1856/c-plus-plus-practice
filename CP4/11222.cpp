#include <iostream>
#include <algorithm>
using namespace std;

int a,b,c;
int n1[1001],n2[1001],n3[1001];
int tmp1[1001],tmp2[1001],tmp3[1001];

int main()
{
	int n;
	cin >> n;
	for(int k = 1 ; k <= n ; k++)
	{
		
		cin >> a;
		for(int i = 0 ; i < a ; i++)
		{
			cin >> n1[i];
		}	
		cin >> b;
		for(int i = 0 ; i < b ; i++)
		{
			cin >> n2[i];
		}
		cin >> c;
		for(int i = 0 ; i < c ; i++)
		{
			cin >> n3[i];
		}
		//sorting
		sort(n1,n1 + a);
		sort(n2,n2 + b);
		sort(n3,n3 + c);
		//remove duplicated
		for(int i = 0 ; i < a - 1 ; i++)
			if(n1[i] == n1[i + 1])
				n1[i] = -1;
		for(int i = 0 ; i < b - 1 ; i++)
			if(n2[i] == n2[i + 1])
				n2[i] = -1;
		for(int i = 0 ; i < c - 1 ; i++)
			if(n3[i] == n3[i + 1])
				n3[i] = -1;
		//copy original
		for(int j = 0 ; j < a ; j++)
			tmp1[j] = n1[j];
		for(int j = 0 ; j < b ; j++)
			tmp2[j] = n2[j];
		for(int j = 0 ; j < c ; j++)
			tmp3[j] = n3[j];
		//compare each other
		for(int i = 0 ; i < a ; i++)
		{
			
			for(int j = 0 ; j < b ; j++)
			{
				if(tmp1[i] == tmp2[j])
				{
					n1[i] = -1;
					n2[j] = -1;
				}
			}
		}
		for(int i = 0 ; i < a ; i++)
		{
			for(int j = 0 ; j < c ; j++)
			{
				if(tmp1[i] == tmp3[j])
				{
					n1[i] = -1;
					n3[j] = -1;
				}
			}
		}
		for(int i = 0 ; i < b ; i++)
		{
			for(int j = 0 ; j < c ; j++)
			{
				if(tmp2[i] == tmp3[j])
				{
					n2[i] = -1;
					n3[j] = -1;
				}
			}
		}
		//count only one solve problem
		int cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 0 ; i < a ; i++)
			if(n1[i] != -1)
				cnt1++;
		for(int i = 0 ; i < b ; i++)
			if(n2[i] != -1)
				cnt2++;
		for(int i = 0 ; i < c ; i++)
			if(n3[i] != -1)
				cnt3++;
		//print out the first place friend
		cout << "Case #" << k << ":\n"; 
		if(cnt1 == cnt2 && cnt2 == cnt3)
		{
			cout << "1 " << cnt1;
			for(int i = 0 ; i < a ; i++)
				if(n1[i] != -1)
					cout << " " << n1[i];
			cout << "\n";
			cout << "2 " << cnt2;
			for(int i = 0 ; i < b ; i++)
				if(n2[i] != -1)
					cout << " " << n2[i];
			cout << "\n";
			cout << "3 " << cnt3;
			for(int i = 0 ; i < c ; i++)
				if(n3[i] != -1)
					cout << " " << n3[i];
			cout << "\n";
		} 
		else if(cnt3 < cnt1 && cnt1 == cnt2)
		{
			cout << "1 " << cnt1;
			for(int i = 0 ; i < a ; i++)
				if(n1[i] != -1)
					cout << " " << n1[i];
			cout << "\n";
			cout << "2 " << cnt2;
			for(int i = 0 ; i < b ; i++)
				if(n2[i] != -1)
					cout << " " << n2[i];
			cout << "\n";
		}
		else if (cnt2 < cnt1 && cnt1 == cnt3)
		{
			cout << "1 " << cnt1;
			for(int i = 0 ; i < a ; i++)
				if(n1[i] != -1)
					cout << " " << n1[i];
			cout << "\n";
			cout << "3 " << cnt3;
			for(int i = 0 ; i < c ; i++)
				if(n3[i] != -1)
					cout << " " << n3[i];
			cout << "\n";
		}
		else if (cnt1 < cnt2 && cnt2 == cnt3)
		{
			cout << "2 " << cnt2;
			for(int i = 0 ; i < b ; i++)
				if(n2[i] != -1)
					cout << " " << n2[i];
			cout << "\n";
			cout << "3 " << cnt3;
			for(int i = 0 ; i < c ; i++)
				if(n3[i] != -1)
					cout << " " << n3[i];
			cout << "\n";
		}
		else if (cnt1 > cnt2 && cnt1 > cnt3)
		{
			cout << "1 " << cnt1;
			for(int i = 0 ; i < a ; i++)
				if(n1[i] != -1)
					cout << " " << n1[i];
			cout << "\n";
		}
		else if (cnt2 > cnt1 && cnt2 > cnt3)
		{
			cout << "2 " << cnt2;
			for(int i = 0 ; i < b ; i++)
				if(n2[i] != -1)
					cout << " " << n2[i];
			cout << "\n";
		}
		else if (cnt3 > cnt1 && cnt3 > cnt2)
		{
			cout << "3 " << cnt3;
			for(int i = 0 ; i < c ; i++)
				if(n3[i] != -1)
					cout << " " << n3[i];
			cout << "\n";
		}
	}	
	return 0;
} 
