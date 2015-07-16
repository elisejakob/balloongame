#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("PHYSICS!!!");
    ofSetWindowShape(1200, 800);
    ofBackground(10);
    ofSetFrameRate(60);
    // smoother circles
    ofSetCircleResolution(40);
    //ofSetBackgroundAuto(false);
    
    loc[0] = ofGetWindowWidth()/2;
    loc[1] = ofGetWindowHeight()/2;
    
    vel.set(0,-1);
    
    acc.set(0, 0);
    
    wind.set(0.001, 0);
    
    ceiling.set(0, 0.01);
    
    // arduino
    serial.setup(0, 9600);
    // opens up the first (index 0) serial port in the list of available ports
    // at a speed of 9600 bauds (bits per second)
    arduinoSpeed = 1;
}

//--------------------------------------------------------------
void ofApp::applyForce(ofVec2f force){
    acc += force;
}

//--------------------------------------------------------------
void ofApp::update(){
    wind[0] = ofNoise(wind[0])/100 * -1;
    applyForce(wind);
    
    // bounce from top
    if (loc[1] < 59) {
        loc[1] = 60;
        vel[1] = 0;
        applyForce(ceiling);
    } else if (loc[0] < 60) {
        loc[0] = 60;
    }
    
    vel += acc;
    loc += vel;
    
    acc.scale(0);
    
    // arduino
    // receive and analyse data in an infinite while loop
    while (true) {
        int c = serial.readByte();
        // break the loop if all data received by the serial port was already processed or there is an error
        if (c == OF_SERIAL_NO_DATA || c == OF_SERIAL_ERROR || c == 0)
            break;
        // if a new line symbol is received, set a value to the pinchY slider
        // clear the buffer to be ready to receive the next value
        if (c == '\n') {
            arduinoSpeed = ofToFloat(str);
            str = "";
        }
        // append the received value to the buffer
        else str.push_back(c);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    color.set(255, 0, 0);
    ofSetColor(color);
    //ofCircle(loc[0], loc[1], 60);
    
    wind2.set(0.01, 0);
    gravity.set(0, 0.5);
    
    for(int i = 0; i < MOVERS; i++){
        // friction
        float c = 0.01;
        ofVec2f friction = mover[i].vVel;
        friction.scale(-1);
        friction.normalize();
        friction.scale(c);
        //mover[i].applyForce(friction);
        
        //mover[i].applyForce(wind2);
        // force of gravity calculated relative to the object's mass
        //mover[i].applyForce(gravity * (mover[i].mass * 0.1));
        
        
        //aForce = attractor.attract(mover[i]);
        //mover[i].applyForce(aForce);
        
        for (int j = 0; j < MOVERS; j++) {
            if (i != j) {
                mForce = mover[j].attract(mover[i]);
                mover[i].applyForce(mForce);
            }
        }
        
        mover[i].draw();
        mover[i].update();
        mover[i].checkEdges();
        
        mover[i].vVel *= arduinoSpeed;
    }
    
    //attractor.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP) {
        vel[0] = 0;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
