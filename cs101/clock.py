
'''
Jonathan Benson
CS101L
Lab 13
'''


import time


def getHMS() :
    '''gets and returns a valid hour, minute, and second from the user and returns them all in a list'''

    hms = ['hour' , 'minute' , 'second']

    returnHMS = [] #a list that will contain the hour, minute, and second
    
    for element in hms :

        while True :

            try :

                userInput = int(input('What is the current {} ==>'.format(element)))

                if element == 'minute' or element == 'second' :

                    if (userInput < 0) or (userInput > 59) : #the minute and second cannot be out of the range of 0-59

                        raise TypeError
                    
                else :

                    if (userInput < 0) or (userInput > 23) : #the hour cannot be out of the range of 0-23

                        raise Exception

                break 


            
            except ValueError : #handles exception if the user enters anything other than a number

                print('The {} must be a number'.format(element))
                

            except TypeError : #handles minute and second range exception

                print('The {} must be greater than 0 and less than 59'.format(element))


            except Exception : #handles hour range exception

                print('The {} must be greater than 0 and less than 24'.format(element))


        returnHMS.append(userInput)


    return returnHMS

            



class Clock :

    def __init__(self , hour = 0 , minute = 0 , second = 0) :
        '''a constructor for the clock'''

        self.hour = hour
        self.minute = minute
        self.second = second


    def __str__(self) :
        '''a Clock method for printing out the clock in the form of "hour:minute:second am/pm"'''

        if self.hour > 11 : #if the hour is greater than 11, then it is pm and minus 12 to convert it to a 12 hour clock
            
            hour = self.hour - 12
            ampm = 'pm'

            if hour == 0 :

                hour = 12

        elif self.hour == 0 : #if the hour is 0, then it is midnight which is 12 A.M.

            hour = 12
            ampm = 'am'

        else : #if the hour is within the range of 1-12, it is am
            
            hour = self.hour
            ampm = 'am'
        

        return '{:02}:{:02}:{:02} {}'.format(hour , self.minute , self.second , ampm)

        


    def tick(self) :
        '''a Clock method that increments the second, minute, or hour, depending on conditions'''

        
        if (self.second == 59) and (self.minute == 59) and (self.hour == 23) :

            self.second = 0
            self.minute = 0
            self.hour = 0
            
        elif (self.second == 59) and (self.minute == 59) :

            self.second = 0
            self.minute = 0
            self.hour += 1

        elif (self.second == 59) :

            self.second = 0
            self.minute += 1

        else :

            self.second += 1

        

            




clock = Clock() #create a Clock object

clock.hour , clock.minute , clock.second = getHMS() #get the hour, minute, and second for the time

while True :

    print(clock) #output the time

    clock.tick() #increment a second

    time.sleep(1) #wait one second

    
