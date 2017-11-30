#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <sstream>
#include <QFile>
#include <QDebug>
#include <QtGui>
#include <QTextStream>

using std::string;

//! The vector class.
/*! This class is designed to create our own blueprint of
 *  a vector from the std library in which it is implemented
 *  as a templated class of type S (for shape). This type is
 *  necessary because we are storing the vector full of the
 *  templated class type S or shapes. The shapes each have
 *  their own set of properties that are stored inside of a
 *  struct. This struct is read into through the input file
 *  and stores each shapes information being push_backed into
 *  the vector. */

template <class S>
class Vector
{
    //! The struct of shape properties.
    /*! Each shape will have specified properties that are read in
     *  front the input file. Each shape is given an id, type, dimensions
     *  that are stored in an array, QPen properties and others. */
    struct ShapeInfo {
        int    tempid;
        string type;
        int    dimensions[];
        string pencolor;
        int    penwidth;
        string penstyle;
        string pencap;
        string penjoin;
        string brushcolor;
        string brushstyle;
        string txtstring;
        string txtcolor;
        string txtalign;
        int    txtpntsize;
        string txtfontfam;
        string txtfontstyle;
        string txtfontweight;
    };

    int size_v;         //!<The current size of vector. */
    S* elem;            //!<Pointer to the shape type S elements. */
    int space;          //!<The number of elements plus number of open space. */
public:
    //! A constructor
    /*! This is the default constructor that will set the private data members
     *  to their appropriate conditions (null or 0). */
    Vector() : size_v{0}, elem{nullptr}, space{0} { }

    //! Alternate constructor
    /*! This is an alternate explicit constructor that will create space for
     *  a vector of users desired size by using a for loop.
     *  @param [in] input an int indicating size for the vector. */
    explicit Vector(int s) : size_v{s}, elem{new double[s]}, space{s}
    {
        for (int i=0; i<size_v; ++i) elem[i] = 0;
    }

//sort functions
    //sort and comparison function will determine which comparison to do with function pointer
    template <class S>
    void sort(bool (*compare)(S*, S*)){
        for (int j = 0; j < size_v - 1; ++j) {
            int min = j;
            for (int i = j+1; i < size_v; ++i) {
                if (compare(this->at(min), this->at(i))) {
                    min = i;
                }
            }
            if (min != j)
                swap(sort.at(j), sort.at(min));
        }
    }
    void sort(){//default sort call will sorted by ID
        sort(compareID);
    }
    bool compareID(Shape* s1, Shape* s2){//return true if s1 has a larger id than s2
        return s1->get_id() > s2->get_id();
    }
    bool compareArea(Shape* s1, Shape* s2){//return true if s1 has a larger area than s2
        return s1->calcArea() > s2->calcArea();
    }
    bool comparePerimeter(Shape* s1, Shape* s2){//return true if s1 has a larger perimeter than s2
        return s1->calcPerimeter() > s2->calcPerimeter();
    }
    //end of sort functions
    template <class T>
    bool compareID(T* s1, T* s2){//return true if s1 has a larger id than s2
        return s1->get_id() > s2->get_id();
    }    template <class T>
    bool compareArea(T* s1, T* s2){//return true if s1 has a larger area than s2
        return s1->calcArea() > s2->calcArea();
    }    template <class T>
    bool comparePerim(T* s1, T* s2){//return true if s1 has a larger perimeter than s2
        return s1->calcPerimeter() > s2->calcPerimeter();
    }

    //! Copy constructor
    /*! This constructor will take a previously instantiated object of class
     *  Vector passed by constant reference and copy all data stored in elem
     *  with the C++ standard library function copy().
     *  @param [in] an argument of class object Vector. */
    Vector(const Vector& src) : size_v{src.size_v}, elem{new double[src.size_v]}, space{src.space}
    {
        copy(src.elem, src.elem + size_v, elem);
    }

    //! Overloaded operator
    /*! This overloaded assignment operator is necessary for copy assignment
     *  to be properly executed by individually copying each value and returns
     *  as a self-reference.
     *  @param [in] an argument of class object Vector. */
    Vector& operator=(const Vector& src)
    {
        double* p = new double[src.size_v];
        copy(src.elem, src.elem + src.size_v, p);
        delete[] elem;
        elem = p;
        size_v = src.size_v;
        return *this;
    }


    //! Destructor
    /*! This is a default destructor that will be executed when program
     *  is finished and will delete all memory in the array of elem. */
    ~Vector() { delete[] elem; }					// destructor

    //! Overloaded operator
    /*! This overloaded reference operator is to insure that the templated
     *  array of elements is stored correctly without errors. It returns
     *  a self-reference to elem.
     *  @param [in] an argument of an integer type to set elem size. */
    const S& operator[](int n) const { return elem[n]; }

    //! A public member function
    /*! This function when called will return the objects current size. */
    int size() const { return size_v; }

    //! A public member function
    /*! This function when called will return the current available space. */
    int capacity() const { return space; }

    //! A public member function
    /*! This function is used to resize the elem array to reserve more space
     *  and that space is initialized with default value 0.0. The reserve()
     *  function is called to allocate the new space while keeping the old elements.
     *  @param [in] An argument of integer type that is the new elem size. */
    void resize(int newsize)
    {
        reserve(newsize);
        for (int i=size_v; i<newsize; ++i) elem[i] = 0;
        size_v = newsize;
    }

    //! A public member function
    /*! This function is a self-implementation of vector.push_back() and
     *  has a specific check if there is space avaiable. If there is not,
     *  space will be made for 8 elements. Then the new shape of type S is
     *  pushed into the end of the vector. Finally, vector size is preincremented.
     *  @param [in] An argument of type S with new data of struct ShapeInfo to store. */
    void push_back(S newShape)
    {
        if (space == 0)
        {
            reserve(8);
        }
        else if (size_v == space)
        {
            reserve(2*space);
        }
        elem[size_v] = newShape;
        ++size_v;
    }

    //! A public member function
    /*! This function will first check if the number of spaces desired to
     *  reserve is less than the current space to avoid decrease allocation.
     *  Then the new space is allocated and the old elements are copied to
     *  the new space. Finally, deallocate old space by deleting elem.
     *  @param [in] An argument of integer type of desired size. */
    void reserve(int newalloc)
    {
        if (newalloc <= space) return;
        double* p = new double[newalloc];
        for (int i=0; i<size_v; ++i) p[i] = elem[i];
        delete[] elem;
        elem = p;
        space = newalloc;
    }

    //! Iterator
    /*! This iterator and constant iterator are simply pointers to the templated class S. */
    using iterator = S*;
    using const_iterator = const S*;

    //! Iterator function
    /*! This iterators function declares the iterator to point to the first element */
    iterator begin()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    //! Constant Iterator function
    /*! This constant iterators function declares the iterator to point to the first element */
    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    //! Iterator function
    /*! This iterators function declares the iterator to point to the last element */
    iterator end()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    //! Constant Iterator function
    /*! This constant iterators function declares the iterator to point to the last element */
    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    //! Iterator function
    /*! This iterators function will insert a new element in the desired space.
     *  It will first check for space and then loop copying the element one
     *  location to the right until the position is equivalent to the location
     *  before the entered space and insert the value.
     *  @param [in] Iterator p is an iterator pointer argument.
     *  @param [in] An argument of const reference to a type S (shape) element. */
    iterator insert(iterator p, const S& val)
    {
        int index = p - begin();
        if (size() == capacity())
            reserve(size()==0 ? 8 : 2*size());
        ++size_v;
        iterator pp = begin() + index;
        for (iterator pos=end()-1; pos!=pp; --pos)
            *pos = *(pos-1);
        *(begin() + index) = val;
        return pp;
    }

    //! Iterator function
    /*! This iterators function will remove the element pointed to by p.
     *  It will loop copying the element one to the left until it reaches the
     *  desired  element to erase.
     *  @param [in] Iterator p is an iterator pointer argument. */
    iterator erase(iterator p)
    {
        if (p == end()) return p;
        for (iterator pos=p+1; pos!=end(); ++pos)
            *(pos-1) = *pos;
        delete (end()-1);
        --size_v;
        return p;
    }

    //! Initialization
    /*! This function is the parsing of the text file that contains numerous shapes
     *  along with all their specified properties. The files data is stored into
     *  a struct containing corresponding variables to store properties. Then an
     *  object of the requested shape by the input file is created and passed in
     *  the required values. Returns a Vector of templated class S for further
     *  implementation.*/
    Vector<S> InitializeShapes();

};

//! Initialization
/*! This function will receive a string of the current shapes type read in from
 *  the input file and perform a series of if else-if statements returning an
 *  integer to the appropriate shape used for switch statements.
 *  @param [in] An argument of string type */
int       ShapeIdentifier(const string shapeType);

#endif /* VECTOR_H_ */

