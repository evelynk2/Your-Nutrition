//
//  ofAppTest.cpp
//  final-project
//
//  Created by Evelyn Krasnik on 4/14/19.
//

#include <stdio.h>
#include "catch.hpp"
#include "ofApp.h"


ofApp *app = new ofApp();
phaseOne *phase_one = new phaseOne();
phaseTwo *phase_two = new phaseTwo();
phaseThree *phase_three = new phaseThree();



TEST_CASE("search word recorded correctly") {
    phase_two->keyPressed('o');
    phase_two->keyPressed('r');
    phase_two->keyPressed('e');
    phase_two->keyPressed('o');
    phase_two->keyPressed(OF_KEY_RETURN);
    
    REQUIRE("oreo" == phase_two->getSearchWord());
    
    SECTION("cannot alter search word after enter has been clicked") {
        
        phase_two->keyPressed(OF_KEY_BACKSPACE);
        REQUIRE("oreo" == phase_two->getSearchWord());
    }
    
}


TEST_CASE("0 total hits") {
    
    SECTION("nonsensical search") {
        phase_two->keyPressed('o');
        phase_two->keyPressed('g');
        phase_two->keyPressed('r');
        phase_two->keyPressed('w');
        phase_two->keyPressed(OF_KEY_RETURN);
        
        REQUIRE(0 == app->saveSearchResults());
    }
    
    SECTION("correct response printed to app") {
        std::string s;
        s += "Your search has resulted in 0 total hits.\nIf you would like to search for something else, click 'Search again'.";
        
        REQUIRE(s == phase_two->totalHitsZero());
    }
    
}

TEST_CASE("phase one togglers and sliders work") {
    bool press = true;

    SECTION("all togglers and sliders changed") {
        int age = 21;
        float height = 61;
        float weight = 123;
        phase_one->femaleButtonPressed(press);
        phase_one->dailyExerciseButtonPressed(press);
        phase_one->gainSteadilyButtonPressed(press);
        phase_one->ageChanged(age);
        phase_one->heightChanged(height);
        phase_one->weightChanged(weight);
        
        REQUIRE(2029.07275f == phase_one->calculateCaloriesNeeded());
    }
    

    SECTION("exercise and diet changed") {
        
        phase_one->rarelyExerciseButtonPressed(press);
        phase_one->loseSteadilyButtonPressed(press);
        
        REQUIRE(1285.49951f == phase_one->calculateCaloriesNeeded());
    }
}


TEST_CASE("phase three togglers work") {
    
    SECTION("No information to display initially") {
        
        REQUIRE(0 == phase_three->getInfoDisplayed().size());

    }
    
    SECTION("New information displayed when toggler clicked") {
        bool press = true;
        phase_three->caloriesFromFatPressed(press);
        phase_three->cholesterolPressed(press);
        
        REQUIRE(2 == phase_three->getInfoDisplayed().size());
        CHECK("Calories From Fat: 0" == phase_three->getInfoDisplayed()[0]);
        CHECK("Cholesterol: 0" == phase_three->getInfoDisplayed()[1]);
    }
    
    SECTION("Information removed when toggler unclicked") {
        bool unpress= false;
        phase_three->caloriesFromFatPressed(unpress);
        
        REQUIRE(1 == phase_three->getInfoDisplayed().size());
        CHECK("Cholesterol: 0" == phase_three->getInfoDisplayed()[0]);
    }
    
}



TEST_CASE("API search connection failed") {
    std::string s;
    s += "Sorry, the connection seems to have been lost.\nPlease exit out and try again.";

    REQUIRE(s == phase_two->drawSearchResults(false));
}



TEST_CASE("API item expanded search connection failed") {

    std::string s;
    s += "The info you have requested could not be processed.\n\n";
    s += "However, based on the initial answers you have provided,\nyour suggested caloric intake per day is ";
    s += "0 calories.\n\nIf you would like to search for another item, click 'Search again'.";
    
    
    REQUIRE(s == phase_three->drawApiFailure(true));
}


TEST_CASE("write json to file correctly") {
    
    string fileinfo;
    string line;
    ifstream myfile ("/Users/evelynkrasnik/Desktop/CS 126/open frameworks/apps/myApps/final-project/src/responseAsJson");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            fileinfo += line;
        }
        myfile.close();
    }
    
    REQUIRE("" == app->saveAsJson());
}


TEST_CASE("calculate calories needed correctly") {

    CHECK(2064.6274414062f == phase_one->calculateCaloriesNeeded("female", 18, 175.26, 74.38, "three times a week", "maintain weight"));

    CHECK(1942.19824f == phase_one->calculateCaloriesNeeded("male", 35, 180.21, 89.34, "every day", "lose weight quickly"));
}
