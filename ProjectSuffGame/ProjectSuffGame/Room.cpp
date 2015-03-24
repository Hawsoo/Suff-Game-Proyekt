#include "Room.h"


Room::Room()
{
}

//--------------------------------------------------
// Updates the room's entities.
//--------------------------------------------------
void Room::Update()
{
	for each (Entity *obj in entities)
	{
		obj->Update();
	}
}

//--------------------------------------------------
// Renders the room's entities and grounds.
//--------------------------------------------------
void Room::Render()
{
	for each (Ground *gnd in grounds)
	{
		gnd->Render();
	}

	for each (Entity *obj in entities)
	{
		obj->Render();
	}
}