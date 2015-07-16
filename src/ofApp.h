#pragma once

#include "ofMain.h"

#include "mover.h"
#define MOVERS 400

#include "liquid.h"

#include "attractor.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    // elisevariabler
    
    ofColor color;
    
    ofVec2f loc;
    ofVec2f vel;
    ofVec2f acc;
    
    ofVec2f wind;
    ofVec2f ceiling;
    ofVec2f wind2;
    ofVec2f gravity;
    
    void applyForce(ofVec2f force);
    
    Mover mover[MOVERS];
    
    Attractor attractor;
    
    Liquid liquid;
    
    ofVec2f aForce;
    ofVec2f mForce;
    
    // arduino
    ofSerial serial;
    string str;
    float arduinoSpeed;
};
