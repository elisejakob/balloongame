//
//  liquid.h
//  balloon
//
//  Created by Elise on 15.07.15.
//
//

#ifndef __balloon__liquid__
#define __balloon__liquid__

#include "ofMain.h"

class Liquid {
public:
    float x, y, w, h;
    float c;
    
    Liquid();
    
    void draw();
};

#endif /* defined(__balloon__liquid__) */
