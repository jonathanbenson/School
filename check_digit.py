'''

Jonathan Benson
Program 3 (Check Digits)
CS101

Algorithm

1. Get user input, their input represents the check digit
2. If the user enters an empty string (presses Enterkey), then end the program, else proceed to step 3
3. Edit the user’s raw input slightly to account for any mistypes
    a. Remove any character in the check digit that is not a letter or number
    b. Capitalize every letter in the check digit
4. If any of the below conditions are unsatisfied with respect to the check digit, then the check digit is invalid so skip to step 7
    a. The check digit must be 13 characters in length
    b. First character of the check digit must be a letter ‘A-D’
    c. Second character of the check digit must be a letter ‘A-E’
    d. The characters 3-12 must be either a letter ‘A-F’ or a digit ‘0-9’
    e. The last character of the check digit must be a digit ‘0-9’
    f. The remainder of the product sum divided by 10 must equal the last digit of the check digit
    g. The product sum is calculated by calculating the sum of all the products of the check digit’s characters’ values and their weights
        i. Characters’ weights
            1. the numeric value associated with the character’s position in the check digit, starting with zero for the first character
        ii. Characters’ values
            1. Letters ‘A-F’ have values of 10-15 respectively
            2.Digits ‘0-9’ have values that are the same as their numeric value
5. If all conditions above are satisfied with respect to the check digit, thenthe check digit is valid so proceed to step 6
6. The check digit is valid
    a. Output both the class and assignment type of the check digit
        i. Class
            1. Determined by the letter of the first character in the check digit and the class that it represents
                a.'A' represents 'CS101' 
                b.'B' represents 'CS191'
                c.'C' represents 'CS201' 
                d.'D' represents 'CS291'
        ii. Assignment type
            1. Determined by the letter of the second character in the check digit and the assignment type that it represents
                a. 'A' represents 'Test'
                b. 'B' represents 'Program'
                c. 'C' represents 'Quiz'
                d. 'D' represents 'Final'
                e. 'E' represents 'Other'
    b. Return to step 1
7. The check digit is invalid
    a. Output the reason why the check digit is invalid based on the condition that was left unsatisfied in step 4a-g
    b. Return to step 1


'''



def calProductSum(checkDigitLoc) : #check digit passed to this function assumed to be modified by the makeover() function
    '''calculates and returns the product sum of the check digit.'''

    productSum = 0

    for weight in range(len(checkDigitLoc) - 1) : #iterating over each character's weight except the last character

        if checkDigitLoc[weight].isalpha() == True : #if the char is a letter, increment the productSum by the product of the weight and the letter's associated value

            productSum += (weight * letterValues[checkDigitLoc[weight]])

        else : #if the char is not a letter, increment the productSum by the product of the weight and the number

            productSum += (weight * int(checkDigitLoc[weight]))

            


    return productSum







def calRemainder(productSumLoc) :
    '''calulates and returns the remainder of the product sum divided by 10, given the product sum of the check digit'''

    remainder = (productSumLoc % 10)
    

    return remainder





def returnInvalidChars(checkDigitLoc) :
    '''returns a list of the invalid characters in the check digit'''

    validLetters = 'ABCDEF' #possible valid letters of the check digit (specifically characters 3-12)


    invalidCharsLoc = [] #list containing the check digit's invalid characters

    for char in checkDigitLoc :

        
        #if the character is not a valid letter 'A-F' or a digit, append that character to a list containing invalid characters
        
        if (char not in validLetters) and (char.isdigit() == False) :

            invalidCharsLoc.append(char)

    

            

    
    return invalidCharsLoc
    

    





def genOutput(checkDigitLoc) : #check digit passed to this function assumed to be modified by the makeover() function
    '''Returns a string that represents the output based on whether the check digit is valid or invalid'''

    

    firstLetters = 'ABCD' #possible valid letters for the first character in the check digit
    secondLetters = 'ABCDE' #possible valid letters for the second character in the check digit
    middleLetters = 'ABCDEF' #possible valid letters between the first two letters and the last character





    #for the branch involving invalidChars below
    invalidChars = returnInvalidChars(checkDigitLoc)



    
    outputLoc = ''

    #outputs for the program if the user inputs an invalid checkdigit
    
    if len(checkDigitLoc) != 13 : #if the check digit is less OR more than 13 characters, output it is invalid and explain why
        outputLoc = 'Incorrect, the value must be 13 characters in length.'

    elif (checkDigitLoc[0] not in firstLetters) : #if the first character in the check digit is not a letter 'A-D', output it is invalid and explain why
        outputLoc = 'Incorrect, the first letter cannot be {}, only letters \'A-D\''.format(checkDigitLoc[0])
        
    elif (checkDigitLoc[1] not in secondLetters) : #if the second character in the check digit is not a letter 'A-E', output it is invalid and explain why
        outputLoc = 'Incorrect, the second letter cannot be {}, only letters \'A-E\''.format(checkDigitLoc[1])

    elif checkDigitLoc[-1].isdigit() == False : #if the last character in the check digit is not a number, output it is invalid and explain why
        outputLoc = 'Incorrect, the last character cannot be {}, only a digit \'0-9\''.format(checkDigitLoc[-1])

    elif len(invalidChars) >= 1 : #if there exists invalid characters in the check digit, output it is invalid and list out the invalid characters
        outputLoc = 'Incorrect, there are invalid character(s) {} in the value'.format(' '.join(invalidChars))
        
    elif calRemainder(calProductSum(checkDigit)) != (int(checkDigitLoc[-1])) : #if the product sum mod 10 does not equal the last character of the check digit
        outputLoc = 'Incorrect, the the remainder of the product sum ({}) divided by 10 is not {}'.format(calProductSum(checkDigitLoc) , checkDigitLoc[-1])

    else : #if all of the conditions above are left unsatisfied, output it is valid and output the class and assignment type
        outputLoc = 'Valid, class is %s and assignment is %s' % (classes[checkDigitLoc[0]] , assignmentTypes[checkDigitLoc[1]])
    



    

    return outputLoc





def makeover(rawInputLoc) :
    '''rewrites the user's input and returns a clean version (all letters uppercased and stripped of whitespace)'''


    
    #makes all letters in the check digit uppercase and deletes all proceeding and trailing whitespace
    rawInputLoc = rawInputLoc.upper().strip()



    whitespaces = [' ' , '\t' , '\n']


    newVersion = '' #re-written check digit

    for char in rawInputLoc :

        if char in whitespaces : #if the character is whitespace, do not include it in the re-written check digit

            newVersion += ''

        else : #if the character is not whitespace, include it in the re-written check digit
            
            newVersion += char


    return newVersion












#inserting letter:value pairs into a dictionary named letterValues
#the numbers do not need a dictionary because their values are equal to their number

letterValues = {}

value = 10

for ordNum in range(65 , 71) :

    letterValues[chr(ordNum)] = value

    value += 1





#inserting letter:class key value pairs into a dictionary named classes
#will be used to return the class given the first letter of the check digit
classes = {
    
    'A' : 'CS101' ,
    'B' : 'CS191' ,
    'C' : 'CS201' ,
    'D' : 'CS291'

    }


#inserting letter:assignmenttype key value pairs into a dictionary named assigment types
#will be used to return the assignnent type given the second letter of the check digit
assignmentTypes = {

    'A' : 'a Test' ,
    'B' : 'a Program' ,
    'C' : 'a Quiz' ,
    'D' : 'a Final' ,
    'E' : 'Other'

    }



#source code

while True : #infinite loop


    print('Welcome to the assignment # validator\n'
          'Enter the assignment number ==> ' ,
          end = '' , sep = '')

    

    rawInput = input() #get the user's raw input

    if rawInput == '' : #if the user enters an empty string, end the program by breaking out of the loop
               
        break


    checkDigit = makeover(rawInput) #return an cleaner check digit based off the user's raw input
    



    #if the user inputs a valid check digit, output the class and assignment type of the check digit
    #if the user inputs an invalid check digit, output the reason why it is invalid
    
    print(genOutput(checkDigit) , end = '\n\n')
    
    
print('Goodbye.') #outputs "Goodbye" if the user decides to end the program by pressing Enter
















        
