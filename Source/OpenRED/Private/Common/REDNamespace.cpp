#include "OpenRED/Public/Common/REDNamespace.h"

#include "OpenRED/Public/Battle/REDGameState_Battle.h"

BATTLE_CObjectManager* red::btl::GetObjectManager()
{
	if (const auto GameState = Cast<AREDGameState_Battle>(GWorld->GetGameState()))
	{
		return GameState->BattleObjectManager.Get();
	}
	return nullptr;
}

BattleEventManager* red::btl::GetEventManager()
{
	if (const auto GameState = Cast<AREDGameState_Battle>(GWorld->GetGameState()))
	{
		return GameState->EventManager.Get();
	}
	return nullptr;
}
