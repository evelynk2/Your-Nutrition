#define CATCH_CONFIG_RUNNER

#include <stdio.h>
#include "catch.hpp"
#include "ofApp.h"


//========================================================================
int main() {

    ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
    // global setup...
    int result = Catch::Session().run();
    
    // global clean-up...
    return result;
}
