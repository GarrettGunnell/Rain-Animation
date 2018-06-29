#pragma once
#include "ofMain.h"

class Rain {
public:
	Rain(float x, float y, float width, float length, float speed, ofColor color, bool thin);
	void move();
	void draw();
	void edgeCollisions(ofRectangle* umbrella1, ofRectangle* umbrella2, ofRectangle* umbrella3, ofRectangle* umbrella4, ofRectangle* umbrella5, ofRectangle* umbrella6, ofRectangle* umbrella7, ofRectangle* umbrella8, ofRectangle* umbrella9, ofRectangle* benchHitbox, ofRectangle* benchHitbox2);
	void splash();
	void reset();

private:
	float x;
	float y;
	float width;
	float length;
	float splashLength;
	float speed;
	float splashTime;
	ofColor color;
	ofColor splashColor;
	bool splashing;
	bool thin;
	bool middle;
};