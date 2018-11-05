from PIL import Image, ImageDraw
import random

#In this 'challenge', we shall use python to create the image. It is easier to do, and it also will allow me to dust up on python since I have not used it since Luigi's Poker. That was a while ago.

IMAGESIZE = 200

image = Image.new('RGB',(IMAGESIZE,IMAGESIZE))
draw = ImageDraw.Draw(image)

random.seed(None)

for x in range(0, IMAGESIZE):
	for y in range(0, IMAGESIZE):
		#the color variable is a 3-tuple object which is randomized upon each iteration
		#had to crack up Wikipedia for this one
		#In mathematics, a tuple is a finite ordered list (sequence) of elements. - Wikipedia
		#In Laymans terms, it is a ordered list.
		color = (random.randint(0,255),random.randint(0,255),random.randint(0,255))
		draw.point((x,y),color)

image.save("random.png")