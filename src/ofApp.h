#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
//    int numberOfClones;
//    float rotationSpeed;
//    float diameter;
    float rotationAngle;
    ofShader shader;
        
    ofMesh pie;
    ofxPanel gui;
    ofxFloatSlider rotationSpeed, numberOfClones, diameter;
    ofxColorSlider colorOne, colorTwo;
    ofxToggle enableShader;
    ofxFloatSlider faderxPosition, faderyPosition;
    ofxFloatSlider shaderColor1;
    ofxFloatSlider shaderColor2;
    ofxFloatSlider shaderColor3;
};
