#include <gtest/gtest.h>
#include "example.h"
#include "Video.h"
#include "Livestream.h"
#include "InvalidVideoLengthException.h"
#include <iostream>
#include "SponsoredLivestream.h"
#include "YoutubeChannel.h"

TEST(SuiteName, TestName) {
    EXPECT_EQ(doSomething(10), 10);
}

TEST(VideoTest, ConstructorWithParameters) {
    Video video("Name", 10, 5, 120, "Description");
    EXPECT_EQ(video.GetVideoName(), "Name");
    EXPECT_EQ(video.GetLikeNumber(), 10);
}
TEST(VideoTest, DefaultConstructor) {
    Video video;
    EXPECT_EQ(video.GetVideoName(), "NO NAME");
    EXPECT_EQ(video.GetLikeNumber(), 0);
}

TEST(VideoTest, GetVideoName) {
    Video video("Name", 10, 5, 120, "Description");
    EXPECT_EQ(video.GetVideoName(), "Name");
}
TEST(VideoTest, OutputOperator) {
    Video video("Name", 10, 5, 120, "Description");
    testing::internal::CaptureStdout();
    std::cout << &video;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Content Name: Name"), string::npos);
    EXPECT_NE(output.find("Likes: 10"), string::npos);
    EXPECT_NE(output.find("Dislikes: 5"), string::npos);
    EXPECT_NE(output.find("Content Length: 120"), string::npos);
    EXPECT_NE(output.find("Content Description: Description"), string::npos);
}

TEST(LivestreamTest, DefaultConstructor) {
    Livestream livestream;
    EXPECT_EQ(livestream.GetVideoName(), "NO NAME");
    EXPECT_EQ(livestream.GetLikeNumber(), 0);
    EXPECT_EQ(livestream.GetWatchers(), 1);
}

TEST(LivestreamTest, ParameterizedConstructor) {
    Livestream livestream("Name", 10, 5, 120, "Description", 20);
    EXPECT_EQ(livestream.GetVideoName(), "Name");
    EXPECT_EQ(livestream.GetLikeNumber(), 10);
    EXPECT_EQ(livestream.GetWatchers(), 20);
}

TEST(LivestreamTest, ShowMethod) {
    Livestream livestream("Name", 10, 5, 120, "Description", 20);
    testing::internal::CaptureStdout();
    livestream.show(std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("This is a Livestream"), std::string::npos);
    EXPECT_NE(output.find("People Watching: 20"), std::string::npos);
    EXPECT_NE(output.find("Content Name: Name"), std::string::npos);
    EXPECT_NE(output.find("Likes: 10"), std::string::npos);
    EXPECT_NE(output.find("Dislikes: 5"), std::string::npos);
    EXPECT_NE(output.find("Content Length: 120"), std::string::npos);
    EXPECT_NE(output.find("Content Description: Description"), std::string::npos);
}

TEST(LivestreamTest, AssignmentOperator) {
    Livestream livestream1("Name1", 10, 5, 120, "Description1", 20);
    Livestream livestream2("Name2", 20, 10, 240, "Description2", 30);

    livestream2 = livestream1;

    EXPECT_EQ(livestream2.GetVideoName(), "Name1");
    EXPECT_EQ(livestream2.GetLikeNumber(), 10);
    EXPECT_EQ(livestream2.GetWatchers(), 20);
}

TEST(LivestreamTest, CitireMethod) {
    Livestream livestream;
    std::istringstream input(" New Name\nNew Description\n180\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    livestream.citire(std::cin);
    std::cin.rdbuf(oldCin);

    EXPECT_EQ(livestream.GetVideoName(), "New Name");
}

TEST(LivestreamTest, Destructor) {
    auto *livestream = new Livestream("Name", 10, 5, 120, "Description", 20);
    int initialWatchers = livestream->GetWatchers();
    delete livestream;
    EXPECT_EQ(initialWatchers, 20);
    EXPECT_NE(livestream->GetWatchers(), initialWatchers);
}

TEST(SponsoredLivestreamTest, DefaultConstructor) {
    SponsoredLivestream livestream;
    EXPECT_EQ(livestream.GetVideoName(), "NO NAME");
    EXPECT_EQ(livestream.GetLikeNumber(), 0);
    EXPECT_EQ(livestream.GetSponsorName(), "Unknown");
    EXPECT_EQ(livestream.GetWatchers(), 1);
    EXPECT_EQ(livestream.GetDiscountCode(), "0000");
}

TEST(SponsoredLivestreamTest, ParameterizedConstructor) {
    SponsoredLivestream livestream("Name", 10, 5, 120, "Description", "Sponsor", 20, "1234");
    EXPECT_EQ(livestream.GetVideoName(), "Name");
    EXPECT_EQ(livestream.GetLikeNumber(), 10);
    EXPECT_EQ(livestream.GetSponsorName(), "Sponsor");
    EXPECT_EQ(livestream.GetWatchers(), 20);
    EXPECT_EQ(livestream.GetDiscountCode(), "1234");
}

TEST(SponsoredLivestreamTest, ShowMethod) {
    SponsoredLivestream livestream("Name", 10, 5, 120, "Description", "Sponsor", 20, "1234");
    testing::internal::CaptureStdout();
    livestream.show(std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Content Name: Name"), std::string::npos);
    EXPECT_NE(output.find("Likes: 10"), std::string::npos);
    EXPECT_NE(output.find("Dislikes: 5"), std::string::npos);
    EXPECT_NE(output.find("Content Length: 120"), std::string::npos);
    EXPECT_NE(output.find("Content Description: Description"), std::string::npos);
    EXPECT_NE(output.find("Sponsor name: Sponsor"), std::string::npos);
    EXPECT_NE(output.find("Discount code: 1234"), std::string::npos);
}

TEST(SponsoredLivestreamTest, AssignmentOperator) {
    SponsoredLivestream livestream1("Name1", 10, 5, 120, "Description1", "Sponsor1", 20, "1234");
    SponsoredLivestream livestream2("Name2", 20, 10, 240, "Description2", "Sponsor2", 30, "5678");

    livestream2 = livestream1;

    EXPECT_EQ(livestream2.GetVideoName(), "Name1");
    EXPECT_EQ(livestream2.GetLikeNumber(), 10);
    EXPECT_EQ(livestream2.GetSponsorName(), "Sponsor1");
    EXPECT_EQ(livestream2.GetWatchers(), 20);
    EXPECT_EQ(livestream2.GetDiscountCode(), "1234");
}

TEST(SponsoredLivestreamTest, CitireMethod) {
    SponsoredLivestream livestream;
    std::istringstream input(" New Name\nNew Description\n180\nNew Sponsor\nDiscount\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    livestream.citire(std::cin);
    std::cin.rdbuf(oldCin);

    EXPECT_EQ(livestream.GetVideoName(), "New Name");
    EXPECT_EQ(livestream.GetSponsorName(), "New Sponsor");
    EXPECT_EQ(livestream.GetDiscountCode(), "Discount");
}

TEST(SponsoredVideoTest, DefaultConstructor) {
    SponsoredVideo video;
    EXPECT_EQ(video.GetVideoName(), "NO NAME");
    EXPECT_EQ(video.GetLikeNumber(), 0);
    EXPECT_EQ(video.GetSponsorName(), "Unknown");
}

TEST(SponsoredVideoTest, ParameterizedConstructor) {
    SponsoredVideo video("Name", 10, 5, 120, "Description", "Sponsor");
    EXPECT_EQ(video.GetVideoName(), "Name");
    EXPECT_EQ(video.GetLikeNumber(), 10);
    EXPECT_EQ(video.GetSponsorName(), "Sponsor");
}

TEST(SponsoredVideoTest, ShowMethod) {
    SponsoredVideo video("Name", 10, 5, 120, "Description", "Sponsor");
    testing::internal::CaptureStdout(); // Capture the standard output
    video.show(std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Content Name: Name"), std::string::npos);
    EXPECT_NE(output.find("Likes: 10"), std::string::npos);
    EXPECT_NE(output.find("Dislikes: 5"), std::string::npos);
    EXPECT_NE(output.find("Content Length: 120"), std::string::npos);
    EXPECT_NE(output.find("Content Description: Description"), std::string::npos);
    EXPECT_NE(output.find("Sponsor Name: Sponsor"), std::string::npos);
}

TEST(SponsoredVideoTest, AssignmentOperator) {
    SponsoredVideo video1("Name1", 10, 5, 120, "Description1", "Sponsor1");
    SponsoredVideo video2("Name2", 20, 10, 240, "Description2", "Sponsor2");

    video2 = video1;

    EXPECT_EQ(video2.GetVideoName(), "Name1");
    EXPECT_EQ(video2.GetLikeNumber(), 10);
    EXPECT_EQ(video2.GetSponsorName(), "Sponsor1");
}

TEST(SponsoredVideoTest, CitireMethod) {
    SponsoredVideo video;
    std::istringstream input(" New Name\nNew Description\n180\nNew Sponsor\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf()); // Redirect cin to read from input stringstream
    video.citire(std::cin);
    std::cin.rdbuf(oldCin); // Restore cin

    EXPECT_EQ(video.GetVideoName(), "New Name");
    EXPECT_EQ(video.GetSponsorName(), "New Sponsor");
}

TEST(YoutubeChannelTest, DefaultConstructor) {
    YoutubeChannel channel;
    EXPECT_EQ(channel.GetName(), "Guest");
    EXPECT_EQ(channel.GetOwnerName(), "Nu a fost precizat");
    EXPECT_EQ(channel.GetDescription(), "Nu a fost precizat");
    EXPECT_EQ(channel.GetSubscribers(), 0);
}

TEST(YoutubeChannelTest, ParameterizedConstructor) {
    YoutubeChannel channel("ChannelName", "OwnerName", "Description");
    EXPECT_EQ(channel.GetName(), "ChannelName");
    EXPECT_EQ(channel.GetOwnerName(), "OwnerName");
    EXPECT_EQ(channel.GetDescription(), "Description");
    EXPECT_EQ(channel.GetSubscribers(), 0);
}

TEST(YoutubeChannelTest, Subscribe) {
    YoutubeChannel channel;
    channel.Subscribe();
    EXPECT_EQ(channel.GetSubscribers(), 1);
}

TEST(YoutubeChannelTest, UnSubscribe) {
    YoutubeChannel channel;
    channel.Subscribe();
    channel.UnSubscribe();
    EXPECT_EQ(channel.GetSubscribers(), 0);
}

TEST(YoutubeChannelTest, PublishVideo) {
    YoutubeChannel channel;
    Video video("VideoName", 10, 5, 120, "VideoDescription");
    channel.PublishVideo(&video);
    EXPECT_EQ(channel.GetPublishedVideosTitles().size(), 1);
    EXPECT_EQ(channel.GetPublishedVideosTitles()[0]->GetVideoName(), "VideoName");
}

TEST(YoutubeChannelTest, DownloadVideo) {
    YoutubeChannel channel;
    Video video("VideoName", 10, 5, 120, "VideoDescription");
    channel.DownloadVideo(video);
    EXPECT_EQ(channel.GetDownloadedVideos().size(), 1);
    EXPECT_EQ(channel.GetDownloadedVideos()[0].GetVideoName(), "VideoName");
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
