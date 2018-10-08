#pragma once
#include "Module.h"
#include "Globals.h"
#include "Box2D/Box2D/Box2D.h"

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

#define PIXELS_PER_METER 50.0f // if touched change METER_PER_PIXEL too
#define METER_PER_PIXEL 0.02f // this is 1 / PIXELS_PER_METER !

#define METERS_TO_PIXELS(m) ((int) floor(PIXELS_PER_METER * m))
#define PIXEL_TO_METERS(p)  ((float) METER_PER_PIXEL * p)

class b2World;
class b2Body;

// TODO 5: Create a small class that keeps a pointer to the b2Body
// and has a method to request the position
// then write the implementation in the .cpp
// Then make your circle creation function to return a pointer to that class


class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

	// TODO 3: Move body creation to 3 functions to create circles, rectangles and chains

	void createCircle() {
		b2BodyDef body;
		body.type = b2_dynamicBody;
		float radius = PIXEL_TO_METERS(25);
		body.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

		b2Body* b = world->CreateBody(&body);

		b2CircleShape shape;
		shape.m_radius = radius;
		b2FixtureDef fixture;
		fixture.shape = &shape;

		b->CreateFixture(&fixture);
	}

	void createBox() {
		b2BodyDef body;
		body.type = b2_dynamicBody;

		body.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

		b2Body* b = world->CreateBody(&body);

		b2PolygonShape shape;
		shape.SetAsBox(PIXEL_TO_METERS(25), PIXEL_TO_METERS(25));
		b2FixtureDef fixture;
		fixture.shape = &shape;
		fixture.density = 1.0f;

		b->CreateFixture(&fixture);
	}

	void createChain() {
		int points[72] = {
			34, 2,
			36, 35,
			12, 32,
			26, 55,
			1, 66,
			25, 78,
			9, 88,
			27, 97,
			20, 105,
			34, 106,
			29, 116,
			40, 112,
			43, 117,
			52, 124,
			63, 126,
			74, 123,
			81, 114,
			82, 108,
			87, 106,
			89, 103,
			84, 99,
			86, 90,
			93, 85,
			88, 80,
			91, 75,
			91, 65,
			98, 59,
			90, 56,
			87, 50,
			93, 33,
			79, 36,
			78, 18,
			75, 6,
			70, 20,
			63, 30,
			50, 15
		};
		b2Vec2 vertices[12];

		for (int i = 0; i < 12; i++) {
			vertices[i].x = PIXEL_TO_METERS(points[i * 2]);
			vertices[i].y = PIXEL_TO_METERS(points[(i * 2) + 1]);

		}

		b2BodyDef body;
		body.type = b2_dynamicBody;

		body.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

		b2Body* b = world->CreateBody(&body);

		int32 count = 12;
		b2ChainShape shape;
		shape.CreateLoop(vertices, count);
		b2FixtureDef fixture;
		fixture.shape = &shape;
		fixture.density = 1.0f;

		b->CreateFixture(&fixture);
	}

private:

	bool debug;
	b2World* world;
};