#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = ball = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	background = App->textures->Load("pinball/background.png");
	ball = App->textures->Load("pinball/ball.png");
	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");
	bonus_fx = App->audio->LoadFx("pinball/bonus.wav");

	background_rect = { 0, 0 , 529, 880 };

	int background_points[76] = {
		515, 880,
		515, 230,
		505, 192,
		493, 168,
		477, 149,
		460, 136,
		462, 115,
		454, 104,
		418, 90,
		388, 85,
		371, 86,
		362, 100,
		344, 144,
		176, 145,
		151, 95,
		140, 85,
		107, 89,
		66, 103,
		55, 115,
		57, 135,
		27, 167,
		9, 205,
		1, 245,
		6, 286,
		15, 325,
		25, 364,
		34, 394,
		43, 426,
		50, 444,
		55, 456,
		36, 465,
		24, 515,
		10, 553,
		10, 576,
		17, 592,
		46, 661,
		44, 813,
		116, 880
	};

	int flipper_joint_right[12] = {
		389, 814,
		436, 730,
		437, 709,
		431, 697,
		372, 796,
		375, 808,
	};

	int flipper_joint_left[12] = {
		143, 813,
		96, 731,
		96, 710,
		103, 697,
		158, 795,
		156, 811
	};

	int ball_thrower[60] = {
		473, 878,
		464, 367,
		442, 312,
		428, 317,
		411, 315,
		405, 313,
		412, 307,
		420, 309,
		433, 306,
		445, 295,
		448, 279,
		443, 264,
		434, 258,
		423, 256,
		410, 259,
		401, 266,
		398, 273,
		390, 281,
		390, 268,
		398, 255,
		412, 248,
		428, 248,
		442, 252,
		451, 264,
		480, 295,
		480, 736,
		513, 737,
		513, 742,
		479, 743,
		480, 878
	};

	int middle_tobogan[58] = {
		356, 551,
		351, 432,
		330, 381,
		304, 353,
		272, 336,
		234, 327,
		192, 328,
		158, 340,
		135, 355,
		110, 379,
		97, 408,
		94, 442,
		97, 471,
		104, 494,
		110, 505,
		143, 489,
		126, 461,
		121, 424,
		123, 400,
		136, 380,
		152, 368,
		175, 354,
		209, 347,
		250, 352,
		281, 365,
		306, 391,
		323, 429,
		330, 488,
		333, 551
	};
	int portal_left[48] = {
		87, 227,
		70, 231,
		55, 228,
		42, 217,
		36, 201,
		37, 182,
		48, 171,
		60, 165,
		72, 164,
		86, 167,
		94, 174,
		101, 185,
		103, 193,
		94, 192,
		89, 179,
		75, 171,
		61, 171,
		49, 178,
		42, 188,
		43, 204,
		49, 214,
		60, 221,
		70, 224,
		78, 224
	};


	App->physics->CreateChain(0, 0, background_points, 76);
	App->physics->CreateChain(0, 0, flipper_joint_right, 12);
	App->physics->CreateChain(0, 0, flipper_joint_left, 12);
	App->physics->CreateChain(0, 0, ball_thrower, 60);
	App->physics->CreateChain(0, 0, middle_tobogan, 58);
	App->physics->CreateChain(0, 0, portal_left, 48);
	App->physics->CreateCircle(396, 198, 16);
	App->physics->CreateCircle(263, 284, 18);
	App->physics->CreateCircle(173, 423, 30);
	App->physics->CreateCircle(73, 638, 11);
	App->physics->CreateCircle(243, 639, 18);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->renderer->Blit(background, 0, 0, &background_rect);

	if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN)
	{
		App->physics->CreateBall(485, 716, 10);
	}
	

	if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		circles.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 25));
		circles.getLast()->data->listener = this;
	}

	if(App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		boxes.add(App->physics->CreateRectangle(App->input->GetMouseX(), App->input->GetMouseY(), 100, 50));
	}

	if(App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		// Pivot 0, 0
		int rick_head[64] = {
			14, 36,
			42, 40,
			40, 0,
			75, 30,
			88, 4,
			94, 39,
			111, 36,
			104, 58,
			107, 62,
			117, 67,
			109, 73,
			110, 85,
			106, 91,
			109, 99,
			103, 104,
			100, 115,
			106, 121,
			103, 125,
			98, 126,
			95, 137,
			83, 147,
			67, 147,
			53, 140,
			46, 132,
			34, 136,
			38, 126,
			23, 123,
			30, 114,
			10, 102,
			29, 90,
			0, 75,
			30, 62
		};

		ricks.add(App->physics->CreateChain(App->input->GetMouseX(), App->input->GetMouseY(), rick_head, 64));
		
		
	}

	// Prepare for raycast ------------------------------------------------------
	
	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();

	// All draw functions ------------------------------------------------------
	p2List_item<PhysBody*>* c = circles.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(circle, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}

	c = boxes.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(box, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}

	c = ricks.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(rick, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	App->audio->PlayFx(bonus_fx);
}
