
            
'''
Jonathan Benson
CS101L
Lab 12
'''


def getReadStream() :
    '''gets and returns a valid input file stream from the user'''

    while True :

        try : #get a file name from the user and open the file

            readFileLoc = input('Enter the name of the file to open ==> ')

            readStreamLoc = open(readFileLoc , 'r')

            return readStreamLoc

        except FileNotFoundError : #output an error message if the user's inputted file cannot be found in the current directory

            print('Could not open the file {}'.format(readFileLoc))



def extractCleanWords(readLinesLoc) :
    '''extracts and cleanly formats all the words from a list of lines and appends all the words to a list'''

    cleanWordsLoc = []

    for line in readLinesLoc :

        lineRawWords = line.split(' ')
        

        for rawWord in lineRawWords : #rewrite every word into a clean version
            
            cleanWord = ''
            

            for char in rawWord : #do not include any character that is not a letter in the rewritten word

                if (char.isalpha() == True) or (char == '-') :

                    cleanWord += char.lower()


            if len(cleanWord) > 3 : #only include the words greater than 3 characters in length in the counting
                
                cleanWordsLoc.append(cleanWord)

    
    return cleanWordsLoc





def constWordCountsDict(cleanWordsLoc) :
    '''constructs and returns a dictionary with word:count as key value pairs'''

    wordCountDictLoc = {}
    
    for word in cleanWordsLoc :

        try : 

            wordCountDictLoc[word] += 1 #if the word already exists in the dictionary, increment its count by one

        except KeyError :

            wordCountDictLoc[word] = 1 #if the word does not already exist in the dictionary, add it and set its count equal to one


    return wordCountDictLoc




def sortWordCounts(wordCountsDictLoc) :
    '''sorts the dictionary containing the words and the count of each word by the count'''

    #add all the word:count pairs in the dictionary as lists to a list to enable sorting
    wordCounts = [[word , count] for word , count in wordCountsDictLoc.items()] 

    #sort the newly created list of word counts by the counts in reverse order
    sortedWordCountsLoc = sorted(wordCounts , key = lambda x : x[1] , reverse = True)

    return sortedWordCountsLoc





def getNumUniqueWords(cleanWordsLoc) :
    '''gets and returns the number of unique words in the document'''

    return len(set(cleanWordsLoc)) #pass the list of clean words to a set constructor and return the length of that set





def getNumWordsOneOccurance(sortedWordCountsLoc) :
    '''counts the number of unique words with a length greater than 3'''

    
    #append all the words that have a count of 1 to a list of words with one occurance
    wordsOneOccurance = [wordCount[0] for wordCount in sortedWordCountsLoc if wordCount[1] == 1]
    

    return len(wordsOneOccurance)





def shellOutput(sortedWordCountsLoc , numWordsOneOccuranceLoc , numUniqueWordsLoc) :
    '''outputs to the shell the 10 most frequently used words, number of words that only occur once, and number of unique words'''


    print(


        'Most frequently used words\n' ,
        '{:<5}{:>15}{:>10}'.format('#' , 'Word' , 'Freq.') ,
        '='*30 ,

        sep = '\n' ,
        end = '\n'

        )
    

    for index , (word , count) in enumerate(sortedWordCountsLoc[:11]) :

        num = index + 1
        
        print('{:<5}{:>15}{:>10}'.format(num , word , count))

    

    print('\nThere are {} words that occur only once'.format(numWordsOneOccuranceLoc))
    print('There are {} unique words in the document\n'.format(numUniqueWordsLoc))





with getReadStream() as readStream :
    

    readLines = readStream.readlines()

    cleanWords = extractCleanWords(readLines) #extract and format all the words for analysis

    wordCountsDict = constWordCountsDict(cleanWords) #count all the words and add the word and their counts to a dictionary as key value pairs respectively

    sortedWordCounts = sortWordCounts(wordCountsDict) #take all the word count pairs in the dictionary and append them to a list for sorting

    numWordsOneOccurance = getNumWordsOneOccurance(sortedWordCounts) #count the number of words that only have one occurance from the list of word counts

    numUniqueWords = getNumUniqueWords(cleanWords) #count the number of unique words from the list of clean words

    

    shellOutput(sortedWordCounts , numWordsOneOccurance , numUniqueWords) #output all of the data

    
    
    




