#include "gtest/gtest.h"
#include "MusicDataFormatter.h"
#include <string>

TEST(MusicDataFormatterTest, formatTitleRemoveSpace)
{
	MusicScan::MusicDataC data;
	data.setTitle(L"   a e i   ");

	MusicScan::MusicDataFormatterC::Format(data);
    EXPECT_EQ(L"AEI", data.getTitle());
}

TEST(MusicDataFormatterTest, formatTitleRemoveNonAsciiChar)
{
	MusicScan::MusicDataC data;
	data.setTitle(L"àéèùêö");

	MusicScan::MusicDataFormatterC::Format(data);
    EXPECT_EQ(L"AEEUEO", data.getTitle());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
