
import random


def genRandWord(lengthPara) :

    alphabet = 'abcdefghijklmnopqrstuvwxyz'

    vowels = 'aeiou'
    cons = 'bcdfghjklmnpqrstvwzxyz'

    randWord = ''


    index = 0
    
    for randChar in range(lengthPara) :

        if len(randWord) == 0 :

            randWord += random.choice(cons)

        elif len(randWord) > 0 :

            faceGlob = coinFlip()

            if faceGlob == '0' : 

                if randWord[index - 1] in cons :

                    randWord += random.choice(vowels)
                else :
                    randWord += random.choice(cons)

            else :

                randWord += random.choice(alphabet)

        index += 1



    return randWord



def coinFlip() :
    '''returns a random bool'''

    nums = ['0' , '1']

    face = random.choice(nums)

    return face



length = int(input('Length: '))
howMany = int(input('How many: '))

for randomWord in range(howMany) :
    print(genRandWord(length))
