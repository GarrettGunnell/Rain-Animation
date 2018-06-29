#pragma once
#include "ofMain.h"

class Rain {
public:
	Rain(float x, float y, float width, float length, float speed, ofColor color, bool thin);
	void move();
	void draw();
	void edgeCollisions(ofRectangle* umbrella1, ofRectangle* umbrella2, ofRectangle* umbrella3, ofRectangle* umbrella4, ofRectangle* umbrella5, ofRectangle* umbrella6, ofRectangle* umbrella7, ofRectangle* umbrella8, ofRectangle* umbrella9, ofRectangle* benchHitbox, ofRectangle* benchHitbox2);
	void splash(); //responsible for the splash animation
	void reset();

private:
	float x;
	float y;
	float width;
	float length;
	float splashLength;
	float speed;
	float splashTime; //stores the time in which the rain splashed, so that I can compare that time to the time elapsed in the program and control the length of the animation accordingly
	ofColor color;
	ofColor splashColor; //the sole purpose of this is to control the color of the splashes on the bench because they're harder to see at a lighter shade
	bool splashing; //tells whether or not the rain drop is currently playing the splash animation
	bool thin; //tells whether or not the rain is in the background or not
	bool middle; //tells whether or not the rain is in the middleground which is where collision with the umbrella and bench happens
};