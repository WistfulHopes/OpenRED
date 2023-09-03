#pragma once

#include "CXXBYTE.h"

inline CXXBYTE<32> AN_CmnActStand = "CmnActStand";
inline CXXBYTE<32> AN_CmnActStandTurn = "CmnActStandTurn";
inline CXXBYTE<32> AN_CmnActEntryWait = "CmnActEntryWait";


inline const CXXBYTE<32>* CmnActNameTable[156] = {
	&AN_CmnActStand,
	&AN_CmnActStandTurn,
	&AN_CmnActEntryWait,
};