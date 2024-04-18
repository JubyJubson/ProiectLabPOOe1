#ifndef OOP_SPONSOREDLIVESTREAM_H
#define OOP_SPONSOREDLIVESTREAM_H
#include <iostream>
#include "SponsoredVideo.h"
#include "Livestream.h"
#include <vector>
using namespace std;

class SponsoredLivestream : public SponsoredVideo, public Livestream{
    string DiscountCode;
public:
    SponsoredLivestream();
    SponsoredLivestream([[maybe_unused]] const string&, int, int, int, [[maybe_unused]] const string&, [[maybe_unused]] const string&, int, const string& );
    ~SponsoredLivestream() override;
    [[maybe_unused]] string GetDiscountCode(){
        return this->DiscountCode;
    }
    void show(ostream&) const override;
    SponsoredLivestream& operator=(const SponsoredLivestream&);
    void citire(istream&) override;
};
#endif //OOP_SPONSOREDLIVESTREAM_H
