#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
      
    // set background to a nice yellow!
    ofBackground(myyellow);
    
    enter_clicked = false;
    user_typing = "";
    
    phase = 1;
    x = 10;
    y = 30;
    
    // setup phase 1 and 2 listeners and GUI
    phase_one.setup();
    phase_two.setup();
    // setup phase 3 listeners
    phase_three.setup();
    
    // set question color
    ofSetColor(myblue);
    api_request_worked = false;
    api_called = false;
}



//--------------------------------------------------------------
void ofApp::update(){
    
    
    // if submitted button clicked in phase one
    if (phase == 1 && phase_one.submitted) {
        phase++;
    }
   
    
    // if the user has clicked enter
    if (enter_clicked) {
        
        user_typing = "";
        enter_clicked = false;
        
        if (phase == 1) {
            phase_one.update();
        }
        
        if (phase == 2) {
            
            // search if request has not already been made (otherwise, without this precaution, if 'enter' is pressed twice, the connection will fail)
            if (search_word != "" && httpresponse.status != kOk_Status) {
                
                // http GET request
                // copy url so there can be several requests made if one doesn't work
                std::string copy_search_url_template;
                copy_search_url_template = search_url_template;
                copy_search_url_template.replace(40, 13, url_search_word);
                httpresponse = ofLoadURL(copy_search_url_template);
                response_body = httpresponse.data;
                
            }
            
        }
    }
    
    
    
    if (phase == 2) {
        
        phase_two.update();

        // if one of the 20 results has been clicked, move to phase 3 to display that information
        if (phase_two.result_pressed) {
            phase_two.result_pressed = false;
            phase++;
        }
        
        // if user wants to search again after getting 0 hits back on their first search attempt (reset back)
        if (phase_two.search_again_pressed) {
            
            search_word = "";
            user_typing = "";
            phase_two.user_typing = "";
            phase_two.search_word = "";
            httpresponse.status = 0;
            phase_two.search_again_pressed = false;
            phase_two.result_page = 2;
            phase_two.setResultScrolling();
            phase_two.result_page = 1;
        }
        
    }
    
    if (phase == 3) {
        
        phase_three.update();
        
        // go back to phase 2 searching
        // reset variables
        if (phase_three.search_again_pressed) {
            
            phase_three.search_again_pressed = false;
            phase_two.search_again_pressed = true;
            phase_two.pressed_empty_result = false;
            phase--;
            api_called = false;
            phase_three.calories_needed = 0;
            httpresponse.status = 0;
            update();
        }
        
        // if the API request hasn't already been made and the user has clicked a valid response
        else if (!api_called && !phase_two.pressed_empty_result) {
        
            std::string copy_item_url_template;
            copy_item_url_template = item_url_template;
            copy_item_url_template.replace(41, 6, item_id);
            httpresponse = ofLoadURL(copy_item_url_template);
            response_body = httpresponse.data;
            api_called = true;
        }
        
        // if user clicked on an invalid result ("no result")
        else if (phase_two.pressed_empty_result) {
            httpresponse.status = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (phase == 1) {
        
        phase_one.draw();
        
    } else if (phase == 2) {
        
        phase_two.draw();

        // when the user has clicked enter
        if (search_word != "") {
            
            if (httpresponse.status == kOk_Status) {
                
                api_request_worked = true;
                saveSearchResults();
                
            } else {
                
                api_request_worked = false;
            }
            
            phase_two.drawSearchResults(api_request_worked);
        }
        

    } else if (phase == 3) {
        
        // API request successful
        if (httpresponse.status == kOk_Status) {
            
            saveNutritionalInfo();
            
            // if it's the first time phase 3 is called
            if (phase_three.calories_needed == 0) {
                phase_three.setupGUI();
            }
            
            phase_three.calories_needed = phase_one.calculateCaloriesNeeded(phase_one.gender, phase_one.age, phase_one.height, phase_one.weight, phase_one.exercise, phase_one.diet);
            
            phase_three.draw(phase_two.item_name, phase_two.brand_name);

            
        } else {
            
            phase_three.calories_needed = phase_one.calculateCaloriesNeeded(phase_one.gender, phase_one.age, phase_one.height, phase_one.weight, phase_one.exercise, phase_one.diet);
            
            // API request failed (only prints suggested caloric intake)
            phase_three.drawApiFailure(false);
        }
        
    }
}


int ofApp::saveSearchResults() {
    
    // ensures that lists are clear in case of multiple searches
    phase_two.itemNames.clear();
    phase_two.itemIDs.clear();
    phase_two.brandNames.clear();
    phase_two.brandIDs.clear();

    saveAsJson();
    
    // load json and reformat it in the same file
    response_json = ofLoadJson(jsonfile_path);
    response_json = ofSavePrettyJson(jsonfile_path, response_json);
    
    result.open(jsonfile_path);
    
    phase_two.total_hits = result["total_hits"].asInt();
    
    int num_results;
    
    // save first 20 (or less if there aren't 20) entries that resulted from search
    if (phase_two.total_hits >= 20) {
        num_results = 20;
    } else {
        num_results = phase_two.total_hits;
    }
    
    for (int i = 0; i < num_results; i++) {
        item_keyword = result["hits"][i]["fields"]["item_name"].asString();
        item_id = result["hits"][i]["_id"].asString();
        brand_id = result["hits"][i]["fields"]["brand_id"].asString();
        brand_keyword = result["hits"][i]["fields"]["brand_name"].asString();
        
        phase_two.itemNames.push_back(item_keyword);
        phase_two.itemIDs.push_back(item_id);
        phase_two.brandIDs.push_back(brand_id);
        phase_two.brandNames.push_back(brand_keyword);
        
    }
    return phase_two.total_hits;
}


void ofApp::saveNutritionalInfo() {
    
    // ensures the info is not null, and if it is, assigns the variable a value of -5
    string nullcheck;
    
    saveAsJson();
    
    // load json and reformat it in the same file
    response_json = ofLoadJson(jsonfile_path);
    response_json = ofSavePrettyJson(jsonfile_path, response_json);
    
    result.open(jsonfile_path);
    
    // saving all nutritional info to variables
    nullcheck = result["nf_calories"].asString();
    if (nullcheck != "null") {
        phase_three.calories = result["nf_calories"].asDouble();
    } else {
        phase_three.calories = -5;
    }
    
    nullcheck = result["nf_calories_from_fat"].asString();
    if (nullcheck != "null") {
        phase_three.calories_from_fat = result["nf_calories_from_fat"].asDouble();
    } else {
        phase_three.calories_from_fat = -5;
    }
    
    nullcheck = result["nf_cholesterol"].asString();
    if (nullcheck != "null") {
        phase_three.cholesterol = result["nf_cholesterol"].asDouble();
    } else {
        phase_three.cholesterol = -5;
    }
    
    nullcheck = result["nf_dietary_fiber"].asString();
    if (nullcheck != "null") {
        phase_three.dietary_fiber = result["nf_dietary_fiber"].asDouble();
    } else {
        phase_three.dietary_fiber = -5;
    }
    
    nullcheck = result["nf_protein"].asString();
    if (nullcheck != "null") {
        phase_three.protein = result["nf_protein"].asDouble();
    } else {
        phase_three.protein = -5;
    }
    
    nullcheck = result["nf_sodium"].asString();
    if (nullcheck != "null") {
        phase_three.sodium = result["nf_sodium"].asDouble();
    } else {
        phase_three.sodium = -5;
    }
    
    nullcheck = result["nf_sugars"].asString();
    if (nullcheck != "null") {
        phase_three.sugar = result["nf_sugars"].asDouble();
    } else {
        phase_three.sugar = -5;
    }
    
    nullcheck = result["nf_total_fat"].asString();
    if (nullcheck != "null") {
        phase_three.total_fat = result["nf_total_fat"].asDouble();
    } else {
        phase_three.total_fat = -5;
    }
    
    nullcheck = result["nf_total_carbohydrate"].asString();
    if (nullcheck != "null") {
         phase_three.total_carbohydrate = result["nf_total_carbohydrate"].asDouble();
    } else {
        phase_three.total_carbohydrate = -5;
    }
   
}


string ofApp::saveAsJson() {
    
    ofstream jsonfile;
    
    jsonfile.open(jsonfile_path);
    
    if (jsonfile.is_open()) {
        
        jsonfile << response_body;
        
        jsonfile.close();
    }
    
    return response_body.getText();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    if (phase == 2) {
        phase_two.keyPressed(key);
    }

    // if user attemps to type after already searching & clicking enter
    if (search_word != "") {
        return;
    }
    
    // if user is still typing
    if (key != OF_KEY_RETURN) {
        
        // if user did not hit backspace
        if (key != OF_KEY_BACKSPACE){
            
            user_typing += key;
            
        } else {
            
            if (user_typing.size() > 0){
                
                // erase last character
                user_typing.erase(user_typing.end() - 1);
            }
        }
    }
    // if user clicked 'enter'
    else {

        // transform to lower case for consistency & equality checking
        std::transform(user_typing.begin(), user_typing.end(), user_typing.begin(), ::tolower);
        
        if (phase == 2 && user_typing != "") {
            
            search_word = user_typing;
            url_search_word = search_word;
            
            // in case of multiple words, replace spaces to %20 for correct API url request
            for (int k = 0; k < url_search_word.length(); k++) {
                
                if (url_search_word[k] == ' ') {
                    
                    url_search_word[k] = '%';
                    url_search_word.insert(k + 1, "20");

                }
            }

        }
        
        enter_clicked = true;
        
    }
    
}





