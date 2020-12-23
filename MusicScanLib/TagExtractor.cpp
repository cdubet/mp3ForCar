/*
 * TagExtractor.cpp
 *
 *  Created on: 18 déc. 2020
 *      Author: christian
 */

#include "TagExtractor.h"
#include "fileref.h"
#include <string>

namespace MusicScan
{
boost::optional<MusicDataC> TagExtractorC::extract(const boost::filesystem::path &filename)
{
	boost::optional<MusicDataC> result;

	TagLib::FileRef fileReference(filename.string().c_str());
	if (fileReference.tag()!=NULL)
	{
		auto tag=fileReference.tag();
		MusicDataC musicData;

		if (!tag->artist().isEmpty())
		{
			musicData.setArtist(tag->artist().toWString());
		}
		if (!tag->album().isEmpty())
		{
			musicData.setAlbum(tag->album().toWString());
		}
		if (!tag->title().isEmpty())
		{
			musicData.setTitle(tag->title().toWString());
		}
		musicData.setTrack(tag->track());
		musicData.setFilename(filename);
		result=musicData;
	}

	return result;
}
} /* namespace MusicScan */
