
#ifndef MP3_TOMP3_H_
#define MP3_TOMP3_H_

#include "MusicFormatConverter.h"

namespace MusicScan
{

class Mp3ToMp3C: public MusicFormatConverterI
{
public:

	virtual ~Mp3ToMp3C() {};

	bool Convert(const boost::filesystem::path & source,const boost::filesystem::path & dest ) override;

private:

};

} /* namespace MusicScan */

#endif
