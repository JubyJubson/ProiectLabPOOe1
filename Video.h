#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>

using namespace std;

class Video {
private:
    string video_name;
    int like_number;
    int dislike_number;
    int video_length;
    string video_description;

public:
    Video(string video_name, int like_number, int dislike_number, int video_length, string video_description);
    Video(const Video& video);
    Video();
    string GetVideoName();
    [[nodiscard]] int GetLikeNumber() const;
    [[nodiscard]] int GetDislikeNumber() const;
    [[nodiscard]] int GetVideoLength() const;
    string GetVideoDesc();
    void LikeVideo();
    void DislikeVideo();
    Video& operator=(const Video& video);
    friend istream& operator>>(istream& in, Video& video);
    ~Video();
    int operator+(const Video& video) const;
    friend Video operator++(Video& video);
};
const ostream& operator<<(ostream& out, Video* video);
const ostream& operator<<(ostream& out, Video video);
#endif // VIDEO_H
