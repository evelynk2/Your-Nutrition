//
//  phaseOne.cpp
//  final-project
//
//  Created by Evelyn Krasnik on 4/22/19.
//

#include "phaseOne.hpp"



void phaseOne::setup() {
        
    question_count = -1;
    x = 10;
    y = 30;
    
    // change font and size
    font.load("futura", 17);
    
    // initialize answers to default (my stats)
    age = 18;
    height = 69;
    weight = 163;
    gender = "female";
    exercise = "three times a week";
    diet = "maintain weight";
    
    gui.setup();

    // disguises headers to blend in
    gui.setHeaderBackgroundColor(myyellow);
    gui.setBorderColor(myyellow);
    gui.setTextColor(myyellow);
    
    // adds listeners to buttons, togglers, and sliders
    addListeners();
    
    // sets up phase one, two, and three of user interface GUI
    setupGUI();
    
    // set question color
    ofSetColor(myblue);
}

void phaseOne::addListeners() {
    // adding the listeners for the sliders
    age_slider.addListener(this, &phaseOne::ageChanged);
    height_slider.addListener(this, &phaseOne::heightChanged);
    weight_slider.addListener(this, &phaseOne::weightChanged);
    
    // adding the listeners for the buttons / togglers
    female_button.addListener(this, &phaseOne::femaleButtonPressed);
    male_button.addListener(this, &phaseOne::maleButtonPressed);
    rarely_exercise_button.addListener(this, &phaseOne::rarelyExerciseButtonPressed);
    three_exercise_button.addListener(this, &phaseOne::threeExerciseButtonPressed);
    four_exercise_button.addListener(this, &phaseOne::fourExerciseButtonPressed);
    five_exercise_button.addListener(this, &phaseOne::fiveExerciseButtonPressed);
    daily_exercise_button.addListener(this, &phaseOne::dailyExerciseButtonPressed);
    lose_quickly_button.addListener(this, &phaseOne::loseQuicklyButtonPressed);
    lose_steadily_button.addListener(this, &phaseOne::loseSteadilyButtonPressed);
    gain_quickly_button.addListener(this, &phaseOne::gainQuicklyButtonPressed);
    gain_steadily_button.addListener(this, &phaseOne::gainSteadilyButtonPressed);
    maintain_weight_button.addListener(this, &phaseOne::maintainWeightButtonPressed);
    submit_button.addListener(this, &phaseOne::submitButtonPressed);
}


void phaseOne::setupGUI() {
    // adding the buttons and sliders to the gui
    
    // PHASE ONE GUI
    gui.add(age_slider.setup("Age:", age, 1, 100));
    age_slider.setPosition(10, 130);
    age_slider.setBackgroundColor(ofColor::white);
    age_slider.setTextColor(ofColor::black);
    age_slider.setFillColor(ofColor::lightGrey);
    
    gui.add(height_slider.setup("Height:", height, 0, 100));
    height_slider.setPosition(10, 225);
    height_slider.setBackgroundColor(ofColor::white);
    height_slider.setTextColor(ofColor::black);
    height_slider.setFillColor(ofColor::lightGrey);
    
    gui.add(female_button.setup("Female", true));
    female_button.setBackgroundColor(ofColor::white);
    female_button.setTextColor(ofColor::black);
    female_button.setFillColor(ofColor::lightGrey);
    female_button.setPosition(300, 310);
    
    gui.add(male_button.setup("Male", false));
    male_button.setBackgroundColor(ofColor::white);
    male_button.setTextColor(ofColor::black);
    male_button.setFillColor(ofColor::lightGrey);
    male_button.setPosition(10, 310);
    
    gui.add(weight_slider.setup("Weight:", weight, 20, 400));
    weight_slider.setPosition(10, 405);
    weight_slider.setBackgroundColor(ofColor::white);
    weight_slider.setTextColor(ofColor::black);
    weight_slider.setFillColor(ofColor::lightGrey);
    
    gui.add(rarely_exercise_button.setup("Rarely", false));
    rarely_exercise_button.setPosition(10, 490);
    rarely_exercise_button.setBackgroundColor(ofColor::white);
    rarely_exercise_button.setTextColor(ofColor::black);
    rarely_exercise_button.setFillColor(ofColor::lightGrey);
    
    
    gui.add(three_exercise_button.setup("Three times a week", true));
    three_exercise_button.setPosition(220, 490);
    three_exercise_button.setBackgroundColor(ofColor::white);
    three_exercise_button.setTextColor(ofColor::black);
    three_exercise_button.setFillColor(ofColor::lightGrey);
    
    gui.add(four_exercise_button.setup("Four times a week", false));
    four_exercise_button.setPosition(430, 490);
    four_exercise_button.setBackgroundColor(ofColor::white);
    four_exercise_button.setTextColor(ofColor::black);
    four_exercise_button.setFillColor(ofColor::lightGrey);
    
    gui.add(five_exercise_button.setup("Five times a week", false));
    five_exercise_button.setPosition(640, 490);
    five_exercise_button.setBackgroundColor(ofColor::white);
    five_exercise_button.setTextColor(ofColor::black);
    five_exercise_button.setFillColor(ofColor::lightGrey);
    
    gui.add(daily_exercise_button.setup("Every day", false));
    daily_exercise_button.setPosition(850, 490);
    daily_exercise_button.setBackgroundColor(ofColor::white);
    daily_exercise_button.setTextColor(ofColor::black);
    daily_exercise_button.setFillColor(ofColor::lightGrey);
    
    gui.add(lose_quickly_button.setup("Lose weight quickly", false));
    lose_quickly_button.setPosition(5, 585);
    lose_quickly_button.setBackgroundColor(ofColor::white);
    lose_quickly_button.setTextColor(ofColor::black);
    lose_quickly_button.setFillColor(ofColor::lightGrey);
    
    gui.add(lose_steadily_button.setup("Lose weight steadily", false));
    lose_steadily_button.setPosition(210, 585);
    lose_steadily_button.setBackgroundColor(ofColor::white);
    lose_steadily_button.setTextColor(ofColor::black);
    lose_steadily_button.setFillColor(ofColor::lightGrey);
    
    gui.add(maintain_weight_button.setup("Maintain weight", true));
    maintain_weight_button.setPosition(420, 585);
    maintain_weight_button.setBackgroundColor(ofColor::white);
    maintain_weight_button.setTextColor(ofColor::black);
    maintain_weight_button.setFillColor(ofColor::lightGrey);
    
    gui.add(gain_quickly_button.setup("Gain weight quickly", false));
    gain_quickly_button.setPosition(630, 585);
    gain_quickly_button.setBackgroundColor(ofColor::white);
    gain_quickly_button.setTextColor(ofColor::black);
    gain_quickly_button.setFillColor(ofColor::lightGrey);
    
    gui.add(gain_steadily_button.setup("Gain weight steadily", false));
    gain_steadily_button.setPosition(840, 585);
    gain_steadily_button.setBackgroundColor(ofColor::white);
    gain_steadily_button.setTextColor(ofColor::black);
    gain_steadily_button.setFillColor(ofColor::lightGrey);
    
    gui.add(submit_button.setup("Submit answers"));
    submit_button.setPosition(10, 705);
    submit_button.setBackgroundColor(ofColor::white);
    submit_button.setTextColor(ofColor::black);
    submit_button.setFillColor(ofColor::lightGrey);
}


// sliders changed
void phaseOne::ageChanged(int &a) {
    age = a;
}
void phaseOne::heightChanged(float &h) {
    // change from in to cm
    height = h * 2.54;
}
void phaseOne::weightChanged(float &w) {
    // change from lb to kg
    weight = w * 0.45359237;
}



// gender buttons pressed
void phaseOne::femaleButtonPressed(bool &p) {
    
    if (p == true) {
        
        if (male_button == true) {
            
            male_button = false;
        }
        gender = "female";
    } else {
        
        if (male_button == false) {
            
            female_button = true;
            gender = "female";
        }
    }
}
void phaseOne::maleButtonPressed(bool &p) {
    
    if (p == true) {
        
        if (female_button == true) {
            
            female_button = false;
        }
        gender = "male";
    } else {
        
        if (female_button == false) {
            
            male_button = true;
            gender = "male";
        }
    }
}

// exercise buttons pressed
void phaseOne::rarelyExerciseButtonPressed(bool &p) {
    
    if (p == true) {
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Rarely" && t == true) {
                t = false;
            }
        }
        exercise = "rarely";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Rarely" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            rarely_exercise_button = true;
            exercise = "rarely";
        }
    }
}
void phaseOne::threeExerciseButtonPressed(bool &p) {
    
    if (p == true) {
        
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Three times a week" && t == true) {
                t = false;
            }
        }
        exercise = "three times a week";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Three times a week" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            three_exercise_button = true;
            exercise = "three times a week";
        }
    }
}
void phaseOne::fourExerciseButtonPressed(bool &p) {
    
    if (p == true) {
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Four times a week" && t == true) {
                t = false;
            }
        }
        exercise = "four times a week";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Four times a week" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            four_exercise_button = true;
            exercise = "four times a week";
        }
    }
}
void phaseOne::fiveExerciseButtonPressed(bool &p) {
    
    if (p == true) {
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Five times a week" && t == true) {
                t = false;
            }
        }
        exercise = "five times a week";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Five times a week" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            five_exercise_button = true;
            exercise = "five times a week";
        }
    }
}
void phaseOne::dailyExerciseButtonPressed(bool &p) {
    
    if (p == true) {
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Every day" && t == true) {
                t = false;
            }
        }
        exercise = "every day";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : exercise_buttons) {
            
            if (t.getName() != "Every day" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            daily_exercise_button = true;
            exercise = "every day";
        }
    }
}


// goal of diet buttons pressed
void phaseOne::loseQuicklyButtonPressed(bool &p) {
    
    if (p == true) {
        
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Lose weight quickly" && t == true) {
                t = false;
            }
        }
        diet = "lose weight quickly";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Lose weight quickly" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            lose_quickly_button = true;
            exercise = "lose weight quickly";
        }
    }
    
}
void phaseOne::loseSteadilyButtonPressed(bool &p) {
    
    if (p == true) {
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Lose weight steadily" && t == true) {
                t = false;
            }
        }
        diet = "lose weight steadily";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Lose weight steadily" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            lose_steadily_button = true;
            exercise = "lose weight steadily";
        }
    }
}
void phaseOne::gainQuicklyButtonPressed(bool &p) {
    
    if (p == true) {
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Gain weight quickly" && t == true) {
                t = false;
            }
        }
        diet = "gain weight quickly";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Gain weight quickly" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            gain_quickly_button = true;
            exercise = "gain weight quickly";
        }
    }
    
}
void phaseOne::gainSteadilyButtonPressed(bool &p) {
    
    if (p == true) {
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Gain weight steadily" && t == true) {
                t = false;
            }
        }
        diet = "gain weight steadily";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Gain weight steadily" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            gain_steadily_button = true;
            exercise = "gain weight steadily";
        }
    }
}
void phaseOne::maintainWeightButtonPressed(bool &p) {
    
    if (p == true) {
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Maintain weight" && t == true) {
                t = false;
            }
        }
        diet = "maintain weight";
    } else {
        bool other_button_true = false;
        for (ofxToggle t : diet_buttons) {
            
            if (t.getName() != "Maintain weight" && t == true) {
                other_button_true = true;
            }
        }
        
        if (!other_button_true) {
            maintain_weight_button = true;
            exercise = "maintain weight";
        }
    }
}

// submit button pressed
void phaseOne::submitButtonPressed() {
    
    submitted = true;
}



void phaseOne::update() {
    // cannot move the panel
    gui.setPosition(10, 10);
    question_count++;
}

void phaseOne::draw() {
    
    std::stringstream ss;
    
    ss << "Fill in the answers to the following questions to individualize the feedback to you\n";
    
    ss << "Press enter when you are ready\n";
    
    if (question_count != -1) {
        
        for (std::string s : question_list) {
            
            ss << s << endl << endl << endl;
            
        }
        gui.draw();
    }
    
    
    font.drawString(ss.str(), x, y);    
}


float phaseOne::calculateCaloriesNeeded() {
    
    return calculateCaloriesNeeded(gender, age, height, weight, exercise, diet);
    
}

float phaseOne::calculateCaloriesNeeded(string gender_var, int age_var, float height_var, float weight_var, string exercise_var, string diet_var) {
  
    
    // based on Mifflin-St. Jeor Equation
    // https://www.livestrong.com/article/178764-caloric-intake-formula/
    
    // basal metabolic rate
    float bmr;
    
    // GENDER
    if (gender_var == "male") {
        bmr = 10 * weight_var + 6.25 * height_var - 5 * age_var + 5;
    } else {
        // female
        bmr = 10 * weight_var + 6.25 * height_var - 5 * age_var - 161;
    }
    
    
    // EXERCISE
    if (exercise_var == "rarely") {
        bmr *= 1.2;
    } else if (exercise_var == "three times a week") {
        bmr *= 1.3;
    } else if (exercise_var == "four times a week") {
        bmr *= 1.3;
    } else if (exercise_var == "five times a week") {
        bmr *= 1.4;
    } else {
        // every day
        bmr *= 1.4;
    }
    
    // GOAL OF DIET
    if (diet_var == "gain weight quickly") {
        // increase by 25%
        bmr *= 1.25;
    } else if (diet_var == "gain weight steadily") {
        // increase by 15%
        bmr *= 1.15;
    } else if (diet_var == "lose weight quickly") {
        // reduce by 25%
        bmr *= .75;
    } else if (diet_var == "lose weight steadily") {
        // reduce by 15%
        bmr *= .85;
    } else {
        // maintain weight
    }
 
    
    calories_needed = bmr;
    return calories_needed;
}



