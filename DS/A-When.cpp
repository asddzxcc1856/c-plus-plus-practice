#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int minute;
	cin >> minute;
	minute += 21 * 60;
	cout << setfill('0') << setw(2) << minute/60 << ":" << setfill('0') << setw(2) << minute%60 << "\n";
}