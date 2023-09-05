import random
from turtle import delay
p=1
winnings=0 
i=0
simulation=float(input("How many years will you like to simulate: "))
if(simulation<0):
    while p==1:  
        print("Please Enter a postive number")
        simulation=float(input("How many years will you like to simulate: "))
        if(simulation>0):
            p=0
days=365*simulation
while i<=days:    
    player=random.randrange(0,1000)
    win=random.randrange(0,1000)
    if player==win:
        print("WIN")
        winnings=winnings-400
        player=0
        win=0        
    else:
        winnings=winnings+1
        player=0
        win=0
    i=i+1
print("Running simulation.........")
print("The expected income per dollar spent on tickets is $",winnings,sep="")