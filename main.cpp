#include "main.h"
#include <stdlib.h>

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
			cube::Item item;
			switch (std::rand() % 10)
			{
			case 0:
				item = equipment->chest;
				equipment->chest = cube::Item(0, 0);
				break;
			case 1:
				item = equipment->feet;
				equipment->feet = cube::Item(0, 0);
				break;
			case 2:
				item = equipment->hands;
				equipment->hands = cube::Item(0, 0);
				break;
			case 3:
				item = equipment->neck;
				equipment->neck = cube::Item(0, 0);
				break;
			case 4:
				item = equipment->pet;
				equipment->pet = cube::Item(0, 0);
				break;
			case 5:
				item = equipment->ring_left;
				equipment->ring_left = cube::Item(0, 0);
				break;
			case 6:
				item = equipment->ring_right;
				equipment->ring_right = cube::Item(0, 0);
				break;
			case 7:
				item = equipment->shoulder;
				equipment->shoulder = cube::Item(0, 0);
				break;
			case 8:
				item = equipment->weapon_left;
				equipment->weapon_left = cube::Item(0, 0);
				break;
			case 9:
			default:
				item = equipment->weapon_right;
				equipment->weapon_right = cube::Item(0, 0);
				break;
			}

			if (item.category == 0)
			{
				return;
			}

			game->PrintMessage(L"You dropped some equipment...\n", 255, 125, 0);
			game->host.world.DropItem(&item, &player->entity_data.position);
		}
	}
};

// Export of the mod created in this file, so that the modloader can see and use it.
EXPORT Mod* MakeMod() {
	return new Mod();
}