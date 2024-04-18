#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
#include "../Content.h"

using namespace std;

class Video : virtual public Content{
protected:
    static int totalVideos;
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
    void DislikeVideo();
    Video& operator=(const Video& video);
    friend istream& operator>>(istream& in, Video& video);
    ~Video() override;
    int operator+(const Video& video) const;
    friend Video operator++(Video& video);
    void show(ostream& out) const override;
    virtual void citire(istream& in);
    friend ostream& operator<<(ostream&, const Video&);
    friend ostream& operator<<(ostream&, Video*);
    static int getTotalVideos();
    static void setTotalVideos(int aux);

};

#endif // VIDEO_H
