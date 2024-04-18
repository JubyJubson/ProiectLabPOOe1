#include "Livestream.h"
Livestream :: Livestream():Video(), watchers(1){}
Livestream :: Livestream([[maybe_unused]] string video_name, int like_number, int dislike_number, int video_length,
                         [[maybe_unused]] string video_description, int watchers):Video(std::move(video_name),
                        like_number, dislike_number, video_length, std::move(video_description)), watchers(watchers){}
Livestream :: ~Livestream(){watchers = 0;}

void Livestream :: show(ostream& out) const{
    out << "This is a Livestream" << "                      People Watching: " << watchers;
    out << endl << "---------------------------------------------------------------";
    out << endl;
    Video::show(out);
}
Livestream& Livestream :: operator=(const Livestream& aux)= default;

void Livestream::citire(std::istream & in){
    Video ::citire(in);
}