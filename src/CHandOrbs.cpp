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

void CHandOrbs::drawHandOrbs(ofPoint &p, float radius) {

    addPoint(p.x-(radius/2), p.y-(radius/2), p.z, radius);
    
    
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
	
    //ofSetColor(255);
    //ofCircle(p.x-(radius/2), p.y-(radius/2), -p.z, radius);
    
	ofDisablePointSprites();
	ofDisableBlendMode();
    
    ofPopMatrix();
    
    points.clear();  //delete points and let the next time through loop make new ones
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
    return abs(p1.distance(pnt));
}