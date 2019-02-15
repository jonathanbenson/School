'''

Problem: create a program to calculate a circle's area and circumference
based on its radius


Algorithm

1. import math
2. Prompt the user to enter in a value for the radius
3. declare the radius as a variable assigned to the input by the user
4. Convert the radius value type into a float
4. Declare area and circumference as variables equal to their formulas
5. Output the circles' area and circumference

Formulas

area = math.pi * radius**2
circumference = 2 * math.pi * radius

'''

#1
import math

#2
print("Please enter in the length of the circles' radius")

#3
radius = input()

#4
radius = float(radius)

#5
area = math.pi * radius**2
circumference = 2 * math.pi * radius

#6
print("A circle with a radius of" , radius , "will have an area of" , area)
print("A circle with a radius of" , radius , "with have a circumference of" , circumference)



