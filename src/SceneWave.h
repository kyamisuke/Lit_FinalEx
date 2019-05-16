//
//  SceneWave.h
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/16.
//

#pragma once

#ifndef SceneWave_h
#define SceneWave_h

#include "ofMain.h"
#include "baseScene.h"
#include "Wave.h"

#endif /* SceneWave_h */

class SceneWave : public baseScene{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    static const int wavesNum = 60;
    Wave waves[wavesNum];
    
    float* volume;
    float* fftSmoothed;
    int nBandsToGet;
    
};
