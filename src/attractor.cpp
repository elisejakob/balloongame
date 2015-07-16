//
//  attractor.cpp
//  balloon
//
//  Created by Elise on 15.07.15.
//
//

#include "attractor.h"

Attractor::Attractor() {
    location.set(ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5);
    mass = 20;
    
    G = 5;
}

void Attractor::draw() {
    ofSetColor(10);
    ofCircle(location[0], location[1], mass);
}
ofVec2f Attractor::attract(Mover m) {
    force = location - m.vLoc;
    distance = force.length();
    distance = ofClamp(distance, 5, 25);
    force.normalize();
    strength = (G * mass * m.mass) / (distance * distance);
    force.scale(strength);
    return force;
}