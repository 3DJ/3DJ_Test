//
//  CHandOrbs.cpp
//  openNiSample007
//
//  Created by Samuel T Ruberti on 2/10/13.
//
//

#include "CHandOrbs.h"

CHandOrbs::CHandOrbs() {
    m_handCircleRadius = 0.0f;
    orb.loadImage("sprites/orb.png");
}

CHandOrbs::~CHandOrbs() {
    
}

void CHandOrbs::drawHandOrbs(ofPoint &p, float radius) {
    
    ofPushMatrix();
    
    //ofFill();
    //ofSetColor(255,0,0);
    //ofCircle(p.x, p.y, p.z, 50.0f);
    
    orb.draw(p.x-(radius/2), p.y-(radius/2), p.z, radius, radius);
    
    ofPopMatrix();
}

void CHandOrbs::drawCirclesOnHands(ofPoint &p, float radius, bool drawLines) {
    
    ofPushMatrix();
    
    if(drawLines) { drawLinesBetweenHands(p,p,radius); }
    
    ofNoFill();
    ofSetColor(255);
    ofSetLineWidth(2.f);
    ofCircle(p.x, p.y, p.z, radius);
    
    ofPopMatrix();
}

void CHandOrbs::drawLinesBetweenHands(ofPoint &p1, ofPoint &p2, float radius) {
    ofLine(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

    distanceBetweenHands(p1, p2);
}

float CHandOrbs::distanceBetweenHands(ofPoint &p1, ofPoint &p2) {
    //return sqrt(  powerof2((p2.x - p1.x))  +  powerof2((p2.y - p1.y))  +  powerof2((p2.z - p1.z)) );
    const ofVec3f pnt = ofVec3f(p2.x,p2.y,p2.z);
    return p1.distance(pnt);
}