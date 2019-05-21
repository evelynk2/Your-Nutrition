//
//  phaseThree.hpp
//  final-project
//
//  Created by Evelyn Krasnik on 4/22/19.
//

#ifndef phaseThree_hpp
#define phaseThree_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include "ofxOsc.h"
#include "ofxGui.h"
#include "ofxJSON.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>      // std::setprecision


// phase three: displaying results of extended search (one item) proportionate to the individual users' information
class phaseThree : public ofBaseApp {
    
    friend class ofApp;
    
public:
    
    void setup();
    void update();
    
    
    void addListeners();
    void setupGUI();
    void setupSearchAgain();
    
    // display results of item calories proportionate to individual calories needed in a day (API request worked)
    void draw(string item_name, string brand_name);
    string drawApiFailure(bool testing);
    
    // listeners for gui three panel
    void caloriesPressed(bool &p);
    void caloriesFromFatPressed(bool &p);
    void cholesterolPressed(bool &p);
    void dietaryFiberPressed(bool &p);
    void proteinPressed(bool &p);
    void sodiumPressed(bool &p);
    void sugarPressed(bool &p);
    void totalFatPressed(bool &p);
    void totalCarbohydratePressed(bool &p);
    
    void searchAgainPressed();
    
    // testing purposes
    vector<string> getInfoDisplayed();
    
    
    ofColor myblue = ofColor(25, 139, 168);
    ofColor myyellow = ofColor(250, 250, 239);

    ofTrueTypeFont font;

    float x, y;
    
    // phase three GUI
    ofxPanel guiThree;
    
    // displayed at the very end to allow user to search again
    ofxPanel searchagain;
    
    // control gui three to visualize nutrition results
    ofxToggle calories_button;
    ofxToggle calories_from_fat_button;
    ofxToggle cholesterol_button;
    ofxToggle dietary_fiber_button;
    ofxToggle protein_button;
    ofxToggle sodium_button;
    ofxToggle sugar_button;
    ofxToggle total_fat_button;
    ofxToggle total_carbohydrate_button;
    
    ofxButton search_again_button;
    
    
    bool search_again_pressed;
    
    // information about item
    float calories;
    double calories_from_fat;
    double cholesterol;
    double dietary_fiber;
    double protein;
    double sodium;
    double sugar;
    double total_fat;
    double total_carbohydrate;
    
    float calories_needed;
    
    vector<string> info_displayed;
    
    ofxVectorGraphics output;
    ofBoxPrimitive boxinfo;
};
#endif /* phaseThree_hpp */
