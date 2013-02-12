//
//  CHandOrbs.cpp
//  openNiSample007
//
//  Created by Samuel T Ruberti on 2/10/13.
//
//

#include "CHandOrbs.h"

CHandOrbs::CHandOrbs(int numHandsToTrack) {
    
    m_numHandsToTrack = numHandsToTrack;
    
    // load the texure
	ofDisableArbTex();
    
	ofLoadImage(texture, "sprites/orb.png");
    for(int i = 0; i < m_numHandsToTrack; i++) {
        sizes.push_back(ofVec3f(100.0f));
    }
    
    // upload the data to the vbo
	vbo.setVertexData(&points[0], m_numHandsToTrack, GL_STATIC_DRAW);
	vbo.setNormalData(&sizes[0], m_numHandsToTrack, GL_STATIC_DRAW);
    
    // load the shader
	if(shader.load("shaders/orbShader")) {
		printf("Shader is loaded\n");
	} else {
        printf("shader NOT loaded\n");
    }
}

CHandOrbs::~CHandOrbs() {
    
}

void CHandOrbs::update() {
    
}

void CHandOrbs::draw() {

}

void CHandOrbs::addPoint(float x, float y, float z, float radius) {
    ofVec3f p(x, y, z);
	points.push_back(p);
	
	// we are passing the size in as a normal x position
	sizes.push_back(ofVec3f(radius));
    
    //reset Vertex and Normal Data for hands
    int total = (int)points.size();
    vbo.setVertexData(&points[0], total, GL_STATIC_DRAW);
    vbo.setNormalData(&sizes[0], total, GL_STATIC_DRAW);
}

void CHandOrbs::drawHandOrbs(vector<ofPoint> &p, float radius) {

    if (p.size() != 2) { return; } //make sure two hands were passed in
    
    for( vector<ofPoint>::iterator eachHand = p.begin(); eachHand != p.end(); eachHand++)
    {
        addPoint(eachHand->x, eachHand->y, eachHand->z, radius);
        
        ofPushMatrix();
        
        glDepthMask(GL_FALSE);
        ofSetColor(90, 100, 255);
        
        // Make orbs GLOW!!!
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofEnablePointSprites();
        
        // bind the shader
        shader.begin();
        
        // bind the texture so that when all the points
        // are drawn they are replace with our dot image
        texture.bind();
        
        vbo.draw(GL_POINTS, 0, (int)points.size());
        texture.unbind();
        
        shader.end();
        
        ofDisablePointSprites();
        ofDisableBlendMode();
        
        ofPopMatrix();
        
        points.clear();  //delete points and let the next time through loop make new ones
        sizes.clear();
    }
    
    drawCirclesOnHands(p, radius, true);
    drawLinesBetweenHands(p, radius);
}

void CHandOrbs::drawCirclesOnHands(vector<ofPoint> &p, float radius, bool drawLines) {
    
    if(drawLines) { drawLinesBetweenHands(p,radius); } //draw connecting lines bewtween hands
    
    ofPushMatrix();
    ofNoFill();
    ofSetColor(255);
    ofSetLineWidth(2.f);
    
    for( vector<ofPoint>::iterator eachHand = p.begin(); eachHand != p.end(); eachHand++)
    {
        ofCircle(eachHand->x, eachHand->y, eachHand->z, radius);
    }
    
    ofPopMatrix();
}

void CHandOrbs::drawLinesBetweenHands(vector<ofPoint> &p, float radius) {
    
    if (p.size() == 2) {  //Make sure there are only two hands
        ofLine(p[0].x, p[0].y, p[0].z, p[1].x, p[1].y, p[1].z);
        ofDrawBitmapString(ofToString(distanceBetweenHands(p)), 50, 50, 0);
    }
}

float CHandOrbs::distanceBetweenHands(vector<ofPoint> &p) {
    //return sqrt(  powerof2((p2.x - p1.x))  +  powerof2((p2.y - p1.y))  +  powerof2((p2.z - p1.z)) );
    const ofVec3f pnt = ofVec3f(p[1].x,p[1].y,p[1].z);
    return abs(p[0].distance(pnt));
}