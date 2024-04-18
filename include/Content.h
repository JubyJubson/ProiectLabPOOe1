#ifndef OOP_CONTENT_H
#define OOP_CONTENT_H
#include <iostream>
using namespace std;

class Content{
public:
    virtual void show(ostream&) const = 0;
    virtual ~Content();
};
#endif //OOP_CONTENT_H
