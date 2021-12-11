#include <iostream>
using namespace std;

void insert_sorting(int b[])
{
	int jump = 5/2; // size/2
	while(jump != 0)
	{
		for(int i = jump ; i < 5 ; i++)
		{
			int temp = b[i];
			int j = i - jump;
			while(temp < b[j] && j>=0)
			{
				b[j + jump] = b[j];
				j = j - jump;
			}
			b[j + jump] = temp; 
		}
		jump = jump / 2;
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
	
	insert_sorting(c);
	
	print_arr(c);
	
    return 0;
}

