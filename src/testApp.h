#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "CHandOrbs.h"

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
    
};

#endif
