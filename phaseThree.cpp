//
//  phaseThree.cpp
//  final-project
//
//  Created by Evelyn Krasnik on 4/22/19.
//

#include "phaseThree.hpp"


void phaseThree::setup() {
    
    x = 10;
    y = 30;
    search_again_pressed = false;
    
    // change font and size
    font.load("futura", 17);
    
    
    // set up buttons and sliders for phase three
    // blend header into background
    guiThree.setup();
    guiThree.setHeaderBackgroundColor(myyellow);
    guiThree.setBorderColor(myyellow);
    guiThree.setTextColor(myyellow);
    
    searchagain.setup();
    searchagain.setHeaderBackgroundColor(myyellow);
    searchagain.setBorderColor(myyellow);
    searchagain.setTextColor(myyellow);
    
   
    
    // adds listeners to buttons, togglers, and sliders
    addListeners();
    
    setupSearchAgain();
    
    // set text color
    ofSetColor(myblue);
}

void phaseThree::addListeners() {
    // adding the listeners for the buttons / togglers that will show up in the GUI (if the info is not null (aka -5))
    calories_button.addListener(this, &phaseThree::caloriesPressed);
    calories_from_fat_button.addListener(this, &phaseThree::caloriesFromFatPressed);
    cholesterol_button.addListener(this, &phaseThree::cholesterolPressed);
    dietary_fiber_button.addListener(this, &phaseThree::dietaryFiberPressed);
    protein_button.addListener(this, &phaseThree::proteinPressed);
    sodium_button.addListener(this, &phaseThree::sodiumPressed);
    sugar_button.addListener(this, &phaseThree::sugarPressed);
    total_fat_button.addListener(this, &phaseThree::totalFatPressed);
    total_carbohydrate_button.addListener(this, &phaseThree::totalCarbohydratePressed);
    search_again_button.addListener(this, &phaseThree::searchAgainPressed);
}


void phaseThree::setupSearchAgain() {
    // SEARCH AGAIN GUI setting up
    searchagain.add(search_again_button.setup("Search again"));
    search_again_button.setPosition(825, 727);
    search_again_button.setBackgroundColor(ofColor::lightGrey);
    search_again_button.setFillColor(ofColor::white);
    search_again_button.setTextColor(ofColor::black);
}


void phaseThree::setupGUI() {
    
    // PHASE THREE GUI-- sets up the buttons only if the information pertaining to the variable is not null (marked as -5)
    if (calories != -5) {
        guiThree.add(calories_button.setup("Calories", false));
        calories_button.setBackgroundColor(ofColor::lightGrey);
        calories_button.setFillColor(ofColor::white);
        calories_button.setTextColor(ofColor::black);
    }
   
    if (calories_from_fat != -5) {
        guiThree.add(calories_from_fat_button.setup("Calories From Fat", false));
        calories_from_fat_button.setBackgroundColor(ofColor::lightGrey);
        calories_from_fat_button.setFillColor(ofColor::white);
        calories_from_fat_button.setTextColor(ofColor::black);
    }
  
    if (cholesterol != -5) {
        guiThree.add(cholesterol_button.setup("Cholesterol", false));
        cholesterol_button.setBackgroundColor(ofColor::lightGrey);
        cholesterol_button.setFillColor(ofColor::white);
        cholesterol_button.setTextColor(ofColor::black);
    }
   
    if (dietary_fiber != -5) {
        guiThree.add(dietary_fiber_button.setup("Dietary Fiber", false));
        dietary_fiber_button.setBackgroundColor(ofColor::lightGrey);
        dietary_fiber_button.setFillColor(ofColor::white);
        dietary_fiber_button.setTextColor(ofColor::black);
    }
    
    if (protein != -5) {
        guiThree.add(protein_button.setup("Protein", false));
        protein_button.setBackgroundColor(ofColor::lightGrey);
        protein_button.setFillColor(ofColor::white);
        protein_button.setTextColor(ofColor::black);
    }
    
    if (sodium != -5) {
        guiThree.add(sodium_button.setup("Sodium", false));
        sodium_button.setBackgroundColor(ofColor::lightGrey);
        sodium_button.setFillColor(ofColor::white);
        sodium_button.setTextColor(ofColor::black);
    }

    if (sugar != -5) {
        guiThree.add(sugar_button.setup("Sugar", false));
        sugar_button.setBackgroundColor(ofColor::lightGrey);
        sugar_button.setFillColor(ofColor::white);
        sugar_button.setTextColor(ofColor::black);
    }
    
    if (total_fat != -5) {
        guiThree.add(total_fat_button.setup("Total Fat", false));
        total_fat_button.setBackgroundColor(ofColor::lightGrey);
        total_fat_button.setFillColor(ofColor::white);
        total_fat_button.setTextColor(ofColor::black);
    }
 
    if (total_carbohydrate != -5) {
        guiThree.add(total_carbohydrate_button.setup("Total Carbohydrate", false));
        total_carbohydrate_button.setBackgroundColor(ofColor::lightGrey);
        total_carbohydrate_button.setFillColor(ofColor::white);
        total_carbohydrate_button.setTextColor(ofColor::black);
    }

}

void phaseThree::searchAgainPressed() {
    
    search_again_pressed = true;
    guiThree.clear();
    
}

void phaseThree::update() {
    // cannot move the panel
    guiThree.setPosition(10, 10);
    searchagain.setPosition(10, 10);
    
}


// listeners for gui three panel
// if the button is pressed, the info to be displayed on the screen will be added to a vector of strings which contain all of the info to be displayed. If it the button is unpressed, the string containing the info will be deleted from the vector
void phaseThree::caloriesPressed(bool &p) {
    
    std::stringstream s;
    s << "Calories: " << calories;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Calories:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}
void phaseThree::caloriesFromFatPressed(bool &p) {
    std::stringstream s;
    s << "Calories From Fat: " << calories_from_fat;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Calories From Fat:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}
void phaseThree::cholesterolPressed(bool &p) {
    std::stringstream s;
    s << "Cholesterol: " << cholesterol;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Cholesterol:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}
void phaseThree::dietaryFiberPressed(bool &p) {
    std::stringstream s;
    s << "Dietary Fiber: " << dietary_fiber;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Dietary Fiber:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}
void phaseThree::proteinPressed(bool &p) {
    std::stringstream s;
    s << "Protein: " << protein;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Protein:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}
void phaseThree::sodiumPressed(bool &p) {
    std::stringstream s;
    s << "Sodium: " << sodium;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Sodium:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}
void phaseThree::sugarPressed(bool &p) {
    std::stringstream s;
    s << "Sugar: " << sugar;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Sugar:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}
void phaseThree::totalFatPressed(bool &p) {
    std::stringstream s;
    s << "Total Fat: " << total_fat;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Total Fat:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}
void phaseThree::totalCarbohydratePressed(bool &p) {
    std::stringstream s;
    s << "Total Carbohydrate: " << total_carbohydrate;
    
    if (p == true) {
        
        info_displayed.push_back(s.str());
        
    } else {
        if (info_displayed.size() != 0) {
            
            for (int i = 0; i < info_displayed.size(); i++) {
                
                if (info_displayed[i].find("Total Carbohydrate:") != string::npos) {
                    info_displayed.erase(info_displayed.begin() + i);
                }
            }
        }
    }
}



void phaseThree::draw(string item_name, string brand_name) {

    guiThree.draw();
  
    std::stringstream ss;
    ss << "Your suggested caloric intake per day is " << std::fixed << std::setprecision(2) << calories_needed << " calories." << endl;
    
    
    std::stringstream ss_name;
    ss_name << "Item:" << endl << item_name << endl << "Brand:" << endl << brand_name << endl;

    
    std::stringstream ss_info;
    for (string info : info_displayed) {
        ss_info << info << endl;
    }
    
    ofSetColor(myblue);

    // displaying information about item
    font.drawString(ss.str(), 385, 40);
    font.drawString(ss_name.str(), 300, 100);
    font.drawString(ss_info.str(), 300, 235);
 

    std::stringstream calor;
    calor << calories_needed;
    
    std::stringstream cal_item;
    cal_item << calories;
    
    float cal_proportion = calories / calories_needed;
    std::stringstream cal_prop;
    cal_prop << "This item has " << cal_proportion * 100 << "% of your suggested daily caloric intake.";
    

    // displaying text for line
    ofSetColor(myblue);
    font.drawString("0", 90, 600);
    font.drawString(calor.str(), 900, 600);
    font.drawString(cal_item.str(), 105 + (cal_proportion * 800), 600);
    font.drawString(cal_prop.str(), 350, 680);
    
    // giving user option to search again
    font.drawString("If you would like to search for another item, press 'Search again'.", 145, 745);

    
    // setting up box outline and line to visualize calories
    ofSetColor(ofColor::lightGrey);
    output.setLineWidth(10);
    output.rect(275, 65, 735, 430);
    output.noFill();
    output.line(100, 560, 900, 560);
    
    
    // marking the line to show where the calories are
    ofSetColor(myblue);
    output.line(100, 545, 100, 575);
    output.line(900, 545, 900, 575);
    output.line(115 + (cal_proportion * 800), 545, 115 + (cal_proportion * 800), 575);
    
    
    search_again_button.setPosition(850, 730);
    searchagain.draw();
}



string phaseThree::drawApiFailure(bool testing) {
    // will only display results of individual's caloric intake (but since API request failed, no individual item info can be shown)
    std::stringstream ss;
    ss << "The info you have requested could not be processed." << endl << endl;
    ss << "However, based on the initial answers you have provided," << endl << "your suggested caloric intake per day is " << calories_needed << " calories." << endl << endl;
    ss << "If you would like to search for another item, click 'Search again'.";
    
    
    // displaying information about item
    font.drawString(ss.str(), 20, 50);
    
    if (!testing) {
        search_again_button.setPosition(20, 220);
        searchagain.draw();
    }
    

    return ss.str();
}


vector<string> phaseThree::getInfoDisplayed() {
    return info_displayed;
}
