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
    void draw();
    void addPoint(float x, float y, float z, float radius);
    
    void drawHandOrbs(ofPoint &p, float radius);
    void drawCirclesOnHands(ofPoint &p, float radius, bool drawLines);
    void drawLinesBetweenHands(ofPoint &p1, ofPoint &p2, float radius);
    float distanceBetweenHands(ofPoint &p1, ofPoint &p2);
    
    int m_numHandsToTrack;
    
    vector <ofVec3f> points;
    vector <ofVec3f> sizes;
    ofVbo vbo;
    ofShader shader;
    ofTexture texture;
    
};

#endif /* defined(__openNiSample007__CHandOrbs__) */
