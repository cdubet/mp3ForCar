#include <TagExtractor.h>
#include <MusicDataFormatter.h>
#include <MusicFileScanner.h>
#include <iostream>

namespace MusicScan
{

MusicFileScannerC::MusicFileScannerC(const boost::filesystem::path & sourcePath):m_sourcePath(sourcePath)
{

}

bool MusicFileScannerC::Scan(std::vector<MusicDataC> &musicData)
{
	if ( !exists( m_sourcePath ) )
	{
		return false;
	}

	if ( !boost::filesystem::is_directory( m_sourcePath ) )
	{
		return false;
	}
	return Scan(musicData,m_sourcePath);
}

bool MusicFileScannerC::Scan(std::vector<MusicDataC> &musicData,const boost::filesystem::path & dirToScan)
{
	if ( !boost::filesystem::exists( dirToScan ) )
	{
		return false;
	}

	boost::filesystem::directory_iterator end_itr;
	for (  boost::filesystem::directory_iterator itr( dirToScan );
			itr != end_itr;
			++itr )
	{
		if (  boost::filesystem::is_directory(itr->status()) )
		{
			printf("dir %s\n",itr->path().string().c_str());
			Scan(musicData, itr->path());//TODO manage error case
		}
		else
		{
			printf("found %s\n",itr->path().string().c_str());
			boost::optional<MusicDataC> musicTagData=TagExtractorC::extract(itr->path());
			if (musicTagData)
			{
				musicData.push_back(MusicDataFormatterC::Format(musicTagData.get()));
			}
		}

	}

	return true;
}


} /* namespace MusicScan */
