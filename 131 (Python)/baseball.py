from array import*

def get_score(inning_info):
    h=[]
    a=[]
    switchn=[]
    switch=1
    count=0
    home=0
    away=0
  

   #gets when the team will switch
    #for z in range(len(inning_info)):
       # if inning_info[z]=='I':
          #  switch.append(z)
    for r in range(len(inning_info)):
        print(len(inning_info))
       # if switchn[0]==r:
            #0=away
          #  if switch==1:
                #switch=0
           # else:
            #    switch=1
           # switchn.remove[0]
           # a.clear()
            #h.clear()
            #count= 0
        if switch==0:
            if inning_info[r]=='s':
                a.insert(r,1)
            elif inning_info[r]=='d':
                a.insert(r,2)
            elif inning_info=='t':
                a.insert(r,6)
            elif inning_info=='h':
                a.insert(r,5)
            count+1
           # print(a)
           # for y in count:
              #  value=a[y]
              #  a[y]=value+1
        elif switch==1:
            if inning_info[r]=='s':
                h.insert(r,1)
            if inning_info[r]=='d':
                h.insert(r,2)
            if inning_info=='t':
                h.insert(r,3)
            if inning_info=='h':
                h.insert(r,4)
            count+1

       # for x in count:
            #h[x]=h[x]+count
        #for x in len(h):
           # if h[x]>4:
                #home=home+1
        #for x in len(a):
           # if h[x]>4:
                #away=away+1 
    print(a)
inning_info=input("Enter the inning information: ")
get_score(inning_info)