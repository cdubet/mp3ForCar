/*
 * Processor.h
 *
 *  Created on: 18 déc. 2020
 *      Author: christian
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <MusicDataC.h>
#include <MusicFileScannerI.h>
#include <MusicFormatConverter.h>

#include <vector>
#include <boost/optional.hpp>

namespace MusicScan
{
class MusicDataC;

class ProcessorC
{
public:
	ProcessorC(MusicFileScannerI &);
	std::vector<MusicDataC> SearchForUniqueMusic();
	bool ConvertToDestination(const std::vector<MusicDataC> & musicList,
			const boost::filesystem::path &dest);

private :
	bool Convert(const boost::filesystem::path & source,const boost::filesystem::path &dest);
	boost::filesystem::path BuildDestinationFilename(const boost::filesystem::path &dest,
													const  MusicDataC  &musicData);

	MusicFileScannerI &m_fileScanner;
	std::vector<std::unique_ptr<MusicFormatConverterI> > m_formatConverter;
};

} /* namespace MusicScan */

#endif /* PROCESSOR_H_ */
