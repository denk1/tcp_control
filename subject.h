#ifndef SUBJECT_H
#define SUBJECT_H
#include <QVector>

class Subject
{
public:
    Subject();

    uint getLength() const;
    uint getWidth() const;
    uint getHeight() const;
    QString getProperty();
    QString getType();

    void setLength(uint l);
    void setWidth(uint w);
    void setHeght(uint h);
    void setProperty(QString strNameProperty);
    void setType(QString strNameType);

private:
    uint length_;
    uint width_;
    uint height_;
    QString strNameType_;
    QString strNameProperty_;

};

#endif // SUBJECT_H
