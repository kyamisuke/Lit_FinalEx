#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    sound.load("Broken Heart.mp3");
    sound.setVolume(1.0);
    sound.setLoop(true);
    sound.play();

    baseScene* sTe = new SceneText();
    baseScene* sT = new SceneTree();
    baseScene* sW = new SceneWave();
    baseScene* sF = new SceneFlow();
    baseScene* sE = new SceneEye();

    scenes.push_back(sTe);
    scenes.push_back(sT);
    scenes.push_back(sW);
    scenes.push_back(sF);
    scenes.push_back(sE);
    currentScene = 0;
    scenes[currentScene]->setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    scenes[currentScene]->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    scenes[currentScene]->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        currentScene++;
        currentScene %= 5;
        scenes[currentScene]->setup();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    printf("passmouse\n");
    scenes[currentScene]->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
