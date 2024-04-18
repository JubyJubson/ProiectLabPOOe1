#include "SponsoredVideo.h"

SponsoredVideo ::SponsoredVideo():Video(), sponsor_name("Unknown"){}
SponsoredVideo ::SponsoredVideo(const string& video_name, int like_number, int dislike_number, int video_length, const string& video_description, const string& sponsor_name):Video(video_name,
                                                                                                                                                                                    like_number, dislike_number, video_length, video_description){
    try {
        if (sponsor_name.empty()){
            throw InvalidSponsorNameException();
        }
        this->sponsor_name = sponsor_name;
    } catch (const std::exception& sp) {
        cerr << "Exception caught: " << sp.what() << endl;
    }
}

SponsoredVideo :: ~SponsoredVideo(){sponsor_name = "Unknown";}
void SponsoredVideo :: show(ostream& out) const{
    out << "This is a Sponsored Video" << "                      Sponsor Name: " << sponsor_name;
    out << endl << "---------------------------------------------------------------" << endl;
    Video::show(out);
}
SponsoredVideo& SponsoredVideo :: operator=(const SponsoredVideo& aux)= default;

void SponsoredVideo::citire(istream & in) {
    Video :: citire(in);
    cout << "Sponsor name: ";
    string sponsor;
    cin.get();
    getline(in,sponsor);
    try {
        if (sponsor.empty()){
            throw InvalidSponsorNameException();
        }
        this -> sponsor_name = sponsor;
    } catch (const exception& sp) {
        cerr << "Exception caught: " << sp.what() << endl;
        cerr << "Sponsor name:"; in >> sponsor;
        this -> sponsor_name = sponsor;
    }
}


