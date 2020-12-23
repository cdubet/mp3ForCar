#include "Processor.h"
#include "VorbisToMp3.h"
#include "Mp3ToMp3.h"
#include <memory>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

namespace MusicScan
{
ProcessorC::ProcessorC(MusicFileScannerI &fileScanner):m_fileScanner(fileScanner)
{
	m_formatConverter.push_back(std::make_unique<VorbisToMp3C>());
	m_formatConverter.push_back(std::make_unique<Mp3ToMp3C>());
}

std::vector<MusicDataC> ProcessorC::SearchForUniqueMusic()
{
	std::vector<MusicDataC> musicData;
	if (m_fileScanner.Scan(musicData))
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
	return musicData;
}

bool ProcessorC::Convert(const boost::filesystem::path & source,const boost::filesystem::path &dest)
{
	for (auto itrTransform=m_formatConverter.begin();itrTransform !=m_formatConverter.end(); ++itrTransform)
	{
		if ((*itrTransform)->Convert(source, dest))
		{
			return true;
		}
	}
	return false;
}

boost::filesystem::path ProcessorC::BuildDestinationFilename(const boost::filesystem::path &dest,
															 const MusicDataC & musicData)
{
	std::wstring newFileNameWithoutExtension;
	std::wstring SEPARATOR(L"_");
	if (!musicData.getArtist().empty())
	{
		newFileNameWithoutExtension=musicData.getArtist();
	}
	if (!musicData.getAlbum().empty())
	{
		newFileNameWithoutExtension+=SEPARATOR;
		newFileNameWithoutExtension+=musicData.getAlbum();
	}

	if (musicData.getTrack()!=0)
	{
		newFileNameWithoutExtension+=SEPARATOR;
		newFileNameWithoutExtension+= std::to_wstring(musicData.getTrack());
	}
	if (!musicData.getTitle().empty())
	{
		newFileNameWithoutExtension+=SEPARATOR;
		newFileNameWithoutExtension+=musicData.getTitle();
	}
	//remove non ascii char

	newFileNameWithoutExtension.erase(std::remove_if(
			newFileNameWithoutExtension.begin(),
			newFileNameWithoutExtension.end(),
			[](unsigned char c) {if (c > '0' && c<='z') return false; else return true;} ),
			newFileNameWithoutExtension.end());
	boost::filesystem::path newFileName= dest/ boost::filesystem::path(newFileNameWithoutExtension+L".mp3");
	return newFileName;
}

bool ProcessorC::ConvertToDestination(const std::vector<MusicDataC> & musicList,
		const boost::filesystem::path &dest)
{
	bool result=true;
	for (auto itr=musicList.begin();itr!=musicList.end();++itr)
	{
		const boost::filesystem::path destFileName=BuildDestinationFilename(dest,*itr);
		std::cout<<itr->getFilename() << " -> " << destFileName<< std::endl;
		if (!Convert(itr->getFilename(),destFileName))
		{
			result=false;
		}
	}
	return result;
}
} /* namespace MusicScan */
