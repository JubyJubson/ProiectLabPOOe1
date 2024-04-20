#ifndef OOP_SHORTS_H
#define OOP_SHORTS_H
#include "Video.h"
#include <iostream>
#include <string>
using namespace std;
class Shorts : virtual public Video{
string backgroundMusic;
public:
    Shorts();
    Shorts(const string&, int, int, int, const string&, const string&);
    void show(ostream& out) const override;
    void citire(istream& in) override;
    Shorts& operator=(const Shorts&);
    ~Shorts() override;
};

#endif //OOP_SHORTS_H
