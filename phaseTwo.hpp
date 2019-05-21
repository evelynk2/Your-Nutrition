//
//  phaseTwo.hpp
//  final-project
//
//  Created by Evelyn Krasnik on 4/22/19.
//

#ifndef phaseTwo_hpp
#define phaseTwo_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include "ofxOsc.h"
#include "ofxGui.h"
#include "ofxJSON.h"
#include "ofxParagraph.h"
#include <string>
#include <sstream>
#include <iostream>


// phase two: displaying results of search of an item
class phaseTwo : public ofBaseApp {
    
    friend class ofApp;
    
public:
    void setup();
    void addListeners();
    void setupGUI();
    
    void update();
    void draw();
    string drawSearchResults(bool api_request_worked);
    
    // returns search word for testing purposes
    string getSearchWord();
    
    // if the user typed something which resulted in 0 total hits, allow them to try again or ask for them to exit
    string totalHitsZero();
    
    // controls the buttons that allow the user to see previous results or next results
    void setResultScrolling();
    
    // confine the info about each item to its respective box
    void setTextBoundaries(vector<string> result_strings);
    
    // saves the response_body to a json file to read from later
    void saveAsJson();
    
    
    // listeners for result buttons
    void resultOnePressed();
    void resultTwoPressed();
    void resultThreePressed();
    void resultFourPressed();
    void resultFivePressed();
    
    // listeners for scrolling through results
    void nextResultsPressed();
    void lastResultsPressed();
    
    void searchAgainPressed();
    
    void keyPressed(int key);

    
    ofColor myblue = ofColor(25, 139, 168);
    ofColor myyellow = ofColor(250, 250, 239);
    
    const int kOk_Status = 200;
    // maximum number of entries returned when search for an item
    const int kMaxNumHits = 20;
    const int kNumResults = 5;
    const int kNumPages = 4;
    
    ofTrueTypeFont font;
    ofTrueTypeFont results_font;
        
    
    // keeps track of the user's typing
    std::string user_typing;
    
    // what the user types in to search
    std::string search_word;
    
    // phase two GUI
    ofxPanel guiTwo;
    
    // displayed when total_hits = 0 & prompts user to click search again or exit
    ofxPanel tryagain;
    
    float x, y;

    // if user clicks a result marked as 'no result'
    bool pressed_empty_result;
    
    // keeps track of which page the results are on (4 pages total if there are 20 results (max))
    int result_page;
    
 
    
    // buttons that will be next to the 5 results displayed after search
    ofxButton result_one_button;
    ofxButton result_two_button;
    ofxButton result_three_button;
    ofxButton result_four_button;
    ofxButton result_five_button;
    vector<ofxButton> result_buttons {result_one_button, result_two_button, result_three_button, result_four_button, result_five_button};
    // shows 5 more results (or previous 5 results)
    ofxButton next_results_button;
    ofxButton last_results_button;
    
    // displayed when total_hits = 0 & if user clicks, allows them to search again
    ofxButton search_again_button;
    
    bool result_pressed;
    bool search_again_pressed;
    
    // json variables
    int total_hits;
    
    
    // keeps track of all entries'
    vector<string> itemNames;
    vector<string> itemIDs;
    vector<string> brandIDs;
    vector<string> brandNames;
    
    std::string brand_name;
    std::string item_name;
    std::string item_id;
    std::string brand_id;
    
    ofxVectorGraphics output;
};

#endif /* phaseTwo_hpp */
