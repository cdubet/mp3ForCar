#ifndef MUSICSCANNER_H_
#define MUSICSCANNER_H_

#include <MusicFileScannerI.h>
#include <MusicDataC.h>
#include <boost/filesystem.hpp>
#include <vector>

namespace MusicScan
{

class MusicFileScannerC: public MusicFileScannerI
{
public:

	MusicFileScannerC(const boost::filesystem::path & sourcePath);
	virtual ~MusicFileScannerC() {}

	bool Scan(std::vector<MusicDataC> &musicData) override;

private:
	bool Scan(std::vector<MusicDataC> &musicData,const boost::filesystem::path & directory);


	boost::filesystem::path m_sourcePath;
};

} /* namespace MusicScan */

#endif /* MUSICSCANNER_H_ */
