#include "Rain.h"

Rain::Rain(float x, float y, float width, float length, float speed, ofColor color, bool thin) {
	this->x = x;
	this->width = width;
	this->length = length;
	this->y = y - this->length;
	this->speed = speed;
	this->color = color;
	this->thin = thin;
	this->splashing = false;
	this->splashTime = 0;
	this->splashLength = 0;
	if (thin == false) {
		int random = ofRandom(1000);
		if (random < 500) {
			this->middle = true;
		}
		else {
			this->middle = false;
		}
	}
	else {
		this->middle = false;
	}
}

void Rain::move() {
	this->y += this->speed;
	this->x -= this->speed / 3;
}

void Rain::draw() {
	if (this->splashing) {
		this->splashLength += ofRandom(0.4, 0.8);
		ofSetColor(200);
		ofPushMatrix();
		ofTranslate(this->x, this->y);
		ofRotate(210);
		ofDrawRectangle(0, -2, 1, this->splashLength);
		ofRotate(315);
		ofDrawRectangle(5, 0, 1, this->splashLength);
		ofPopMatrix();
		if (ofGetElapsedTimeMillis() > this->splashTime + 180) {
			this->reset();
		}
	}
	else {
		ofSetColor(this->color);
		ofPushMatrix();
		ofTranslate(this->x, this->y);
		ofRotate(15);
		ofDrawRectangle(0, 0, this->width, this->length);
		ofPopMatrix();
	}
}

void Rain::edgeCollisions(ofRectangle* umbrella1, ofRectangle* umbrella2, ofRectangle* umbrella3, ofRectangle* umbrella4, ofRectangle* umbrella5, ofRectangle* umbrella6, ofRectangle* umbrella7, ofRectangle* umbrella8, ofRectangle* umbrella9) {
	if (!this->splashing) {
		if (this->thin) {
			if (this->y + this->length > 750) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
		}
		else if (this->middle) {
			if (umbrella9->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (umbrella8->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (umbrella7->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (umbrella6->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (umbrella5->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (umbrella4->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (umbrella3->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (umbrella2->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (umbrella1->inside(this->x, this->y)) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
			else if (this->y + this->length > 775) {
				this->splashTime = ofGetElapsedTimeMillis();
				this->splash();
			}
		}
		else if (this->y + this->length > 775) {
			this->splashTime = ofGetElapsedTimeMillis();
			this->splash();
		}
		else if (this->x < 0) {
			this->reset();
		}
	}
}

void Rain::splash() {
	this->speed = 0;
	this->splashing = true;
}

void Rain::reset() {
	int random = ofRandom(1000);
	int otherRandom = ofRandom(1000);
	if (random < 800) {
		if (this->thin) {
			this->x = ofRandom(ofGetWidth());
			this->width = ofRandom(0.2, 0.5);
			this->length = ofRandom(20, 25);
			this->y = 0 - this->length;
			this->speed = ofRandom(20, 21);
			//20,21
			//14,15
		}
		else {
			this->x = ofRandom(ofGetWidth());
			this->width = ofRandom(0.7, 1);
			this->length = ofRandom(20, 25);
			this->y = 0 - this->length;
			this->speed = ofRandom(18, 19);
			//18,19
			//12,14
			if (otherRandom < 700) {
				this->middle = true;
			}
			else {
				this->middle = false;
			}
		}
	}
	else {
		if (this->thin) {
			this->x = ofGetWidth();
			this->width = ofRandom(0.2, 0.5);
			this->length = ofRandom(20, 25);
			this->y = ofRandom(0, 743);
			this->speed = ofRandom(20, 21);
		}
		else {
			this->x = ofGetWidth();
			this->width = ofRandom(0.7, 1);
			this->length = ofRandom(20, 25);
			this->y = ofRandom(0, 770);
			this->speed = ofRandom(18, 19);
			if (otherRandom < 700) {
				this->middle = true;
			}
			else {
				this->middle = false;
			}
		}
	}
	this->splashing = false;
	this->splashLength = 0;
}