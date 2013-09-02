//
//  CJointOrbs.h
//  openNiSample007
//
//  Created by Samuel T Ruberti on 9/2/13.
//
//

#ifndef __openNiSample007__CJointOrbs__
#define __openNiSample007__CJointOrbs__

#include "ofMain.h"

class CJointOrbs : public ofBaseApp{

public:

    CJointOrbs(int numJointsToTrack);
    ~CJointOrbs();

    void update();
    void preDraw();
    void draw();
    void addPoint(float x, float y, float z, float radius);

    void drawJointOrbs(vector<ofPoint> &p, float radius);

    int m_numJointsToTrack;

    vector <ofVec3f> points;
    vector <ofVec3f> sizes;

    ofVbo vbo;
    ofShader shader;
    ofTexture texture;
    ofTrueTypeFont font;

private:

    void  drawCirclesOnJoints(vector<ofPoint> &p, float radius, bool drawLines);
    void  drawLinesBetweenJoints(vector<ofPoint> &p, float radius);
};

#endif /* defined(__openNiSample007__CJointOrbs__) */
