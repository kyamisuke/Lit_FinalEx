//
//  SceneTree.h
//  LiT_FinalEx
//
//  Created by 村上航輔 on 2019/05/16.
//

#ifndef SceneTree_h
#define SceneTree_h


#endif /* SceneTree_h */
#include "ofMain.h"
#include "baseScene.h"
#include "branch.h"

class SceneTree : public baseScene{
    
public:
    void setup();
    void update();
    void draw();
    
    vector <branch> branches;
    int count = 0;
    ofSoundPlayer sound;
    float *vol;
    
};
