
#include "MusicDataFormatter.h"

namespace MusicScan
{

char Convert(wchar_t initialChar)
{
	switch(initialChar)
	{
	case L'à':
	case '@':
	case 160:
		return 'A';
	case L'ç':
		return 'C';
	case L'é':
	case L'è':
	case L'ê':
		return 'E';
	case L'ö':
		return 'O';
	case L'ü':
	case L'ù':
		return 'U';
	default:
		return ::toupper(initialChar);
	}
}

bool ShouldBeIgnored(wchar_t candidate)
{
	switch(candidate)
	{
	case '&':
	case '~':
	case '\"':
	case '#':
	case '\'':
	case '{':
	case '(':
	case '[':
	case '-':
	case '|':
	case '`':
	case '_':
	case '^':
	case '\\':
	case ')':
	case ']':
	case '=':
	case '+':
	case '}':
	case '*':
	case '%':
	case ':':
	case ',':
	case ';':
	case '?':
	case '!':
	case '<':
	case '>':
		return true;
	default:
		return (candidate <=' ');
	}
}
std::wstring FormatString(const std::wstring &source)
{
	std::wstring formattedString;
	for (wchar_t car:source)
	{
		if (!ShouldBeIgnored(car))
		{
			formattedString.push_back(Convert(car));
		}
	}
	return formattedString;
}

void MusicDataFormatterC::Format(MusicDataC &data)
{
	data.setTitle(FormatString(data.getTitle()));
	data.setAlbum(FormatString(data.getAlbum()));
	data.setArtist(FormatString(data.getArtist()));
}

} /* namespace MusicScan */
