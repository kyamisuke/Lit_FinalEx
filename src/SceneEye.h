//
//  SceneEye.h
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/16.
//
#pragma once

#ifndef SceneEye_h
#define SceneEye_h


#endif /* SceneEye_h */

#include "ofMain.h"
#include "baseScene.h"

class SceneEye : public baseScene{
    
public:
    void setup();
    void draw();
    void update();
    
    void reset();
    float normRandom();
    
    static const int n = 10000;
    float m[n];
    float x[n];
    float y[n];
    float vx[n];
    float vy[n];
    float width = ofGetWidth();
    float height = ofGetHeight();
    float mouseX, mouseY;
    
    ofSoundPlayer sound;
    float* volume;
    float* fftSmoothed;
    
    int nBandsToGet;
};
