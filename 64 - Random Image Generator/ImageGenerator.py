#my professor told me to write a comment on each
from PIL import Image, ImageDraw
#statement. I don't know why though.
import random

#In this 'challenge', we shall use python to create the image. It is easier to do, and it also will allow me to dust up on python since I have not used it since Luigi's Poker. That was a while ago.

#make the image random upon each successful run
random.seed(None)

#make the resolution of the image random cause why not!
IMAGESIZE = random.randint(150, 300)

#The Image File
image = Image.new('RGB',(IMAGESIZE,IMAGESIZE))
#The draw object that will actually draw on the image
draw = ImageDraw.Draw(image)

#the color variable is a 3-tuple object which is randomized upon each iteration
#had to crack up Wikipedia for this one
#In mathematics, a tuple is a finite ordered list (sequence) of elements. - Wikipedia
#In Laymans terms, it is a ordered list.

for x in range(0, IMAGESIZE):
	for y in range(0, IMAGESIZE):
		color = (random.randint(0,255),random.randint(0,255),random.randint(0,255))
		draw.point((x,y),color)

#finally, save the image
image.save("random.png")