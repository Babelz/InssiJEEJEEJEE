#pragma once
#include <Box2D\Box2D.h>

class Convert {
	
public:
	static const float SCALE;
	static b2Vec2 worldToBox2d(float x, float y) {
		return b2Vec2(x / SCALE, y / SCALE);
	}

	static b2Vec2 worldToBox2d(b2Vec2 vec) {
		vec.x /= SCALE;
		vec.y /= SCALE;
		return vec;
	}

	static float worldToBox2d(float f) {
		return f / SCALE;
	}

	static b2Vec2 box2dToWorld(float x, float y) {
		return b2Vec2(x * SCALE, y * SCALE);
	}

	static b2Vec2 box2dToWorld(b2Vec2 vec) {
		vec.x *= SCALE;
		vec.y *= SCALE;
		return vec;
	}

	static float box2dToWorld(float f) {
		return f * SCALE;
	}
};

