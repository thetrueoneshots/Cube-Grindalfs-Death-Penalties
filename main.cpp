#include "main.h"
#include <stdlib.h>
#include <vector>

// Public variables.
// For example: int number = 10;

// Includes for the self written hooks.
// For example: #include "src/hooks/a_hook.h" 

/* Mod class containing all the functions for the mod.
*/

cube::Item* GetRandomEquipment(cube::Creature* creature)
{
	cube::Equipment* equipment = &creature->entity_data.equipment;
	std::vector<cube::Item*> items;

	if (equipment->chest.category != 0)
	{
		items.push_back(&equipment->chest);
	}

	if (equipment->feet.category != 0)
	{
		items.push_back(&equipment->feet);
	}

	if (equipment->hands.category != 0)
	{
		items.push_back(&equipment->hands);
	}

	if (equipment->neck.category != 0)
	{
		items.push_back(&equipment->neck);
	}

	if (equipment->ring_left.category != 0)
	{
		items.push_back(&equipment->ring_left);
	}

	if (equipment->ring_right.category != 0)
	{
		items.push_back(&equipment->ring_right);
	}

	if (equipment->shoulder.category != 0)
	{
		items.push_back(&equipment->shoulder);
	}

	if (equipment->weapon_left.category != 0)
	{
		items.push_back(&equipment->weapon_left);
	}

	if (equipment->weapon_right.category != 0)
	{
		items.push_back(&equipment->weapon_right);
	}

	if (items.size() <= 0)
	{
		return nullptr;
	}

	return items.at(std::rand() % items.size());
}

void DropRandomEquipment(cube::Game* game, cube::Creature* creature)
{
	cube::Item* item = GetRandomEquipment(creature);
	if (item == nullptr)
	{
		return;
	}

	game->PrintMessage(L"You dropped some equipment...\n", 255, 125, 0);
	game->host.world.DropItem(item, &creature->entity_data.position);

	// Reset item after DropItem is called, so a dropped copy is made.
	*item = cube::Item(0, 0);
}

void DeleteCharacter(cube::Game* game)
{
	game->GoToStartMenu();
	game->DeleteCharacter(game->current_character_slot);
}

class Mod : GenericMod {

	void OnPlayerDeath(cube::Game* game, cube::Creature* player) 
	{
		/*
		if (std::rand() % 2 == 0)
		{
			DropRandomEquipment(game, player);
		}
		*/
		DeleteCharacter(game);
	}

	void OnCreatureDeath(cube::Game* game, cube::Creature* creature) {
		cube::Creature* local_player = game->GetPlayer();

		if (creature->id == local_player->pet_id)
		{
			local_player->entity_data.equipment.pet = cube::Item(0, 0);
		}
	}

	int OnChat(std::wstring* message)
	{
		const wchar_t* msg = message->c_str();
		int index = 0;
		
		// Empty for now

		return 0;
	}
	
	void OnGameTick(cube::Game* game)
	{
		static bool init = false;
		if (!init)
		{
			init = true;
			// Empty for now
		}
	}
};

// Export of the mod created in this file, so that the modloader can see and use it.
EXPORT Mod* MakeMod() {
	return new Mod();
}