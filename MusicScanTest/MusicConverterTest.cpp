#include "gtest/gtest.h"
#include "VorbisToMp3.h"
#include <string>


TEST(MusicConverterTest, whenFileIsNotOggReturnFalse)
{
	boost::filesystem::path sourcePath("music.wav");
	MusicScan::VorbisToMp3C converter;
	const bool res=converter.Convert(sourcePath,"anything");
	EXPECT_FALSE(res);
}
TEST(MusicConverterTest, whenFileIsOggReturnTrue)
{
	boost::filesystem::path sourcePath("music.ogg");
	MusicScan::VorbisToMp3C converter;
	const bool res=converter.Convert(sourcePath,"anything");
	EXPECT_TRUE(res);
}
/*
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/
