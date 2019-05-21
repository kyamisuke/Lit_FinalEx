//
//  SceneFlow.cpp
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/19.
//

#include "SceneFlow.h"

//--------------------------------------------------------------
void SceneFlow::setup(){
    ofBackground(0);
    rot = 0;
    ofSetFrameRate(60);
    
//    sound.load("Broken Heart.mp3");
//    sound.setVolume(1.0);
//    sound.setLoop(true);
//    sound.play();
    
    fftSmoothed = new float[8192];
    for (int i=0; i<8192; i++) fftSmoothed[i] = 0;
    nBandsToGet = 60;
}

//--------------------------------------------------------------
void SceneFlow::update(){
    ofSoundUpdate();
    volume = ofSoundGetSpectrum(nBandsToGet);
    
    for (int i=0; i<nBandsToGet; i++) {
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < volume[i]) fftSmoothed[i] = volume[i];
    }
}

//--------------------------------------------------------------
void SceneFlow::draw(){
    float randomx = 1;
    float randomy = 1;

    if (fftSmoothed[40] - preVol > 0.005) {
        ofSetColor(255, 32);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        randomx = ofRandom(-1, 1);
        randomy = ofRandom(-1, 1);
        inv = true;
    } else {
        ofSetColor(0, 32);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateDeg(rot);
    for (int i=0; i<500; i++) {
        circle = 200 + 150*sin(ofGetSystemTimeMillis()*freq*i);
        col = ofMap(circle, 50, 350, 255, 60);
        ofColor c = ofColor(74, 0, col);
        r = ofMap(circle, 50, 350, 5, 2);
        if (inv) {
            c.invert();
            inv = true;
        }
        ofSetColor(c);
        ofDrawCircle(circle*cos(i)+fftSmoothed[40]*1000*randomx, circle*sin(i)+fftSmoothed[40]*1000*randomy, r);
        preVol = fftSmoothed[40];
//        ofPushMatrix();
//        ofTranslate(circle*cos(i)+fftSmoothed[40]*400, circle*sin(i)+fftSmoothed[40]*400);
//        for (int i=0; i < 3; i++) {
//            ofRotateDeg(i*120);
//            ofDrawTriangle(0, r+fftSmoothed[40]*200, -r*0.5, -r*0.5*pow(3, 0.5), r*0.5, -r*0.5*pow(3, 0.5));
//        }
//        ofPopMatrix();
        rot += 0.00005;
    }
    if (inv) {
        inv = false;
    }
}

