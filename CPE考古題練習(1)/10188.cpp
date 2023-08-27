#include <iostream>
using namespace std;

int main ()
{
    int n,m,times = 1;
    while(cin >> n)
    {
    	cin.get();
    	if (n == 0)
    	{
    		return 0;
		}
		string nallword,nallword2,nstr[105],mallword,mallword2,mstr[105];
		for(int i = 0 ; i < n ; i++)
		{
			getline(cin,nstr[i]);
			nallword += nstr[i];
			nallword += '\n';
		}
		
		cin >> m;
		cin.get();
		for(int i = 0 ; i < m ; i++)
		{
			getline(cin,mstr[i]);
			mallword += mstr[i];
			mallword += '\n';
		}
		int ncnt = 0;
		int nspace = 0;
		for(int i = 0 ; i < nallword.length() ;i++)
		{
			if(nallword[i] != '\n')
				ncnt++;
			if(nallword[i] == ' ')
				nspace++;
			if(nallword[i] != ' ' && nallword[i] != '\n')
			{
				nallword2 += nallword[i];
			}
		}
		int mcnt = 0;
		int mspace = 0;
		for(int i = 0 ; i < mallword.length() ;i++)
		{
			if(mallword[i] != '\n')
				mcnt++;
			if(mallword[i] == ' ')
				mspace++;
			if(mallword[i] != ' ' && mallword[i] != '\n')
			{
				mallword2 += mallword[i];
			}
		}
		if(nallword == mallword)
		{
			cout << "Run #" << times++ << ":" << " Accepted " << ncnt << "\n";
		}
		else if (mcnt - mspace == ncnt - nspace && mallword2 == nallword2)
		{
			cout << "Run #" << times++ << ":" << " Presentation Error " << ncnt << "\n";
		}
		else
		{
			cout << "Run #" << times++ << ":" << " Wrong Answer " << ncnt << "\n";
		}
	}
}