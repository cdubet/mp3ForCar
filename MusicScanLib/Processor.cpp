#include "Processor.h"
#include <string>
#include <algorithm>
#include <vector>

namespace MusicScan
{
void ProcessorC::RemoveDuplicate(std::vector<MusicDataC> &musicData)
{
	std::vector<std::wstring> titleAlreadyFound;
	titleAlreadyFound.reserve(musicData.size());

	for (auto itr=musicData.begin();itr!=musicData.end();++itr)
	{
		auto itrFind=std::find(titleAlreadyFound.begin(), titleAlreadyFound.end(), itr->getTitle());
		if (itrFind == titleAlreadyFound.end())
		{
			titleAlreadyFound.push_back(itr->getTitle());
		}
		else
		{
			musicData.erase(itr);
		}
	}

}
} /* namespace MusicScan */
