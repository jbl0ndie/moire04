#include "ofApp.h"
#include "generatePieMesh.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    
    // Load a GL3 shader for the background
    shader.load("shaders/noise.vert", "shaders/noise.frag");
    
    // Setup the UI elements: args = name, default, min, max
    gui.setup();
    gui.add(rotationSpeed.setup( "Rotation speed", 0.2, -1, 1));
    gui.add(numberOfClones.setup( "Number of clones", 90, 2, 120));
    gui.add(diameter.setup( "Diameter", 650.0, 50.0, 1000.0));
    // TODO: Find way to specify ofColor directly, as you can only pass one colour value as the default for the colour slider. I.e. set the default colours to be non-grey.
    //TODO: Find and fix this error: [warning] ofMath: ofMap(): avoiding possible divide by zero, check inputMin and inputMax: 255 255. It comes from the following two lines. If you comment them out, it stops complaining about this error. Changing the min/max values doesn't seem to fix it though.
//    gui.add(colorOne.setup( "Background colour 1", 50, 0, 255));
//    gui.add(colorTwo.setup( "Background colour 2", 100, 0, 255));
    gui.add(enableShader.setup( "Enable shader" ));
    // Add interface element to control the x and y offset of the foreground wheel
    gui.add(faderxPosition.setup( "Wheel X-position", 10, 0, 20));
    gui.add(faderyPosition.setup( "Wheel Y-position", 10, 0, 20));
    gui.add(shaderColor1.setup( "Shader colour 1", 0.0, 0.0, 1.0));
    gui.add(shaderColor2.setup( "Shader colour 2", 0.0, 0.0, 1.0));
    gui.add(shaderColor3.setup( "Shader colour 3", 0.0, 0.0, 1.0));

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
    
    // Presumably the update function should be the place to put an updating var?
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofColor colorOne;
//    ofColor colorTwo;
    
//    colorOne.set (255, 75, 0);
//    colorTwo.set (0, 200, 200);
    
    // TODO: Fix the random colours
    // Sets the background to a circular gradient & implements random colours
    // Adds optional shader for background (doesn't work yet)
    if (enableShader == TRUE) {
        //        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        ofSetColor(colorOne); // This is where the fragment shader's globalColor is defined
        shader.begin();
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        // TODO: this is broken
        shader.setUniform1f("shaderColor1", shaderColor1);
        shader.setUniform1f("shaderColor2", shaderColor2);
        shader.setUniform1f("shaderColor3", shaderColor3);
        shader.end();
    }
    else {
        ofBackgroundGradient((ofColor(0, 200, 200)), ofColor((200, 0, 0)), OF_GRADIENT_CIRCULAR);
    }
    
    
    //draw the background wheel
    
    ofPushMatrix(); // Background wheel matrix
    ofPushStyle();
    ofTranslate(ofGetWindowWidth()/2 - faderxPosition, ofGetWindowHeight()/2 - faderyPosition);
    ofSetColor(0); // Set back wheel to black
    
    // Draw the requisite no of clones, rotating and spacing them out
    for (int i=0; i<numberOfClones/2; i++) {
        ofRotate(2 *(360 / numberOfClones), 0, 0, 1);
        pie.draw();
    }
    
    ofPopStyle();
    ofPopMatrix();
    
    
// Draw and rotate the foreground wheel matrix

    // Change the origin to the centre again but with an ofset to produce moire
    ofPushMatrix(); // Foreground wheel matrix 1
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 1);
    ofRotate(rotationAngle, 0, 0, 1);
    
    ofPushMatrix(); // Foreground wheel matrix 2
    ofTranslate(faderxPosition, faderyPosition, 1);

    // Draw the foreground wheel
    ofPushStyle();
    ofSetColor(0);  // Set black colour
    
    // Draw the requisite no of clones, rotating and spacing them out
    for (int i=0; i<numberOfClones/2; i++) {
        ofRotate(2 * (360 / numberOfClones), 0, 0, 1);
        pie.draw();
    }
    
    ofPopMatrix();// Foreground wheel matrix 2
    ofPopMatrix();// Foreground wheel matrix 1
    
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
