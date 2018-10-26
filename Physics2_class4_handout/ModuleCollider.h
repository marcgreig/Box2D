#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

enum type {
	circle,
	chain,
	player
};

class ModuleCollider : public Module
{
public:
	ModuleCollider(Application* app, bool start_enabled = true);
	virtual ~ModuleCollider();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	type collider_type;
	iPoint collider_pos;
	int size; //radius if circle
	int* points[]; //only for chains
};