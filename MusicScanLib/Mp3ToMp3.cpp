#include "Mp3ToMp3.h"
#include "ffmpegcpp.h"
#include <memory>

namespace MusicScan
{

bool Mp3ToMp3C::Convert(const boost::filesystem::path & sourceFile,const boost::filesystem::path & dest)
{
	boost::system::error_code ec;
	boost::filesystem::copy_file(sourceFile,dest,ec);
	if (ec.value()==0 )
	{
		printf("%s ->%s\n",sourceFile.string().c_str(),dest.string().c_str());
	}
	else
	{
		//TODO manage error case
		printf("FAILED %s ->%s\n",sourceFile.string().c_str(),dest.string().c_str());
		return false;
	}
	return true;
}
} /* namespace MusicScan */
