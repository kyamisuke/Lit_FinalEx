//
//  SceneText.cpp
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/18.
//

#include "SceneText.h"

void SceneText::reset() {
    int count = 0;
    float w = font.stringWidth(str[current]), h = font.stringHeight(str[current]);
    float px = ofGetHeight() / 2 - h / 2, py = ofGetHeight() / 2 +  h / 2 + 50;
    
    while (1) {
        float randomX = ofRandomWidth();
        float randomY = ofRandom(px, py);
        if (pix.getColor(randomX, randomY).a != 0) {
            gx[count] = randomX;
            gy[count] = randomY;
            count++;
        }
        if (count == n) {
            break;
        }
    }
    
    if (str[current].length() < 7) {
        for (int i=0; i<300; i++) {
            if (i<150) {
                gx[i] = ofRandom(-500, -50);
                gy[i] = ofRandom(px-100, py+100);
            } else {
                gx[i] = ofRandom(ofGetWidth()+50, ofGetWidth()+500);
                gy[i] = ofRandom(px-100, py+100);
            }
        }
    }
    
}

//--------------------------------------------------------------
void SceneText::setup(){
    ofBackground(0, 32);
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofSetWindowTitle(ofToString((float)ofGetFrameRate()));
    
    font.load("VeraSe.ttf",100);
    str.push_back("Hello");
    str.push_back("My name");
    str.push_back("is");
    str.push_back("DJ kyami");
    str.push_back("I create song");
    str.push_back("-Broken Heart-");
    //str.push_back("💔");
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    //reset();
    
    for (int i=0; i<n; i++) {
        m[i] = ofRandom(-1, 1)*16;
        x[i] = ofRandomWidth();
        y[i] = ofRandomHeight();
        gx[i] = ofRandomWidth();;
        gy[i] = ofRandomHeight();
    }
    
    fftSmoothed = new float[8192];
    for (int i=0; i<8192; i++) fftSmoothed[i] = 0;
    nBandsToGet = 60;
}

//--------------------------------------------------------------

void SceneText::update() {
    ofSoundUpdate();
    volume = ofSoundGetSpectrum(nBandsToGet);
    
    for (int i=0; i<nBandsToGet; i++) {
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < volume[i]) fftSmoothed[i] = volume[i];
    }
}

//--------------------------------------------------------------

void SceneText::draw(){
    ofSetColor(0, 32);
    ofDrawRectangle(0, 0, width, height);
    
    fbo.begin();
    ofClear(255, 255, 255, 0);
    ofSetColor(0);
    float w = font.stringWidth(str[current]), h = font.stringHeight(str[current]);
    float px = ofGetWidth() / 2 - w / 2, py = ofGetHeight() / 2 +  h / 2;
    font.drawString(str[current], px, py);
    fbo.end();
    fbo.readToPixels(pix);
    
    for (int i=0; i<n; i++) {
        float dx = gx[i] - x[i];
        float dy = gy[i] - y[i];
        
        dx *= 0.03;
        dy *= 0.03;
        
        vx[i] = dx;
        vy[i] = dy;
        
        x[i] += vx[i];
        y[i] += vy[i];
        
        ofSetColor(102,153,255);
        ofDrawCircle(x[i], y[i], 2+fftSmoothed[5]*50);
    }
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void SceneText::mousePressed(int x, int y, int button){
    reset();
    current++;
    current %= str.size();
}
