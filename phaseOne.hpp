//
//  phaseOne.hpp
//  final-project
//
//  Created by Evelyn Krasnik on 4/22/19.
//

#ifndef phaseOne_hpp
#define phaseOne_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include "ofxOsc.h"
#include "ofxGui.h"
#include "ofxJSON.h"
#include <string>
#include <sstream>
#include <iostream>

// phase one: gathering individual information about user
class phaseOne : public ofBaseApp {
    
    friend class ofApp;
    
public:
    void setup();
    void addListeners();
    void setupGUI();
    
    void update();
    void draw();
        
    
    // sliders used
    void ageChanged(int &age);
    void weightChanged(float &weight);
    void heightChanged(float &height);
    
    // gender buttons pressed
    void femaleButtonPressed(bool &p);
    void maleButtonPressed(bool &p);
    
    // exercise buttons pressed
    void rarelyExerciseButtonPressed(bool &p);
    void threeExerciseButtonPressed(bool &p);
    void fourExerciseButtonPressed(bool &p);
    void fiveExerciseButtonPressed(bool &p);
    void dailyExerciseButtonPressed(bool &p);
    
    // goal of diet buttons pressed
    void loseQuicklyButtonPressed(bool &p);
    void loseSteadilyButtonPressed(bool &p);
    void gainQuicklyButtonPressed(bool &p);
    void gainSteadilyButtonPressed(bool &p);
    void maintainWeightButtonPressed(bool &p);
    
    // submit button pressed
    void submitButtonPressed();
    
    // calculates the calories a person needs based on individualized information from gui One (pass in info for testing purposes)
    float calculateCaloriesNeeded(string gender, int age, float height, float weight, string exercise, string diet);
    // calculate with default or saved info
    float calculateCaloriesNeeded();
    
    ofColor myblue = ofColor(25, 139, 168);
    ofColor myyellow = ofColor(250, 250, 239);
        
    // phase one GUI
    ofxPanel gui;
    
    // age
    ofxIntSlider age_slider;
    // height
    ofxFloatSlider height_slider;
    // weight
    ofxFloatSlider weight_slider;
    // gender
    ofxToggle female_button;
    ofxToggle male_button;
    // exercise
    ofxToggle rarely_exercise_button;
    ofxToggle three_exercise_button;
    ofxToggle four_exercise_button;
    ofxToggle five_exercise_button;
    ofxToggle daily_exercise_button;
    vector<ofxToggle> exercise_buttons {rarely_exercise_button, three_exercise_button, four_exercise_button, five_exercise_button, daily_exercise_button};
    
    // goal of diet
    ofxToggle lose_quickly_button;
    ofxToggle lose_steadily_button;
    ofxToggle gain_quickly_button;
    ofxToggle gain_steadily_button;
    ofxToggle maintain_weight_button;
    vector<ofxToggle> diet_buttons {lose_quickly_button, lose_steadily_button, gain_quickly_button, gain_steadily_button, maintain_weight_button};
    
    // submit
    ofxButton submit_button;
    
    
    
    // stores initial questions
    vector<std::string> question_list {
        // slider
        "\nUse the slider to show your age: ",
        
        // slider
        "Use the slider to show your height (in inches): ",
        
        // button
        "Choose 'Male' or 'Female'",
        
        // slider
        "Use the slider to show your weight (in lbs):",
        
        // button
        "How often do you exercise? ",
        
        //button
        "What do you want your diet to accomplish? \n",
        
        "When finished, click 'Submit Answers' below."};
    
    
    // answers to the questions
    int age;
    float height;
    string gender;
    float weight;
    string exercise;
    string diet;
    // if answers are submitted
    bool submitted;
    
    float calories_needed;
    
    ofTrueTypeFont font;

    // keeps track of which question/answer user is on
    int question_count;
    
    
    float x, y;

};





#endif /* phaseOne_hpp */
