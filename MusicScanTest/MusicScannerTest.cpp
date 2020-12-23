#include "gtest/gtest.h"
#include "MusicFileScanner.h"
#include <string>
#include <vector>

TEST(MusicConverterTest, scanDirThenFindFiles)
{
	boost::filesystem::path sourcePath("/home/christian/tmp/MUSIQUE_AUTO_SRC");
	MusicScan::MusicFileScannerC fileScanner(sourcePath);
	std::vector<MusicScan::MusicDataC> musicData;
	bool result=fileScanner.Scan(musicData);

	EXPECT_TRUE(result);
	EXPECT_FALSE(musicData.empty());
}

