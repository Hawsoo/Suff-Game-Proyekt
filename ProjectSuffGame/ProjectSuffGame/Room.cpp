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
// Renders the room's entities.
//--------------------------------------------------
void Room::Render()
{
	for each (Entity *obj in entities)
	{
		obj->Render();
	}

	for each (Ground *gnd in grounds)
	{
		gnd->Render();
	}
}