//
//  branch.cpp
//  trees_growing
//
//  Created by 村上航輔 on 2019/05/13.
//

#include "branch.h"

branch::branch(float sx, float sy, float ex, float ey, float sl, float sd) {
    startx = sx;
    starty = sy;
    endx = ex;
    endy = ey;
    length = sl;
    degree = sd;
    nextx = startx;
    nexty = starty;
    prevx = startx;
    prevy = starty;
    next_flag = true;
    draw_flag = true;
    s_color = 255;
    s_weight = 0.;
//    printf("constructer: %f %f\n", abs(nextx - endx), abs(nexty - endy));
}

void branch::update( vector <branch> &branches, int &count) {
//    printf("update: %f %f\n", abs(nextx - endx), abs(nexty - endy));

    nextx += (endx - nextx)*0.4;
    nexty += (endy - nexty)*0.4;
    s_color = 255 - count / 10;
    s_weight = 3./(count / 100+1);
    
    if (abs(nextx - endx) < 1. && abs(nexty - endy) < 1. && next_flag) {
        //printf("pass update:if\n");
        next_flag = false;
        draw_flag = false;
        nextx = endx;
        nexty = endy;
        int num = int(ofRandom(2, 4));
        for (int i=0; i<num; i++) {
            float sx = endx;
            float sy = endy;
            float sl = ofRandom(ofRandom(10.0, 20.0), length*0.99);
            float sd = ofRandom(-24., 24.);
            float ex = sx + sl * cos((sd+degree+offset)*DEG_TO_RAD);
            float ey = sy + sl * sin((sd+degree+offset)*DEG_TO_RAD);
            branch newbranch = branch(sx, sy, ex, ey, sl, sd + degree);
            branches.push_back(newbranch);
        }
        count++;
    }
    if (branches.size() > 6000) {
        count = 0;
        s_color = 0;
        s_weight = 0;
        float sx = ofRandom(ofGetWidth());
        float sl = ofRandom(0, 250);
        branches.clear();
        branch newbranch = branch(sx, ofGetHeight(), sx, ofGetHeight() - sl, sl, 0.0);
        branches.push_back(newbranch);
    }
}

void branch::render() {
    if (draw_flag) {
        ofSetColor(s_color);
        ofSetLineWidth(s_weight);
        ofDrawLine(prevx, prevy, nextx, nexty);
    }
    prevx = nextx;
    prevy = nexty;
}
