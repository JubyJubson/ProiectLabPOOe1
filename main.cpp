#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;
class Video{
private:
    string video_name;
    int like_number;
    int dislike_number;
    int video_length;
    string video_description;
public:
    Video(string video_name, int like_number, int dislike_number, int video_length, string video_description){
        this -> video_name = std::move(video_name);
        this -> like_number = like_number;
        this -> dislike_number = dislike_number;
        this -> video_length = video_length;
        this -> video_description = std::move(video_description);
    }

    Video(const Video& video){
        this -> video_name = video.video_name;
        this -> like_number = video.like_number;
        this -> dislike_number = video.dislike_number;
        this -> video_length = video.video_length;
        this -> video_description = video.video_description;
    }
    string GetVideoName(){
        return video_name;
    }
    [[nodiscard]] int GetLikeNumber() const{
        return like_number;
    }
    [[nodiscard]] int GetDislikeNumber() const{
        return dislike_number;
    }
    [[nodiscard]] int GetVideoLenght() const{
        return video_length;
    }
    string GetVideoDesc(){
        return video_description;
    }

    void Like_video(){
        this -> like_number ++;
    }

    void Dislike_video(){
        this -> dislike_number ++;
    }
    Video(){
        this -> video_name = "NO NAME";
        this -> like_number = 0;
        this -> dislike_number = 0;
        this -> video_length = 0;
        this -> video_description = "This video doesn't have a description";
    }

    Video& operator=(const Video& video)= default;

    friend istream& operator>>(istream& in, Video& video){
        video.like_number = 0;
        video.dislike_number = 0;
        cout << "Video Name: ";
        in.get();
        std::getline(in, video.video_name);
        cout << endl;
        cout << "Video Description: ";
        std::getline(in,video.video_description);
        cout << "Video Length(please insert a positive number): ";
        in >> video.video_length;
        cout << endl;
        return in;
    }

    ~Video(){
        video_description = "There is no description";
        video_name = "There is no name";
        video_length = 0;
        like_number = 0;
        dislike_number = 0;
    }

    int operator+(const Video& video) const{
        return  this->like_number + video.like_number;
    }

    friend Video operator++ (Video& video){
        video.like_number ++;
        return video;
    }

};
class YoutubeChannel{
private:
    string Name;
    string OwnerName;
    string Description;
    int SubscriberCount;
    int Subscribed;
    vector<Video*> PublishedVideosTitles;
    vector<Video> DownloadedVideos;
public:
    YoutubeChannel(){
        this -> Name = "Guest";
        this -> OwnerName = "Nu a fost precizat";
        this -> Description ="Nu a fost precizat";
        this -> SubscriberCount = 0;
        this -> Subscribed = 0;
    }

    YoutubeChannel(string Name, string Ownername, string Description){
        this -> Name = std::move(Name);
        this -> OwnerName = std::move(Ownername);
        this -> Description = std::move(Description);
        this -> SubscriberCount = 0;
        this -> Subscribed = 0;
    }

    void Subscribe(){
        if (Subscribed == 0) {
            SubscriberCount++;
            Subscribed = 1;
            cout << "You have subscribed to this Channel";
        }
        else
            cout << "You are already subscribed to this Channel!";
    }


    void UnSubscribe() {
        if (Subscribed == 1) {
            SubscriberCount--;
            Subscribed = 0;
            cout << "You have unsubscribed from this Channel!";
        }
        else
            cout << "You can't unsubscribe from a channel you aren't subscribed to!";
    }


    void PublishVideo(Video* video){
        PublishedVideosTitles.push_back(video);
    }

    void DownloadVideo(const Video& video){
        DownloadedVideos.push_back(video);
    }

    string GetName(){
        return Name;
    }

    string GetOwnerName(){
        return OwnerName;
    }

    string GetDescription(){
        return Description;
    }

    [[nodiscard]] int GetSubscribers() const{
        return SubscriberCount;
    }

    vector<Video*> GetPublishedVideosTitles(){
        return PublishedVideosTitles;
    }
    vector<Video> GetDownloadedVideos(){
        return DownloadedVideos;
    }

//    [[nodiscard]] int GetSubscribed() const{
//        return Subscribed;
//    }

    void set_SubscriberCount(int x){
        this ->SubscriberCount = x;
    }

    void set_Name(string nume){
        this -> Name = std::move(nume);
    }

    void set_OwnerName(string owner){
        this -> OwnerName = std::move(owner);
    }

    void set_Desc(string desc){
        this -> Description = std::move(desc);
    }

friend istream& operator>>(istream& in, YoutubeChannel& canal){
        cout << "Channel Name: ";
        in.get();
        std::getline(in, canal.Name);
        cout << endl;
        cout << "Owner Name: ";
        std::getline(in, canal.OwnerName);
        cout << endl;
        cout << "Channel Description:";
        std::getline(in, canal.Description);
        cout << endl;
        canal.SubscriberCount = 0;
        return in;
    }

};
const ostream& operator<<(ostream& out, Video* video){
    out << "Video Name: " << (*video).GetVideoName() << "    Video length: "<< (*video).GetVideoLenght()<< " minutes    Likes: "<<  (*video).GetLikeNumber() << "    Dislikes: "<< (*video).GetDislikeNumber() << endl;
    out << "Video Description: " << (*video).GetVideoDesc() << endl << endl;
    return out;
}

const ostream& operator<<(ostream& out, Video video){
    out << "Video Name: " << video.GetVideoName() << "    Video length: "<< video.GetVideoLenght()<< " minutes    Likes: "<<  video.GetLikeNumber() << "    Dislikes: "<< video.GetDislikeNumber() << endl;
    out << "Video Description: " << video.GetVideoDesc() << endl << endl;
    return out;
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


int main() {
    vector<YoutubeChannel> ListaCanale;

    YoutubeChannel canal1("Victoryx", "Fugulin Victor", "Canal de League of Legends - Fiora OTP");
    canal1.set_SubscriberCount(87);
    Video v1("Primul meu video - LoL ep.1", 10, 3, 8, "Acesta este primul meu video in care imi voi etala maestria cu campionul Fiora");
    Video v2("Ranked cu colegul de camera(Mihaita) - LoL ep.2", 20, 8, 30, "Fiora gameplay - OP.GG: JimTheMan");
    Video v3("Incepem Climb-ul la SoloQueue - LoL ep.3", 50, 13, 23, "La limita de emerald - Fiora gameplay - OP.GG: JimTheMan");
    Video * ptr1 = &v1, *ptr2 = &v2, *ptr3 = &v3;
    canal1.PublishVideo(ptr1);
    canal1.PublishVideo(ptr2);
    canal1.PublishVideo(ptr3);

    ListaCanale.push_back(canal1);

    YoutubeChannel canal2("DeniPeni", "Denisa Ioana !GOSOIU!", "Pentru cei pasionati de arta");
    canal2.set_SubscriberCount(671);
    Video v4("Picturile mele ep.1 - Peisaje Tomanale", 61, 9, 17, "Primele mele peisaje tomanle, sper ca o sa va placa!");
    Video v5("Picturile mele ep.2- Peisaje de Vara", 124, 15, 26, "Primele mele peisaje de primavara, sper ca o sa va placa!");
    Video v6("Picturile mele ep.3- Opere obscure ", 322, 28, 10, "Peisaje mai obscure folosind tehnica clar-obscurului, sper ca o sa va placa!");
    Video * ptr4 = &v4, * ptr5 = &v5, * ptr6 = &v6;
    canal2.PublishVideo(ptr4);
    canal2.PublishVideo(ptr5);
    canal2.PublishVideo(ptr6);
    ListaCanale.push_back(canal2);

    YoutubeChannel canal3("Profu XXL", "Fugulin Daniel Valentin", "Pregatiri Bac si Admitere");
    canal3.set_SubscriberCount(1782);
    Video v7("Rezolvari Simulare Matematica Sub I - 2024", 174, 14, 30, "Invata matematica cu ProfuXXL");
    Video v8("Rezolvari Simulare Matematica Sub II - 2024", 253, 25, 45, "Invata matematica cu ProfuXXL");
    Video v9("Rezolvari Simulare Matematica Sub III - 2024", 451, 32, 60, "Invata matematica cu ProfuXXL");
    Video * ptr7 = &v7, * ptr8 = &v8, * ptr9 = &v9;
    canal3.PublishVideo(ptr7);
    canal3.PublishVideo(ptr8);
    canal3.PublishVideo(ptr9);

    ListaCanale.push_back(canal3);

    Video v1_nou, v2_nou, v3_nou;
    Video* ptr1_nou, *ptr2_nou, *ptr3_nou;
    YoutubeChannel canal_download;
    string download_name, download_description;
    int download_length;
    cout << "                          WELCOME TO YOUTUBE                                    " << endl;
    cout << "To view all YouTube Channels - Press 1" << endl;
    cout << "To view you Channel - Press 2" << endl;
    cout << "To make a new Channel - Press 3" << endl;
    cout << "To download videos - Press 4" << endl;
    cout << endl << "EXIT - Press 0" << endl;
    int download;
    int x;
    int z;
    int y;
    int b;
    int n;
    int nou = 0;
    int nr_video = 1;
    cin >> x;
    while(x) {
        switch (x) {
            case 1: {
                for (unsigned long long i = 0; i < ListaCanale.size(); i++) {
                    cout << "Press " << i + 1 << " to visit this channnel:" << endl;
                    cout << ListaCanale.at(i);
                        if (i == 0)
                            cout << "         Total number of likes: " << v1 + v2 + v3.GetLikeNumber()<< endl;
                        else if (i == 1)
                            cout << "         Total number of likes: " << v4 + v5 + v6.GetLikeNumber()<< endl;
                        else if (i == 2)
                            cout << "         Total number of likes: " << v7 + v8 + v9.GetLikeNumber()<< endl;
                        else
                            cout << "         Total number of likes: " << v1_nou + v2_nou + v3_nou.GetLikeNumber()<< endl;
                    cout << endl;
                }

                cout << "Return to main menu - Press 0" << endl;
                cin >> y;
                switch (y) {
                    case 1:
                        cout << "Channel name: " << ListaCanale.at(0).GetName()
                             << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                        for (unsigned long long i = 0, j = 3; i < ListaCanale.at(0).GetPublishedVideosTitles().size(); i++, j += 2) {
                            cout << "-" << canal1.GetPublishedVideosTitles().at(i);
                            cout << "          Press " << j << " to like this video      Press " << j + 1
                                 << " to dislike this video" << endl << endl;
                        }
                        cout << endl << "Return to the main menu - Press 0" << endl;


                        cin >> z;
                        while (z) {
                            switch (z) {
                                case 1:
                                    canal1.Subscribe();
                                    cout << endl;
                                    cout << canal1;
                                    cout << endl << endl;
                                    break;
                                case 2:
                                    canal1.UnSubscribe();
                                    cout << endl;
                                    cout << canal1;
                                    cout << endl << endl;
                                    break;
                                case 3:
                                    ++*canal1.GetPublishedVideosTitles().at(0);
                                    cout << canal1.GetPublishedVideosTitles().at(0);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 4:
                                    canal1.GetPublishedVideosTitles().at(0)->Dislike_video();
                                    cout << canal1.GetPublishedVideosTitles().at(0);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                case 5:
                                    ++*canal1.GetPublishedVideosTitles().at(1);
                                    cout << canal1.GetPublishedVideosTitles().at(1);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 6:
                                    canal1.GetPublishedVideosTitles().at(1)->Dislike_video();
                                    cout << canal1.GetPublishedVideosTitles().at(1);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                case 7:
                                    ++*canal1.GetPublishedVideosTitles().at(2);
                                    cout << canal1.GetPublishedVideosTitles().at(2);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 8:
                                    canal1.GetPublishedVideosTitles().at(2)->Dislike_video();
                                    cout << canal1.GetPublishedVideosTitles().at(2);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                default:
                                    break;
                            }
                            cout << "Press 1 to return to " << canal1.GetName()
                                 << "'s channel             Press 0 to return to the main menu" << endl;
                            cin >> b;
                            if (b == 0) break;
                            cout << "Channel name: " << ListaCanale.at(0).GetName()
                                 << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                            for (unsigned long long i = 0, j = 3; i < ListaCanale.at(0).GetPublishedVideosTitles().size(); i++, j += 2) {
                                cout << "-" << canal1.GetPublishedVideosTitles().at(i);
                                cout << "          Press " << j << " to like this video      Press " << j + 1
                                     << " to dislike this video" << endl << endl;
                            }
                            cout << endl << "Return to the main menu - Press 0" << endl;
                            cin >> z;
                        }
                        break;
                    case 2:
                        cout << "Channel name: " << ListaCanale.at(1).GetName()
                             << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                        for (unsigned long long i = 0, j = 3;
                             i < ListaCanale.at(1).GetPublishedVideosTitles().size(); i++, j += 2) {
                            cout << "-" << canal2.GetPublishedVideosTitles().at(i);
                            cout << "          Press " << j << " to like this video      Press " << j + 1
                                 << " to dislike this video" << endl << endl;
                        }
                        cout << endl << "Return to the main menu - Press 0" << endl ;
                        cin >> z;
                        while (z) {
                            switch (z) {
                                case 1:
                                    canal2.Subscribe();
                                    cout << endl;
                                    cout << canal2;
                                    cout << endl << endl;

                                    break;
                                case 2:
                                    canal2.UnSubscribe();
                                    cout << endl;
                                    cout << canal2;
                                    cout << endl << endl;
                                    break;
                                case 3:
                                    ++*canal2.GetPublishedVideosTitles().at(0);
                                    cout << canal2.GetPublishedVideosTitles().at(0);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 4:
                                    canal2.GetPublishedVideosTitles().at(0)->Dislike_video();
                                    cout << canal2.GetPublishedVideosTitles().at(0);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                case 5:
                                    ++*canal2.GetPublishedVideosTitles().at(1);
                                    cout << canal2.GetPublishedVideosTitles().at(1);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 6:
                                    canal2.GetPublishedVideosTitles().at(1)->Dislike_video();
                                    cout << canal2.GetPublishedVideosTitles().at(1);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                case 7:
                                   ++*canal2.GetPublishedVideosTitles().at(2);
                                    cout << canal2.GetPublishedVideosTitles().at(2);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 8:
                                    canal2.GetPublishedVideosTitles().at(2)->Dislike_video();
                                    cout << canal2.GetPublishedVideosTitles().at(2);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                default:
                                    break;
                            }
                            cout << "Press 1 to return to " << canal2.GetName()
                                 << "'s channel             Press 0 to return to the main menu" << endl;
                            cin >> b;
                            if (b == 0)
                                break;
                            cout << "Channel name: " << ListaCanale.at(1).GetName()
                                 << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                            for (unsigned long long i = 0, j = 3;
                                 i < ListaCanale.at(1).GetPublishedVideosTitles().size(); i++, j += 2) {
                                cout << "-" << canal2.GetPublishedVideosTitles().at(i);
                                cout << "          Press " << j << " to like this video      Press " << j + 1
                                     << " to dislike this video" << endl << endl;
                            }
                            cout << endl << "Return to the main menu - Press 0" << endl;
                            cin >> z;
                        }
                        break;
                    case 3:
                        cout << "Channel name: " << ListaCanale.at(2).GetName()
                             << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                        for (unsigned long long i = 0, j = 3;
                             i < ListaCanale.at(2).GetPublishedVideosTitles().size(); i++, j += 2) {
                            cout << "-" << canal3.GetPublishedVideosTitles().at(i);
                            cout << "          Press " << j << " to like this video      Press " << j + 1
                                 << " to dislike this video" << endl << endl;
                        }
                        cout << endl << "Return to the main menu - Press 0" << endl ;
                        cin >> z;
                        while (z) {
                            switch (z) {
                                case 1:
                                    canal3.Subscribe();
                                    cout << endl;
                                    cout << canal3;
                                    cout << endl << endl;
                                    break;
                                case 2:
                                    canal3.UnSubscribe();
                                    cout << endl;
                                    cout << canal3;
                                    cout << endl << endl;
                                    break;
                                case 3:
                                    ++*canal3.GetPublishedVideosTitles().at(0);
                                    cout << canal3.GetPublishedVideosTitles().at(0);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 4:
                                    canal3.GetPublishedVideosTitles().at(0)->Dislike_video();
                                    cout << canal3.GetPublishedVideosTitles().at(0);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                case 5:
                                    ++*canal3.GetPublishedVideosTitles().at(1);
                                    cout << canal3.GetPublishedVideosTitles().at(1);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 6:
                                    canal3.GetPublishedVideosTitles().at(1)->Dislike_video();
                                    cout << canal3.GetPublishedVideosTitles().at(1);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                case 7:
                                    ++*canal3.GetPublishedVideosTitles().at(2);
                                    cout << canal3.GetPublishedVideosTitles().at(2);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 8:
                                    canal3.GetPublishedVideosTitles().at(2)->Dislike_video();
                                    cout << canal3.GetPublishedVideosTitles().at(2);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                default:
                                    break;
                            }
                            cout << "Press 1 to return to " << canal3.GetName()
                                 << "'s channel             Press 0 to return to the main menu" << endl;
                            cin >> b;
                            if (b == 0)
                                break;
                            cout << "Channel name: " << ListaCanale.at(2).GetName()
                                 << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                            for (unsigned long long i = 0, j = 3;
                                 i < ListaCanale.at(2).GetPublishedVideosTitles().size(); i++, j += 2) {
                                cout << "-" << canal3.GetPublishedVideosTitles().at(i);
                                cout << "          Press " << j << " to like this video      Press " << j + 1
                                     << " to dislike this video" << endl << endl;
                            }
                            cout << endl << "Return to the main menu - Press 0" << endl;
                            cin >> z;
                        }
                        break;
                    case 4:
                        cout << "Channel name: " << ListaCanale.at(3).GetName()
                             << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                        for (unsigned long long i = 0, j = 3;
                             i < ListaCanale.at(3).GetPublishedVideosTitles().size(); i++, j += 2) {
                            cout << "-" << ListaCanale.at(3).GetPublishedVideosTitles().at(i);
                            cout << "          Press " << j << " to like this video      Press " << j + 1
                                 << " to dislike this video" << endl << endl;
                        }
                        cout << endl << "Return to the main menu - Press 0" << endl ;
                        cin >> z;
                        while (z) {
                            switch (z) {
                                case 1:
                                    ListaCanale.at(3).Subscribe();
                                    cout << endl;
                                    cout <<  ListaCanale.at(3);
                                    cout << endl << endl;
                                    break;
                                case 2:
                                    ListaCanale.at(3).UnSubscribe();
                                    cout << endl;
                                    cout <<  ListaCanale.at(3);
                                    cout << endl << endl;
                                    break;
                                case 3:
                                    ListaCanale.at(3).GetPublishedVideosTitles().at(0)->Like_video();
                                    cout <<  ListaCanale.at(3).GetPublishedVideosTitles().at(0);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 4:
                                    ListaCanale.at(3).GetPublishedVideosTitles().at(0)->Dislike_video();
                                    cout <<  ListaCanale.at(3).GetPublishedVideosTitles().at(0);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                case 5:
                                    ListaCanale.at(3).GetPublishedVideosTitles().at(1)->Like_video();
                                    cout <<  ListaCanale.at(3).GetPublishedVideosTitles().at(1);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 6:
                                    ListaCanale.at(3).GetPublishedVideosTitles().at(1)->Dislike_video();
                                    cout <<  ListaCanale.at(3).GetPublishedVideosTitles().at(1);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                case 7:
                                    ListaCanale.at(3).GetPublishedVideosTitles().at(2)->Like_video();
                                    cout <<  ListaCanale.at(3).GetPublishedVideosTitles().at(2);
                                    cout << "You have liked this video!" << endl;
                                    break;
                                case 8:
                                    ListaCanale.at(3).GetPublishedVideosTitles().at(2)->Dislike_video();
                                    cout <<  ListaCanale.at(3).GetPublishedVideosTitles().at(2);
                                    cout << "You have disliked this video!" << endl;
                                    break;
                                default:
                                    break;
                            }
                            cout << "Press 1 to return to " <<  ListaCanale.at(3).GetName()
                                 << "'s channel             Press 0 to return to the main menu" << endl;
                            cin >> b;
                            if (b == 0)
                                break;
                            cout << "Channel name: " << ListaCanale.at(3).GetName()
                                 << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                            for (unsigned long long i = 0, j = 3;
                                 i < ListaCanale.at(3).GetPublishedVideosTitles().size(); i++, j += 2) {
                                cout << "-" <<  ListaCanale.at(3).GetPublishedVideosTitles().at(0);
                                cout << "          Press " << j << " to like this video      Press " << j + 1
                                     << " to dislike this video" << endl << endl;
                            }
                            cout << endl << "Return to the main menu - Press 0" << endl;
                            cin >> z;
                        }
                        break;
                    default:
                        break;
                }
                break;
                case 2:
                    if (nou == 1){
                        string nume_nou;
                        string owner_nou;
                        string desc_nou;
//                        Video v1_nou, v2_nou, v3_nou;
//                        Video* ptr1_nou, *ptr2_nou, *ptr3_nou;
                        cout << ListaCanale.at(3);
                        cout << endl;
                        cout << "Publish a new video - Press 1"<< endl;
                        cout << "Change your channel name - Press 2" << endl;
                        cout << "Change your channel owner name - Press 3" << endl;
                        cout << "Change your channel description - Press 4" << endl;
                        cout << endl << "Return to main menu - Press 0" << endl;
                        cin >> x;
                        switch (x){
                            case 1:
                                if (nr_video == 1){
                                    cout << "Your first video will be:" << endl;
                                    cin >> v1_nou;
                                    ptr1_nou = &v1_nou;
                                    ListaCanale.at(3).PublishVideo(ptr1_nou);
                                    cout << "You posted this video on your channel: " << endl;
                                    cout << ListaCanale.at(3).GetPublishedVideosTitles().at(0);
                                    nr_video ++;
                                }
                                else if(nr_video == 2){
                                    cout <<"Your second video will be:" << endl;
                                    cin >> v2_nou;
                                    ptr2_nou = &v2_nou;
                                    ListaCanale.at(3).PublishVideo(ptr2_nou);
                                    cout << "You posted this video on your channel: " << endl;
                                    cout << ListaCanale.at(3).GetPublishedVideosTitles().at(1);
                                    nr_video ++;
                                }
                                else if(nr_video == 3){
                                    cout << "Your third video will be and final video (for now) will be:" << endl;
                                    cin >> v3_nou;
                                    ptr3_nou = &v3_nou;
                                    ListaCanale.at(3).PublishVideo(ptr3_nou);
                                    cout << "You posted this video on your channel: " << endl;
                                    cout << ListaCanale.at(3).GetPublishedVideosTitles().at(2);
                                    nr_video ++;
                                }
                                else
                                    cout << "You have reached the max limit of videos you can post for now - We are working on incresing the limit, stay tuned!" << endl;
                                break;
                            case 2:
                                cout << "New Name: ";
                                cin.get();
                                std::getline(cin,nume_nou);
                                ListaCanale.at(3).set_Name(nume_nou);
                                cout << "       Your channel has been modified!" << endl << endl;
                                break;
                            case 3:
                                cout << "New Owner Name: ";
                                cin.get();
                                std::getline(cin,owner_nou);
                                ListaCanale.at(3).set_OwnerName(owner_nou);
                                cout << "       Your channel has been modified!" << endl << endl;
                                break;
                            case 4:
                                cout << "New Description: ";
                                cin.get();
                                std::getline(cin,desc_nou);
                                ListaCanale.at(3).set_Desc(desc_nou);
                                cout << "       Your channel has been modified!" <<endl << endl;
                                break;
                            default:
                                break;
                        }
                    }
                    else
                        cout << "You don't have a channel - Make one by pressing 3" << endl;
                break;
                case 3:
                    if (nou == 0){
                        YoutubeChannel canal_nou;
                        cin >> canal_nou;
                        ListaCanale.push_back(canal_nou);
                        nou = 1;
                        cout << "Your brand new channel is ready!        You can view it by pressing 1 or modify it by pressing 2!" << endl;
                    }
                    else
                        cout <<"You already have a channel - Press 2 to modify it!" << endl;
                break;
                case 4:
                    cout<<"Press 1 to download videos or press 2 to view your downloaded videos: ";
                    cin >> download;
                    cout << endl;
                    if (download == 1) {
                        cout << "Please insert the number of videos you want to download:  " << endl;
                        cin >> n;
                        for (int i = 1; i <= n; i++) {
                            cout << "Video number " << i << " will be: " << endl;
                            cout << "Name:";
                            cin.get();
                            getline(cin, download_name);
                            cout << endl;
                            cout << "Description:";
                            getline(cin, download_description);
                            cout << "Length:";
                            cin >> download_length;
                            canal_download.DownloadVideo(
                                    Video(download_name, 0, 0, download_length, download_description));
                        }
                    }
                    else{
                        if (canal_download.GetDownloadedVideos().empty()) {
                            cout << "You don't have any downloaded videos, download some by pressing 4 and then 1 to see them here!" << endl;
                            break;
                        }
                        for (unsigned long long i = 0; i < canal_download.GetDownloadedVideos().size(); i++) {
                            cout << "Video number " << i + 1 << " is: " << endl;
                            cout << canal_download.GetDownloadedVideos().at(i);
                        }
                    }
                    break;
                default:
                    break;

            }

        }
        cout << "                          WELCOME TO YOUTUBE                                    " << endl;
        cout << "To view all YouTube Channels - Press 1" << endl;
        cout << "To view you Channel - Press 2" << endl;
        cout << "To make a new Channel - Press 3" << endl;
        cout << "To download videos - Press 4" << endl;
        cout << endl << "EXIT - Press 0" << endl;
        cin >> x;
    }
    return 0;
}
