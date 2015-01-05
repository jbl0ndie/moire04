#include "ofApp.h"
#include "generatePieMesh.h"

//TODO: Find and fix this error: [warning] ofMath: ofMap(): avoiding possible divide by zero, check inputMin and inputMax: 255 255

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    
    // Setup the UI elements: args = name, default, min, max
    gui.setup();
    gui.add(rotationSpeed.setup( "Rotation speed", 0.2, -1, 1));
    gui.add(numberOfClones.setup( "Number of clones", 90, 2, 120));
    gui.add(diameter.setup( "Diameter", 650.0, 50.0, 1000.0));
    // TODO: Find way to specify ofColor directly, as you can only pass one colour value as the default for the colour slider. I.e. set the default colours to be non-grey.
    gui.add(colorOne.setup( "Background colour 1", 50, 0, 255));
    gui.add(colorTwo.setup( "Background colour 2", 100, 0, 255));
    gui.add(randomColour.setup( "Random colour" ));

    // TODO: Add interface element to control the x and y offset of the foreground wheel
    //TODO: Add save function for good parameter mixes, so they can be reused as presets
    
    // TODO: Find a way to update the diameter and numberOfClones without moving it out of the setup function. As it is now, you can't change the diameter or numberOfClones because they're called in the setup function for efficiency of not having to call the function on each draw
    // Pre-generate a pie
    //This is where the pie generation originally took place before it was moved to update
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //Rotation speed of the foreground wheel
    pie = generatePieMesh( diameter, numberOfClones );
    rotationAngle += rotationSpeed;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofColor colorOne;
//    ofColor colorTwo;
    
//    colorOne.set (255, 75, 0);
//    colorTwo.set (0, 200, 200);
    
    // TODO: Fix the random colours
    // Sets the background to a circular gradient & implements random colours
    if (randomColour == true) {
        ofBackgroundGradient((ofColor(0, 200, 200)), ofColor((200, 0, 0)), OF_GRADIENT_CIRCULAR);
    }
    else {
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    }
    
    
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
    glRotatef(rotationAngle, 0, 0, 1);
    
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

    
    //Print fps at top right of window
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", ofGetWindowWidth()-100, 15);
    
    // Draw the GUI
    gui.draw();
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
