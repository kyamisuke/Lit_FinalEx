//
//  SceneFlow.h
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/19.
//
#pragma once

#ifndef SceneFlow_h
#define SceneFlow_h

#endif /* SceneFlow_h */

#include "ofMain.h"
#include "baseScene.h"

class SceneFlow : public baseScene{
    
public:
    void setup();
    void update();
    void draw();

    int circle = 200;
    float rot;
    float col;
    float freq = 0.000005;
    int count = 0;
    float r;
    
    ofSoundPlayer sound;
    float *volume;
    float *fftSmoothed;
    
    float preVol=0;
    
    bool inv=false;
        
    int nBandsToGet;
    
};
