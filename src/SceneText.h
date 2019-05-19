//
//  SceneText.h
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/18.
//

#pragma once

#ifndef SceneText_h
#define SceneText_h

#endif /* SceneText_h */

#include "ofMain.h"
#include "baseScene.h"

class SceneText : public baseScene {
public:
    void setup();
    void draw();
    void mousePressed(int x, int y, int button);
    
    void reset();
    
    ofTrueTypeFont font;
    static const int n = 2000;
    float m[n];
    float x[n];
    float y[n];
    float vx[n];
    float vy[n];
    float width = ofGetWidth();
    float height = ofGetHeight();
    float mouseX, mouseY;
    
    ofFbo fbo;
    ofPixels pix;
    vector <string> str;
    float gx[n];
    float gy[n];
    float amout=0;
    int count=0;
    
    int current = 0;
    
};
