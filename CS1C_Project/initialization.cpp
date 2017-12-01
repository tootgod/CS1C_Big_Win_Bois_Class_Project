#include "vector.h"
#include "shape.h"

/******************************************************************************
 * This function will receive a constant string of a shape and perform if
 * else-if statements to correlate each shape with a number.
 * returns - integer corresponding to a shape
 ******************************************************************************/
int ShapeIdentifier(const string sType)
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
 * This function will open a QFile of a text document that contains a list of
 * shapes and  their properties. All properties will be stored in a pointer to a
 * struct of ShapeInfo. A continuous while loop will loop until reaching the end
 * of the file and after each shape is read in a new shapes constructor should be
 * called and pushed into a vector of templated class type S(Shape) using push_back.
 * returns - a vector of templated class S.
 ******************************************************************************/
template <class S>
Vector<S> Vector<S>::InitializeShapes()
{
    QFile inFile("InputFile.txt");           //!<QFile type that reads the text file */
    ShapeInfo *tempShapes = new ShapeInfo(); //!<Struct ShapeInfo object to store text file */
    Vector<S> temp;                          //!<Templated Vector class that stores shapes */
    QString fileString;                      //!<QString to temporarily read in the text file */
    QString dimString;                       //!<QString that stores the dimensions string to split apart */
    int     shapeType;                       //!<Int that stores the shape type and used in switch */
    QPainter *paint = new QPainter();        //!<QPainter that will create and store a paint brush */


    if (!inFile.open(QIODevice::ReadOnly))
    {
        cout << "The file cannot be found.\n\n";
    }

    QTextStream fin(&inFile);

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

        shapeType = ShapeIdentifier(fileString.toStdString());

        if (tempShapes->type == "Line")
        {
            for (int index = 0; index < 4; index++)
            {
                dimString = fileString.section(',', index, index);
                dimString.remove(' ');
                tempShapes->dimensions[index] = dimString.toInt();
            }
            fileString.clear();
        }
        else if (tempShapes->type == "Polyline")
        {
            for (int index = 0; index < 8; index++)
            {
                dimString = fileString.section(',', index, index);
                dimString.remove(' ');
                tempShapes->dimensions[index] = dimString.toInt();
            }
            fileString.clear();
        }
        else if (tempShapes->type == "Polygon")
        {
            for (int index = 0; index < 8; index++)
            {
                dimString = fileString.section(',', index, index);
                dimString.remove(' ');
                tempShapes->dimensions[index] = dimString.toInt();
            }
            fileString.clear();
        }
        else if (tempShapes->type == "Rectangle")
        {
            for (int index = 0; index < 4; index++)
            {
                dimString = fileString.section(',', index, index);
                dimString.remove(' ');
                tempShapes->dimensions[index] = dimString.toInt();
            }
            fileString.clear();
        }
        else if (tempShapes->type == "Square")
        {
            for (int index = 0; index < 3; index++)
            {
                dimString = fileString.section(',', index, index);
                dimString.remove(' ');
                tempShapes->dimensions[index] = dimString.toInt();
            }
            fileString.clear();
        }
        else if (tempShapes->type == "Ellipse")
        {
            for (int index = 0; index < 4; index++)
            {
                dimString = fileString.section(',', index, index);
                dimString.remove(' ');
                tempShapes->dimensions[index] = dimString.toInt();
            }
            fileString.clear();
        }
        else if (tempShapes->type == "Circle")
        {
            for (int index = 0; index < 3; index++)
            {
                dimString = fileString.section(',', index, index);
                dimString.remove(' ');
                tempShapes->dimensions[index] = dimString.toInt();
            }
            fileString.clear();
        }
        else
        {
            for (int index = 0; index < 4; index++)
            {
                dimString = fileString.section(',', index, index);
                dimString.remove(' ');
                tempShapes->dimensions[index] = dimString.toInt();
            }
            fileString.clear();
        }


        if (tempShapes->type == "Text")
        {
            fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->txtstring = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,11);
            tempShapes->txtcolor = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,15);
            tempShapes->txtalign = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,15);
            tempShapes->txtpntsize = fileString.toInt();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,16);
            tempShapes->txtfontfam = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,15);
            tempShapes->txtfontstyle = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,16);
            tempShapes->txtfontweight = fileString.toStdString();
            fileString.clear();

            paint->setFont(QFont::setWeight(tempShapes->txtfontweight));
            paint->setFont(QFont::setStyle(tempShapes->txtfontstyle));
            paint->setFont(QFont::setFamily(tempShapes->txtfontfam));
            paint->setFont(QFont::setPointSize(tempShapes->txtpntsize));
        }
        else
        {
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

            paint->setPen(QPen::setCapStyle(tempShapes->pencap));
            paint->setPen(QPen::setColor(tempShapes->pencolor));
            paint->setPen(QPen::setWidth(tempShapes->penwidth));
            paint->setPen(QPen::setJoinStyle(tempShapes->penjoin));
            paint->setPen(QPen::setStyle(tempShapes->penstyle));
        }




        switch (shapeType)
        {
        case 0:
            delete tempShapes;
            break;
        case 1:
            delete tempShapes;
            break;
        case 2:  fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushcolor = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushstyle = fileString.toStdString();
            fileString.clear();

            paint->setBrush(QBrush::setColor(tempShapes->brushcolor));
            paint->setBrush(QBrush::setStyle(tempShapes->brushstyle));

            delete tempShapes;
            break;
        case 3: fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushcolor = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushstyle = fileString.toStdString();
            fileString.clear();

            paint->setBrush(QBrush::setColor(tempShapes->brushcolor));
            paint->setBrush(QBrush::setStyle(tempShapes->brushstyle));

            delete tempShapes;
            break;
        case 4:
            fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushcolor = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushstyle = fileString.toStdString();
            fileString.clear();

            paint->setBrush(QBrush::setColor(tempShapes->brushcolor));
            paint->setBrush(QBrush::setStyle(tempShapes->brushstyle));

            delete tempShapes;
            break;
        case 5: fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushcolor = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushstyle = fileString.toStdString();
            fileString.clear();

            paint->setBrush(QBrush::setColor(tempShapes->brushcolor));
            paint->setBrush(QBrush::setStyle(tempShapes->brushstyle));

            delete tempShapes;
            break;
        case 6:
            fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushcolor = fileString.toStdString();
            fileString.clear();

            fileString = fin.readLine();
            fileString.remove(0,12);
            tempShapes->brushstyle = fileString.toStdString();
            fileString.clear();

            paint->setBrush(QBrush::setColor(tempShapes->brushcolor));
            paint->setBrush(QBrush::setStyle(tempShapes->brushstyle));

            delete tempShapes;
            break;
        case 7:
            delete tempShapes;
            break;

        }
        temp.push_back(tempShapes);

    }
    return temp;
}
