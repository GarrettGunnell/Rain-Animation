#pragma once
#include "ofMain.h"

class Rain {
public:
	Rain(float x, float y, float width, float length, float speed, ofColor color, bool thin);
	void move();
	void draw();
	void edgeCollisions();
	void reset();

private:
	float x;
	float y;
	float width;
	float length;
	float speed;
	ofColor color;
	bool thin;
};