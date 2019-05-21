#  Proposal

**Health App**


This Health App will be a windowed application which will take user input to extract information from the following API:

1. An API which is a search engine and database for nutritional information
1. https://developer.nutritionix.com/docs/v1_1
1. [Nutrionix][https://developer.nutritionix.com]


The User Interface will be implemented as such:
* Main screen will prompt user to enter several questions: (save all these variables)
* Age
* Height
* Gender
* Weight (kg)
* Exercise:
* Rarely, (3/4/5) times a week, every day
* Diet: 
* Lose weight (quickly / steadily), gain weight (quickly / steadily), or maintain weight
* Then, main screen will prompt user to search for a food item or brand
* If total hits is not null, it will then display the top 5 results with a button "show more" below it if there are more results
* If "show more" is clicked, then more results (by 5) will continue appearing
* If one of the results is clicked, the brand ID and the item ID of that item are stored 
* The screen will then display:
*calories
*calories from fat
*total fat
*saturated fat
*sodium
*cholestoral
*sugars
*protein
*serving size quantity
* The caloric results will be visualized with the Graphics library based on the proportion of calories the item contains to how much the person ideally needs to eat in a day



Four possible entries & return results:
1. **/search**: returns an array of matching foods (returns item ID and brand ID)
2. **/item**: returns an item object with all of the nutritional data available for that item
3. **/brand**: returns a brand object that contains data on all its nutritional content
4. **/brand/search**: allows for a standard or autocomplete search


Libraries to be included...:
* ofURLFileLoader to make a GET request to the API
* Json library to parse the results from the API
* Graphics library to visualize the information (ofXvectorGraphics)


How to calculate calories needed per day:

First we calculate the Basal Metabolic Rate (BMR)*:
- Men: 10 x weight (kg) + 6.25 x height (cm) - 5 x age (y) + 5
- Women: 10 x weight (kg) + 6.25 x height (cm) - 5 x age (y) - 161.

Next we multiply base rate by between 1.2 and 1.6 depending on exercise level.
Finaly we reduce by 15% for Fat Loss, or 25% for Fast Fat Loss. The 'absolute lowest' number of calories is capped at 8 calories per pound of body weight.
Gain weight steadily increases by 15%, Gain weight quickly increases by 25%.

https://www.completefoods.co/diy/nutrient-profiles/calculator
[CompleteFoods][https://www.completefoods.co]






**IF THERE IS TIME...**
1. Extract information from a SECOND API:
1. a Health News API which lists all health-related news articles based on a keyword
1. https://newsapi.org/s/us-health-news-api
[NewsApi][https://newsapi.org]

2. The User Interface will be implemented as such:
* Main screen will prompt user to select from two buttons: search database of health-related news with keyword OR return best food choices based on the specifications of the individual

3. If search in the database of health-related news is chosen...
* Screen will prompt user to type in a keyword (or several) to then search the database and will return the API's results in the form of:
* Title, Author, (perhaps) Main Image, and Quick Summary
* If article is clicked on....
* Screen will display the full article



