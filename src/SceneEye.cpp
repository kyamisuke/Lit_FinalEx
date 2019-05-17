//
//  SceneEye.cpp
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/17.
//

#include "SceneEye.h"

void SceneEye::reset() {
    for (int i=0; i<n; i++) {
        m[i] = ofRandom(-1, 1)*16;
        x[i] = ofRandomWidth();
        y[i] = ofRandomHeight();
    }
    
}

//--------------------------------------------------------------

void SceneEye::setup(){
    ofBackground(0, 32);
    ofSetFrameRate(60);
    ofSetWindowTitle(ofToString((float)ofGetFrameRate()));
    reset();
    
    fftSmoothed = new float[8192];
    for (int i=0; i<8192; i++) fftSmoothed[i] = 0;
    nBandsToGet = 60;
}

//--------------------------------------------------------------
void SceneEye::update(){
    ofSoundUpdate();
    volume = ofSoundGetSpectrum(nBandsToGet);
    
    for (int i=0; i<nBandsToGet; i++) {
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < volume[i]) fftSmoothed[i] = volume[i];
    }
}

//--------------------------------------------------------------
void SceneEye::draw(){
    ofSetColor(0, 32);
    ofDrawRectangle(0, 0, width, height);
    
    if (fftSmoothed[40] > 0.04) {
        reset();
        mouseX = ofRandom(ofGetWidth());
        mouseY = ofRandom(ofGetHeight());
    }
    
    for (int i=0; i<n; i++) {
        float dx = mouseX - x[i];
        float dy = mouseY - y[i];
        
        float d = sqrt(dx*dx + dy*dy);
        if (d < 1) d = 1;
        
        float f = sin(d * 0.04) * m[i] / d;
        
        vx[i] = vx[i] * 0.5 + f * dx;
        vy[i] = vy[i] * 0.5 + f * dy;
    }
    
    for (int i=0; i<n; i++) {
        x[i] += vx[i];
        y[i] += vy[i];
        
        if (x[i] < 0) x[i] = width;
        else if (x[i] > width) x[i] = 0;
        
        if (y[i] < 0) y[i] = height;
        else if (y[i] > height) y[i] =0;
        
        if (m[i] < 0) ofSetColor(30, 100, 255);
        else ofSetColor(100, 0, 100);
        
        ofDrawCircle(x[i], y[i], 2);
    }
    
}

