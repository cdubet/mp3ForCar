#include "gtest/gtest.h"
#include "VorbisToMp3.h"
#include "Mp3ToMp3.h"
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

TEST(MusicConverterTest, whenFileMp3ThenFileIsCopied)
{
	boost::filesystem::path sourcePath("/home/christian/tmp/MUSIQUE_AUTO_SRC/McKennit/Celtic - Loreena McKennitt - Irish  Ballad.mp3");
	boost::filesystem::path destPath("/home/christian/tmp/MUSIQUE_AUTO/CELTICWOMAN_BELIEVE_14_AWOMANSHEART.mp3");

	MusicScan::Mp3ToMp3C converter;
	const bool res=converter.Convert(sourcePath,destPath);
	EXPECT_TRUE(res);
}

