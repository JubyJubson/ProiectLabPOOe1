#include <gtest/gtest.h>
#include "Video.h"

class VideoTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Example test case
TEST_F(VideoTest, GetVideoNameTest) {
    Video video("Test Video", 10, 5, 100, "This is a test video");

    std::string videoName = video.GetVideoName();

     EXPECT_EQ(videoName, "Test Video");
}


TEST_F(VideoTest, InvalidVideoLengthExceptionTest) {
    try {
        Video invalidVideo("Invalid Video", 0, 0, -1, "This video has an invalid length");
        FAIL() << "Expected InvalidVideoLengthException";
    } catch (const exception& e) {
        EXPECT_STREQ(e.what(), "Invalid video length. Please provide a positive number.");
    }
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
