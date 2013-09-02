#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "CHandOrbs.h"
#include "CJointOrbs.h"

class testApp : public ofBaseApp{

public:

	void setup();
    ~testApp();

    void setupKinectEssentials();
    void setupHandTracking();
    void setupBaseUserPreferences();
	void update();
	void draw();
    void drawMesh(ofxOpenNIUser *user);
    void exit();
    
    void handleUsersJoints();
    void getUserJointPoints(int userIndex);
    void scalePoints(vector<ofPoint> *points);
    void handleJointMovement(vector<ofPoint> *points);
    void loadSoundsForJoints();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

    ofTrueTypeFont verdana;

	ofxOpenNI openNIDevice;
    ofEasyCam cam;
    CHandOrbs *orbs;
    CJointOrbs *m_joints;
    ofSoundPlayer song;
    ofSoundPlayer sounds[15]; //sounds for joints
    vector<ofPoint> m_prev_joint_pos;

    float handCircleRadius;
    float jointCircleRadius;
    float m_distThresh;
    float m_timeThresh;
    float m_prev_time;

};

#endif
