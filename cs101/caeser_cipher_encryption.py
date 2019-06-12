
            



            
def makeover(stringLoc) :
    '''performs a makeover (makes all letters uppercase) on the user's raw input given the string'''

    stringLoc = stringLoc.upper()
    

    return stringLoc







def encrypt(stringLoc , shiftLoc) :
    '''encrypts a string by the desired shift given the string and the desired shift'''

    duplicates = 3

    if shiftLoc >= 26 :

        duplicates *= (shiftLoc // 26)

    
    

    letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' * duplicates

    stringEncryptedLoc = ''

    

    for character in stringLoc :

        if character not in letters : #if the character in the string is anything other than a letter, concatenate it to the encrypted string

            stringEncryptedLoc += character

        else : #if the character in the string is a letter, concatenate a letter shifted 'shiftLoc' letters

            stringEncryptedLoc += letters[letters.find(character , (duplicates // 2)) + shiftLoc]
    

    return stringEncryptedLoc #returns the encrypted string





def decrypt(stringLoc , shiftLoc) :
    '''decrypts a string by the desired shift given a string and the desired shift'''

    duplicates = 3 #number of alphabet duplicates needed in order to compensate for wrapping (example Z becomes A). Default is 3

    if shiftLoc >= 26 : #if the desired shift is greater than 26, multiply the duplicates by the number of shifts divided by the letters in the alphabet (26)

        duplicates *= (shiftLoc // 26)

    

    letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' * duplicates

    stringDecryptedLoc = ''
    

    for character in stringLoc :

        if character not in letters : #if the character in the string is anything other than a letter, concatenate it to the decrypted string

            stringDecryptedLoc += character

        else : #if the character in the string is a letter, concatenate a letter shifted back 'shiftLoc' letters

            stringDecryptedLoc += letters[letters.find(character , ((duplicates // 2) + 1)) - shiftLoc]

        
    

    return stringDecryptedLoc #returns a decypted string

    

    



while True :

    print(

        '\nMAIN MENU\n'
        '1) Encode a string\n'
        '2) Decode a string\n'
        'Q) Quit\n'
        'Enter your selection ==> '
        
        , end = '')

    selection = input().upper().strip() #get user's selection, make all letters upper case, strip all proceeding and trailing whitespace

    


    

    validSelection = ('1' , '2' , 'Q')

    while selection not in validSelection : #keep prompting the user everytime they enter an invalid selection
        selection = input('Enter your seleciton ==> ')

    


        
    if selection == 'Q' : #if the user enters Q, then they want to quit so end the program

        break

    else :

        

        if selection == '1' : #if the user enters 1, then they want to encrypt a string

            rawInput = input('\nEnter (brief) text to encrypt: ')

            string = makeover(rawInput) #make all the letters uppercase



            

            shift = input('Enter the number to shift letters by: ') #get the desired shift from the user
            shift = int(shift) #convert the user's input into an integer


            
            stringEncrypted = encrypt(string , shift) #encrypt() should return an encrypted string based on user's string and the desired shift

            print('Encrypted: {}'.format(stringEncrypted)) #output the encrypted string

            


            
            

        elif selection == '2' : #if the user enters 2, then they want to decrypt a string

            rawInput = input('\nEnter (brief) text to decrypt: ') #get a raw input from the user

            string = makeover(rawInput) #make all the letters uppercase



            

            shift = input('Enter the number to shift letters by: ') #get the desired shift from the user
            shift = int(shift) #convert the user's input into an integer

            stringDecrypted = decrypt(string , shift) #decrypt() should return a decrypted string based on user's string and the desired shift

            print('Decrypted: {}'.format(stringDecrypted)) #output the decrypted string



           # Execution checked -Pragathi thammaneni 

            
            

            


    

