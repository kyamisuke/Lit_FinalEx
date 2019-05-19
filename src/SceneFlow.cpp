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
    ofSetBackgroundAuto(true);
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
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateDeg(rot);
    for (int i=0; i<500; i++) {
        circle = 200 + 150*sin(ofGetSystemTimeMillis()*freq*i);
        //        circle = 200 + 150*sin(ofGetSystemTimeMillis()*volume[40]*0.00001*i);
        col = ofMap(circle, 50, 350, 255, 60);
        r = ofMap(circle, 50, 350, 5, 2);
        ofSetColor(74, 0, col);
        ofDrawCircle(circle*cos(i), circle*sin(i)+volume[40]*400, r);
        ofPushMatrix();
        ofTranslate(circle*cos(i), circle*sin(i));
        for (int i=0; i < 360; i+= 60) {
            ofRotateDeg(i);
            ofDrawTriangle(circle*cos(i), circle*sin(i)+volume[40]*400, circle*cos(i)-r*0.5, circle*sin(i)-r*0.5*pow(3, 0.5), circle*cos(i)+r*0.5, circle*sin(i)-r*0.5*pow(3, 0.5));
        }
        ofPopMatrix();
        rot += 0.00005;
    }
}

