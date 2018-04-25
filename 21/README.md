# Challenge 21 : BMI Calculator
**Body mass Index**, also known as **BMI** is a value derived from the mass (weight) and height of an individual. The BMI is defined as the ***body mass divided by the square of the body height***, and is universally expressed in units of kg/m2, resulting from mass in kilograms and height in metres. -***Wikipedia***

## Finding out the Calculation of the BMI
In order to find out the calculation of the BMI, we require the weight of the person, and the height of the person. We'll assume that they have either. Once we have both inputs, we divide the mass (kg) by it's height(m). If we are using the *English Units*, then we must multiple the calculation by 703.

## The Code

```
float BMI
float height 
float weight

BMI = weight / height

//if the English units are used
BMI = (weight/height) * 703

```