#include "OpenRED/Public/Common/RoundTimer.h"

RoundTimer::RoundTimer()
{
	m_FrameTimeMax = 5940;
	m_CurrentFrameTime = 5940;
	m_TimeStep = 1;
	m_Started = false;
	m_Pause = true;
	m_Infinity = false;
	m_forcePause = false;
}
