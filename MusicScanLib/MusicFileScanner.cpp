#include <TagExtractor.h>
#include <MusicDataFormatter.h>
#include <MusicFileScanner.h>

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

bool MusicFileScannerC::Scan(std::vector<MusicDataC> &musicData,const boost::filesystem::path & dir)
{
	boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
	for (  boost::filesystem::directory_iterator itr( m_sourcePath );
			itr != end_itr;
			++itr )
	{
		if (  boost::filesystem::is_directory(itr->status()) )
		{
			Scan(musicData, itr->path());//TODO manage error case
		}
		else
		{
			printf("%s\n",itr->path().string().c_str());
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
