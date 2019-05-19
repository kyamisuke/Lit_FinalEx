#include "SceneWave.h"

//--------------------------------------------------------------
void SceneWave::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    
    for (int i=0; i<wavesNum; i++) waves[i] = Wave(i);
    
    fftSmoothed = new float[8192];
    for (int i=0; i<8192; i++) fftSmoothed[i] = 0;
    nBandsToGet = 70;
}

//--------------------------------------------------------------
void SceneWave::update(){
    ofSoundUpdate();
    volume = ofSoundGetSpectrum(nBandsToGet);
    
    for (int i=0; i<nBandsToGet; i++) {
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < volume[i]) fftSmoothed[i] = volume[i];
    }
}

//--------------------------------------------------------------
void SceneWave::draw(){
    ofSetColor(0, 32);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i=0; i < wavesNum; i++) {
        waves[i].display(fftSmoothed[i+10]);
    }
}

//--------------------------------------------------------------
void SceneWave::keyPressed(int key){
    if (key == 'c'){
        ofSetColor(0);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
}
