#include "SponsoredLivestream.h"
#include "Video.h"
#include "Livestream.h"

#include <utility>
SponsoredLivestream ::SponsoredLivestream():SponsoredVideo(),Livestream(), DiscountCode("0000"){}
SponsoredLivestream ::SponsoredLivestream([[maybe_unused]] string video_name, int like_number, int dislike_number, int video_length,
                                          [[maybe_unused]] string video_description, [[maybe_unused]] string sponsor_name, int watchers, string DiscountCode):
                                          Video(std::move(video_name), like_number, dislike_number, video_length, std::move(video_description)),
                                          SponsoredVideo(std::move(video_name), like_number, dislike_number, video_length, std::move(video_description), std::move(sponsor_name)),
                                          Livestream(std::move(video_name), like_number, dislike_number, video_length, std::move(video_description), watchers),
                                          DiscountCode(std::move(DiscountCode))
                                          {}
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
}

void SponsoredLivestream::citire(std::istream & in) {
    SponsoredVideo ::citire(in);
    cout << "Discount code: ";
    in >> DiscountCode;
    cout << endl;
}