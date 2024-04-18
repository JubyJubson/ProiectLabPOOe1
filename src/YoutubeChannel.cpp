#include "YoutubeChannel.h"
#include "Video.h"
using namespace std;
YoutubeChannel::YoutubeChannel() {
    this->Name = "Guest";
    this->OwnerName = "Nu a fost precizat";
    this->Description = "Nu a fost precizat";
    this->SubscriberCount = 0;
    this->Subscribed = 0;
}

YoutubeChannel::YoutubeChannel(string Name, string Ownername, string Description) {
    this->Name = std::move(Name);
    this->OwnerName = std::move(Ownername);
    this->Description = std::move(Description);
    this->SubscriberCount = 0;
    this->Subscribed = 0;
}

void YoutubeChannel::Subscribe() {
    if (Subscribed == 0) {
        SubscriberCount++;
        Subscribed = 1;
        cout << "You have subscribed to this Channel";
    } else
        cout << "You are already subscribed to this Channel!";
}

void YoutubeChannel::UnSubscribe() {
    if (Subscribed == 1) {
        SubscriberCount--;
        Subscribed = 0;
        cout << "You have unsubscribed from this Channel!";
    } else
        cout << "You can't unsubscribe from a channel you aren't subscribed to!";
}

void YoutubeChannel::PublishVideo(Video* video) {
    PublishedVideosTitles.push_back(video);
}

void YoutubeChannel::DownloadVideo(const Video& video) {
    DownloadedVideos.push_back(video);
}

string YoutubeChannel::GetName() {
    return Name;
}

string YoutubeChannel::GetOwnerName() {
    return OwnerName;
}

string YoutubeChannel::GetDescription() {
    return Description;
}

int YoutubeChannel::GetSubscribers() const {
    return SubscriberCount;
}

vector<Video*> YoutubeChannel::GetPublishedVideosTitles() {
    return PublishedVideosTitles;
}

vector<Video> YoutubeChannel::GetDownloadedVideos() {
    return DownloadedVideos;
}

void YoutubeChannel::set_SubscriberCount(int x) {
    this->SubscriberCount = x;
}

void YoutubeChannel::set_Name(std::string nume) {
    this->Name = std::move(nume);
}

void YoutubeChannel::set_OwnerName(std::string owner) {
    this->OwnerName = std::move(owner);
}

void YoutubeChannel::set_Desc(std::string desc) {
    this->Description = std::move(desc);
}

istream& operator>>(std::istream& in, YoutubeChannel& canal) {
    cout << "Channel Name: ";
    in.get();
    getline(in, canal.Name);
    cout << std::endl;
    cout << "Owner Name: ";
    getline(in, canal.OwnerName);
    cout << std::endl;
    cout << "Channel Description:";
    getline(in, canal.Description);
    cout << std::endl;
    canal.SubscriberCount = 0;
    return in;
}

ostream& operator<< (ostream& out, YoutubeChannel canal){
    out << "------------------------------Channel Name: " << canal.GetName() <<"--------------------------------------" << endl;
    out << "Owner name: " << canal.GetOwnerName() <<  "    Channel description: "<< canal.GetDescription()<< endl;
    out << "Subscriber count: " << canal.GetSubscribers();
//    out << "Posted Videos:" << endl;
//    for (Video* video : canal.GetPublishedVideosTitles())
//        out << "- " <<  video ;
    return out;
}