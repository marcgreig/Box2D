#include "Globals.h"
#include "Application.h"
#include "ModulePhysics.h"
#include "ModuleCollider.h"

ModuleCollider::ModuleCollider(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleCollider::~ModuleCollider()
{
}

// Load assets
bool ModuleCollider::Start()
{
	LOG("Loading Collider");

	//int background_points[76] = {
	//	515, 880,
	//	515, 230,
	//	505, 192,
	//	493, 168,
	//	477, 149,
	//	460, 136,
	//	462, 115,
	//	454, 104,
	//	418, 90,
	//	388, 85,
	//	371, 86,
	//	362, 100,
	//	344, 144,
	//	176, 145,
	//	151, 95,
	//	140, 85,
	//	107, 89,
	//	66, 103,
	//	55, 115,
	//	57, 135,
	//	27, 167,
	//	9, 205,
	//	1, 245,
	//	6, 286,
	//	15, 325,
	//	25, 364,
	//	34, 394,
	//	43, 426,
	//	50, 444,
	//	55, 456,
	//	36, 465,
	//	24, 515,
	//	10, 553,
	//	10, 576,
	//	17, 592,
	//	46, 661,
	//	44, 813,
	//	116, 880
	//};
	//int flipper_joint_right[12] = {
	//	389, 814,
	//	436, 730,
	//	437, 709,
	//	431, 697,
	//	372, 796,
	//	375, 808,
	//};
	//int flipper_joint_left[12] = {
	//	143, 813,
	//	96, 731,
	//	96, 710,
	//	103, 697,
	//	158, 795,
	//	156, 811
	//};
	//int ball_thrower[60] = {
	//	473, 878,
	//	464, 367,
	//	442, 312,
	//	428, 317,
	//	411, 315,
	//	405, 313,
	//	412, 307,
	//	420, 309,
	//	433, 306,
	//	445, 295,
	//	448, 279,
	//	443, 264,
	//	434, 258,
	//	423, 256,
	//	410, 259,
	//	401, 266,
	//	398, 273,
	//	390, 281,
	//	390, 268,
	//	398, 255,
	//	412, 248,
	//	428, 248,
	//	442, 252,
	//	451, 264,
	//	480, 295,
	//	480, 736,
	//	513, 737,
	//	513, 742,
	//	479, 743,
	//	480, 878
	//};
	//int middle_tobogan[58] = {
	//	356, 551,
	//	351, 432,
	//	330, 381,
	//	304, 353,
	//	272, 336,
	//	234, 327,
	//	192, 328,
	//	158, 340,
	//	135, 355,
	//	110, 379,
	//	97, 408,
	//	94, 442,
	//	97, 471,
	//	104, 494,
	//	110, 505,
	//	143, 489,
	//	126, 461,
	//	121, 424,
	//	123, 400,
	//	136, 380,
	//	152, 368,
	//	175, 354,
	//	209, 347,
	//	250, 352,
	//	281, 365,
	//	306, 391,
	//	323, 429,
	//	330, 488,
	//	333, 551
	//};
	//int portal_left[48] = {
	//	87, 227,
	//	70, 231,
	//	55, 228,
	//	42, 217,
	//	36, 201,
	//	37, 182,
	//	48, 171,
	//	60, 165,
	//	72, 164,
	//	86, 167,
	//	94, 174,
	//	101, 185,
	//	103, 193,
	//	94, 192,
	//	89, 179,
	//	75, 171,
	//	61, 171,
	//	49, 178,
	//	42, 188,
	//	43, 204,
	//	49, 214,
	//	60, 221,
	//	70, 224,
	//	78, 224
	//};
	//App->physics->CreateChain(0, 0, background_points, 76);
	//App->physics->CreateChain(0, 0, flipper_joint_right, 12);
	//App->physics->CreateChain(0, 0, flipper_joint_left, 12);
	//App->physics->CreateChain(0, 0, ball_thrower, 60);
	//App->physics->CreateChain(0, 0, middle_tobogan, 58);
	//App->physics->CreateChain(0, 0, portal_left, 48);
	//App->physics->CreateCircle(396, 198, 16);
	//App->physics->CreateCircle(263, 284, 18);
	//App->physics->CreateCircle(173, 423, 30);
	//App->physics->CreateCircle(73, 638, 11);
	//App->physics->CreateCircle(243, 639, 18);
	return true;
}

// Update: draw background
update_status ModuleCollider::Update()
{
	return UPDATE_CONTINUE;
}

// Unload assets
bool ModuleCollider::CleanUp()
{
	LOG("Unloading Collider");

	return true;
}
