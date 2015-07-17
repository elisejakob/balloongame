//
//  mover.cpp
//  balloon
//
//  Created by Elise on 14.07.15.
//
//

#include "mover.h"
#include "ofApp.h"

Mover::Mover() {
    // constructor
    float m = ofRandom(1, 2.5);
    
    color.set(ofRandom(50, 250), ofRandom(50, 250), ofRandom(50, 250), ofRandom(100, 150));
    
    mass = m;
    vLoc.set(0, 0);
    vVel.set(0, 0);
    vAcc.set(0, 0);
    
    G = 0.4;
}

void Mover::applyForce(ofVec2f force) {
    ofVec2f f = force/mass;
    vAcc += f;
}

void Mover::update() {
    vVel += vAcc;
    vLoc += vVel;
    vAcc.scale(0);
}

void Mover::draw() {
    ofSetColor(color);
    ofCircle(vLoc[0], vLoc[1], mass*10);
}

void Mover::checkEdges() {
    if (vLoc.x > ofGetWindowWidth()) {
        vLoc.x = ofGetWindowWidth();
        vVel.x *= -1;
        vVel.scale(0);
    } else if (vLoc[0] < 0) {
        vVel[0] *= -1;
        vLoc[0] = 0;
        vVel.scale(0);
    }
    if (vLoc[1] > ofGetWindowHeight()) {
        vVel[1] *= -1;
        vLoc[1] = ofGetWindowHeight();
        vVel.scale(0);
    } else if (vLoc[1] < 0) {
        vVel[1] *= -1;
        vLoc[1] = 0;
        vVel.scale(0);
    }
}

bool Mover::isInside(Liquid l) {
    if (vLoc[0] > l.x && vLoc[0] < l.x + l.w && vLoc[1] > l.y && vLoc[1] < l.y + l.h) {
        return true;
    } else {
        return false;
    }
}

void Mover::applyDrag(Liquid l) {
    speed = vVel.length();
    dragMagnitude = l.c * speed * speed;
    
    drag = vVel;
    drag.scale(-1);
    drag.normalize();
    
    drag.scale(dragMagnitude);
    
    applyForce(drag);
}

ofVec2f Mover::attract(Mover m) {
    force = vLoc - m.vLoc;
    distance = force.length();
    distance = ofClamp(distance, 5, 25);
    force.normalize();
    strength = (G * mass * m.mass) / (distance * distance);
    force.scale(strength);
    return force;
}
