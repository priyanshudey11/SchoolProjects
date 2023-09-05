cost= float(input("What is the cost of the car: "))
driven=float(input("About how much will the car be driven per year: "))
gas=float(input("What is the estimated amount of gass: "))
mpg= float(input("What is the miles per gallon: "))
resale=float(input("What is the estamte resale value of the car: "))
 
costd=(driven/mpg)*gas
totalc= cost+costd*5-cost
if (totalc<0):
    print("You will make about",abs(totalc),"by buying this car after 5 years.")
elif (totalc>0):
    print("You will lose about",totalc,"by buying this car " )
else:
    print("You will not lose or gain anything by owing this car")
