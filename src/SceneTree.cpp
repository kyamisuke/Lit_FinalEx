#include "SceneTree.h"

//--------------------------------------------------------------
void SceneTree::setup(){
    ofSetBackgroundAuto(false);
    ofSetFrameRate(30);
    branch newbranch = branch(ofGetWidth()/2, ofGetHeight(), ofGetWidth()/2, ofGetHeight()-80.0, 80.0, 0.0);
    branches.push_back(newbranch);
}

//--------------------------------------------------------------
void SceneTree::update(){
//    vol = ofSoundGetSpectrum(1);
}

//--------------------------------------------------------------
void SceneTree::draw(){
//    printf("draw: %d\n", (int)branches.size());
//
//    printf("vol: %f", vol[0]);
    for (int i=0; i < branches.size(); i++) {
        branches[i].render();
        branches[i].update(branches, count);
    }
}

//--------------------------------------------------------------
