//
//  liquid.cpp
//  balloon
//
//  Created by Elise on 15.07.15.
//
//

#include "liquid.h"

Liquid::Liquid() {
    x = 0;
    y = ofGetWindowHeight()/2;
    //w = ofGetWindowWidth(); ??????
    w = 1200;
    h = ofGetWindowWidth()/2;
    c = 0.3;
}

void Liquid::draw() {
    ofSetColor(0, 60);
    ofRect(x, y, w, h);
};