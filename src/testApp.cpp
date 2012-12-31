#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {

    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();//FromXML("openni/config/ofxopenni_config.xml");
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addUserGenerator();
    openNIDevice.setLogLevel(OF_LOG_VERBOSE);
    openNIDevice.getWidth();
 
    openNIDevice.setMaxNumUsers(2);
    openNIDevice.setUsePointCloudsAllUsers(true);

    openNIDevice.start();

    /*Setup Base User Settings */
    ofxOpenNIUser user;
    user.setUseMaskTexture(true);
    user.setUsePointCloud(true);
    user.setPointCloudDrawSize(2); // this is the size of the glPoint that will be drawn for the point cloud
    user.setPointCloudResolution(5); // this is the step size between points for the cloud
    openNIDevice.setBaseUserClass(user);
    
    
    // if you want to get fine grain control over each possible tracked user for some reason you can iterate
    // through users like I'm doing below. Please note the use of nID = 1 AND nID <= openNIDevices[0].getMaxNumUsers()
    // as what you're doing here is retrieving a user that is being stored in a std::map using it's XnUserID as the key
    // that means it's not a 0 based vector, but instead starts at 1 and goes upto, and includes maxNumUsers...
    //    for (XnUserID nID = 1; nID <= openNIDevices[0].getMaxNumUsers(); nID++){
    //        ofxOpenNIUser & user = openNIDevices[0].getUser(nID);
    //        user.setUseMaskTexture(true);
    //        user.setUsePointCloud(true);
    //        //user.setUseAutoCalibration(false); // defualts to true; set to false to force pose detection
    //        //user.setLimbDetectionConfidence(0.9f); // defaults 0.3f
    //        user.setPointCloudDrawSize(2);
    //        user.setPointCloudResolution(1);
    //    }
    
    
    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
    cam.setFarClip(5000);
}

//--------------------------------------------------------------
void testApp::update(){
    openNIDevice.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    ofSetColor(0, 255, 0);
	string msg = "Num of Users Tracked: " + ofToString(openNIDevice.getNumTrackedUsers());
	verdana.drawString(msg, 20, ofGetHeight() - 26);
    
    cam.begin();

    ofPushMatrix();
    ofColor(255,50,50);
    ofCircle(0, 0, 0, 20); //Draw Circle in center of screen for orientation...
    ofPopMatrix();    

    string pos = "not tracking user";
    
    int numUsers = openNIDevice.getNumTrackedUsers();
    if (numUsers) {
        for (int i = 0; i < numUsers; i++) {
            ofxOpenNIUser & user = openNIDevice.getTrackedUser(i);
            if (user.isTracking()) {
                drawMesh(&user);
            }
        }
    }
    cam.end();
}

void testApp::drawMesh(ofxOpenNIUser *user)
{
    ofMesh m = user->getPointCloud();
    
    vector<ofVec3f> vertices = m.getVertices();
    for ( vector<ofVec3f>::iterator vertex = vertices.begin(); vertex < vertices.end(); vertex++)
    {
        ofPushMatrix();
        ofRotateX(180);
        const ofPoint t = ofPoint(-(openNIDevice.getWidth()/2), -(openNIDevice.getHeight()/2),-1500);
        ofTranslate(t);
        ofPoint p = ofPoint(vertex->x, vertex->y, vertex->z);
        ofSetColor(255, 255, 255);
        ofCircle(p.x, p.y, p.z, 5.0f);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    switch (key) {
        case 'i':
            
            
        break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

