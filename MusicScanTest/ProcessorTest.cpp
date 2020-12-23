#include "gtest/gtest.h"
#include "MusicDataC.h"
#include "Processor.h"
#include "MusicFileScannerI.h"
#include <string>

namespace MusicScan
{
static MusicDataC data1;
static MusicDataC data2;
static MusicDataC data3;
static MusicDataC data4;


class FakeMusicScanner: public MusicFileScannerI
{
public:
	 bool Scan(std::vector<MusicDataC> &musicData) override;
};
bool FakeMusicScanner::Scan(std::vector<MusicDataC> &listTitle)
{
	data1.setTitle(L"title1");
	data2.setTitle(L"title2");
	data3.setTitle(L"title1");
	data4.setTitle(L"title4");
	listTitle.push_back(data1);
	listTitle.push_back(data2);
	listTitle.push_back(data3);
	listTitle.push_back(data4);

	return true;
}
}

TEST(ProcessorTest, whenTitleAreDuplicatedThenOneIsRemoved)
{
	MusicScan::FakeMusicScanner fakeFileScanner;
	MusicScan::ProcessorC processor(fakeFileScanner);
	auto listTitle= processor.SearchForUniqueMusic();

    EXPECT_EQ(3, listTitle.size());
    EXPECT_EQ(MusicScan::data1, listTitle[0]);
    EXPECT_EQ(MusicScan::data2, listTitle[1]);
    EXPECT_EQ(MusicScan::data4, listTitle[2]);
}
