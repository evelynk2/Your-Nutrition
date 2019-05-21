#pragma once


#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include "ofxOsc.h"
#include "ofxGui.h"
#include "ofxJSON.h"
#include "ofxParagraph.h"
#include "phaseOne.hpp"
#include "phaseTwo.hpp"
#include "phaseThree.hpp"
#include <string>
#include <sstream>
#include <iostream>

// handles API requests & calling different phases
class ofApp : public ofBaseApp {
    
    friend class phaseOne;
    friend class phaseTwo;
    friend class phaseThree;
    
    phaseOne phase_one;
    phaseTwo phase_two;
    phaseThree phase_three;

public:

    void setup();
    void addListeners();
    void setupGUI();
    
    void update();
    void draw();
    
    int saveSearchResults();
    void saveNutritionalInfo();
    
    // saves the response_body to a json file to read from later
    string saveAsJson();
    
    void keyPressed(int key);
 
    ofColor myblue = ofColor(25, 139, 168);
    ofColor myyellow = ofColor(250, 250, 239);
    
    const int kOk_Status = 200;
    
    // true if API request worked, false otherwise
    bool api_request_worked;
    
    bool api_called;
    
    ofTrueTypeFont font;
    ofTrueTypeFont results_font;
    
    
    // which phase of the app the user is in
    // phase 1: asking user questions & retrieving answers
    // phase 2: searching for food item / brand
    // phase 3: visualizing search results
    int phase;
    
    
    // if user clicks enter
    bool enter_clicked;
    
    float x, y;
    

    
    std::string jsonfile_path = "/Users/evelynkrasnik/Desktop/CS 126/open frameworks/apps/myApps/final-project/src/responseAsJson";
    
    // keeps track of the user's answers
    std::string user_typing;
    
    // what the user types in to search
    std::string search_word;
    // the search word inputted to url (accounts for spaces)
    std::string url_search_word;
    std::string item_keyword;
    std::string brand_keyword;
    std::string item_id;
    std::string brand_id;
    

        
    // NUTRIONIX API KEY INFO:
    // Application ID = 21ef5bf5
    // Application Key = fa0e6126186a57128098040b90301bed
    
    // ITEMKEYWORD will be replaced by url_search_word (spot = 40), 13
    std::string search_url_template = "https://api.nutritionix.com/v1_1/search/URLSEARCHWORD?results=0%3A20&cal_min=0&cal_max=50000&fields=item_name%2Cbrand_name%2Citem_id%2Cbrand_id&appId=21ef5bf5&appKey=fa0e6126186a57128098040b90301bed";

    

    // ITEMID will be replaced by item_id (spot = 41), 6
    std::string item_url_template = "https://api.nutritionix.com/v1_1/item?id=ITEMID&appId=21ef5bf5&appKey=fa0e6126186a57128098040b90301bed";
    

    // BRANDID will be replaced by brand_id (spot = 39), 7
    std::string brand_url_template = "https://api.nutritionix.com/v1_1/brand/BRANDID?appId=21ef5bf5&appKey=fa0e6126186a57128098040b90301bed";

    
    // BRANDKEYWORD will be replaced by brand_keyword (spot = 52), 12
    std::string brand_search_url_template = "https://api.nutritionix.com/v1_1/brand/search?query=BRANDKEYWORD&min_score=1&appId=21ef5bf5&appKey=fa0e6126186a57128098040b90301bed";

    
    
    ofHttpResponse httpresponse;
    ofBuffer response_body;
    ofJson response_json;
    ofxJSONElement result;

};
