//
//  branch.h
//  trees_growing
//
//  Created by 村上航輔 on 2019/05/13.
//

#pragma once

#include "ofMain.h"

class branch : public ofBaseApp{
    
public:
    branch(float sx, float sy, float ex, float ey, float sl, float sd);
    void update( vector <branch> &branches, int &count);
    void render();
    
    float startx;
    float starty;
    float endx;
    float endy;
    float length;
    float degree;
    float nextx;
    float nexty;
    float prevx;
    float prevy;
    bool next_flag;
    bool draw_flag;
    
    float offset = -90.0;
    float s_color;
    float s_weight;
};
