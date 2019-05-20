//
//  SceneLine.cpp
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/20.
//

#include "SceneLine.h"

float SceneLine::x(float t) {
    return sin(t/10)*150 + cos(t/v1)*150;
}
float SceneLine::y(float t) {
    return cos(t/10)*150 + sin(t/v1)*150;
}
float SceneLine::x2(float t) {
    return sin(t/10)*10 + cos(t/v1)*150;
}
float SceneLine::y2(float t) {
    return cos(t/10)*10 + sin(t/v1)*150;
}

//--------------------------------------------------------------
void SceneLine::setup(){
    ofBackground(20);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    v1 = ofRandom(0.4)+0.2;
    
    fftSmoothed = new float[8192];
    for (int i=0; i<8192; i++) fftSmoothed[i] = 0;
    nBandsToGet = 60;
    
    line.setMode(OF_PRIMITIVE_LINES);
    circle.setMode(OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void SceneLine::update(){
    rot += 0.1;
    line.clear();
    circle.clear();
    ofSoundUpdate();
    volume = ofSoundGetSpectrum(nBandsToGet);
    
    for (int i=0; i<nBandsToGet; i++) {
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < volume[i]) fftSmoothed[i] = volume[i];
    }
}

//--------------------------------------------------------------
void SceneLine::draw(){
    biasx=1;
    biasy=1;
    
    // set circle radius
    float r = 300 + fftSmoothed[40]*PI*1000;
    alpha1 = ofMap(sin(fftSmoothed[40]*PI), 0, 1.0, 0, 255);
//    alpha2 = ofMap(fftSmoothed[30]*PI, 0, 0.05, 255, 0);
//    c1.a = alpha2;
//    c2.a = alpha2;
    c3.a = alpha1;
    
    // invert color
    if (fftSmoothed[40] - preVol > 0.03) {
        v1 = ofRandom(0.4) + 0.2;
        inv = true;
        c1.invert();
        c2.invert();
        c3.invert();
//        c1.a = 255;
//        c2.a = 255;
        //c3.a = 255;
        bg.invert();
    }
    if (fftSmoothed[40] - preVol > 0.01) {
        biasx = ofRandom(-1, 1);
        biasy = ofRandom(-1, 1);
    }

    // draw bg
    ofSetColor(bg);
    ofDrawRectangle(0, 0, width, height);
    
    // update angle
    angle += 0.0001;
    
    ofTranslate(width/2+fftSmoothed[40]*1000*biasx, height/2-fftSmoothed[40]*1000*biasy);
    
    // rotate line
    ofRotateDeg(sin(angle));
    
    // draw circle mesh
    for (int j=0; j<24; j++) {
        for (int i=0; i<6; i++) {
            circle.addVertex(ofVec3f(r*cos((float((i+j)*15)-rot)*DEG_TO_RAD),r*sin((float((i+j)*15)-rot)*DEG_TO_RAD), 0));
            circle.addColor(c3);
            circle.addVertex(ofVec3f(r*cos((float(180-(i-j)*15)-rot)*DEG_TO_RAD),r*sin((float(180-(i-j)*15)-rot)*DEG_TO_RAD), 0));
            circle.addColor(c3);
        }
    }
    
    // draw line mesh
    for(int i=1; i < NUM_LINES; i++){
        ofSetColor(c1);
        ofDrawCircle(x(t+i), y(t+i), 2);
        line.addVertex(ofVec3f(x(t+i), y(t+i), 0));
        line.addColor(c1);
        
        ofSetColor(c2);
        ofDrawCircle(x2(t+i), y2(t+i), 2);
        line.addVertex(ofVec3f(x2(t+i), y2(t+i), 0));
        line.addColor(c2);
        
        //        ofSetLineWidth(1.2);
        //
        //        ofDrawLine(x(t+i),y(t+i),x2(t+i),y2(t+i));
    }
    ofSetLineWidth(1.2);
    circle.draw();
    line.draw();
    
    t += 0.005;
    
    if(increment) v1 += fator;
    
    // re-invert color
    if (inv) {
        c1.invert();
        c2.invert();
        c3.invert();
        bg.invert();
        inv = false;
        ofColor tmp = c1;
        c1 = c2;
        c2 = tmp;
    }
    
    preVol = fftSmoothed[40];
}

//--------------------------------------------------------------
void SceneLine::keyPressed(int key){
    if(key == ' '){
        v1 = ofRandom(0.4)+0.2;
    }
    
    if (key == OF_KEY_LEFT) {
        increment = true;
        fator = -0.000001;
    } else if (key == OF_KEY_RIGHT) {
        increment = true;
        fator = 0.000001;
    }
    
    if (key == OF_KEY_UP) {
        
        NUM_LINES+=1;
    } else if (key == OF_KEY_DOWN) {
        NUM_LINES-=1;
    }
}

//--------------------------------------------------------------
void SceneLine::keyReleased(int key){
    increment = false;
}

//--------------------------------------------------------------
void SceneLine::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void SceneLine::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void SceneLine::mousePressed(int x, int y, int button){
    v1 = ofRandom(0.4) + 0.2;
    inv = true;
}

//--------------------------------------------------------------
void SceneLine::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void SceneLine::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void SceneLine::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void SceneLine::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void SceneLine::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void SceneLine::dragEvent(ofDragInfo dragInfo){
    
}
