//
//  Wave.h
//  Elusive_Pearls
//
//  Created by 村上航輔 on 2019/05/14.
//

#ifndef Wave_h
#define Wave_h


#endif /* Wave_h */

#pragma once

#include "ofMain.h"

class Wave : public ofBaseApp{
    
public:
    Wave();
    Wave(int i);
    void display(float vol);
    
    int index;
    float x;
    float y;
    float sx;
    float sy;
    float R;
    float Rs;
    float r;
    float rn;
    float rns;
    float tn;
    float tns;
    float tr;
    int c;
    float Rmax;
    
    ofColor colors[4];
};
