#include <iostream>
using namespace std;

void select_sorting(int b[])
{
	for(int i = 0 ; i < 4 ; i++)
	{
		int temp = b[i];
		for (int j = i + 1 ; j < 5 ; j++ )
		{
			if(b[j] < b[i])
			{
				int temp = b[j];
				b[j] = b[i];
				b[i] = temp;	
			}
		}
	}
}

void print_arr(int b[])
{
	cout << "±Æ§Çµ²ªG : ";
	for (int i = 0 ; i < 5 ; i++)
	{
		cout << b[i] << " ";
	}
	cout << "\n";
}

int main ()
{
	int c[10] = {55,23,87,62,16};
	
	select_sorting(c);
	
	print_arr(c);
	
    return 0;
}

