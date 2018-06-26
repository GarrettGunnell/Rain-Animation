#include "ofApp.h"

void ofApp::setup() {
	background.load("Background.png");
	bench.load("Bench and Person.png");
	for (int i = 0; i < NUM_RAIN_DROPS; ++i) {
		float random = ofRandom(0.2, 1);
		if (random < 0.5) {
			thinRainDrops.push_back(new Rain(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), random, ofRandom(20, 30), ofRandom(20, 21), ofColor(150), true));
		}
		else {
			thickRainDrops.push_back(new Rain(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), random, ofRandom(20, 30), ofRandom(18, 19), ofColor(180), false));
		}
	}
}

void ofApp::update() {
	for (int i = 0; i < thinRainDrops.size(); ++i) {
		thinRainDrops[i]->move();
		thinRainDrops[i]->edgeCollisions();
	}
	for (int i = 0; i < thickRainDrops.size(); ++i) {
		thickRainDrops[i]->move();
		thickRainDrops[i]->edgeCollisions();
	}
}

void ofApp::draw() {
	ofSetColor(255, 255, 255);
	background.draw(0, 0, ofGetWidth(), ofGetHeight());
	for (int i = 0; i < thinRainDrops.size(); ++i) {
		thinRainDrops[i]->draw();
	}
	ofSetColor(255, 255, 255);
	bench.draw(0, 0, ofGetWidth(), ofGetHeight());
	for (int i = 0; i < thickRainDrops.size(); ++i) {
		thickRainDrops[i]->draw();
	}
}

void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y) {

}

void ofApp::mouseDragged(int x, int y, int button) {

}

void ofApp::mousePressed(int x, int y, int button) {

}

void ofApp::mouseReleased(int x, int y, int button) {

}

void ofApp::mouseEntered(int x, int y) {

}

void ofApp::mouseExited(int x, int y) {

}

void ofApp::windowResized(int w, int h) {

}

void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::dragEvent(ofDragInfo dragInfo) { 

}
