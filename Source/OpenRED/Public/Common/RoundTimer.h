#pragma once

class RoundTimer
{
public:
	int m_FrameTimeMax;
	int m_CurrentFrameTime;
	unsigned int m_TimeStep;
	bool m_Started;
	bool m_Pause;
	bool m_Infinity;
	bool m_forcePause;
};
