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
    
    CHandOrbs();
    ~CHandOrbs();
    
    void drawHandOrbs(ofPoint &p, float radius);
    void drawCirclesOnHands(ofPoint &p, float radius, bool drawLines);
    void drawLinesBetweenHands(ofPoint &p1, ofPoint &p2, float radius);
    float distanceBetweenHands(ofPoint &p1, ofPoint &p2);
    
    float m_handCircleRadius;
    
    ofImage orb;
    
};

#endif /* defined(__openNiSample007__CHandOrbs__) */
