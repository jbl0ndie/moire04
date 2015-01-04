#include "ofApp.h"
#include "generatePieMesh.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLineWidth(0);
    ofEnableSmoothing();
    ofSetFrameRate(30);
    
    numberOfClones = 90;
    diameter = 650.0;
    
    // Pre-generate a pie
    pie = generatePieMesh( diameter, numberOfClones );
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //Rotation speed of the foreground wheel
    rotationSpeed += 0.25;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor colorOne;
    ofColor colorTwo;
    
    colorOne.set (255, 75, 0);
    colorTwo.set (0, 200, 200);
    
    // Sets the background to a circular gradient
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    //draw the background wheel
    
    ofPushMatrix(); // Background wheel matrix
    ofPushStyle();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofSetColor(0); // Set back wheel to black
    
    // Draw the requisite no of clones, rotating and spacing them out
    for (int i=0; i<numberOfClones/2; i++) {
        glRotatef(2 *(360 / numberOfClones), 0, 0, 1);
        pie.draw();
    }
    
    ofPopStyle();
    ofPopMatrix();
    
    
    // Rotate the foreground wheel matrix
    
    // Change the origin to the centre so rotation occurs around the middle
    
    glPushMatrix(); // Foreground wheel matrix
    glTranslatef(ofGetWindowWidth()/2 + 10, ofGetWindowHeight()/2 + 10, 0);
    glRotatef(rotationSpeed, 0, 0, 1);
    
    // Draw the foreground wheel
    ofPushStyle();
    ofSetColor(0);  // Set black colour
    
    // Draw the requisite no of clones, rotating and spacing them out
    for (int i=0; i<numberOfClones/2; i++) {
        glRotatef(2 * (360 / numberOfClones), 0, 0, 1);
        pie.draw();
    }
    
    ofPopStyle();
    ofPopMatrix();
    
    
    //Display a black circle on top to mask the centre of the screen where
    //we get some visual artifacts
    //    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 25);
    
    //Print fps at top left of window
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
