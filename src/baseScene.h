//
//  baseScean.h
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/16.
//

#pragma once

#ifndef baseScean_h
#define baseScean_h


#endif /* baseScean_h */

#include "ofMain.h"

class baseScene {
    
public:
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    
    virtual void keyPressed(int key){};
    virtual void keyReleased(int key){};
    virtual void mouseMoved(int x, int y ){};
    virtual void mouseDragged(int x, int y, int button){};
    virtual void mousePressed(int x, int y, int button){};
    virtual void mouseReleased(int x, int y, int button){};
    virtual void mouseEntered(int x, int y){};
    virtual void mouseExited(int x, int y){};
    virtual void windowResized(int w, int h){};
    virtual void dragEvent(ofDragInfo dragInfo){};
    virtual void gotMessage(ofMessage msg){};
    
};
