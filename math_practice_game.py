


'''
Jonathan Benson
'''


import random



def genRandExp() :
    '''this function will generate a random expression'''

    randNums = [1,2,3,4,5,6,7,8,9,10]
    randSigns = ['+' , '-']

    randNum1 = random.choice(randNums)
    randNum2 = random.choice(randNums)

    randSign = random.choice(randSigns)


    
    return randNum1 , randNum2 , randSign






def calExp(num1Arg , num2Arg , signArg) :
    '''this expression will calculate the expression '''

    solLoc = 0
    
    if signArg == '+' :

        solLoc = num1Arg + num2Arg

    else :

        solLoc = num1Arg - num2Arg


    return solLoc



def printExp(num1Arg , num2Arg , signArg) :
    '''prints the expression given the randomly generated numbers'''

    expression = ''

    num1Arg = str(num1Arg)
    num2Arg = str(num2Arg)

    expression = 'What is' + ' ' + num1Arg + ' ' + signArg + ' ' + num2Arg  + ' ' + '?'

    return expression




def correctOrNot(userGuessArg , solArg) :
    '''finds out if the user is correct or not '''

    solArg = str(solArg)
    
    if userGuessArg == solArg :

        return True

    else :

        return False
    



def rightAnswer(solArg , userGuessArg) :
    '''generates a string for the right answer if the user is wrong'''

    solArg = str(solArg)
    userGuessArg = str(userGuessArg)

    rightAnswerStr = ''

    rightAnswerStr = 'The correct answer is ' + solArg + ' not ' + userGuessArg

    
    return rightAnswerStr


def playAgain(playAgainVarArg) :
    '''will return True if 'Y' is passed to the function, and False if 'N' is passed '''
    
    if playAgainVarArg == 'Y' :
        return True
    else :
        return False










playAgainVar = True

while playAgainVar == True : #a condition on whether or not the player wants to keep playing

    boolean = True

    questionNum = 0 #a tally for the number of questions answered throughout the program
    correctAnswers = 0 #a tally for the number of correct answers the user has provided

    while questionNum < 5 : #the user will get 5 questions to answer before finding out their score

        
        num1 = 0
        num2 = 0
        sign = ''
        guessNum = 1 #a tally for how many guesses the user has provided

        num1, num2, sign = genRandExp() #generate random numbers and sign for expression

        solGlob = calExp(num1 , num2 , sign) #calculate the solution of the expression, given numbers and sign



        print(printExp(num1 , num2 , sign)) #print the question and prompt the user to input the answer
        userGuess = input('Guess #%d ==>' % guessNum)

        boolean = correctOrNot(userGuess , solGlob) #if boolean = true, they have the correct answer, else: wrong answer




        if boolean == True : #if they are correct, tell them they are correct and give another question

            print('You are correct\n')

            correctAnswers += 1
            questionNum += 1


        
        

        if boolean == False : #if they are wrong, give them 3 more chances to guess the correct answer.
            #boolean is a marker for whether or not the user is correct or not
            
                
            while boolean == False :
                guessNum += 1
                
                userGuess = input('Guess #%d ==>' % guessNum) #give the user another try

                    
                boolean = correctOrNot(userGuess , solGlob) #check to see if they are right or not

                if boolean == True : #if the user is correct, tell them they are correct and inrement the variable correctAnswers by 1

                    print('You are correct\n')

                    questionNum += 1

                    boolean = True #will break out of the loop because now the user is correct

                else :
                    

                    if guessNum >= 3 : #if the user guesses wrong 3 times

                        print(rightAnswer(solGlob , userGuess) , '\n') #output the correct answer and their wrong answer
                        
                        questionNum += 1 #increment the number of questions they have answered by 1

                        boolean = True #will break out of the loop because now the user is correct
                          

    print('You got %d out of 5' % correctAnswers) #outputs their score out of 5
    print('That\'s' , ((correctAnswers / 5) * 100) , '%') #outputs their score as a percentage

    playAgainVar = input('Do you want to play again? Y to continue, N to quit ==>') #prompt the user if they want to play again




    while True : #will keep prompting the user to enter in 'Y' or 'N' if their input is neither 'Y' or 'N'
        if playAgainVar == 'Y' :
            break
        elif playAgainVar == 'N' :
            break
        else :
            playAgainVar = input('Y to continue, N to quit ==>')



            

    playAgainVar = playAgain(playAgainVar) #if the user enters N, assigns playAgainVar to False, and True if they input Y


                    
            
            
            






    
    

    
    
    
    

    

    
