#include "Shorts.h"

void Shorts::show(ostream &out) const {
    Video::show(out);
    out <<"Background music: " << backgroundMusic << endl << endl;
}

void Shorts::citire(istream &in) {
    Video::citire(in);
    cout << "Background music: ";
    cin.get();
    getline(in,backgroundMusic);

}

Shorts& Shorts::operator=(const Shorts & aux) = default;

Shorts::Shorts():Video(), backgroundMusic("No Music"){}

Shorts::Shorts(const string& video_name, int like_number, int dislike_number, int video_length, const string& video_description, const string& backgroundMusic):
Video(video_name,like_number, dislike_number, video_length, video_description){
    this -> backgroundMusic = backgroundMusic;
}

Shorts::~Shorts() {
backgroundMusic = "No Music";
}


