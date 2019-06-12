
'''
Jonathan Benson
Program 7
CS101
'''

import random


class Bacteria :


    def __init__(self , resistance = 3) :
        '''Constructor for the Bacteria class'''

        self.health = 10
        self.resistance = resistance
        self.life_span = 15
        self.birth_counter = 3


    def __str__(self) :
        '''Returns the health, resistance, life span and birth counter of a singular bacterium'''

        return 'H({})\tR({})\tLS({})\tBC({})'.format(self.health , self.resistance , self.life_span , self.birth_counter)


    def is_alive(self) :
        '''Returns True if the bacterium is alive, else false'''


        #the bacterium is alive if its health and life span are greater than 0
        
        return True if (self.health > 0) and (self.life_span > 0) else False


    def tick(self) :
        '''Decrements a bacterium's birth counter and life span by 1'''

        self.birth_counter -= 1
        self.life_span -= 1



    def dose(self , dosage = 25) :
        '''Doses a bacterium'''

        #a dose decrements a bacterium's health by the dosage amount times 1 over the resistance
        damage = dosage * (1 / self.resistance)

        self.health -= damage


    def get_reproduction(self) :
        '''Gets a new bacterium with a mutated resistance within the range of 1 to 10'''

        while True :

            mutation = random.randint(-1,1)

            new_bacteria = Bacteria(self.resistance + mutation)
            
            #the new bacterium's resistance must be in the range of 1 to 10
            if (new_bacteria.resistance > 10) or (new_bacteria.resistance < 1) :

                continue

            return new_bacteria


    def reproduce(self) :
        '''Checks if a bacterium has the ability to reproduce and returns either a new bacterium or None'''

        #the bacterium must be alive and its birth counter less than 0 for it to be able to reproduce
        if (self.is_alive() == True) and (self.birth_counter <= 0) :

            self.birth_counter = 3 #reset its birth counter if it reproduces

            return self.get_reproduction()








class Host :


    def __init__(self , host_id , num_bacteria) :
        '''Constructor for the Host class'''

        self.id = host_id

        self.bacterial = [Bacteria() for iteration in range(num_bacteria)]
        
        self.bacteria_count = len(self.bacterial)


    def get_avg_health(self) :
        '''Calculates and returns the average health of the bacteria within the host'''


        health_sum = 0

        for bacteria in self.bacterial : #iterate through the bacteria in the host

            health_sum += bacteria.health #increment the sum of all health of the bacteria

        avg_health = health_sum / len(self.bacterial) #calculate the average health of the bacteria

        return avg_health


    

    def get_avg_resistance(self) :
        '''Calculates and returns the average resistance of the bacteria in the host'''

        resistance_sum = 0

        for bacteria in self.bacterial : #iterate through the bacteria in the host

            resistance_sum += bacteria.resistance #increment the sum of all resistance of the bacteria

        avg_resistance = resistance_sum / len(self.bacterial) #calculate the average resistance of the bacteria

        return avg_resistance
    
        

    def __str__(self) :
        '''Outputs to the shell the number of bacteria in the host, as well as their average health and reistance'''

        count = len(self.bacterial)

        if count > 0 :
            
            avg_health = self.get_avg_health()
            avg_resistance = self.get_avg_resistance()

        else : #if there is no bacteria within the host, output na for their health and resistance

            avg_health = 'na'
            avg_resistance = 'na'
        

        return 'Count : {}\nAverage Health : {}\nAverage Resistance : {}'.format(count , avg_health , avg_resistance)


    def dose_all(self) :
        '''Doses the bacteria within the host'''

        for bacteria in self.bacterial :

            bacteria.dose()

            

    def tick(self , with_dose) :
        '''something'''

        #dose all of the bacteria if they need to be dosed
        if with_dose == True :

            self.dose_all()

        
        for bacteria in self.bacterial[:] :

            bacteria.tick()

            if bacteria.is_alive() == False :

                self.bacterial.remove(bacteria)

            else :

                new_bacteria = bacteria.reproduce()

                if new_bacteria != None :

                    self.bacterial.append(new_bacteria)




#initialize each host
hosts = [Host(i , 1) for i in range(1,4)]


for host in hosts :
    
    #all hosts undergo 30 ticks with no dose initially
    for tick in range(30) :

        host.tick(False)



    #the first host undergoes 15 extra ticks with no dose
    if host.id == 1 :

        for tick in range(15) :

            host.tick(False)

        #output to the shell the first host's bacteria count, avg resistance and avg health
        print('No dosage')
        print(host)


    #the second host undergoes 15 extra ticks with a dose on each tick
    elif host.id == 2 :

        for tick in range(15) :

            host.tick(True)

        #output to the shell the second host's bacteria count, avg resistance and avg health
        print('\nFull dosage')
        print(host)



    #the third host undergoes 15 extra ticks with a dose on every other tick
    elif host.id == 3 :
        
        for tick in range(15) :

            if tick % 2 == 0 :

                host.tick(True)

            else :

                host.tick(False)

        #output to the shell the third host's bacteria count, avg resistance and avg health
        print('\nHalf dosed')
        print(host)








        
