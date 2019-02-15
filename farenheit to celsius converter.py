''' Farenheit to Celsius Conversion Program

1. prompt the user to enter in the temperature in farenheit
2. assign farenheit to the input of the user
3. Convert the users input to a float
4. assign celsius to the formula
5. round celsius and farenheit to the nearest whole number
6. output the result

useful formula: celsius = (farenheit - 32) * (5/9)
'''

#1
print("Please enter the temperature in farenheit")

#2
farenheit = input()

#3
farenheit = float(farenheit)

#4
celsius = (farenheit - 32) * (5/9)

#5
celsius = round(celsius)
farenheit = round(farenheit)

#6
print(farenheit , "degrees farenheit is equal to" , celsius , "degrees celsius")


