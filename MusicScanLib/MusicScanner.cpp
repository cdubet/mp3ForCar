/*
 * MusicScanner.cpp
 *
 *  Created on: 18 déc. 2020
 *      Author: christian
 */

#include "MusicScanner.h"
#include <TagExtractor.h>

namespace MusicScan
{

MusicScannerC::MusicScannerC(const boost::filesystem::path & sourcePath):m_sourcePath(sourcePath)
{

}

bool MusicScannerC::Scan()
{
	if ( !exists( m_sourcePath ) )
	{
		return false;
	}

	if ( !boost::filesystem::is_directory( m_sourcePath ) )
	{
		return false;
	}
	return Scan(m_sourcePath);
}

bool MusicScannerC::Scan(const boost::filesystem::path & dir)
{
	boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
	for (  boost::filesystem::directory_iterator itr( m_sourcePath );
			itr != end_itr;
			++itr )
	{
		if (  boost::filesystem::is_directory(itr->status()) )
		{
			Scan( itr->path());//TODO manage error case
		}
		else
		{
			printf("%s\n",itr->path().string().c_str());
			boost::optional<MusicDataC> musicData=TagExtractorC::extract(itr->path());
			if (musicData)
			{
				m_musicData.push_back(*musicData);
			}
		}

	}
	return true;
}

} /* namespace MusicScan */
