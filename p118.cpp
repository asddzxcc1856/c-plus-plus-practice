#include <iostream>
#include <map>
using namespace std;

map<pair<int,int>,bool> ma;
string str;
int m,n;
int nx,ny,i;
char der;
bool lose;

int main ()
{
	cin >> m >> n;
	while(cin >> nx >> ny >> der)
	{
		cin >> str;
		lose = false;
		for (i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == 'F')
			{
				if(der == 'N')
				{
					if((ny + 1)>n)
					{
						pair<int,int> p;
						p.first = nx;
						p.second = ny;
						if(ma.find(p)!=ma.end())
						{
							continue;
						}
						else
						{
							lose = true;
							break;
						}
					}
					else
					{
						ny += 1;
					}
				}
				else if (der == 'E')
				{
					if((nx + 1)>m)
					{
						pair<int,int> p;
						p.first = nx;
						p.second = ny;
						if(ma.find(p)!=ma.end())
						{
							continue;
						}
						else
						{
							lose = true;
							break;
						}
					}
					else
					{
						nx += 1;
					}
				}
				else if (der == 'W')
				{
					if((nx - 1)<0)
					{
						pair<int,int> p;
						p.first = nx;
						p.second = ny;
						if(ma.find(p)!=ma.end())
						{
							continue;
						}
						else
						{
							lose = true;
							break;
						}
					}
					else
					{
						nx -= 1;
					}
				}	
				else if (der == 'S')
				{
					if((ny - 1)<0)
					{
						pair<int,int> p;
						p.first = nx;
						p.second = ny;
						if(ma.find(p)!=ma.end())
						{
							continue;
						}
						else
						{
							lose = true;
							break;
						}
					}
					else
					{
						ny -= 1;
					}
				}
			}
			else if (str[i] == 'R')
			{
				if(der == 'W')
				{
					der = 'N';	
				}
				else if (der == 'E')
				{
					der = 'S';
				}
				else if (der == 'S')
				{
					der = 'W';
				}
				else if (der == 'N')
				{
					der = 'E';
				}	
			}
			else if (str[i] == 'L')
			{
				if(der == 'W')
				{
					der = 'S';	
				}
				else if (der == 'E')
				{
					der = 'N';
				}
				else if (der == 'S')
				{
					der = 'E';
				}
				else if (der == 'N')
				{
					der = 'W';
				}	
			}	
		}
		if(lose == false)
		{
			cout << nx << " " << ny << " " << der << "\n";
		}
		else
		{
			pair<int,int> p;
			p.first = nx;
			p.second = ny;
			ma[p] = true;
			cout << nx << " " << ny << " " << der << " LOST" << "\n";
		}
	}

    return 0;
}

