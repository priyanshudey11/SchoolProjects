#Question 1 Priyanshu 
import math
lengthr=float(input('Please input length of the rectange '))
while (lengthr<0):
    print('Please input postive value')
    lengthr=float(input('Please input length of the rectange '))
    
widthr=float(input('Please input width of the rectange '))
while (widthr<0):
    print('Please input postive value')
    lengthr=float(input('Please input length of the rectange '))
    
heightr=float(input('Please input height of the rectange '))
while (heightr<0):
    print('Please input postive value')
    heightr=float(input('Please input length of the rectange '))
    
radius=float(input('Please input radius of the sphere '))
while (radius<0):
    print('Please input postive value')
    radius=float(input('Please input length of the rectange '))
    
volumerectange= (lengthr* widthr*heightr)
volumeshere=((radius*radius*radius)*(4/3)*math.pi)
if volumeshere>volumerectange:
    print("It will fit in the sphere ")
else:
    print("It will not fit in the sphere")