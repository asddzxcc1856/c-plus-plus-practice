#include <iostream>
using namespace std;

template <typename Object>
class List{
	private:
		struct Node
		{
			Object data;
			Node* prev;
			Node* next;
			
			Node(const Object & d = Object{}, Node* p = nullptr, Node* n = nullptr) : data{d}, prev{p}, next{n} {}
			Node(Object && d,Node* p = nullptr, Node* n = nullptr) : data{move(d)}, prev{p}, next{n} {}
		};
	public:
		class const_iterator
		{
			
		};
		class iterator : public const_iterator
		{
			
		};
	public:
		List()
		{
			
		}
		List(const List & rhs)
		{
			
		}
		~List()
		{
			
		}
		List & operator= (const List & rhs)
		{
			
		}
		List(List && rhs)
		{
			
		}
		List & operator= (List && rhs)
		{
			
		}
		
		iterator begin()
		{
			return {head->next};
		}
		
		const_iterator begin() const
		{
			return {head->next};
		}
		
		iterator end()
		{
			return {tail};
		}
		
		const_iterator end() const
		{
			return {tail};
		}
		
		int size() const
		{
			return theSize;
		}
		
		bool empty() const
		{
			return size() == 0;
		}
		
		void clear()
		{
			while(!empty())
			{
				pop_front();
			}
		}
		
		Object & front()
		{
			return *begin();
		}
		
		const Object & front() const
		{
			return *begin();
		}
		
		Object & end()
		{
			return *--end();
		}
		
		const Object & front() const
		{
			return *--end();
		}
		
		void push_front(const Object & x)
		{
			insert(begin(),x);
		}
		
		void push_front(Object && x)
		{
			insert(begin(),move(x));
		}
		
		void push_back(const Object & x)
		{
			insert(end(),x);
		}
		
		void push_front(Object && x)
		{
			insert(end(),move(x));
		}
		
		void pop_front()
		{
			erase(begin());
		}
		
		void pop_back()
		{
			erase(--end());
		}
		
		iterator insert(iterator itr, const Object & x)
		{
			
		}
		
		iterator insert(iterator itr, Object && x)
		{
			
		}
		
		iterator erase(iterator itr)
		{
			
		}
		
		iterator erase(iterator from, iterator to)
		{
			
		}
		
	private:
		int theSize;
		Node* tail;
		Node* head;
		
		void init()
		{
			
		}
};