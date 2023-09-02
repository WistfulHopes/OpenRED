#include "OpenRED/Public/Battle/Internal/Objects/OBJ_CBase.h"

void OBJ_CBase::ActionRequestForce(const CXXBYTE<32>* actionName)
{
	CXXBYTE<32> label = CXXBYTE<32>("");
	ActionRequestEx(actionName, 9, nullptr, &label, 0);
}

void OBJ_CBase::ActionRequestEx(const CXXBYTE<32>* actionName, unsigned flag, OBJ_CBase* pEnemy, CXXBYTE<32>* label,
	unsigned reqflag)
{
}
