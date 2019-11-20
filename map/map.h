#ifndef map_hpp
#define map_hpp

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif
#include "bst.h"
namespace custom {
	template < typename K, typename V> class map {
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif
		
	public:
		class pair {
		public:
			K first;
			V second;
			
			//Methods
			
			//Default Constructor
			pair() : first(), second(){} //pair constructor is just like this because they could be anything(templates), not specific.
			
			pair(const K & first, const V & second) : first(first), second(second) {}
			
			//Assignment Operator for Pair
			pair &operator = (const pair &rhs)
			{
				first  = rhs.first; //assign rhs to first template
				second = rhs.second; //assign rhs to second template
				return *this; //return
			}
			
			//Equality Operator
			bool operator == (const pair &rhs)
			{
				return first == rhs.first; //Always compare rhs to lhs
			}
			
			//Greater Than
			bool operator > (const pair &rhs)
			{
				return first > rhs.first; //Always compare rhs to lhs
			}
			
			//Less than
			bool operator < (const pair &rhs)
			{
				return first < rhs.first; //Always compare rhs to lhs
			}
			
			//Greater or Equal
			bool operator >= (const pair &rhs)
			{
				return first >= rhs.first; //Always compare rhs to lhs
			}
			
			//Less or Equal
			bool operator <= (const pair &rhs)
			{
				return first <= rhs.first; //Always compare rhs to lhs
			}
			
		}; //end of PAIR CLASS
		
		class iterator{
#ifdef UNIT_TESTING
			friend int ::main(int argc, const char* argv[]);
#endif
		private:
			
			typename BST <pair>::iterator it;
		public:
			iterator(){
				it = NULL;
			}
			iterator(typename BST <pair>::iterator it){
				this->it = it;
			}
			iterator(const iterator& aIt){
				it = aIt.it;
			}
			iterator operator = (typename BST <pair>::iterator *aPtr){
				it = aPtr;
				return *this;
			}
			bool operator==(iterator anIt)const{
				return it == anIt.it;
			}
			
			bool operator!=(iterator anIt)const{
				return it != anIt.it;
			}
			// iterator to node comparition!!!!!!!!
			bool operator==(typename BST <pair>::iterator* & blp)const{
				return it == blp;
			}
			// iterator to node comparition!!!!!!!!
			bool operator!=(typename BST <pair>::iterator* & blp)const{
				return it != blp;
			}
			
			//prefix operator
			iterator operator++(){
				++it; //we already have an iterator defined for bst, just use it and..
				return *this; //return it.
			}
			
			//postfix operator
			iterator operator++(int lhs)
			{
				iterator temporaryIt(*this); //create temporary iterator with lhs as parameter
				it++; //we already have an iterator defined for bst, just use it.
				return temporaryIt;
			}
			//prefix operator
			iterator operator--(){
				--it; //we already have an iterator defined for bst, just use it.
				return *this; //and return it
			}
			
			//postfix operator
			iterator operator--(int lhs)
			{
				iterator tempIt(*this); //create temporary iterator with lhs as parameter
				it--; //we already have an iterator defined for bst, just use it.
				return tempIt;
			}
			
			//dereference operator
			pair& operator *(){
				return *it; //return the reference/value of it (it comes from the iterator of bst, so it is easy to define)
			}
		};
		
	
#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
#endif
		
	private:
		BST < pair > bst; //Defining a bst instance with a pair
		
	public:
		map() : bst() {} //Constructor for map is just calling constructor for BST
		
		//Assignment Op
		map &operator = (const map &rhs)
		{
			bst = rhs.bst; //assigning the rhs to bst
			return *this; //returning
		}
		
		//Size
		int size()
		{
			return bst.size(); //calling size from BST
		}
		
		//Empty
		bool empty()
		{
			return !size(); //NOT size is equal to empty, duh.
		}
		
		//Clear
		void clear()
		{
			bst.clear(); //Calling clear from BST
		}
		
		//Brakets for Access (to change value or insert value, kind of like an array)
		V &operator [] (K key)
		{

			pair tempPair(key, V()); //creates a pair out of the key and a default value
			typename BST<pair>:: iterator it = bst.find(tempPair); //iterator referring to the node with the right key.
			
			if (it != NULL) //If the iterator points to something that exists in the BST...
			{
				return (*it).second; //return the second element of the pair(the value)
			}
			else //If it does not exist...
			{
				bst.insert(tempPair); //then create  it...
				return (*bst.find(tempPair)).second; //return the default value
			}
			
			return (*bst.find(pair(key, V()))).second;
		}
		
		//Find
		iterator find (K key)
		{
			pair tempPair(key, V()); //create a pair with the passed key and a default value
			iterator it(bst.find(tempPair)); //use an iterator and call the find from bst passing the pair created before to find the node
			iterator temp(it); //create a temporary iterator to return and pass it the found node
			return temp; //return it
		}
		
		
		void insert(pair pair) { bst.insert(pair); }
		//Insert
		void insert (K key, V value)
		{
			pair pair(key, value); //create a pair with the passed key and value
			bst.insert(pair); //use insert from bst and pass it the pair to find the right node
		}
		
		//Begin
		iterator begin()
		{
			iterator myIt(bst.begin()); //Calling non-default from iterator with the begin function from BST as parameter
			return myIt; //returning it
		}
		
		//End
		iterator end()
		{
		    iterator myIt2(bst.end()); //Calling non-default from iterator with the end function from BST as parameter
			return myIt2; //returning it
		}
	
	};
}

#endif