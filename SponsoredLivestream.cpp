#include "SponsoredLivestream.h"
#include "Video.h"
#include "Livestream.h"

SponsoredLivestream ::SponsoredLivestream():SponsoredVideo(),Livestream(), DiscountCode("0000"){}
SponsoredLivestream ::SponsoredLivestream(const string& video_name, int like_number, int dislike_number, int video_length,
                                          const string& video_description, const string& sponsor_name, int watchers, const string& DiscountCode):
        Video(video_name, like_number, dislike_number, video_length, video_description),
        SponsoredVideo(video_name, like_number, dislike_number, video_length, video_description, sponsor_name),
        Livestream(video_name, like_number, dislike_number, video_length, video_description, watchers)
{this -> DiscountCode = DiscountCode;}
SponsoredLivestream :: ~SponsoredLivestream(){DiscountCode = "0000"; }


void SponsoredLivestream :: show(ostream& out) const{
    Livestream :: show(out);
    out << "    Sponsor name: " << sponsor_name << "            Discount code: " << DiscountCode << endl << endl;
}

SponsoredLivestream& SponsoredLivestream :: operator=(const SponsoredLivestream& aux){
    Video :: operator=(aux);
    SponsoredVideo ::operator=(aux);
    Livestream ::operator=(aux);
    this -> DiscountCode = aux.DiscountCode;
    return *this;
}

void SponsoredLivestream::citire(std::istream & in) {
    SponsoredVideo ::citire(in);
    cout << "Discount code: ";
    in >> DiscountCode;
    cout << endl;
}