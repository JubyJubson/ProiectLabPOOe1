#include "Video.h"
using namespace std;
Video::Video(std::string video_name, int like_number, int dislike_number, int video_length, std::string video_description) {
    this->video_name = std::move(video_name);
    this->like_number = like_number;
    this->dislike_number = dislike_number;
    this->video_length = video_length;
    this->video_description = std::move(video_description);
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
}

std::string Video::GetVideoName() {
    return video_name;
}

int Video::GetLikeNumber() const {
    return like_number;
}

int Video::GetDislikeNumber() const {
    return dislike_number;
}

int Video::GetVideoLength() const {
    return video_length;
}

std::string Video::GetVideoDesc() {
    return video_description;
}

void Video::LikeVideo() {
    this -> like_number++;
}

void Video::DislikeVideo() {
    this -> dislike_number++;
}

Video& Video::operator=(const Video& video) = default;

std::istream& operator>>(std::istream& in, Video& video) {
    video.like_number = 0;
    video.dislike_number = 0;
    std::cout << "Video Name: ";
    in.get();
    std::getline(in, video.video_name);
    std::cout << std::endl;
    std::cout << "Video Description: ";
    std::getline(in, video.video_description);
    std::cout << "Video Length (please insert a positive number): ";
    in >> video.video_length;
    std::cout << std::endl;
    return in;
}

Video::~Video() {
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

const ostream& operator<<(ostream& out, Video* video){
    out << "Video Name: " << (*video).GetVideoName() << "    Video length: "<< (*video).GetVideoLength() << " minutes    Likes: "<<  (*video).GetLikeNumber() << "    Dislikes: "<< (*video).GetDislikeNumber() << endl;
    out << "Video Description: " << (*video).GetVideoDesc() << endl << endl;
    return out;
}

const ostream& operator<<(ostream& out, Video video){
    out << "Video Name: " << video.GetVideoName() << "    Video length: "<< video.GetVideoLength() << " minutes    Likes: "<<  video.GetLikeNumber() << "    Dislikes: "<< video.GetDislikeNumber() << endl;
    out << "Video Description: " << video.GetVideoDesc() << endl << endl;
    return out;
}