#include <iostream>
#include <vector>
#include <string>
#include "Video.h"
#include "YoutubeChannel.h"
#include "SponsoredVideo.h"
#include "Livestream.h"
#include "SponsoredLivestream.h"
#include <exception>

using namespace std;
int main() {
    vector<YoutubeChannel>ListaCanale;
//    try {
//        Video invalidVideo("Invalid Video", 0, 0, -1, "This video has an invalid length");
//    } catch (const std::exception& e) {
//        std::cerr << "Exception caught: " << e.what() << std::endl;
//    }

    YoutubeChannel canal1("Victoryx", "Fugulin Victor", "Canal de League of Legends - Fiora OTP");
    canal1.set_SubscriberCount(87);
    Video v1("Primul meu video - LoL ep.1", 10, 3, 8, "Acesta este primul meu video in care imi voi etala maestria cu campionul Fiora");
    SponsoredVideo v2("Ranked cu colegul de camera(Mihaita) - LoL ep.2", 20, 8, 30, "Fiora gameplay - OP.GG: JimTheMan", "Riot Games");
    SponsoredVideo v3("Incepem Climb-ul la SoloQueue - LoL ep.3", 50, 13, 23, "La limita de emerald - Fiora gameplay - OP.GG: JimTheMan", "Riot Games");
    SponsoredLivestream l1 ("Primul meu live alaturi de Mihaita Piticu'", 120, 37, 98, "Incercam sa ajungem Diamond - Solo/Duo cu Mihaita Piticu \n Aplicati codul de discount pentru 30% reducere la skinuri", "Riot Games", 965, "SKIN30");
    Video * ptr1 = &v1, *ptr2 = &v2, *ptr3 = &v3, *lptr1 = &l1;
    auto *p1 = dynamic_cast<SponsoredLivestream*>(lptr1);
    auto *p2 = dynamic_cast<SponsoredVideo*>(ptr2);
    auto *p3 = dynamic_cast<SponsoredVideo*>(ptr3);
//    cout << p1;
//    cout << typeid(*p1).name() << endl;
    Livestream *livestream;
    canal1.PublishVideo(ptr1);
    canal1.PublishVideo(p2);
    canal1.PublishVideo(p3);
    canal1.PublishVideo(p1);

    ListaCanale.push_back(canal1);

    YoutubeChannel canal2("DeniPeni", "Denisa Ioana !GOSOIU!", "Pentru cei pasionati de arta");
    canal2.set_SubscriberCount(671);
    Video v4("Picturile mele ep.1 - Peisaje Tomanale", 61, 9, 17, "Primele mele peisaje tomanle, sper ca o sa va placa!");
    Video v5("Picturile mele ep.2- Peisaje de Vara", 124, 15, 26, "Primele mele peisaje de primavara, sper ca o sa va placa!");
    SponsoredVideo v6("Picturile mele ep.3- Opere obscure ", 322, 28, 10, "Peisaje mai obscure folosind tehnica clar-obscurului, folosind acuarele Pelikan", "Pelikan");
    Video * ptr4 = &v4, * ptr5 = &v5, * ptr6 = &v6;
    auto* sv1 = dynamic_cast<SponsoredVideo*>(ptr6);
    canal2.PublishVideo(ptr4);
    canal2.PublishVideo(ptr5);
    canal2.PublishVideo(sv1);
    ListaCanale.push_back(canal2);

    YoutubeChannel canal3("Profu XXL", "Fugulin Daniel Valentin", "Pregatiri Bac si Admitere");
    canal3.set_SubscriberCount(1782);
    Video v7("Rezolvari Simulare Matematica Sub I - 2024", 174, 14, 30, "Invata matematica cu ProfuXXL");
    Video v8("Rezolvari Simulare Matematica Sub II - 2024", 253, 25, 45, "Invata matematica cu ProfuXXL");
    Video v9("Rezolvari Simulare Matematica Sub III - 2024", 451, 32, 60, "Invata matematica cu ProfuXXL");
    Livestream v10("Rezolvam Live problemele de Admitere de la UniBuc", 200, 12, 120, "Puteti pune intrebari legate de matematica in chat si o sa incerc \n sa raspund la cat mai multe dintre ele", 187);
    Video * ptr7 = &v7, * ptr8 = &v8, * ptr9 = &v9, *ptr10 = &v10;
    auto* l2 = dynamic_cast<Livestream*>(ptr10);
    canal3.PublishVideo(ptr7);
    canal3.PublishVideo(ptr8);
    canal3.PublishVideo(ptr9);
    canal3.PublishVideo(l2);
    ListaCanale.push_back(canal3);

    Video v1_nou, v2_nou, v3_nou;
    Video* ptr1_nou, *ptr2_nou, *ptr3_nou;
    Livestream l1_nou, l2_nou, l3_nou;
    SponsoredVideo sp1, sp2, sp3;
    SponsoredLivestream sl1, sl2, sl3;
    YoutubeChannel canal_download;
    string download_name, download_description;
    int download_length;
    cout << "         WELCOME TO YOUTUBE           Fun Fact: There are currently "  <<Video::getTotalVideos()<< " videos on Youtube" << endl;
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
    int a;
    cin >> x; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
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
                cin >> y; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                switch (y) {
                    case 1:
                        cout << "Channel name: " << ListaCanale.at(0).GetName()
                             << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                        cout << "Published Videos: " << endl << endl;
                        for (unsigned long long i = 0; i < ListaCanale.at(0).GetPublishedVideosTitles().size(); i++) {
                            cout << "       -" << canal1.GetPublishedVideosTitles().at(i)->GetVideoName();
                            livestream = dynamic_cast<Livestream*>(canal1.GetPublishedVideosTitles().at(i));
                            if (livestream)
                            {
                                cout << "   ***LIVE***";
                            }
                            cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                        }
                        cout << endl << "Return to the main menu - Press 0" << endl;


                        cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                        while (z) {
                            switch (z) {
                                case 1:
                                    canal1.Subscribe();
                                    cout << endl << endl;
                                    break;
                                case 2:
                                    canal1.UnSubscribe();
                                    cout << endl << endl;
                                    break;
                                case 3:
                                    cout << *(canal1.GetPublishedVideosTitles().at(0));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 4:
                                    cout << *(canal1.GetPublishedVideosTitles().at(1));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 5:
                                    cout << *(canal1.GetPublishedVideosTitles().at(2));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 6:
                                    cout << *(canal1.GetPublishedVideosTitles().at(3));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                default:
                                    break;
                            }
                            if (z >= 3) {
                                cout << "Press 1 to return to " << canal1.GetName()
                                     << "    Press 2 to like this video      Press 3 to dislike this video       0 - Main Menu"
                                     << endl;
                                cin >> b; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                if (b == 0) break;
                                else if (b == 1) {
                                    cout << "Channel name: " << canal1.GetName()
                                         << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                                    cout << "Published Videos: " << endl << endl;
                                    for (unsigned long long i = 0; i < canal1.GetPublishedVideosTitles().size(); i++) {
                                        cout << "       -" << canal1.GetPublishedVideosTitles().at(i)->GetVideoName();
                                        livestream = dynamic_cast<Livestream*>(canal1.GetPublishedVideosTitles().at(i));
                                        if (livestream)
                                        {
                                            cout << "   ***LIVE***";
                                        }
                                        cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                                    }
                                    cout << endl << "Return to the main menu - Press 0" << endl;
                                    cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

                                }
                                else if (b == 2){
                                    ++*canal1.GetPublishedVideosTitles().at(z-3);
                                    cout << "You have liked this Video!" << endl << endl;
                                }
                                else if (b == 3){
                                    canal1.GetPublishedVideosTitles().at(z-3)->DislikeVideo();
                                    cout << "You have liked this Video!" << endl << endl;
                                }
                            }
                            else{
                                cout << "Channel name: " << ListaCanale.at(0).GetName()
                                     << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                                cout << "Published Videos: " << endl << endl;
                                for (unsigned long long i = 0; i < ListaCanale.at(0).GetPublishedVideosTitles().size(); i++) {
                                    cout << "       -" << canal1.GetPublishedVideosTitles().at(i)->GetVideoName();
                                    livestream = dynamic_cast<Livestream*>(canal1.GetPublishedVideosTitles().at(i));
                                    if (livestream)
                                    {
                                        cout << "   ***LIVE***";
                                    }
                                    cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                                }
                                cout << endl << "Return to the main menu - Press 0" << endl;
                                cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                            }

                        }
                        break;
                    case 2:
                        cout << "Channel name: " << ListaCanale.at(1).GetName()
                             << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                        cout << "Published Videos: " << endl << endl;
                        for (unsigned long long i = 0; i < ListaCanale.at(1).GetPublishedVideosTitles().size(); i++) {
                            cout << "       -" << canal2.GetPublishedVideosTitles().at(i)->GetVideoName();
                            livestream = dynamic_cast<Livestream*>(canal2.GetPublishedVideosTitles().at(i));
                            if (livestream)
                            {
                                cout << "   ***LIVE***";
                            }
                            cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                        }
                        cout << endl << "Return to the main menu - Press 0" << endl;


                        cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                        while (z) {
                            switch (z) {
                                case 1:
                                    canal2.Subscribe();
                                    cout << endl << endl;
                                    break;
                                case 2:
                                    canal2.UnSubscribe();
                                    cout << endl << endl;
                                    break;
                                case 3:
                                    cout << *(canal2.GetPublishedVideosTitles().at(0));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 4:
                                    cout << *(canal2.GetPublishedVideosTitles().at(1));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 5:
                                    cout << *(canal2.GetPublishedVideosTitles().at(2));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 6:
                                    cout << *(canal2.GetPublishedVideosTitles().at(3));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                default:
                                    break;
                            }
                            if (z >= 3) {
                                cout << "Press 1 to return to " << canal2.GetName()
                                     << "    Press 2 to like this video      Press 3 to dislike this video       0 - Main Menu"
                                     << endl;
                                cin >> b; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                if (b == 0) break;
                                else if (b == 1) {
                                    cout << "Channel name: " << canal2.GetName()
                                         << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                                    cout << "Published Videos: " << endl << endl;
                                    for (unsigned long long i = 0; i < canal2.GetPublishedVideosTitles().size(); i++) {
                                        cout << "       -" << canal2.GetPublishedVideosTitles().at(i)->GetVideoName();
                                        livestream = dynamic_cast<Livestream*>(canal2.GetPublishedVideosTitles().at(i));
                                        if (livestream)
                                        {
                                            cout << "   ***LIVE***";
                                        }
                                        cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                                    }
                                    cout << endl << "Return to the main menu - Press 0" << endl;
                                    cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

                                }
                                else if (b == 2){
                                    ++*canal2.GetPublishedVideosTitles().at(z-3);
                                    cout << "You have liked this Video!" << endl << endl;
                                }
                                else if (b == 3){
                                    canal2.GetPublishedVideosTitles().at(z-3)->DislikeVideo();
                                    cout << "You have liked this Video!" << endl << endl;
                                }
                            }
                            else{
                                cout << "Channel name: " << canal2.GetName()
                                     << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                                cout << "Published Videos: " << endl << endl;
                                for (unsigned long long i = 0; i < canal2.GetPublishedVideosTitles().size(); i++) {
                                    cout << "       -" << canal2.GetPublishedVideosTitles().at(i)->GetVideoName();
                                    livestream = dynamic_cast<Livestream*>(canal2.GetPublishedVideosTitles().at(i));
                                    if (livestream)
                                    {
                                        cout << "   ***LIVE***";
                                    }
                                    cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                                }
                                cout << endl << "Return to the main menu - Press 0" << endl;
                                cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                            }

                        }
                        break;
                    case 3:
                        cout << "Channel name: " << ListaCanale.at(2).GetName()
                             << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                        cout << "Published Videos: " << endl << endl;
                        for (unsigned long long i = 0; i < ListaCanale.at(2).GetPublishedVideosTitles().size(); i++) {
                            cout << "       -" << canal3.GetPublishedVideosTitles().at(i)->GetVideoName();
                            livestream = dynamic_cast<Livestream*>(canal3.GetPublishedVideosTitles().at(i));
                            if (livestream)
                            {
                                cout << "   ***LIVE***";
                            }
                            cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                        }
                        cout << endl << "Return to the main menu - Press 0" << endl;


                        cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                        while (z) {
                            switch (z) {
                                case 1:
                                    canal3.Subscribe();
                                    cout << endl << endl;
                                    break;
                                case 2:
                                    canal3.UnSubscribe();
                                    cout << endl << endl;
                                    break;
                                case 3:
                                    cout << *(canal3.GetPublishedVideosTitles().at(0));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 4:
                                    cout << *(canal3.GetPublishedVideosTitles().at(1));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 5:
                                    cout << *(canal3.GetPublishedVideosTitles().at(2));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 6:
                                    cout << *(canal3.GetPublishedVideosTitles().at(3));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                default:
                                    break;
                            }
                            if (z >= 3) {
                                cout << "Press 1 to return to " << canal3.GetName()
                                     << "    Press 2 to like this video      Press 3 to dislike this video       0 - Main Menu"
                                     << endl;
                                cin >> b; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                if (b == 0) break;
                                else if (b == 1) {
                                    cout << "Channel name: " << canal3.GetName()
                                         << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                                    cout << "Published Videos: " << endl << endl;
                                    for (unsigned long long i = 0; i < canal3.GetPublishedVideosTitles().size(); i++) {
                                        cout << "       -" << canal3.GetPublishedVideosTitles().at(i)->GetVideoName();
                                        livestream = dynamic_cast<Livestream*>(canal3.GetPublishedVideosTitles().at(i));
                                        if (livestream)
                                        {
                                            cout << "   ***LIVE***";
                                        }
                                        cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                                    }
                                    cout << endl << "Return to the main menu - Press 0" << endl;
                                    cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

                                }
                                else if (b == 2){
                                    ++*canal3.GetPublishedVideosTitles().at(z-3);
                                    cout << "You have liked this Video!" << endl << endl;
                                }
                                else if (b == 3){
                                    canal3.GetPublishedVideosTitles().at(z-3)->DislikeVideo();
                                    cout << "You have liked this Video!" << endl << endl;
                                }
                            }
                            else{
                                cout << "Channel name: " << canal3.GetName()
                                     << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                                cout << "Published Videos: " << endl << endl;
                                for (unsigned long long i = 0; i < canal3.GetPublishedVideosTitles().size(); i++) {
                                    cout << "       -" << canal3.GetPublishedVideosTitles().at(i)->GetVideoName();
                                    livestream = dynamic_cast<Livestream*>(canal3.GetPublishedVideosTitles().at(i));
                                    if (livestream)
                                    {
                                        cout << "   ***LIVE***";
                                    }
                                    cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                                }
                                cout << endl << "Return to the main menu - Press 0" << endl;
                                cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                            }

                        }
                        break;
                    case 4:
                        cout << "Channel name: " << ListaCanale.at(3).GetName()
                             << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                        cout << "Published Videos: " << endl << endl;
                        for (unsigned long long i = 0; i < ListaCanale.at(3).GetPublishedVideosTitles().size(); i++) {
                            cout << "       -" << ListaCanale.at(3).GetPublishedVideosTitles().at(i)->GetVideoName();
                            livestream = dynamic_cast<Livestream*>(ListaCanale.at(3).GetPublishedVideosTitles().at(i));
                            if (livestream)
                            {
                                cout << "   ***LIVE***";
                            }
                            cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                        }
                        cout << endl << "Return to the main menu - Press 0" << endl;


                        cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                        while (z) {
                            switch (z) {
                                case 1:
                                    ListaCanale.at(3).Subscribe();
                                    cout << endl << endl;
                                    break;
                                case 2:
                                    ListaCanale.at(3).UnSubscribe();
                                    cout << endl << endl;
                                    break;
                                case 3:
                                    cout << *(ListaCanale.at(3).GetPublishedVideosTitles().at(0));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 4:
                                    cout << *(ListaCanale.at(3).GetPublishedVideosTitles().at(1));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                case 5:
                                    cout << *(ListaCanale.at(3).GetPublishedVideosTitles().at(2));
                                    cout << "---------------------------------------------------------------" << endl;
                                    break;
                                default:
                                    break;
                            }
                            if (z >= 3) {
                                cout << "Press 1 to return to " << ListaCanale.at(3).GetName()
                                     << "    Press 2 to like this video      Press 3 to dislike this video       0 - Main Menu"
                                     << endl;
                                cin >> b; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                if (b == 0) break;
                                else if (b == 1) {
                                    cout << "Channel name: " << ListaCanale.at(3).GetName()
                                         << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                                    cout << "Published Videos: " << endl << endl;
                                    for (unsigned long long i = 0; i < ListaCanale.at(3).GetPublishedVideosTitles().size(); i++) {
                                        cout << "       -" << ListaCanale.at(3).GetPublishedVideosTitles().at(i)->GetVideoName();
                                        livestream = dynamic_cast<Livestream*>(ListaCanale.at(3).GetPublishedVideosTitles().at(i));
                                        if (livestream)
                                        {
                                            cout << "   ***LIVE***";
                                        }
                                        cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                                    }
                                    cout << endl << "Return to the main menu - Press 0" << endl;
                                    cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

                                }
                                else if (b == 2){
                                    ++*ListaCanale.at(3).GetPublishedVideosTitles().at(z-3);
                                    cout << "You have liked this Video!" << endl << endl;
                                }
                                else if (b == 3){
                                    ListaCanale.at(3).GetPublishedVideosTitles().at(z-3)->DislikeVideo();
                                    cout << "You have liked this Video!" << endl << endl;
                                }
                            }
                            else{
                                cout << "Channel name: " << ListaCanale.at(3).GetName()
                                     << "         Press 1 to subscribe            Press 2 to unsubscribe" << endl << endl;
                                cout << "Published Videos: " << endl << endl;
                                for (unsigned long long i = 0; i < ListaCanale.at(3).GetPublishedVideosTitles().size(); i++) {
                                    cout << "       -" << ListaCanale.at(3).GetPublishedVideosTitles().at(i)->GetVideoName();
                                    livestream = dynamic_cast<Livestream*>(ListaCanale.at(3).GetPublishedVideosTitles().at(i));
                                    if (livestream)
                                    {
                                        cout << "   ***LIVE***";
                                    }
                                    cout << "          Press " << i + 3 << " to view this video" << endl << endl;
                                }
                                cout << endl << "Return to the main menu - Press 0" << endl;
                                cin >> z; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                            }

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
                        cin >> x; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                        switch (x){
                            case 1:
                                if (nr_video == 1){
                                    cout << "Your first video will be:" << endl;
                                    cout << "Press 1 for Video    Press 2 for Livestream   Press 3 for Sponsored Video     Press 4 for Sponsored Livestream" << endl;
                                    cin >> a;
                                    if (a == 1){
                                        try {
                                            cin >> v1_nou;
                                        } catch (const exception& e) {
                                            cerr << "Exception caught: " << e.what() << endl;
                                        }
                                        ptr1_nou = &v1_nou;
                                        ListaCanale.at(3).PublishVideo(ptr1_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You posted this video on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(0);
                                    }
                                    else if (a == 2){
                                        cin >> l1_nou;
                                        ptr1_nou = &l1_nou;
                                        auto* p1_nou = dynamic_cast<Livestream*>(ptr1_nou);
                                        ListaCanale.at(3).PublishVideo(p1_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have stared a livestream on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(0);
                                    }
                                    else if (a == 3){
//                                        try {
//                                            cin >> sp1;
//                                        } catch (const exception& sp) {
//                                            cerr << "Exception caught: " << sp.what() << endl;
//                                        }
                                        cin >> sp1;
                                        ptr1_nou = &sp1;
                                        auto* p1_nou = dynamic_cast<SponsoredVideo*>(ptr1_nou);
                                        ListaCanale.at(3).PublishVideo(p1_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have posted this sponsored video on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(0);
                                    }
                                    else if (a == 4){
                                        cin >> sl1;
                                        ptr1_nou = &sl1;
                                        auto* p1_nou = dynamic_cast<SponsoredLivestream*>(ptr1_nou);
                                        ListaCanale.at(3).PublishVideo(p1_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have stared a sponsored livestream on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(0);
                                    }
                                    nr_video ++;
                                }
                                else if(nr_video == 2){
                                    cout << "Your second video will be:" << endl;
                                    cout << "Press 1 for Video    Press 2 for Livestream   Press 3 for Sponsored Video     Press 4 for Sponsored Livestream" << endl;
                                    cin >> a;
                                    if (a == 1){
                                        cin >> v2_nou;
                                        ptr2_nou = &v2_nou;
                                        ListaCanale.at(3).PublishVideo(ptr2_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You posted this video on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(1);
                                    }
                                    else if (a == 2){
                                        cin >> l2_nou;
                                        ptr2_nou = &l2_nou;
                                        auto* p2_nou = dynamic_cast<Livestream*>(ptr2_nou);
                                        ListaCanale.at(3).PublishVideo(p2_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have stared a livestream on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(1);
                                    }
                                    else if (a == 3){
                                        cin >> sp2;
                                        ptr2_nou = &sp2;
                                        auto* p2_nou = dynamic_cast<SponsoredVideo*>(ptr2_nou);
                                        ListaCanale.at(3).PublishVideo(p2_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have posted this sponsored video on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(1);
                                    }
                                    else if (a == 4){
                                        cin >> sl2;
                                        ptr2_nou = &sl2;
                                        auto* p2_nou = dynamic_cast<SponsoredLivestream*>(ptr2_nou);
                                        ListaCanale.at(3).PublishVideo(p2_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have stared a sponsored livestream on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(1);
                                    }
                                    nr_video ++;
                                }
                                else if(nr_video == 3){
                                    cout << "Your third and final(for now) video will be:" << endl;
                                    cout << "Press 1 for Video    Press 2 for Livestream   Press 3 for Sponsored Video     Press 4 for Sponsored Livestream" << endl;
                                    cin >> a;
                                    if (a == 1){
                                        cin >> v3_nou;
                                        ptr3_nou = &v3_nou;
                                        ListaCanale.at(3).PublishVideo(ptr3_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You posted this video on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(2);
                                    }
                                    else if (a == 2){
                                        cin >> l3_nou;
                                        ptr3_nou = &l3_nou;
                                        auto* p3_nou = dynamic_cast<Livestream*>(ptr3_nou);
                                        ListaCanale.at(3).PublishVideo(p3_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have stared a livestream on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(2);
                                    }
                                    else if (a == 3){
                                        cin >> sp3;
                                        ptr3_nou = &sp3;
                                        auto* p3_nou = dynamic_cast<SponsoredVideo*>(ptr3_nou);
                                        ListaCanale.at(3).PublishVideo(p3_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have posted this sponsored video on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(2);
                                    }
                                    else if (a == 4){
                                        cin >> sl3;
                                        ptr3_nou = &sl3;
                                        auto* p3_nou = dynamic_cast<SponsoredLivestream*>(ptr3_nou);
                                        ListaCanale.at(3).PublishVideo(p3_nou);
                                        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                                        cout << "You have stared a sponsored livestream on your channel: " << endl;
                                        cout << ListaCanale.at(3).GetPublishedVideosTitles().at(2);
                                    }
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
                cin >> download; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
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
                    Video ::setTotalVideos(Video :: getTotalVideos() - n);
                }
                else{
                    if (canal_download.GetDownloadedVideos().empty()) {
                        cout << "You don't have any downloaded videos, download some by pressing 4 and then 1 to see them here!" << endl;
                        break;
                    }
                    for (unsigned long long i = 0; i < canal_download.GetDownloadedVideos().size(); i++) {
                        cout << "Video number " << i + 1 << " is: " << endl;
                        cout <<  "---------------------------------------------------------------" << endl;
                        cout << canal_download.GetDownloadedVideos().at(i);
                        cout << "---------------------------------------------------------------" << endl;
                    }
                }
                break;
                default:
                    break;

            }

        }
        cout << "         WELCOME TO YOUTUBE            Fun Fact: There are currently "  <<Video::getTotalVideos()<< " videos on Youtube" << endl;
        cout << "To view all YouTube Channels - Press 1" << endl;
        cout << "To view you Channel - Press 2" << endl;
        cout << "To make a new Channel - Press 3" << endl;
        cout << "To download videos - Press 4" << endl;
        cout << endl << "EXIT - Press 0" << endl;
        cin >> x; cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    }
    return 0;
}
