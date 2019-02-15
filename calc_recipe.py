'''
Jonathan Benson
CS 101
Program #1
'''



#Input
#Users' desired quantity of each type of product

#Prompt the user to enter a  desired quantity for each product.
#Assign variables to their respected input.
#Convert variables' value types into integers.
dozen_cookies = int(input('How many dozen cookies?\n'))
cakes = int(input('How many cakes?\n'))
dozen_donuts = int(input('How many dozen donuts?\n'))

product_quantities = [dozen_cookies , cakes , dozen_donuts]


#Process
#calculate how much of each ingredient to order, given the desired quantity of each type of product.

#Create a dictionary for each products' recipe with each elements' key as  the ingredient and the value as the respected ingredients' quantity.

dozen_cookies_recipe = {
    'cups_butter' : 2.5 ,
    'cups_sugar' : 2 ,
    'eggs' : 2 ,
    'cups_flour' : 8
    }

sheet_cake_recipe = {
    'cups_butter' : 0.5 ,
    'cups_sugar' : 1 ,
    'eggs' : 2 ,
    'cups_flour' : 1.5
    }

dozen_donuts_recipe = {'cups_butter' : 0.25 ,
                       'cups_sugar' : 0.5 ,
                       'eggs' : 3 ,
                       'cups_flour' : 5
                       }

recipes = [dozen_cookies_recipe , sheet_cake_recipe , dozen_donuts_recipe]

#Assign each ingredients' variable to the total sum of:
#Quantity of each product (user's input values) times the quantity of its respected ingredient (dictionary values) from their recipe
#ingredient = product * recipe
ingredientList = []

cups_butter = 0
cups_sugar = 0
eggs = 0
cups_flour = 0

ingredients = [cups_butter , cups_sugar , eggs , cups_flour]

for recipe in recipes :
    
    for ingredient in recipe :
        if ingredient == 'cups_butter' :
            cups_butter += recipe[ingredient]
        elif ingredient == 'cups_sugar' :
            cups_sugar += recipe[ingredient]
        elif ingredient == 'eggs' :
            eggs += recipe[ingredient]
        elif ingredient == 'cups_flour' :
            cups_flour += recipe[ingredient]
    

print(ingredients)

        
        



#Output
#Quantity of each ingredient

#Print the quantity of each ingredient (rounded to 2 decimal points).
print('You will need to order:')
print(round(cups_butter , 2) , 'cups of butter')
print(round(cups_sugar , 2) , 'cups of sugar')
print(round(eggs , 2) , 'eggs')
print(round(cups_flour , 2) , 'cups of flour')














