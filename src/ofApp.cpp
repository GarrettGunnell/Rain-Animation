#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(false);
	ofSetFrameRate(60);
	background.load("Background.png");
	bench.load("Bench and Person.png");
	umbrella1 = new ofRectangle(346, 340, 287, 78); //This initializes the umbrella hitbox, yeah I know it's ugly please don't point it out please thanks
	umbrella2 = new ofRectangle(363, 320, 246, 78);
	umbrella3 = new ofRectangle(354, 330, 266, 78);
	umbrella4 = new ofRectangle(376, 311, 220, 78);
	umbrella5 = new ofRectangle(387, 305, 200, 78);
	umbrella6 = new ofRectangle(396, 300, 180, 78);
	umbrella7 = new ofRectangle(409, 295, 160, 78);
	umbrella8 = new ofRectangle(426, 290, 122, 78);
	umbrella9 = new ofRectangle(441, 285, 90, 78);
	for (int i = 0; i < NUM_THIN_DROPS; ++i) {
		thinRainDrops.push_back(new Rain(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(0.2, 0.5), ofRandom(20, 30), ofRandom(20, 21), ofColor(100), true));
	}
	for (int i = 0; i < NUM_THICK_DROPS; ++i) {
		thickRainDrops.push_back(new Rain(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(1, 1.5), ofRandom(20, 30), ofRandom(18, 19), ofColor(160), false));
	}
}

void ofApp::update() {
	for (int i = 0; i < thinRainDrops.size(); ++i) {
		thinRainDrops[i]->move();
		thinRainDrops[i]->edgeCollisions(umbrella1, umbrella2, umbrella3, umbrella4, umbrella5, umbrella6, umbrella7, umbrella8, umbrella9);
	}
	for (int i = 0; i < thickRainDrops.size(); ++i) {
		thickRainDrops[i]->move();
		thickRainDrops[i]->edgeCollisions(umbrella1, umbrella2, umbrella3, umbrella4, umbrella5, umbrella6, umbrella7, umbrella8, umbrella9);
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
	ofDrawBitmapString(ofToString(ofGetMouseX()) + ", " + ofToString(ofGetMouseY()), 100, 100);
	//ofDrawRectangle(346, 340, 287, 78); //umbrella 1
	//ofDrawRectangle(363, 320, 246, 78); //umbrella 2
	//ofDrawRectangle(354, 330, 266, 78); //umbrella 3
	//ofDrawRectangle(376, 311, 220, 78); //umbrella 4
	//ofDrawRectangle(387, 305, 200, 78); //umbrella 5
	//ofDrawRectangle(396, 300, 180, 78); //umbrella 6
	//ofDrawRectangle(409, 295, 160, 78); //umbrella 7
	//ofDrawRectangle(426, 290, 122, 78); //umbrella 8
	//ofDrawRectangle(441, 285, 90, 78); //umbrella 9
	ofDrawRectangle(180, 460, 641, 30);
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
