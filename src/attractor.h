//
//  attractor.h
//  balloon
//
//  Created by Elise on 15.07.15.
//
//

#ifndef __balloon__attractor__
#define __balloon__attractor__

#include "ofMain.h"
#include "mover.h"

class Attractor {
public:
    float mass;
    ofVec2f location;
    
    Attractor();
    void draw();
    
    ofVec2f force;
    ofVec2f attract(Mover m);
    float distance;
    float strength;
    
    float G;
};

#endif /* defined(__balloon__attractor__) */
