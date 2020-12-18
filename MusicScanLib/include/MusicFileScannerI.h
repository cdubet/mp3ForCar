#ifndef MUSIC_SCANNER_I_H_
#define MUSIC_SCANNER_I_H_

#include <MusicDataC.h>

namespace MusicScan
{

class MusicFileScannerI // @suppress("Class has a virtual method and non-virtual destructor")
{
public:
	virtual bool Scan(std::vector<MusicDataC> &musicData)=0;
};
}
#endif
