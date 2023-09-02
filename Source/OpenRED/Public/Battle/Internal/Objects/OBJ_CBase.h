#pragma once
#include "OpenRED/Public/Battle/Internal/CXXBYTE.h"

class OBJ_CBase
{
public:
	void ActionRequestForce(const CXXBYTE<32>* actionName);
	void ActionRequestEx(
		const CXXBYTE<32>* actionName,
		unsigned int flag,
		OBJ_CBase* pEnemy,
		CXXBYTE<32>* label,
		unsigned int reqflag);
};
