#pragma once

#include "ofMain.h"
#include "Rain.h"

class ofApp : public ofBaseApp{

	public:
		ofImage background;
		ofImage bench;
		Rain* rainDrop;
		vector<Rain*> thinRainDrops;
		vector<Rain*> thickRainDrops;
		const int NUM_RAIN_DROPS = 1000;
		const int NUM_THIN_DROPS = 500;
		const int NUM_THICK_DROPS = 300;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
