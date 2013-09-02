//
//  CHandOrbs.h
//  openNiSample007
//
//  Created by Samuel T Ruberti on 2/10/13.
//
//

#ifndef __openNiSample007__CHandOrbs__
#define __openNiSample007__CHandOrbs__

#include "ofMain.h"

class CHandOrbs : public ofBaseApp{

public:

    CHandOrbs(int numHandsToTrack);
    ~CHandOrbs();

    void update();
    void preDraw();
    void draw();
    void addPoint(float x, float y, float z, float radius);
    void addDistanceToStringCollection(string s);

    void drawHandOrbs(vector<ofPoint> &p, float radius);
    void drawHandDistancesToScreen(vector<string> &dists);
    float distanceBetweenHands(vector<ofPoint> &p);

    int m_numHandsToTrack;

    vector <ofVec3f> points;
    vector <ofVec3f> sizes;
    vector <string> dists;

    ofVbo vbo;
    ofShader shader;
    ofTexture texture;
    ofTrueTypeFont font;

private:

    void  drawCirclesOnHands(vector<ofPoint> &p, float radius, bool drawLines);
    void  drawLinesBetweenHands(vector<ofPoint> &p, float radius);


};

#endif /* defined(__openNiSample007__CHandOrbs__) */
