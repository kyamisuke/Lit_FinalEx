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

class SceneLine : public baseScene{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float x(float t);
    float y(float t);
    float x2(float t);
    float y2(float t);
    
    float t;
    float angle =0;
    int NUM_LINES = 380;
    float v1 =0.4;
    float v2;
    bool increment = false;
    float fator =0.00001;
    
    ofMesh line, circle;
    ofColor c1 = ofColor(102,102,153);
    ofColor c2 = ofColor(102,0,153);
    ofColor c3 = ofColor(0, 0, 255);
    ofColor bg = ofColor(0, 0, 0, 32);
    
    float biasx=1;
    float biasy=1;
    
    bool inv = false;
    int alpha1=0;
    int alpha2=0;
    float rot=0;
    
    float width = ofGetWidth();
    float height = ofGetHeight();
    
    float* volume;
    float* fftSmoothed;
    float preVol=0;
    int nBandsToGet;
    
};
