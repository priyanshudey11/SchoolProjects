import math
count=0
print("Welcome to Priyanshu's Intrest calcultor please follow the directions")
while (count==0):

    amount= float(input("What is the intial ammont of the loan: "))
    loanpayments= float(input("How many montly payments do you need to make: "))
    rate= float (input("What is the intrest you are paying for the loan: "))
    mrate= rate/12
    #starts the calcultions for each part of the formula
    rate_one= mrate+1
    power= math.pow(rate_one,loanpayments)
    #Top Fraction
    paymentT= mrate*power
    #Bottom Fraction
    paymentB=power-1
    #Fraction Division
    paymentF= paymentT/paymentB
    #Total intrest 
    payment=amount*paymentF
    totalpayment=payment*loanpayments
    #payment= (math.pow(rate(1+rate),loanpayments)*rate)/ math.pow((1 + rate),loanpayments-1)))
    print("Loan Amounnt: $",int(amount))
    #Divides into multi mounts and add a percentage
    print("Mountly Intrest Rate: ",int(mrate*100),"%")
    print("Number of Payments: ",int(loanpayments))
    print("Your Mountly payment: $",round(payment,2))
    #total amount needed to pay
    print("Amount repaid: $",round(totalpayment,2))
    #total intreset
    print("Interset Paid: $",round(totalpayment-amount,2))
    #For using the calcutor again
    again= input("Would you like to use the calcultor again?: ")

    if again[:1]=="y":
        count=0
    elif again[:1]=="Y":
        count=0
    else:
        count=1
else:
    print("Thankyou for using the calcultor have a great day!")

