#include <iostream>
#include <boost/filesystem.hpp>
#include "MusicFileScanner.h"
#include "Processor.h"

int main(int argc,char **argv)
{

	if (argc !=3)
	{
		std::cout<< argc <<"received expected 2: source path, dest path\n";
		return 0;
	}
	const boost::filesystem::path  sourcePath=argv[1];
	const boost::filesystem::path resultPath=argv[2];

	boost::system::error_code ec;
	boost::filesystem::create_directory(resultPath,ec);

	MusicScan::MusicFileScannerC fileScanner(sourcePath);
	MusicScan::ProcessorC musicFileProcessor(fileScanner);

	auto musicData=musicFileProcessor.SearchForUniqueMusic();

	std::cout<<musicData.size()<<" files to process"<<std::endl;
	musicFileProcessor.ConvertToDestination(musicData, resultPath);

	return 0;
}
