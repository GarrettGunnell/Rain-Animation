#include "Rain.h"

Rain::Rain(float x, float y, float width, float length, float speed, ofColor color, bool thin) {
	this->x = x;
	this->width = width;
	this->length = length;
	this->y = y - this->length;
	this->speed = speed;
	this->color = color;
	this->thin = thin;
}

void Rain::move() {
	this->y += this->speed;
	this->x -= this->speed / 2;
}

void Rain::draw() {
	ofSetColor(this->color);
	ofPushMatrix();
	ofTranslate(this->x, this->y);
	ofRotate(30);
	ofDrawRectangle(0, 0, this->width, this->length);
	ofPopMatrix();
}

void Rain::edgeCollisions() {
	if (this->y + this->length > ofGetHeight()) {
		this->reset();
	}
	else if (this->x < 0) {
		this->reset();
	}
}

void Rain::reset() {
	int random = ofRandom(1000);
	if (random < 500) {
		if (this->thin) {
			this->x = ofRandom(ofGetWidth());
			this->width = ofRandom(0.2, 0.5);
			this->length = ofRandom(20, 30);
			this->y = 0 - this->length;
			this->speed = ofRandom(14, 15);
		}
		else {
			this->x = ofRandom(ofGetWidth());
			this->width = ofRandom(0.5, 1);
			this->length = ofRandom(20, 30);
			this->y = 0 - this->length;
			this->speed = ofRandom(12, 14);
		}
	}
	else {
		if (this->thin) {
			this->x = ofGetWidth();
			this->width = ofRandom(0.2, 0.5);
			this->length = ofRandom(20, 30);
			this->y = ofRandom(ofGetHeight());
			this->speed = ofRandom(20, 21);
		}
		else {
			this->x = ofGetWidth();
			this->width = ofRandom(0.5, 1);
			this->length = ofRandom(20, 30);
			this->y = ofRandom(ofGetHeight());
			this->speed = ofRandom(18, 19);
		}
	}
}