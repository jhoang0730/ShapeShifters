#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

template <typename T>
class Vector
{
private:

    int size_v;     // the size
    T* elem;     // a pointer to the elements
    int space;     // size+free_space

public:

    /* Constructors */
    Vector();     // default constructor
    explicit Vector(int s);    // alternate constructor

    /* Copy constructor and copy assignment
     * Precondition: vector object
     * Postcondition: the object is copied
     */
    Vector(const Vector& otherVector);
    Vector& operator=(const Vector& otherVector)
    {
        T *p = new T[otherVector.size_v];       // allocate new space
        copy(otherVector.elem, otherVector.elem + otherVector.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem;                            // deallocate old space
        elem = p;                                 // now we can reset elem
        size_v = otherVector.size_v;
        return *this;  // return a self-reference
    }

    /* Move constructor and move assignment
     * Precondition: <none>
     * Postcondition: the object is moved and deallocate old memory
     */
    Vector(const Vector&& otherVector) noexcept;    // move constructor
    Vector& operator=(const Vector&& otherVector) noexcept; // move assignment

    /* Destructor
     * Precondition: <none>
     * Postcondition: the object is deallocated
     */
    ~Vector() {delete[] elem;}

    /* operator[] function */
    T& operator[] (int n) const { return elem[n]; }    // access: return reference
    const T& operator[] (int n) { return elem[n]; }    // access: return reference

    /* Functions return integer private data members
     * Precondition: <none>
     * Postcondition: return size_v or space
     */
    int size() const { return size_v; }    // the current size
    int capacity() const { return space; }     // current available space

    /* Function to make the vector have newsize elements and initialize each new element with the default value 0.0
     * Precondition: int newsize
     * Postcondition: assign current size to newsize
     */
    void resize(int newsize);

    /* Function to add an element
     * Precondition: T val
     * Postcondition: an element is added
     */
    void push_back(T val)
    {
        if (space == 0)
        reserve(8);         	// start with space for 8 elements
        else if (size_v == space)
        reserve(2 * space); 	// get more space
        elem[size_v] = val;     // add d at end
        ++size_v;               // increase the size (size_v is the number of elements)
    }

    /* Function to get more space
     * Precondition: int newalloc
     * Postcondition: more space is added
     */
    void reserve(int newalloc);

    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() {   // points to first element
        if (size_v == 0)
        return nullptr;
        return &elem[0];
    }

    const_iterator begin() const {
        if (size_v == 0)
        return nullptr;
        return &elem[0];
    }

    iterator end() {   // points to one beyond the last element
        if (size_v == 0)
        return nullptr;
        return &elem[size_v];
    }

    const_iterator end() const {
        if (size_v == 0)
        return nullptr;
        return &elem[size_v];
    }

    iterator insert(iterator p, const T& val) { // insert a new element val before p
        int index = p - begin();

        if (size() == capacity())
        reserve(size() = 0 ? 8 : 2 * size());

        ++size_v;

        iterator pp = begin() + index;

        for (iterator pos = end() - 1; pos != pp; --pos)
            *pos = *(pos - 1);

        *(begin() + index) = val;
        return pp;
    }

    iterator erase(iterator p) {    // remove element pointed to by p
        if (p == end())
        return p;

        for (iterator pos = p + 1; pos != end(); ++pos)	*(pos - 1) = *pos;

        --size_v;
        return p;
    }
};

template <typename T>
Vector<T>::Vector()
{
    size_v = 0;
    space = 0;
    elem = nullptr;
}

template <typename T>
Vector<T>::Vector(int s)
{
    size_v = s;
    space = s;
    elem = new T[size_v];

    for (int i = 0; i < size_v; i++)
        elem[i] = T{};

}

template <typename T>
Vector<T>::Vector(const Vector &otherVector)
{
    size_v = otherVector.size_v;
    elem = new T[otherVector.size_v];
    space = otherVector.space;

    copy(otherVector.elem, otherVector.elem + size_v, elem); // copying elements using std::copy() algorithm
}

template <typename T>
void Vector<T>::reserve(int capacity)
{
    T *temp;
    space = capacity;

    // allocate new space
    temp = new T[size_v];
    for (int i = 0; i < size_v; i++)
        temp[i] = elem[i];


    delete[] elem;
    elem = new T[space];

    // copying old elements
    for (int i = 0; i < space; i++)
        elem[i] = temp[i];

    // deallocate old space
    delete[] temp;
}

template<typename T>
void Vector<T>::resize(int newsize)
{
    reserve(newsize);
    for (int i = size_v; i < newsize; ++i)
        elem[i] = 0;            // initializing new elements
    size_v = newsize;
}

#endif /* VECTOR_H_ */

