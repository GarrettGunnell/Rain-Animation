#pragma once
#include "ofMain.h"

class Rain {
public:
	Rain(float x, float y, float width, float length, float speed, ofColor color, bool thin);
	void move();
	void draw();
	void edgeCollisions();
	void splash();
	void reset();

private:
	float x;
	float y;
	float width;
	float length;
	float speed;
	float splashTime;
	ofColor color;
	bool splashing;
	bool thin;
};