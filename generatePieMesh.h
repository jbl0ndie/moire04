//
//  generatePieMesh.h
//  generatePieMeshExample
//
//  Original example by rc1 on 27/12/2014.
//  Created by jbl0ndie on 01/01/2015.
//
//

#pragma once
#include "ofMain.h"

ofMesh generatePieMesh( float radius, float segments ) {
    
    // Create our mesh.
    ofMesh mesh;
    mesh.setMode( OF_PRIMITIVE_TRIANGLE_FAN );
    
    // Add the center point
    mesh.addVertex( ofVec3f::zero() );
    // Say it is the first point
    mesh.addIndex( 0 );
    
    // Add the outer points rc1 had i< segments and it missed the last segment
    for ( float i = 0; i <= segments; ++i ) {
        
        // Use our matrix to plot the points.
        // Because I can't be bothered doing the trig :)
        ofMatrix4x4 matrix;
        // This is done backwards
        // 1. Move to the outside
        matrix.translate( 0.0f, radius, 0.0f );
        // 2. Make a segment the size of one segment
        matrix.rotate( (360 / segments) * (i / segments), 0.0, 0.0, 1.0 );
        // 3. Invert the scale so it works clockwise
        matrix.scale( 1.0, -1.0, 1.0 );
        
        // Create a point at zero and multiply it by our matrix
        ofVec3f p = ofVec3f::zero() * matrix;
        // Add the point
        mesh.addVertex( p );
        // Set the point index
        mesh.addIndex( i + 1 );
    }
    
    return mesh;
}