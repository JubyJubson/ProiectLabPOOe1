#include "Video.h"
#include "InvalidVideoLengthException.h"
using namespace std;
Video::Video(string video_name, int like_number, int dislike_number, int video_length, string video_description) {
    this->video_name = std::move(video_name);
    this->like_number = like_number;
    this->dislike_number = dislike_number;
    this->video_length = video_length;
    this->video_description = std::move(video_description);
    totalVideos++;
}

Video::Video(const Video& video) {
    this->video_name = video.video_name;
    this->like_number = video.like_number;
    this->dislike_number = video.dislike_number;
    this->video_length = video.video_length;
    this->video_description = video.video_description;
}

Video :: Video(){
    this -> video_name = "NO NAME";
        this -> like_number = 0;
        this -> dislike_number = 0;
        this -> video_length = 0;
        this -> video_description = "This video doesn't have a description";
        totalVideos ++;
}

std::string Video::GetVideoName() {
    return video_name;
}

int Video::GetLikeNumber() const {
    return like_number;
}

void Video::DislikeVideo() {
    this -> dislike_number++;
}

Video& Video::operator=(const Video& video) = default;


Video:: ~Video() {
    video_description = "There is no description";
    video_name = "There is no name";
    video_length = 0;
    like_number = 0;
    dislike_number = 0;
}

int Video::operator+(const Video& video) const {
    return this->like_number + video.like_number;
}

Video operator++(Video& video) {
    video.like_number++;
    return video;
}

void Video :: show(ostream& out) const{
    out << "            Content Name: " << video_name << endl << endl;
    out << "    Content Length:"<<video_length  << "    Likes: "<<  like_number << "    Dislikes: "<< dislike_number <<endl << endl;
    out << "Content Description: " << video_description << endl << endl;
}

ostream& operator<<(ostream& out, Video* video){
    video->show(out);
    return out;
}

ostream& operator<<(ostream& out, const Video& video){
    video.show(out);
    return out;
}

void Video::citire(std::istream &in) {
    like_number = 0;
    dislike_number = 0;
    cin.get();
    cout << "Video Name: ";
    getline(in, video_name);
    cout << endl;
    cout << "Video Description: ";
    getline(in, video_description);
    cout << "Video Length (please insert a positive number): ";
    try {
        in >> video_length;
        if (video_length < 0) {
            throw InvalidVideoLengthException();
        }
    }
    catch (const std::exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        cerr << "Video length: "; in >> video_length;
    }
    cout << endl;
    totalVideos ++;
}

istream& operator>>(istream& in, Video& video) {
    video.citire(in);
    return in;
}

int Video:: getTotalVideos() {
    return totalVideos;
}

void Video::setTotalVideos(int aux){
    totalVideos = aux;
}

int Video:: totalVideos = -12;