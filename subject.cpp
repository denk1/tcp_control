#include "subject.h"

Subject::Subject()
{

}

uint Subject::getLength() const
{
    return length_;
}

uint Subject::getWidth() const
{
    return width_;
}

uint Subject::getHeight() const
{
    return height_;
}

QString Subject::getProperty()
{
    return strNameProperty_;
}

QString Subject::getType()
{
    return strNameType_;
}

void Subject::setLength(uint l)
{
    length_ = l;
}

void Subject::setWidth(uint w)
{
    width_ = w;
}

void Subject::setHeght(uint h)
{
    height_ = h;
}

void Subject::setProperty(QString strNameProperty)
{
    strNameProperty_ = strNameProperty;
}

void Subject::setType(QString strNameType)
{
    strNameType_ = strNameType;
}
