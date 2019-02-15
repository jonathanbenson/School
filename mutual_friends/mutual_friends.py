'''
Jonathan Benson
Lab 11
'''

def extractFriends(linesLoc) :
    '''extracts each friend-pair and appends them as tuples (friend1 , friend2) to a list'''

    friendsListLoc = [] #this list will contain each friend-pair as a nested tuple

    for line in linesLoc :

        line = line.strip().split(' ')

        friendsListLoc.append((line[0] , line[1])) #append a tuple containing both names to the list of friend-pair tuples

    return friendsListLoc




def constructNameFriends(friendsListLoc) :
    '''constructs a dictionary with each person and all their friends as keys, values respectively'''

    nameFriendsLoc = {} #this dictionary will contain each person and all of their friends as keys, values respectively

    for friendOne , friendTwo in friendsListLoc :

        if friendOne not in nameFriendsLoc :

            nameFriendsLoc[friendOne] = set() #create a new key value pair for that friend with an empty set as its value
            nameFriendsLoc[friendOne].add(friendTwo) #add their current friend to the new empty set paired to them

        else :

            nameFriendsLoc[friendOne].add(friendTwo)
            

        if friendTwo not in nameFriendsLoc : #do the same thing for the second friend in the tuple

            nameFriendsLoc[friendTwo] = set()
            nameFriendsLoc[friendTwo].add(friendOne)

        else :

            nameFriendsLoc[friendTwo].add(friendOne)



    return nameFriendsLoc
    


def printMenu():
    '''prints a menu with options'''

    print(

        'Social Network\n' ,
        'I. Find all friends shared by 2 people' ,
        'D. Find all friends of X, that person Y does not have.' ,
        'S. Find all friends that X and Y have, but do not share with each other.' ,
        'Q. Quit.\n' ,

        end = '\n' ,
        sep = '\n'

        )


def getValidOption() :
    '''prints a menu of all the options and returns a valid input'''

    

    while True :

        options = 'IDSQ'

        #if user input is not a valid option from the menu, output an error message and reprompt
        try :

            userInput = input('==> ').upper()

            if userInput not in options :

                raise Exception

            break

        except Exception :

            print('{} is not a valid option.'.format(userInput))


    print()

        


    return userInput



def getValidPerson() :
    '''gets and returns a valid name from the user'''

    while True :

        #if the name the user enters is not in the dictionary containing all of the people, output an error message and reprompt
        try :

            person = input('Enter a valid person ==> ')

            if person not in nameFriends :

                raise Exception

            return person

        except Exception :

            print('{} is not part of this network, enter another name.'.format(person))
            


    


def intersection(x , y) :
    '''returns all friends shared by two people's friends x and y'''

    return x.intersection(y)
    

def difference(x , y) :
    '''returns all friends of x, that person y does not have'''

    return x.difference(y)

def sd(x , y) :
    '''returns all friends that x and y have, but do not share with each other'''


    return x.symmetric_difference(y)






def functionCall(userInput) :
    '''calls the function based on the user's input and returns what that function returns'''


    if userInput == 'I' : #if the user input is 'I', call the intersection function and print the result

        a , b = getValidPerson() , getValidPerson()

        intersectionPeople = intersection(nameFriends[a] , nameFriends[b])

        print('{} and {} share these people.'.format(a,b))
        print('\n'.join(intersectionPeople) , end = '\n')
        
    elif userInput == 'D' : #if the user input is 'D', call the difference function from above and print the result

        a , b = getValidPerson() , getValidPerson()

        differencePeople = difference(nameFriends[a] , nameFriends[b])

        print('These people are friends with {} but not with {}.'.format(a,b))
        print('\n'.join(differencePeople) , end = '\n')

    elif userInput == 'S' : #if the user input is 'S', call the symmetric difference function from above and print the result

        a , b = getValidPerson() , getValidPerson()

        sdPeople = sd(nameFriends[a] , nameFriends[b])
        
        print('These people are friends with {} and {}, but not both.'.format(a,b))
        print('\n'.join(sdPeople) , end = '\n')
        

    elif userInput == 'Q' : #if the user input is 'Q', return False to signify the user wants to quit (will come into play later in the program)

        return False

    
    


with open('friends.txt' , 'r') as readStream :


    lines = readStream.readlines()
    
    friendsList = extractFriends(lines) #extract all the friend-pairs and append them to a list contained in a tuple for each


    #construct a dictionary with the keys as each person (unique) pairded to a set of all their friends
    nameFriends = constructNameFriends(friendsList)
    

    while True : #will execute code block until a person enters 'q' or 'Q' to signify they want to quit

        printMenu()

        call = functionCall(getValidOption()) #call the function depending on the what the user has inputted
        

        if call == False : #functionCall will return False if the user has entered 'q' signifying that the user wants to end the program

            break

        



print('Goodbye.') #output 'Goodbye.' signiying the program as ended


# checked the execution
        
