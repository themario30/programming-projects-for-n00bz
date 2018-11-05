#  Challenge 64 - Random Image Generator

## What is a Random Image Generator?

A random image generator is self-explainatory. It generates an image using random numbers. Each pixel in the image has a random color value. In this case, the color value being generated here is using RGB, that is, a value between 0 and 255 in red, green, and blue values.

##Why Python?
It has been quite awhile since I've coded in Python. My last 'serious coding in Python' was back when I was making the Luigi Poker game in python in use as a plugin for Discord Red, a bot which can be run locally on your machine. So it would nice to rub off some rust from Python as I've been getting myself more and more into C#.

## Code
	for x in range(0, IMAGESIZE):
		for y in range(0, IMAGESIZE):
			color = (random.randint(0,255),random.randint(0,255),random.randint(0,255))
			draw.point((x,y),color)
		
## Final Thoughts

I felt like I coped out on a challenge. Although it was essentially randomizing three values, and looping through each pixel, I felt like the challenge was from how the file was being saved. I did get to look through the PIL library a bit and learned a bit more about how it works.

### November 5th, 2018

