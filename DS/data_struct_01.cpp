#include <iostream>
#include <list>
using namespace std;


template <typename Container>
void print(const Container & c, ostream & out = cout)
{
	if(c.empty())
		out << "(empty)";
	else
	{
		auto itr = begin(c);
		
		out << "[" << *itr++;
		
		while(itr != end(c))
			out << ", " << *itr++;
		out << "]" << endl;
		
	}
}

int main()
{
	list<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	print(ls);	
	list<int> ls2 = move(ls);
	print(ls2);
	print(ls);
}