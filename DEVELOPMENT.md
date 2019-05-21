# Development of project

## Experience working with libraries
- ofxVectorGraphics  
    - Added the ofxVectorGraphics library addon
    - Created an instance of it in ofApp and added code to draw a line in the windowed application 
- ofURLFileLoader
    - Made a http GET request to the API
    - parsed certain information into variables
- ofJson
    - downloaded ofxJSON to deserialize the json
    - I am using ofxJSONElement which wraps json.cpp class to deserialize the json variable by variable (much more efficient for organizing the information since a lot of this is hardcoded to this application)
- ofxParagraph (and ofxSmartFont)
    - downloaded to keep string within boundaries
    - unable to print out to app, so kept my 'algorithm' to keep string within boundaries


## Steps
1. Create the User Interface to ask questions & store answers
2. Make an http request using ofURLFileLoader
3. Load the json-formatted response into a file & then use ofJson to reformat it and save it as a json object
4. Deserialize the json
5. Create phase 2 of the UI which will show the results of the search
    - this will show the top 5 results (if there are 5) as buttons (so user can choose the item which matches closest to their search, and then more information about that item will be displayed)
        -  the info will be the name of the item and the brand name and the score
        - if there are not 5, the remaining buttons will say "Not existent" or I will deactivate the button and blend the color in with the background (so it becomes invisible)
        - at the bottom of the screen, there will be a button that shows an arrow ">" so the user can choose to look through more options (up to 20) if there are that many
6. When the user clicks on a result, a panel with different nutritional information (calories, saturated fat, etc.) will show up on the left and the user can click & unclick which information they want to see about that specific food item
    - phase 3 of the UI
    - will include visualization of calories the person should be eating in a day proportionate to how much the specific food item contains 
7. Decomponse entire ofApp class into separate classes based on phases
    - created phaseOne, phaseTwo, and phaseThree class
    - ofApp controls the API requests
8. User flexibility added
    - if total hits = 0, API failed, or just in general after the information has been displayed, user has option to search for another item
9. Changed sliders to allow the user to enter in their weight in lb (then convert to kg) and height in inches (and then convert it to cm)
10. Change color scheme and fix all bugs


## Testing
1. Difficulties with linking up main to run both the tests and the app at the same time
    - linker error
    - "Error(s) in input: Unrecognised token: -N"
    - created own main to ignore the console input
        - error: TEST_CASE already defined
        - had to uninclude the ofAppTesting.cpp, just include catch.hpp
2. make methods return a value without looping or calling another function
    - create more helper methods to test
3. tested print methods, key pressing, and calculation methods (calculating calories needed)



## Problems encountered
- [x] Limit user to typing only integers or only letters (depending on question)
    - Example: "enter in age: ".... user would only be allowed to enter in integers
    - Created buttons/sliders for fixed inputs
- [x] creating buttons and separating them by question is VERY hard
    - there are a lot of bugs when setting the slider and button sizes
- [x] change ofxButton to ofxToggle so when pressed, the X stays filled (visual purposes for ease of use)
    - only allow user to press one button for each question. So if one button is already pressed, that one has to 'unpress' when a new one is pressed.
    - ofxToggle has problems with adding a listener
        - had to make listeners take in a bool parameter; problem is fixed
- [x] the panel can be moved (and I want it to stay fixed) but I cannot find a way to deregister the mouse movements to only the header, so for now, I have diguised the header to blend into the background so only by accident the user can move it
    - set location back to 10,10 on update
- [x] figuring out the ofJson library to deserialize the JSON and print out onto the screen
    - downloaded library ofxJSON and used ofxJSONElement to deserialize information variable by variable
- [x] with multiple words, the API request does not go through (because lacking something in the URL)
    - replace "%20" with each space (that's how the API request handles them)
- [x] fix overlap of words in phase two of the gui when the results are displayed in separate boxes
    - downloaded ofxParagraph addon
        - did not work, so kept my original solution
- [x] need to create a variable that tracks whether the api request worked or not, because if it didn't phase 2 (search results) and phase 3 of the GUI shouldn't activate
- [x] default individual variable info was being saved wrong because listeners to buttons & togglers are called every update, not only when they are pressed
- [x] allowing user to search after a failed attempt creates issues with created lists & printing out user typing
- [x] allow the user to search after MULTIPLE failed attempts (so it's kind of a loop)
- [x] phase three was on an infinite loop of calling the API which made it go over limit
    - created separate boolean variable to check if API has already been called
- [x] Take care of the situation when there are less than 20 hits (but more than 0) for a search
    - the results with no info will display 'no result' 
    - had to create a separate variable which checks to see if these 'no results' are clicked on
- [x] Ensure that one of the information togglers are always clicked by default (can't unlick male AND female; one of them has to always be clicked so value is there)
- [x] user flexibility (specifically allowing user to search again during phase 3) is causing difficulties because i have to reset the GUI's and ensure that they do not store the previous result information
    - currently, issue with pressing 'no result' and having the previous result show up in phase 3 rather than an API failure
        - had to reset boolean variables
- [x] I believed there was an API request limit (and there is), but the reason I was going over my request limit per day was because the call to the API was on an infinite loop each time the app updated
    - fixed by creating a variable which checked if the API had been called 
        
    


## Potential Addons
1. Calorie King API (NO POINT)
    1. API Key: a5f5108c-7dca-4746-aec7-fb9ef13ef478
    1. https://developer.calorieking.com/food-api/documentation
    1. [CalorieKing][https://developer.calorieking.com];
    1. it's the same thing as Nutritionix
2. Instead of prompting user to enter height in cm & weight in kg, ask for height in feet/inches and weight in lbs & then convert for the calculation at the end (DONE)
3. Give the user more flexibility in switching between screens (DONE)
    - if API connection fails or total hits = 0 for example, allow the user to re-type something in or try again
4. Make the graphics better (DONE)

