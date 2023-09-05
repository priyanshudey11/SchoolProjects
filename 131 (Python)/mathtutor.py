import math
import random
import time
end=0
operations=""
finial=0
while (end==0):
    correct=1
    add_sub=random.randint(0,1)
    value1=random.randint(0,9999)
    value2=random.randint(0,9999)
    if (add_sub==0):
       finial= value1+value2
       operations="+"
    else:
       finial= value1-value2
       operations="-"
    print(value1,operations,value2,"= ?")
    intputs=int(input("Answer: "))
    while(correct==1):
        if (intputs>finial):
            print("Try again your number is to high")
            print(value1," + ",value2,"= ?")
            intputs=int(input("Answer: "))
        elif(intputs<finial):
            print("Try again your numbver is to low ")
            print(value1," + ",value2,"= ?")
            intputs=int(input("Answer: "))
        else:
            again=input("You got it right. Do you want to continue the Tutoring session: ")
            correct=0
            if again[:1]=="y":
                end=0
            elif again[:1]=="Y":
                end=0
            else:
                end=1
                print("Thankyou for using the Math Tutor")