

'''
Jonathan Benson
Lab 14
CS101L
'''

import turtle


class Point(object) :

    def __init__(self , x , y , color) :
        '''Constructor of class Point'''

        self.x = x
        self.y = y
        self.color = color

    def draw(self) :
        '''draws a point at the point's x and y coordinates'''

        turtle.penup()
        turtle.goto(self.x , self.y)
        turtle.pendown()
        turtle.color(self.color)
        turtle.setheading(0)
        self.draw_action()

    def draw_action(self) :
        '''draws a single point and the current pen poisition'''

        turtle.dot()


class Box(Point) :
    '''The Box class inherits from the Point class'''
     
    def __init__(self , x , y , length , width , color) :
        '''Constructor for the Box class'''

        Point.__init__(self , x , y , color) #call the constructor of the Point class to get the starting position

        self.length = length
        self.width = width

    def draw_action(self) :
        '''draws a box at the current position'''

        for iteration in range(2) :
            turtle.forward(self.length)
            turtle.left(90)
            turtle.forward(self.width)
            turtle.left(90)
        

class BoxFilled(Box) :
    '''The BoxFilled class inherits from both the Box and Point classes'''

    def __init__(self , x , y , length , width , color , fill_color) :
        '''Constructor for the BoxFilled class'''

        Box.__init__(self , x , y , length , width , color)

        self.color_fill = fill_color

    def draw_action(self) :
        '''Draws a filled box at the current pen position'''

        
        turtle.fillcolor(self.color_fill)
        turtle.begin_fill()
        Box.draw_action(self)
        turtle.end_fill()


   
class Circle(Point) :
    '''The Circle class inherits from the Point class'''

    def __init__(self , x , y , radius , color , extent = 360) :
        '''A constructor for the Circle class'''

        Point.__init__(self , x , y , color)

        self.radius = radius
        self.extent = 360
        

    def draw_action(self) :
        '''draws a circle at the current pen position'''

        turtle.circle(self.radius , extent = self.extent)



class CircleFilled(Circle) :
    '''The CircleFilled class inherits both from the Circle and Point class'''

    def __init__(self , x , y , radius , color , fill_color) :
        '''A constructor for the CircleFilled class'''

        Circle.__init__(self , x , y , radius , color)

        self.fill_color = fill_color


    def draw_action(self) :
        '''draws a filled circle at the current pen position'''

        turtle.fillcolor(self.fill_color)
        turtle.begin_fill()
        Circle.draw_action(self)
        turtle.end_fill()

        


#draw a red point at the coordinates (-350,300)
p = Point(-350 , 300 , 'red')
p.draw()

#draw a blue box with a length of 200 and width of 100 at the coordinates (-350,200)
b1 = Box(-350,200,100,50,'blue')
b1.draw()

#draw a blue box filled red with a length of 200 and width of 75 at the coordinates (-350,100)
b2 = BoxFilled(-350,100,200,75,'blue','red')
b2.draw()

#draw a green circle with a radius of 50 at the coordinates (-300,-50)
c1 = Circle(-300,-50,50,'green')
c1.draw()

#draw a black circle filled yellow with a radius of 30 at the coordinates (-300,-200)
c2 = CircleFilled(-300,-200,30,'black' , 'yellow')
c2.draw()











