/*
 * Processor.h
 *
 *  Created on: 18 déc. 2020
 *      Author: christian
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <MusicDataC.h>
#include <vector>

namespace MusicScan
{

class ProcessorC
{
public:
	void RemoveDuplicate(std::vector<MusicDataC> &musicData);
};

} /* namespace MusicScan */

#endif /* PROCESSOR_H_ */
