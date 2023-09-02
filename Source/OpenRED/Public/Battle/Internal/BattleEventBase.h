#pragma once

class DemoEndCheck
{
public:
	bool isDemoEnd[2];
	bool isMemberDemoEnd[2][3];
};

class BattleEventBase
{
public:
	bool m_Started;
	bool m_CounterReset;
	unsigned int m_Counter;
	int m_DemoTimeoutCounter;
	int m_SubState;
	DemoEndCheck m_DemoEndCheck;
	bool m_EnableDemoEndCheck;
};
