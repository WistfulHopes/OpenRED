#pragma once

class BattleEventManager;
class BATTLE_CObjectManager;

namespace red
{
	namespace btl
	{
		BATTLE_CObjectManager* GetObjectManager(); 
		BattleEventManager* GetEventManager(); 
	};
}
