#ifndef YOUTUBECHANNEL_H
#define YOUTUBECHANNEL_H

#include <iostream>
#include <string>
#include <vector>
#include "Video.h"
#include "SponsoredVideo.h"
#include "SponsoredLivestream.h"

using namespace std;

class YoutubeChannel {
protected:
    string Name;
    string OwnerName;
    string Description;
    int SubscriberCount;
    int Subscribed;
    vector<Video*> PublishedVideosTitles;
    vector<Video> DownloadedVideos;


public:
    YoutubeChannel();
    YoutubeChannel(string Name, string Ownername, string Description);
    void Subscribe();
    void UnSubscribe();
    void PublishVideo(Video* video);
    void DownloadVideo(const Video& video);
    string GetName();
    string GetOwnerName();
    string GetDescription();
    [[nodiscard]] int GetSubscribers() const;
    vector<Video*> GetPublishedVideosTitles();
    vector<Video> GetDownloadedVideos();
    void set_SubscriberCount(int x);
    void set_Name(std::string nume);
    void set_OwnerName(std::string owner);
    void set_Desc(std::string desc);
    friend istream& operator>>(istream& in, YoutubeChannel& canal);
};
ostream& operator<< (ostream& out, YoutubeChannel canal);
#endif // YOUTUBECHANNEL_H
