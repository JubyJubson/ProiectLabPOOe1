#ifndef OOP_SPONSOREDVIDEO_H
#define OOP_SPONSOREDVIDEO_H
#include <iostream>
#include <string>
#include "Video.h"
#include "InvaliSponsorNameException.h"
using namespace std;

class SponsoredVideo : virtual public Video{
protected:
    string sponsor_name;
public:
    SponsoredVideo();
    SponsoredVideo(const string&, int, int, int , const string&, const string&);
    ~SponsoredVideo() override;
    [[maybe_unused]] string GetSponsorName(){
        return this -> sponsor_name;
    }
    void show(ostream&) const override;
    SponsoredVideo& operator=(const SponsoredVideo&);
    void citire(istream&) override;
};

#endif //OOP_SPONSOREDVIDEO_H
