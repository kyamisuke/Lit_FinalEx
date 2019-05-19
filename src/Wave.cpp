//
//  Wave.cpp
//  Elusive_Pearls
//
//  Created by 村上航輔 on 2019/05/14.
//

#include "Wave.h"

Wave::Wave() {
    
}

Wave::Wave(int i) {
    
    index = i;
    sx       = ofGetWidth()/2;
    sy       = ofGetHeight();
    R       = 0;
    Rs      = ofRandom(0.5, 3);
    //r       = 5;
    rn      = 0.0;
    rns     = ofRandom(0.1, 0.5);
    tn      = 0.0;
    tns     = ofRandom(0.001, 0.005);
    tr      = ofRandom(0, 360);
    c       = i % 4;
    Rmax    = ofRandom(100, ofGetWidth());
    
    int alpha = 50;
    
    colors[0].set(100);
    colors[1].set(34,116,204);
    colors[2].set(79,79,243);
    colors[3].set(51, 0, 102);
}

void Wave::display(float vol) {
    float t = ofMap(ofNoise(tn + index), 0, 1, 0, 360);
    tn += tns;
    //r = 5 * ofNoise(rn + index);
    rn += rns;
    
    x = R*sin(t*DEG_TO_RAD) + sx;
    y = R*cos(t*DEG_TO_RAD) + sy;
    ofSetColor(colors[c]);
    ofDrawCircle(x, y, vol*50);
    R += Rs;
    
    if (R > Rmax) {
        R = 0;
        Rmax = ofRandom(100, ofGetWidth());
    }
}
