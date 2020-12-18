#ifndef MUSICDATAC_H_
#define MUSICDATAC_H_

#include <string>
#include <boost/filesystem/convenience.hpp>

namespace MusicScan
{

class MusicDataC
{
public:
	std::wstring getAlbum() const
	{
		return m_album;
	}

	void setAlbum(const std::wstring & mAlbum)
	{
		m_album = mAlbum;
	}

	std::wstring getArtist() const
	{
		return m_artist;
	}

	void setArtist(const std::wstring & mArtist)
	{
		m_artist = mArtist;
	}

	boost::filesystem::path getFilename() const
	{
		return m_filename;
	}

	void setFilename(const boost::filesystem::path &mFilename)
	{
		m_filename = mFilename;
	}

	std::wstring getTitle() const
	{
		return m_title;
	}

	void setTitle(const std::wstring mTitle)
	{
		m_title = mTitle;
	}

	unsigned int getTrack() const
	{
		return m_track;
	}

	void setTrack(unsigned int mTrack)
	{
		m_track = mTrack;
	}

private:
	boost::filesystem::path m_filename;
	std::wstring m_artist;
	std::wstring m_title;
	std::wstring m_album;
	unsigned int m_track;

};

} /* namespace MusicScan */

#endif /* MUSICDATAC_H_ */
