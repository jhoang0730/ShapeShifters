#include <iostream>
using namespace std;

template<class T> 
class vector 
{ 
 private:
 
   int size_v;     // the size 
   T* elem;     // a pointer to the elements 
   int space;     // size+free_space 
   
  public: 
  
   vector() : size_v{0}, elem{nullptr}, space{0};     // default constructor 
   
   explicit vector(int s) : size_v{s}, elem{new vector[s]}, space{s} // alternate constructor
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = 0;
    }
   
   vector(const vector& copiedShape) : size_v{copiedShape.size_v}, elem{new vector[copiedShape.size_v]}, space{copiedShape.space} // copy constructor
    {
        copy(copiedShape.elem, copiedShape.elem + size_v, elem);   // copy constructor 
    }

   vector& operator=vector(const vector& copiedShape)  // copy assignment 
   {
        vector *p = new vector[copiedShape.size_v];       // allocate new space
        copy(copiedShape.elem, copiedShape.elem + copiedShape.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem;                            // deallocate old space
        elem = p;                                 // now we can reset elem
        size_v = copiedShape.size_v;
        return *this;  // return a self-reference
    }
   
   vector(const vector&& movedShape) noexcept    // move constructor
   {
       size_v = movedShape.size_v;
       elem = new vector;
       *elem = *movedShape.elem;

       delete[] movedShape.elem;
   } 
   
   vector& operator=vector(const vector&& movedShape) noexcept // move assignment
   {
       delete[] this->elem;
       this->copy(movedShape);
       delete[] movedShape.elem;
       return this*;
   } 
   
   ~vector()  // destructor 
   {
       delete[] elem;
   }  
   
   T& operator[] (int n)    // access: return reference 
   {
       return elem[n];
   }
   
   const T& operator[] (int n)    // access: return reference 
   {
       return elem[n];
   }
   
   int size() const    // the current size 
   {
       return size_v;
   }
   
   int capacity() const     // current available space 
   {
       return space;
   }
   
   void resize(int newsize)   // grow 
   {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = 0; // initialize new elements
        size_v = newsize;
    }
   
   void push_back(T val)   // add element 
   {
        if (space == 0)
            reserve(8);         // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); // get more space
        elem[size_v] = d;       // add d at end
        ++size_v;               // increase the size (size_v is the number of elements)
    }
   
   void reserve(int newalloc);    // get more space 
   {
       return nullptr; // temp remove & replace
   } 
   
   using iterator = T*; 
   
   using const_iterator = const T*; 
   
   iterator begin()   // points to first element
   {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }
   
   const_iterator begin() const
   {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }  
   
   iterator end()   // points to one beyond the last element 
   {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }
   
   const_iterator end() const
   {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    } 
   
   iterator insert(iterator p, const T& v) // insert a new element v before p 
   {
       return nullptr; // temp remove & replace
   }
   
   iterator erase(iterator p)    // remove element pointed to by p 
   {
   return nullptr; // temp remove & replace
   }
}; 