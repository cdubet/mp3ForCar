#include "VorbisToMp3.h"
#include "ffmpegcpp.h"
#include <memory>

namespace MusicScan
{
VorbisToMp3C::VorbisToMp3C(int sampleRate, int channels):m_sampleRate(sampleRate),m_channels(channels)
{

}

bool VorbisToMp3C::ConvertToMp3(const boost::filesystem::path & source,const boost::filesystem::path & dest)
{
	try
	{
		ffmpegcpp::Muxer* muxer = new ffmpegcpp::Muxer(dest.c_str());
		ffmpegcpp::AudioCodec* codec = new ffmpegcpp::AudioCodec(AV_CODEC_ID_MP3);
		ffmpegcpp::AudioEncoder* encoder = new ffmpegcpp::AudioEncoder(codec, muxer);
		std::unique_ptr<ffmpegcpp::VorbisAudioFileSource>audioFile=std::make_unique<ffmpegcpp::VorbisAudioFileSource>(source.c_str(),m_sampleRate,m_channels,encoder);
		audioFile->PreparePipeline();
		while (!audioFile->IsDone())
		{
			audioFile->Step();
		}
		muxer->Close();
	}
	catch (ffmpegcpp::FFmpegException & e)
	{
		return false;
	}
	return true;
}
bool VorbisToMp3C::Convert(const boost::filesystem::path & source,const boost::filesystem::path & dest )
{
	auto extension=source.extension();
	if (extension.string().compare(".ogg")==0)
	{
		return true;
	}
	return false;
}

} /* namespace MusicScan */
