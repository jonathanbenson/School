'''
Jonathan Benson
CS101
Program 5
'''



import os


def getRead() :
    '''gets and returns a valid file name and stream containing sunspot data from user's input.'''

    

    while True :

        try : #get an input file from the user and create a connection to it so its contents can be extracted

            readFileLoc = input('Enter file with input data. ==> ')

            readStreamLoc = open(readFileLoc , 'r')

            return (readFileLoc , readStreamLoc)


        except FileNotFoundError : #print an error message if the file the user inputted cannot be opened

            print(

                'The file \'{}\' does not exist in the current working directory'.format(readFileLoc) ,
                '==> \'{}\''.format(os.getcwd()) ,

                sep = '\n' ,
                end = '\n\n'

                )



def getWrites():
    '''gets and returns a valid read file name and stream from user's input.'''


    nums = ('first' , 'second')

    writeStreamsLoc = []
    writeFilesLoc = []


    for num in nums : #get two output files from the user
    
        while True :

            try :

                if num == 'first' : #execute for getting the first output file

                    writeFileLoc = input('Please enter the {} file that will contain the monthly total sunspot data. ==> '.format(num))

                else : #execute code block for getting the second output file

                    writeFileLoc = input('Please enter the {} file that will contain the monthly smoothed data. ==> '.format(num))

                
                
                writeStreamLoc = open(writeFileLoc , 'w')
                

                writeFilesLoc.append(writeFileLoc)
                writeStreamsLoc.append(writeStreamLoc)

                break


            except IOError : #if a file the user inputted cannot be opened or created, output an error message


                print(

                'The file \'{}\' cannot be opened or created within the directory'.format(writeFileLoc) ,
                '==> \'{}\''.format(os.getcwd()) ,

                sep = '\n' ,
                end = '\n\n'

                )

        



    return writeFilesLoc , writeStreamsLoc #first list will contain the output file names, and the second list will contain the output file streams





def extractYMDS(readLinesLoc) :
    '''extracts the year, month, day, and number of sunspots for that day, and appends all of them as lists to a list'''

    ymdsLoc = []

    for line in readLinesLoc :

        sl = line.split(',')


        ymdsLoc.append(

            (sl[0] , sl[1] , sl[2] , sl[4])

            )

        
    
    return ymdsLoc



def interpretDP(value) :
    '''a data point will be interpreted and returned as 0 if it is represented as a non-number value or -1 in the data, else the original value'''

    try :

        dpLoc = int(value)

        if dpLoc == -1 :

            raise ValueError

        return dpLoc

    except ValueError :

        return 0



def constructYMS(ymdsLoc) :
    '''converts the list 'ymds' into a list 'yms' containing nested lists [year , month, total number of sunspots observed that month]'''

    #ymdsDict will become a nested dictionary in the format {year: {month:sunspots , ...} }
    #where sunspots is the total number of sunspots observed that month
    ymdsDict = {}


    for ymds in ymdsLoc :

        
        year , month , day , sunspots = [interpretDP(dp) for dp in ymds]
        
            
        #summing the total number of sunspots for each month of each year
        
        if year not in ymdsDict :

            ymdsDict[year] = {month:sunspots}

        else :
            

            if month not in ymdsDict[year] :

                ymdsDict[year][month] = sunspots


            else :

                ymdsDict[year][month] += sunspots



    #using the dictionary 'ymsDict' above, construct a list of nested lists containing the year, month, number of sunspots for that month
    ymsLoc = []

    for year , monthSunspots in ymdsDict.items() :

        for month , sunspots in monthSunspots.items() :

            ymsLoc.append([year , month , sunspots])




    return ymsLoc




def constructYMSSmoothed(ymsLoc) :
    '''construct and return a list of lists [[year, month, smoothed data for that month], ...]'''

    ymsSmoothedLoc = []


    for index , (year , month , sunspots) in enumerate(ymsLoc[6:-7]) : #7th element to the element 7 elements from the end

        index += 6  #starts at index of 6 (7th element)


        #smoothed data for example m7 (seventh month) : ( 0.5m1 + m2 + m3 ... m11 + m12 + 0.5m13 ) / 12
        sunspotsSmoothed = (

            (
                ((ymsLoc[index - 6][2]) / 2) +
                (ymsLoc[index - 5][2]) +
                (ymsLoc[index - 4][2]) +
                (ymsLoc[index - 3][2]) +
                (ymsLoc[index - 2][2]) +
                (ymsLoc[index - 1][2]) +
                (ymsLoc[index][2]) +
                (ymsLoc[index + 1][2]) +
                (ymsLoc[index + 2][2]) +
                (ymsLoc[index + 3][2]) +
                (ymsLoc[index + 4][2]) +
                (ymsLoc[index + 5][2]) +
                ((ymsLoc[index + 6][2]) / 2)

                ) / 12

            )

        
        
        ymsSmoothedLoc.append([year , month , sunspotsSmoothed])


        

    return ymsSmoothedLoc






def constructWriteLinesOne(ymsLoc) :
    '''generate a list of all the lines to output to the first write file given a nested list of lists: [[year, month, number of sunspots that month], ...]'''

    writeLinesOneLoc = []
    
    #each line of the first output file will be year,month,number of sunspots that month
    for year , month , sunspots in ymsLoc :

        writeLinesOneLoc.append('{},{},{}\n'.format(year , month , sunspots))

    
    return writeLinesOneLoc






def constructWriteLinesTwo(ymsSmoothedLoc) :
    '''generate a list containing all the lines to output to the first write file given a list of lists: [[year, month, smoothed data for that month] , ...]'''

    writeLinesTwoLoc = []

    
    #each line of the second output file will be year,month,smoothed data for that month
    for year , month , sunspotsSmoothed in ymsSmoothedLoc :

        writeLinesTwoLoc.append('{},{},{}\n'.format(year , month , sunspotsSmoothed))


    return writeLinesTwoLoc






def printExecution(readFileLoc , writeFileOneLoc , writeFileTwoLoc) :
    '''outputs to the user what the program as executed'''

    print(
        '' ,
        'Extracted data from \'{}\' in the directory:'.format(readFileLoc) ,
        '==> \'{}\''.format(os.getcwd()) ,
        '' ,
        'Outputted monthly total sunspots data to the file \'{}\' and monthly smoothed data to the file \'{}\' both to the directory:'.format(writeFileOneLoc , writeFileTwoLoc) ,
        '==> {}'.format(os.getcwd()) ,

        sep = '\n' ,
        end = '\n'

        )



#main

#get the both the input file's and output files' names and streams
readFile , readStream = getRead()
writeFiles , writeStreams = getWrites()

writeFileOne , writeFileTwo = writeFiles
writeStreamOne , writeStreamTwo = writeStreams



#get a list of all of the lines of the input file
readLines = readStream.readlines()


#ymds is a list containing nested lists each containing year, month, day, number of sunspots (that day) in order
ymds = extractYMDS(readLines)

#yms is a list containing nested lists each containing year, month, total number of sunspots (that month) in order
yms = constructYMS(ymds)

#ymsSmoothed is a list containing nested lists each containing year, month, smoothed data (for that month) in order
ymsSmoothed = constructYMSSmoothed(yms)

#construct a list of lines for each output file
writeLinesOne = constructWriteLinesOne(yms)
writeLinesTwo = constructWriteLinesTwo(ymsSmoothed)

#output normal data and smoothed data to their respected output files
writeStreamOne.writelines(writeLinesOne)
writeStreamTwo.writelines(writeLinesTwo)

#prints the program's execution to the shell
printExecution(readFile , writeFileOne , writeFileTwo)


#close all file streams at the end of the program
readStream.close()
writeStreamOne.close()
writeStreamTwo.close()



