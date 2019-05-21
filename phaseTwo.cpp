//
//  phaseTwo.cpp
//  final-project
//
//  Created by Evelyn Krasnik on 4/22/19.
//

#include "phaseTwo.hpp"


void phaseTwo::setup() {
    
    x = 10;
    y = 30;
    
    // change font and size
    font.load("futura", 17);
    results_font.load("arial", 12);
    

    result_page = 1;
    user_typing = "";
    search_again_pressed = false;
    pressed_empty_result = false;

    // set up buttons and sliders for phase two
    guiTwo.setup();
    tryagain.setup();
    
    // disguises headers to blend in
    guiTwo.setHeaderBackgroundColor(myyellow);
    guiTwo.setBorderColor(myyellow);
    guiTwo.setTextColor(myyellow);
    tryagain.setHeaderBackgroundColor(myyellow);
    tryagain.setBorderColor(myyellow);
    tryagain.setTextColor(myyellow);
    
    // adds listeners to buttons, togglers, and sliders
    addListeners();
    
    // sets up phase one, two, and three of user interface GUI
    setupGUI();
    
    // set question color
    ofSetColor(myblue);
}


void phaseTwo::addListeners() {
    // adding the listeners for the buttons / togglers
    result_one_button.addListener(this, &phaseTwo::resultOnePressed);
    result_two_button.addListener(this, &phaseTwo::resultTwoPressed);
    result_three_button.addListener(this, &phaseTwo::resultThreePressed);
    result_four_button.addListener(this, &phaseTwo::resultFourPressed);
    result_five_button.addListener(this, &phaseTwo::resultFivePressed);
    last_results_button.addListener(this, &phaseTwo::lastResultsPressed);
    next_results_button.addListener(this, &phaseTwo::nextResultsPressed);
    search_again_button.addListener(this, &phaseTwo::searchAgainPressed);
}

void phaseTwo::setupGUI() {
    // PHASE TWO GUI
    guiTwo.add(result_one_button.setup("Result One:"));
    result_one_button.setPosition(5, 200);
    result_one_button.setBackgroundColor(ofColor::lightGrey);
    result_one_button.setTextColor(ofColor::black);
    result_one_button.setFillColor(ofColor::white);
    
    guiTwo.add(result_two_button.setup("Result Two:"));
    result_two_button.setPosition(210, 200);
    result_two_button.setBackgroundColor(ofColor::lightGrey);
    result_two_button.setTextColor(ofColor::black);
    result_two_button.setFillColor(ofColor::white);
    
    guiTwo.add(result_three_button.setup("Result Three:"));
    result_three_button.setPosition(415, 200);
    result_three_button.setBackgroundColor(ofColor::lightGrey);
    result_three_button.setTextColor(ofColor::black);
    result_three_button.setFillColor(ofColor::white);
    
    guiTwo.add(result_four_button.setup("Result Four:"));
    result_four_button.setPosition(625, 200);
    result_four_button.setBackgroundColor(ofColor::lightGrey);
    result_four_button.setTextColor(ofColor::black);
    result_four_button.setFillColor(ofColor::white);
    
    guiTwo.add(result_five_button.setup("Result Five:"));
    result_five_button.setPosition(835, 200);
    result_five_button.setBackgroundColor(ofColor::lightGrey);
    result_five_button.setTextColor(ofColor::black);
    result_five_button.setFillColor(ofColor::white);
    
    guiTwo.add(last_results_button.setup("Previous Five Results"));
    last_results_button.setPosition(10, 700);
    last_results_button.setBackgroundColor(ofColor::lightGrey);
    last_results_button.setTextColor(ofColor::black);
    last_results_button.setFillColor(ofColor::white);
    
    
    guiTwo.add(next_results_button.setup("Next Five Results"));
    next_results_button.setPosition(800, 700);
    next_results_button.setBackgroundColor(ofColor::lightGrey);
    next_results_button.setTextColor(ofColor::black);
    next_results_button.setFillColor(ofColor::white);
    
    
    
    // TRYAGAIN setup
    tryagain.add(search_again_button.setup("Search again"));
    search_again_button.setPosition(10, 250);
    search_again_button.setBackgroundColor(ofColor::lightGrey);
    search_again_button.setTextColor(ofColor::black);
    search_again_button.setFillColor(ofColor::white);
    
}


// result buttons
void phaseTwo::resultOnePressed() {
    result_pressed = true;
    
    if (brandNames.size() >= ((result_page - 1) * 5)) {
        brand_name = brandNames[(result_page - 1) * 5];
        item_name = itemNames[(result_page - 1) * 5];
        item_id = itemIDs[(result_page - 1) * 5];
        brand_id = brandIDs[(result_page - 1) * 5];
    } else {
        pressed_empty_result = true;
    }
    
    
}
void phaseTwo::resultTwoPressed() {
    result_pressed = true;

    if (brandNames.size() > (1 + (result_page - 1) * 5)) {
        brand_name = brandNames[1 + (result_page - 1) * 5];
        item_name = itemNames[1 + (result_page - 1) * 5];
        item_id = itemIDs[1 + ((result_page - 1) * 5)];
        brand_id = brandIDs[1 + ((result_page - 1) * 5)];
    } else {
        pressed_empty_result = true;
    }
    
}
void phaseTwo::resultThreePressed() {
    result_pressed = true;
    
    if (brandNames.size() > (2 + (result_page - 1) * 5)) {
        brand_name = brandNames[2 + (result_page - 1) * 5];
        item_name = itemNames[2 + (result_page - 1) * 5];
        item_id = itemIDs[2 + ((result_page - 1) * 5)];
        brand_id = brandIDs[2 + ((result_page - 1) * 5)];
    } else {
        pressed_empty_result = true;
    }
    
}
void phaseTwo::resultFourPressed() {
    result_pressed = true;
    
    if (brandNames.size() > (3 + (result_page - 1) * 5)) {
        brand_name = brandNames[3 + (result_page - 1) * 5];
        item_name = itemNames[3 + (result_page - 1) * 5];
        item_id = itemIDs[3 + ((result_page - 1) * 5)];
        brand_id = brandIDs[3 + ((result_page - 1) * 5)];
    } else {
        pressed_empty_result = true;
    }

}
void phaseTwo::resultFivePressed() {
    result_pressed = true;

    if (brandNames.size() > (4 + (result_page - 1) * 5)) {
        brand_name = brandNames[4 + (result_page - 1) * 5];
        item_name = itemNames[4 + (result_page - 1) * 5];
        item_id = itemIDs[4 + ((result_page - 1) * 5)];
        brand_id = brandIDs[4 + ((result_page - 1) * 5)];
    } else {
        pressed_empty_result = true;
    }
 
}


// listeners for scrolling through results
void phaseTwo::nextResultsPressed() {
    // precaution against bugs
    if (result_page == kNumPages) {
        return;
    }
    result_page++;
}
void phaseTwo::lastResultsPressed() {
    // precaution against bugs
    if (result_page == 1) {
        return;
    }
    result_page--;
}


void phaseTwo::searchAgainPressed() {
    
    search_again_pressed = true;
    
    // deregister the button & blend it into background
    tryagain.setBackgroundColor(ofColor::beige);
    tryagain.setFillColor(ofColor::beige);
    tryagain.setTextColor(ofColor::beige);
    tryagain.unregisterMouseEvents();
}



void phaseTwo::update() {
    // cannot move the panel
    guiTwo.setPosition(10, 10);
    tryagain.setPosition(10, 10);
    // set question color
    ofSetColor(myblue);
    
}


string phaseTwo::getSearchWord() {
    
    return search_word;
}

void phaseTwo::draw() {
    
    std::stringstream ss;
    
    ss << "To begin your search, type in a keyword you would like to search the database for" << endl << "and then press enter." << endl;
    

    if (search_word == "") {
        ss << user_typing;
    }

    // when the user has clicked enter
    if (search_word != "") {
        ss << search_word << endl;
    }
    

    font.drawString(ss.str(), x, y);
}


string phaseTwo::drawSearchResults(bool api_request_worked) {
    
    if (!api_request_worked) {
        
        std::string s = "Sorry, the connection seems to have been lost.\nPlease exit out and try again.";
        
        font.drawString(s, 10, 170);
        
        return s;
        
    } else {
        
        std::stringstream tothits;
        tothits << "\n\n\n\ntotal hits: " << total_hits;
        
        font.drawString(tothits.str(), x, y);
        
        std::stringstream ss;
        
        std::stringstream resultOne;
        std::stringstream resultTwo;
        std::stringstream resultThree;
        std::stringstream resultFour;
        std::stringstream resultFive;
        
        
        if (total_hits > 0) {
            
            setResultScrolling();
            
            // display buttons
            guiTwo.draw();
            // display text
            draw();
            
            // display squares with info
            ofSetColor(ofColor::lightGrey);
            output.rect(10, 225, 190, 250);
            output.rect(220, 225, 190, 250);
            output.rect(420, 225, 190, 250);
            output.rect(630, 225, 190, 250);
            output.rect(840, 225, 175, 250);
            output.setLineWidth(8);
            output.fill();
            
            ofSetColor(ofColor::black);
            
            for (int k = 0; k < kNumPages; k++) {
                
                // if it's the page and there are 5 results to fill it up
                if (k == result_page - 1 && total_hits >= (result_page * kNumResults)) {
                    
                    resultOne << "Item: " << endl << itemNames[k * kNumResults] << endl << endl << "Brand: " << endl << brandNames[k * kNumResults];
                    resultTwo << "Item: " << endl << itemNames[1 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[1 + (k * kNumResults)];
                    resultThree << "Item: " << endl << itemNames[2 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[2 + (k * kNumResults)];
                    resultFour << "Item: " << endl <<  itemNames[3 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[3 + (k * kNumResults)];
                    resultFive << "Item: " << endl << itemNames[4 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[4 + (k * kNumResults)];
                    
                    // if there aren't enough results to fill the page up
                } else if (k == result_page - 1 && total_hits <= ((result_page - 1) * kNumResults)) {
                    
                    resultOne << "No result";
                    resultTwo << "No result";
                    resultThree << "No result";
                    resultFour << "No result";
                    resultFive << "No result";
                    
                    // if there are only some results on a page
                } else if (k == result_page - 1 && total_hits < (result_page * kNumResults)) {
                    
                    if (total_hits == 1 + ((result_page - 1) * kNumResults)) {
                        
                        resultOne << "Item: " << endl << itemNames[k * kNumResults] << endl << endl << "Brand: " << endl << brandNames[k * kNumResults];
                        resultTwo << "No result";
                        resultThree << "No result";
                        resultFour << "No result";
                        resultFive << "No result";
                        
                        
                    } else if (total_hits == 2 + ((result_page - 1) * kNumResults)) {
                        
                        resultOne << "Item: " << endl << itemNames[k * kNumResults] << endl << endl << "Brand: " << endl << brandNames[k * kNumResults];
                        resultTwo << "Item: " << endl << itemNames[1 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[1 + (k * kNumResults)];
                        resultThree << "No result";
                        resultFour << "No result";
                        resultFive << "No result";
                        
                    } else if (total_hits == 3 + ((result_page - 1) * kNumResults)) {
                        
                        resultOne << "Item: " << endl << itemNames[k * kNumResults] << endl << endl << "Brand: " << endl << brandNames[k * kNumResults];
                        resultTwo << "Item: " << endl << itemNames[1 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[1 + (k * kNumResults)];
                        resultThree << "Item: " << endl << itemNames[2 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[2 + (k * kNumResults)];
                        resultFour << "No result";
                        resultFive << "No result";
                        
                    } else if (total_hits == 4 + ((result_page - 1) * kNumResults)) {
                        
                        resultOne << "Item: " << endl << itemNames[k * kNumResults] << endl << endl << "Brand: " << endl << brandNames[k * kNumResults];
                        resultTwo << "Item: " << endl << itemNames[1 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[1 + (k * kNumResults)];
                        resultThree << "Item: " << endl << itemNames[2 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[2 + (k * kNumResults)];
                        resultFour << "Item: " << endl <<  itemNames[3 + (k * kNumResults)] << endl << endl << "Brand: " << endl << brandNames[3 + (k * kNumResults)];
                        resultFive << "No result";
                        
                    }
                    
                }
            }
            
            font.drawString(ss.str(), x, y);

            vector<std::string> result_strings {resultOne.str(), resultTwo.str(), resultThree.str(), resultFour.str(), resultFive.str()};
            
            setTextBoundaries(result_strings);
            
            return ss.str();
            
        } else {
            
            // have the button reappear
            tryagain.setBackgroundColor(ofColor::white);
            tryagain.setFillColor(ofColor::lightGrey);
            tryagain.setTextColor(myblue);
            tryagain.registerMouseEvents();
            tryagain.draw();
            
            totalHitsZero();
            return "total hits 0";
        }
        
    }
    
}


string phaseTwo::totalHitsZero() {

    std::string s;
    s += "Your search has resulted in 0 total hits.\nIf you would like to search for something else, click 'Search again'.";
    
    font.drawString(s, 10, 200);
    // draw again so header doesn't overlap text
    draw();
    
    return s;
}


void phaseTwo::setResultScrolling() {
    
    // "previous five results" button listener removed & blended into background (to disappear)
    if (result_page == 1) {
        
        last_results_button.setFillColor(myyellow);
        last_results_button.setBackgroundColor(myyellow);
        last_results_button.setTextColor(myyellow);
        last_results_button.removeListener(this, &phaseTwo::lastResultsPressed);
    }
    
    // "next five results" button listener removed & blended into background (to disappear)
    else if (result_page == kNumPages) {
        next_results_button.setFillColor(myyellow);
        next_results_button.setBackgroundColor(myyellow);
        next_results_button.setTextColor(myyellow);
        next_results_button.removeListener(this, &phaseTwo::nextResultsPressed);
    }
    
    // both buttons set back to normal
    else {
        
        last_results_button.setFillColor(ofColor::white);
        last_results_button.setBackgroundColor(ofColor::lightGrey);
        last_results_button.setTextColor(ofColor::black);
        last_results_button.addListener(this, &phaseTwo::lastResultsPressed);
        
        next_results_button.setFillColor(ofColor::white);
        next_results_button.setBackgroundColor(ofColor::lightGrey);
        next_results_button.setTextColor(ofColor::black);
        next_results_button.addListener(this, &phaseTwo::nextResultsPressed);
    }
    
}





void phaseTwo::setTextBoundaries(vector<string> result_strings) {
    
    // 23 characters is the max before string flows over into other box
    int position = 0;
    for (std::string rs : result_strings) {

        if (rs == "No result") {
            break;
        }

        // finds position of Item & Brand & generates a substring of everything between that & another one for everything after Brand
        std::size_t pos = rs.find("Item: ");
        std::size_t pos2 = rs.find("Brand: ");
        std::string rs_item = rs.substr(pos, (pos2 - pos));
        std::string rs_brand = rs.substr(pos2);


        for (int index = 0; index < rs_item.length(); index++) {

            if (index % 20 > 9 && rs_item[index] == ' ') {

                rs_item[index] = '\n';

            }
        }


        for (int index = 0; index < rs_brand.length(); index++) {

            if (index % 20 > 15 && rs_brand[index] == ' ') {

                rs_brand[index] = '\n';

            }

        }

        result_strings[position] = rs_item + rs_brand;
        position++;
    }


    results_font.drawString(result_strings[0], 15, 260);
    results_font.drawString(result_strings[1], 230, 260);
    results_font.drawString(result_strings[2], 425, 260);
    results_font.drawString(result_strings[3], 635, 260);
    results_font.drawString(result_strings[4], 845, 260);
}




void phaseTwo::keyPressed(int key) {
    
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
        
        search_word = user_typing;
    }
    
}




