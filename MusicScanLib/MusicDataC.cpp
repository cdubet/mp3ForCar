/*
 * MusicDataC.cpp
 *
 *  Created on: 18 déc. 2020
 *      Author: christian
 */

#include "MusicDataC.h"

namespace MusicScan
{
int MusicDataC::compare( const MusicDataC& rhs) const
{
	int result =getTrack() - rhs.getTrack();
	if (result==0)
	{
		result=getAlbum().compare(rhs.getAlbum());
		if (result==0)
		{
			result=getArtist().compare(rhs.getArtist());
			if (result==0)
			{
				result=getTitle().compare(rhs.getTitle());
				if (result==0)
				{
					result= getFilename().compare(rhs.getFilename());
				}
			}
		}
	}
	return result;
}
} /* namespace MusicScan */
