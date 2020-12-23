#include "VorbisToMp3.h"
#include "ffmpegcpp.h"
#include <memory>
#include <iostream>

namespace MusicScan
{
VorbisToMp3C::VorbisToMp3C(int sampleRate, int channels):m_sampleRate(sampleRate),m_channels(channels)
{

}

bool VorbisToMp3C::ConvertToMp3(const boost::filesystem::path & source,const boost::filesystem::path & dest)
{
	try
	{
		std::cout<<source<<std::endl;
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
		std::cout<<"failing "<<source<<e.what()<<std::endl;
		return false;
	}
	return true;
}

bool VorbisToMp3C::Convert(const boost::filesystem::path & source,const boost::filesystem::path & dest )
{
	auto extension=source.extension();
	if (extension.string().compare(".ogg")==0)
	{
		return ConvertToMp3(source,dest);
	}
	return false;
}

} /* namespace MusicScan */
