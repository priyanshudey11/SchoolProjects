import random
import time
simulation=float(input("How many years will you like to simulate: "))
if(simulation<=0):
    print("Please Enter a postive number")
    simulation=float(input("How many years will you like to simulate: "))
i=0
playernumw=0
winnum=0
y=0
x=0
winc=0
days=365*simulation
listp=[]
listw=[]
while i<days:
  if y==0:
    while x<3:
        playernumw=0
        winnum=0
        #first numbers
        playernumw=random.randrange(0,70)
        listp.insert(x,playernumw)
        winnum=random.randrange(0,70)
        listw.insert(x,winnum)
        x=x+1
    #Last Numvers 
    playernumw=0
    winnum=0
    playernumw=random.randrange(0,25)
    listp.insert(4,playernumw)
    winnum=random.randrange(0,25)
    listw.insert(4,winnum)
    #Checks if winner
    if listp.pop(0)==listw.pop(0):
        if listp.pop(1)==listw.pop(1):
            if listp.pop(2)==listw.pop(2):
                if listp.pop(3)==listw.pop(3):
                    if listp.pop(4)==listw.pop(4):
                        win=win+1
        y=1
    elif y==1:
        listp.clear()
        listw.clear()
        playernumw=0
        winnum=0
        y=0
        i=i+1
    elif days==i:
        y=1
print("Running simulation.............")
time.sleep(5)
print(winc)
