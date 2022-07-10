#include <iostream>
#include <algorithm>
#include <ctime> 
using namespace std;

template <typename Object>
class Vector
{
	public:
		explicit Vector(int initSize = 0) : theSize{initSize}, theCapacity{ initSize + SPACE_CAPACITY}
		{
			cout << "constructor\n";
			objects = new Object[theCapacity];
		}
		
		Vector(const Vector & rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr}
		{
			cout << "copy constructor\n";
			objects = new Object[theCapacity];
			for (int k = 0 ; k < theSize ; ++k)
				objects[k] = rhs.objects[k];
		}
		
		Vector & operator=(const Vector & rhs)
		{
			cout << "copy assignment\n";
			Vector copy = rhs;
			swap(*this,copy);
			return *this;
		}
		
		~Vector()
		{
			delete[] objects;
		}
		
		Vector( Vector && rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects}
		{
			cout << "move constructor\n";
			rhs.objects = nullptr;
			rhs.theSize = 0;
			rhs.theCapacity = 0;
		}
		
		Vector & operator= (Vector && rhs)
		{
			cout << "move assignment\n";
			swap(theSize,rhs.theSize);
			swap(theCapacity,rhs.theCapacity);
			swap(objects,rhs.objects);
			
			return *this;
		}
		
		void resize(int newSize)
		{
			if(newSize > theCapacity)
				reserve( newSize * 2);
			theSize = newSize;
		}
		
		void reserve(int newCapacity)
		{
			if (newCapacity < theSize)
				return;
			
			Object *newArray = new Object[newCapacity];
			for(int k = 0 ; k < theSize ; ++k)
				newArray[k] = move(objects[k]);
				
			theCapacity = newCapacity;
			swap(objects,newArray);
			delete[] newArray;
		}
		Object & operator[](int index)
		{
			return objects[index];
		}
		
		const Object & operator[](int index) const
		{
			return objects[index];
		}
		
		bool empty() const
		{
			return size() == 0;
		}
		
		int size() const
		{
			return theSize;
		}
		
		int capacity() const
		{
			return theCapacity;
		}
		
		void push_back(const Object & x)
		{
			if(theSize == theCapacity)
				reserve(2 * theCapacity + 1);
			objects[theSize++] = x;
		}
		void push_back(Object && x)
		{
			if(theSize == theCapacity)
				reserve(2 * theCapacity + 1);
			objects[theSize++] = move(x);
		}
		
		void pop_back()
		{
			--theSize;
		}
		
		const Object & back() const
		{
			return objects[theSize - 1];
		}
		
		typedef Object * iterator;
		typedef const Object * const_iterator;
		
		iterator begin()
		{
			return &objects[0];
		}
		
		const_iterator begin() const
		{
			return &objects[0];
		} 
		
		iterator end()
		{
			return &objects[size()];
		}
		
		const_iterator end() const
		{
			return &objects[size()];
		}
		static const int SPACE_CAPACITY = 16;
	private:
		int theSize;
		int theCapacity;
		Object * objects;
};

int main ()
{
	Vector<int> v;
	for(int i = 0 ; i < 10000000 ; i++)
		v.push_back(i);
		
	double START,END;
	
	START = clock();
	Vector<int> v1 = move(v);
	END = clock();
	cout << endl << "cost time : " << (END - START) << " ms" << endl;
	
	START = clock();
	Vector<int> v2 = v;
	END = clock();
	cout << endl << "cost time : " << (END - START) << " ms" << endl;
	

}