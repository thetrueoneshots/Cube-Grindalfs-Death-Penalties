#include "main.h"
#include <stdlib.h>
#include <vector>

// Public variables.
// For example: int number = 10;

// Includes for the self written hooks.
// For example: #include "src/hooks/a_hook.h" 

/* Mod class containing all the functions for the mod.
*/

class Mod : GenericMod {

	void OnPlayerDeath(cube::Game* game, cube::Creature* player) 
	{
		cube::Equipment* equipment = &player->entity_data.equipment;

		if (std::rand() % 1 == 0)
		{
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
				return;
			}

			cube::Item* item = items.at(std::rand() % items.size());

			game->PrintMessage(L"You dropped some equipment...\n", 255, 125, 0);
			game->host.world.DropItem(item, &player->entity_data.position);

			// Reset item after DropItem is called, so a dropped copy is made.
			*item = cube::Item(0, 0);
		}
	}
};

// Export of the mod created in this file, so that the modloader can see and use it.
EXPORT Mod* MakeMod() {
	return new Mod();
}