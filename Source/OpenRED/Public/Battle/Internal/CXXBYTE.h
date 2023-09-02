#pragma once

template <int I>
struct CXXBYTE
{
	CXXBYTE()
	{
		strncpy(m_Buf, "", I);
	}
	CXXBYTE(const char* in)
	{
		strncpy(m_Buf, in, I);
	}
	
	char m_Buf[I];
};