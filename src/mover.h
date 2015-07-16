//
//  mover.h
//  balloon
//
//  Created by Elise on 14.07.15.
//
//

#ifndef __balloon__mover__
#define __balloon__mover__

#include "ofMain.h"
#include "liquid.h"

class Mover {
public:
    Mover();
    void applyForce(ofVec2f force);
    void draw();
    void update();
    void checkEdges();
    void applyDrag(Liquid l);
    
    ofVec2f vLoc;
    ofVec2f vVel;
    ofVec2f vAcc;
    
    float mass;
    
    ofColor color;
    
    bool isInside(Liquid l);
    
    float speed;
    float dragMagnitude;
    
    ofVec2f drag;
    
    ofVec2f force;
    ofVec2f attract(Mover m);
    float distance;
    float strength;
    
    float G;
};

#endif /* defined(__balloon__mover__) */
