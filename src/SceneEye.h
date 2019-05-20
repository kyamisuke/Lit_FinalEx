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
    
    ofColor c1 = ofColor(30, 100, 255);
    ofColor c2 = ofColor(100, 0, 100);
    ofColor bg = ofColor(0, 32);
    bool inv = false;
    
    int nBandsToGet;
};
