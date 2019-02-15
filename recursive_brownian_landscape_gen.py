

import random
from PIL import Image , ImageDraw


x = 1000
y = 1000
tot = 1000

image = Image.new('RGB' , (x,y) , color = 'white')

draw = ImageDraw.Draw(image)


points = {}

def recursion(x , y , divider = 1 , count = 0) :

    

    if tot / divider < 1 :

        print('Done')

    else :

        for x_box in range(0 , tot , int(tot / divider)) :

            for y_box in range(0 , tot , int(tot / divider)) :

                rand = random.randint(-2,2)

                for x in range(x_box , x_box + (int(tot / divider)) + 1) :

                    for y in range(y_box , y_box + (int(tot / divider)) + 1) :

                        try :

                            points[(x,y)] = [n + rand for n in points[(x,y)]]

                        except KeyError :

                            points[(x,y)] = [150,150,150]

                

        return recursion(x , y , divider * 2 , count + 1)

                

    

recursion(x,y,1)

            

    
        
for point in points :

    draw.point(tuple(point) , tuple(points[tuple(point)]))




image.save('brownianland.bmp')
image.show()






