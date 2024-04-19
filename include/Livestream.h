#ifndef OOP_LIVESTREAM_H
#define OOP_LIVESTREAM_H
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;

class Livestream : virtual public Video{
protected:
    int watchers;
public:
    Livestream();
    Livestream([[maybe_unused]] const string&, int, int, int, [[maybe_unused]] const string&, int);
    ~Livestream() override;
    [[maybe_unused]] [[nodiscard]] int GetWatchers() const{
        return this -> watchers;
    }
    void show(ostream&) const override;
    Livestream& operator=(const Livestream&);
    void citire(istream&) override;
};

#endif //OOP_LIVESTREAM_H
