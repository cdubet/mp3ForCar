
#ifndef VORBISTOMP3_H_
#define VORBISTOMP3_H_

#include "MusicFormatConverter.h"

namespace MusicScan
{

class VorbisToMp3C: public MusicFormatConverterI
{
public:
	VorbisToMp3C(int sampleRate=44100, int channels=2);
	virtual ~VorbisToMp3C() {};

	bool Convert(const boost::filesystem::path & source,const boost::filesystem::path & dest ) override;

private:
	bool ConvertToMp3(const boost::filesystem::path & source,const boost::filesystem::path & dest);

	int m_sampleRate;
	int m_channels;
};

} /* namespace MusicScan */

#endif /* VORBISTOMP3_H_ */
