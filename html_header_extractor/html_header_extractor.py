
'''
Jonathan Benson
Program 4
CS101
'''

import os #import the os module



def getReadStream() :
    '''gets and returns a valid read file name and read file stream from the user'''

    while True :

        try : #execute code block until an error is raised

            userInput = input('Please enter a valid file to read from. ==> ') #get the name of the file to read from the user

            readStreamLoc = open(userInput , 'r') #create a file stream to their read file

            print()

            break

        except FileNotFoundError : #if the file does not exist, output an error message

            print('FileNotFoundError')
            print('The file \'{}\' does not exist in the directory: \'{}\'.'.format(userInput , os.getcwd()))

    
    return userInput , readStreamLoc



    

def getWriteStream() :
    '''gets and returns a valid write file name and write file stream from the user'''

    while True :

        try :

            userInput = input('Please enter a valid file to write to. ==> ') #get the file to output to from the user

            writeStreamLoc = open(userInput , 'w') #create a file stream for the write file

            print()


            break
            

        except IOError : #if the file cannot be created or overriden, then output an error message

            print('IOError')
            print('The file \'{}\' either does not exist or cannot be created within the directory: \'{}\'.'.format(userInput , os.getcwd()))

        



    return userInput , writeStreamLoc




def extractHeaders(rLinesLoc) :
    '''extracts all the lines of the read file that are header tags and appends them to a list'''

    headersLoc = []
    
    for rLineLoc in rLinesLoc : #for each line in the read file


        #if the first two characters in the line are '<h' and the third character is a digit, then the line contains a header
        if (rLineLoc[:2] == '<h') and (rLineLoc[2].isdigit() == True) :

            headersLoc.append(rLineLoc) #append that line containing a header to a list

            

    return headersLoc #a list containing all the lines of the read file containing headers




def genWLines(headersLoc) :
    '''generates all the lines of the write file in the correct format and appends them to a list of write lines'''



    wLinesLoc = [] #wLines -> a list of all the write lines (each write line corrosponding to a header of the html file)


    for headerLoc in headersLoc : #for each write line in the list of write lines

        wLineLoc = '*' + headerLoc[4:-6] + '\n'

        

        if int(headerLoc[2]) > 1 : #inserting tabs based on size of header for each write line

            wLineLoc = wLineLoc.split() #convert each line (string) into a list so its characters can be modified

            wLineLoc.insert(0 , '\t' * (int(headerLoc[2]) - 1)) #insert number of tabs minus one times the size of the header

            wLineLoc = ''.join(wLineLoc) + '\n' #convert the line back into a string

                

        wLinesLoc.append(wLineLoc) #append each correctly formatted line into a list containing all the lines of the write file


    return wLinesLoc #return a list containing all the lines to be outputted to the write file




def displayExecution(readFileLoc , writeFileLoc) :
    '''displays visually what happened in the program'''

    writePath = (os.getcwd() + r'{}'.format(os.path.sep) + writeFileLoc) #constructing the file path of the write file via concatenation

    readPath = (os.getcwd() + r'{}'.format(os.path.sep) + readFileLoc) #constructing the file path of the read file via concatenation


    #outputting the executions the program has made to the shell
    print(
        '''

        {}

        ==> '{}'


        {}

        ==> '{}'


        '''.format(

            'Extracted all information contained within header tags from the file:' ,

            readPath ,

            '...and outputted them to the file:' ,

            writePath


            )

        )


    
    

def getRunAgain() :
    '''prompts the user if they want to run the program again or not, returns True or False'''


    while True :

        userInput = input('( Y ) to run again. ( N ) to quit. ==> ') #getting user input


        #if the user inputs a 'y', upper or lower, then they want to run the program again
        if userInput.upper() == 'Y' :

            return True

        #if the user inputs a 'n', upper or lower, then they want to stop the program        
        elif userInput.upper() == 'N' :

            return False

        #if the user inputs anything else besides 'y' or 'n', output that they have entered invalid input
        else :

            print('Invalid input.' , end = '\n')



            


#source code
            
runAgain = True #a check to run the program again or not, dependant on user input later in the code

while runAgain :

    #getting and assigning both file names and file streams
    readFile , readStream = getReadStream()
    writeFile , writeStream = getWriteStream()


    rLines = readStream.readlines() #append all the lines of the read file to a list as strings


    headers = extractHeaders(rLines) #extract all lines from the read file containing a header and append them to a list

    wLines = genWLines(headers) #format all the lines of the write file correctly based on the header they each contain


    writeStream.writelines(wLines) #output all the write lines to the write file



    displayExecution(readFile , writeFile) #output to the shell the what the program has executed


    #close both file streams
    readStream.close()
    writeStream.close()


    runAgain = getRunAgain() #prompt the user whether or not they want to run the program again


print('Goodbye.') #will output 'Goodbye.' to the shell if the program has ended







    

