
#ifndef MUSIC_FORMAT_CONVERTER_H_
#define MUSIC_FORMAT_CONVERTER_H_

#include <boost/filesystem.hpp>

namespace MusicScan
{

class MusicFormatConverterI
{
public :
	virtual bool Convert(const boost::filesystem::path & source,const boost::filesystem::path & dest )=0;
};

} /* namespace MusicScan */

#endif /* MUSIC_FORMAT_CONVERTER_H_ */
