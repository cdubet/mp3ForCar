#ifndef MUSICSCANNER_H_
#define MUSICSCANNER_H_
#include <MusicDataC.h>
#include <boost/filesystem.hpp>
#include <vector>

namespace MusicScan
{

class MusicScannerC
{
public:
	MusicScannerC(const boost::filesystem::path & sourcePath);

	bool Scan();
private:
	bool Scan(const boost::filesystem::path & directory);

	std::vector<MusicDataC> m_musicData;
	boost::filesystem::path m_sourcePath;
};

} /* namespace MusicScan */

#endif /* MUSICSCANNER_H_ */
