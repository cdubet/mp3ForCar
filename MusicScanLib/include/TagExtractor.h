/*
 * TagExtractor.h
 *
 *  Created on: 18 déc. 2020
 *      Author: christian
 */

#ifndef TAGEXTRACTOR_H_
#define TAGEXTRACTOR_H_

#include "MusicDataC.h"
#include <boost/optional/optional.hpp>
namespace MusicScan
{

class TagExtractorC
{
public:
	static boost::optional<MusicDataC> extract(const boost::filesystem::path &filename);
};

} /* namespace MusicScan */

#endif /* TAGEXTRACTOR_H_ */
