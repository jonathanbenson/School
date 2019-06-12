#Create a program to calculate the roots of a quadratic given the inputs of a, b, and c


import math

while True :
    a = float(input("Please enter in a value for a\n"))

    if a == 0 :
        print('"a" must not be equal to 0')
        a = float(input("Please enter in a value for a"))

    b = float(input("Please enter in a value for b\n"))
    c = float(input('Please enter in a value for c\n'))


    if ((b**2) - (4 * a * c)) < 0 :
        print(a , 'x^2 + ' , b , 'x + ' , c , sep = '')
        print("No real roots")

    else:
        root1 = (-b + math.sqrt((b**2) - (4 * a * c))) / (2 * a)
        root2 = (-b - math.sqrt((b**2) - (4 * a * c))) / (2 * a)
        print(a , 'x^2 + ' , b , 'x + ' , c , sep = '')
        print("x=" , root1)
        print("x=" , root2)




