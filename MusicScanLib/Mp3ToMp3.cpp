#include "Mp3ToMp3.h"
#include "ffmpegcpp.h"
#include <memory>

namespace MusicScan
{

bool Mp3ToMp3C::Convert(const boost::filesystem::path & sourceFile,const boost::filesystem::path & dest)
{
	boost::system::error_code ec;
	boost::filesystem::copy_file(sourceFile,dest,ec);
	if (ec.value()!=0 )
	{
		//TODO manage error case
		printf("copy FAILED [%s] ->[%s] err=%d\n",
				sourceFile.string().c_str(),
				dest.string().c_str(),
				ec.value());
		return false;
	}
	return true;
}
} /* namespace MusicScan */
