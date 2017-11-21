#ifndef VSHAPE_H_
#define VSHAPE_H_

#include <iostream>
#include <sstream>
#include <QFile>
#include <QtGui>
#include <QTextStream>

template <class S>
class vShape
{
    /*
    vShape of doubles much like stl vShape container

    NOTE: elem[n] is vShape component n for all n >= 0 AND n < size_v
          size_v = the number of items stored in the vShape
          space = the available storage capacity of the vShape where size_v <= space
          if size_v < space there is space for (space ï¿½ size_v) doubles after elem[size_vï¿½1]
*/

    int size_v;		// the size
    double* elem;	// pointer to the elements (or 0)
    int space;		// number of elements plus number of free slots
public:
    vShape() : size_v{0}, elem{nullptr}, space{0} { }					// default constructor

    explicit vShape(int s) : size_v{s}, elem{new double[s]}, space{s}	// alternate constructor
    {
        for (int i=0; i<size_v; ++i) elem[i] = 0; // elements are initialized
    }

    //sort function
    //sort and comparison function will determine which comparison to do with function pointer
    void sort(){
        for (int j = 0; j < size_v - 1; ++j) {
            int min = j;
            for (int i = j+1; i < size_v; ++i) {
                if (/*funcion pointer to comparison function for id, perim, or area*/) {
                    min = i;
                }
            }
            if (min != j)
                swap(sort.at(j), sort.at(min));
        }
    }

    bool compareID(Shape* s1, Shape* s2){//return true if s1 has a larger id than s2
        return s1->get_id() > s2->get_id();
    }
    bool compareArea(Shape* s1, Shape* s2){//return true if s1 has a larger area than s2
        return s1->calcArea() > s2->calcArea();
    }
    bool comparePerim(Shape* s1, Shape* s2){//return true if s1 has a larger perimeter than s2
        return s1->calcPerimeter() > s2->calcPerimeter();
    }

    vShape(const vShape& src) : size_v{src.size_v}, elem{new double[src.size_v]}, space{src.space} // copy constructor
    {
        copy(src.elem, src.elem + size_v, elem); 	// copy elements - std::copy() algorithm
    }

    vShape& operator=(const vShape& src)			// copy assignment
    {
        double* p = new double[src.size_v];			// allocate new space
        copy(src.elem, src.elem + src.size_v, p);	// copy elements - std::copy() algorithm
        delete[] elem;								// deallocate old space
        elem = p;									// now we can reset elem
        size_v = src.size_v;
        return *this;								// return a self-reference
    }

    ~vShape() { delete[] elem; }					// destructor

    double& operator[](int n) { return elem[n]; }	// access: return reference

    const double& operator[](int n) const { return elem[n]; }

    int size() const { return size_v; }

    int capacity() const { return space; }

    void resize(int newsize)							// growth
    // make the vShape have newsize elements
    // initialize each new element with the default value 0.0
    {
        reserve(newsize);
        for (int i=size_v; i<newsize; ++i) elem[i] = 0; // initialize new elements
        size_v = newsize;
    }

    void push_back(S *newShape)
    // increase vShape size by one; initialize the new element with d
    {
        if (space == 0)
        {
            reserve(8);					// start with space for 8 elements
        }
        else if (size_v == space)
        {
            reserve(2*space);           // get more space
        }
        elem[size_v] = newShape;					// add d at end
        ++size_v;									// increase the size (size_v is the number of elements)
    }

    void reserve(int newalloc)
    {
        if (newalloc <= space) return; 				// never decrease allocation
        double* p = new double[newalloc]; 			// allocate new space
        for (int i=0; i<size_v; ++i) p[i] = elem[i];// copy old elements
        delete[] elem; 								// deallocate old space
        elem = p;
        space = newalloc;
    }

    using iterator = double*;
    using const_iterator = const double*;

    iterator begin()		// points to first element
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

    iterator end()			// points to one beyond the last element
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

    iterator insert(iterator p, const double& val) // insert a new element val before p
    {
        int index = p - begin();
        if (size() == capacity())
            reserve(size()==0 ? 8 : 2*size());	// make sure we have space
        ++size_v;
        iterator pp = begin() + index;			// the place to put value
        for (iterator pos=end()-1; pos!=pp; --pos)
            *pos = *(pos-1);					// copy element one position to the right
        *(begin() + index) = val; 				// insert value
        return pp;
    }

    iterator erase(iterator p)	// remove element pointed to by p
    {
        if (p == end()) return p;
        for (iterator pos=p+1; pos!=end(); ++pos)
            *(pos-1) = *pos;	// copy element one position to the left
        delete (end()-1);
        --size_v;
        return p;
    }

    int ShapeIdentifier(string sType)
    {
        if (sType == "Line")
        {
            return 0;
        }
        else if (sType == "Polyline")
        {
            return 1;
        }
        else if (sType == "Rectangle")
        {
            return 2;
        }
        else if (sType == "Square")
        {
            return 3;
        }
        else if (sType == "Polygon")
        {
            return 4;
        }
        else if (sType == "Ellipse")
        {
            return 5;
        }
        else if (sType == "Circle")
        {
            return 6;
        }
        else
        {
            return 7;
        }
    }


    /******************************************************************************
     * This function will receive the input file from main() and store the file
     * appropriately into the vShape of Shapes. It will store each line into its own
     * specified category.
     * returns - nothing
     ******************************************************************************/
    vShape<S> InitializeShapes()
    {
        QFile inFile("InputFile.txt");
        ShapeInfo *tempShapes = new ShapeInfo;
        vShape<S> temp;
        QString fileString;
        QString dimString;
        string tempString;
        string token;
        int    tempDim[8];


        if (!inFile.open(QIODevice::ReadOnly))
        {
            cout << "The file cannot be found.\n\n";
        }

        QTextStream fin(&inFile);

        /***************************************************************************
    * While Loop - loops through storing all information on the input file into
    * the correct category. Will continue until it reaches the end of the file
    * or the pointer is NULL
    ***************************************************************************/
        while (!fin.atEnd())
        {
            fileString = fin.readLine();
            fileString.remove(0,9);
            tempShapes->tempid = fileString.toInt();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,11);
            tempShapes->type = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,16);

            if (tempShapes->type == "Line")
            {
                for (int index = 0; index < 4; index++)
                {
                    dimString = fileString.section(',', index, index);
                    dimString.remove(' ');
                    tempDim[index] = dimString.toInt();
                }
                fileString.clear();
            }
            else if (tempShapes->type == "Polyline")
            {
                for (int index = 0; index < 8; index++)
                {
                    dimString = fileString.section(',', index, index);
                    dimString.remove(' ');
                    tempDim[index] = dimString.toInt();
                }
                fileString.clear();
            }
            else if (tempShapes->type == "Polygon")
            {
                for (int index = 0; index < 8; index++)
                {
                    dimString = fileString.section(',', index, index);
                    dimString.remove(' ');
                    tempDim[index] = dimString.toInt();
                }
                fileString.clear();
            }
            else if (tempShapes->type == "Rectangle")
            {
                for (int index = 0; index < 4; index++)
                {
                    dimString = fileString.section(',', index, index);
                    dimString.remove(' ');
                    tempDim[index] = dimString.toInt();
                }
                fileString.clear();
            }
            else if (tempShapes->type == "Square")
            {
                for (int index = 0; index < 3; index++)
                {
                    dimString = fileString.section(',', index, index);
                    dimString.remove(' ');
                    tempDim[index] = dimString.toInt();
                }
                fileString.clear();
            }
            else if (tempShapes->type == "Ellipse")
            {
                for (int index = 0; index < 4; index++)
                {
                    dimString = fileString.section(',', index, index);
                    dimString.remove(' ');
                    tempDim[index] = dimString.toInt();
                }
                fileString.clear();
            }
            else if (tempShapes->type == "Circle")
            {
                for (int index = 0; index < 3; index++)
                {
                    dimString = fileString.section(',', index, index);
                    dimString.remove(' ');
                    tempDim[index] = dimString.toInt();
                }
                fileString.clear();
            }
            else
            {
                for (int index = 0; index < 4; index++)
                {
                    dimString = fileString.section(',', index, index);
                    dimString.remove(' ');
                    tempDim[index] = dimString.toInt();
                }
                fileString.clear();
            }

            fileString = fin.readLine();
            fileString.remove(0,10);
            tempShapes->pencolor = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,10);
            tempShapes->penwidth = fileString.toInt();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,10);
            tempShapes->penstyle = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,13);
            tempShapes->pencap = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,14);
            tempShapes->penjoin = fileString.toStdString();
            fileString.clear();

            fin.readLine();





        }
    }


private:
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
    };

};

#endif /* VSHAPE_H_ */
