#include "gtest/gtest.h"
#include "MusicDataC.h"
#include "Processor.h"
#include <string>

TEST(ProcessorTest, whenTitleAreDuplicatedThenOneIsRemoved)
{
	MusicScan::MusicDataC data1;
	data1.setTitle(L"title1");

	MusicScan::MusicDataC data2;
	data2.setTitle(L"title2");

	MusicScan::MusicDataC data3;
	data3.setTitle(L"title1");

	MusicScan::MusicDataC data4;
	data4.setTitle(L"title4");

	std::vector<MusicScan::MusicDataC >listTitle;
	listTitle.push_back(data1);
	listTitle.push_back(data2);
	listTitle.push_back(data3);
	listTitle.push_back(data4);

	MusicScan::ProcessorC processor;
	processor.RemoveDuplicate(listTitle);

    EXPECT_EQ(3, listTitle.size());
    EXPECT_EQ(data1, listTitle[0]);
    EXPECT_EQ(data2, listTitle[1]);
    EXPECT_EQ(data4, listTitle[2]);
}
