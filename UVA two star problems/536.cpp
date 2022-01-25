#include <iostream>
using namespace std;


int cut(string pre,string in,int root,int l,int r)
{
	if(l >= r)
	{
		return root;
	}
	for(int i = l ; i < r ; i++)
	{
		if(pre[root] == in[i])
		{
			root = cut(pre,in,root+1,l,i);
			root = cut(pre,in,root,i+1,r);
			cout << in[i];
			break;
		}
	}
	return root;
}

int main ()
{
	string str1,str2;
	while(cin >> str1 >> str2)
	{
		cut(str1,str2,0,0,str2.length());
		cout << "\n";
	}
}
