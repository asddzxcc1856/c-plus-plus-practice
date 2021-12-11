#include <iostream>
using namespace std;

void bubble_sorting(int b[])
{
	for(int i = 0 ; i < 5 ; i++)
	{
		for (int j = 0 ; j < 5 - i - 1 ; j++ )
		{
			if(b[j] > b[j + 1])
			{
				int temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;	
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
	
	bubble_sorting(c);
	
	print_arr(c);
	
    return 0;
}

