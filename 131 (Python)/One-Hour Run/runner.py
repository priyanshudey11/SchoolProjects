
import time
start_time = time.time()
def import_data(filepath):
    data = []
    add=[]
    temp=[]
    zeros=[]
    file=open(filepath,'r')
    for r in file:
        data.append([int(n) for n in r.split()])
        res = [sum(x) for x in zip(*data)]
        add.append(res)
    #corrects blank spaces
    add=[x for x in add if x]
    add=add.pop()
    #corrects blank spaces in a 2d array
    data= [x for x in data if x != []]

    for y in range(len(data)):
        for x in range(len(data[y])):
            if data[y][x]==0:
                zeros.append(x) 
    zeros.sort()
    #counts number of zeros 
    zeros={i:zeros.count(i) for i in zeros}

    for val in range(len(add)):
        if val in zeros:
            subtract=zeros[val]
            divides= (add[val]//((len(data))-subtract))
            temp.append(divides)
            subtract=0
            divides=0
        else:
            divides= (add[val]//(len(data)))
            temp.append(divides)
            divides=0

    data.append(temp)
    #file.close
    #gets rid of the zeros
    data= ([[y for y in x if y != 0] for x in data])
    print(data)
    data[0][1]=0
    print (data)
    return data

def export(filepath,data):
    add=0
    divide=0
    avgtime=[]
    avgtimec=[]
    time=[]
    zero=0
    maxcount=1
    numberofvr=[]
    out_file=open(filepath,'w')

    for y in range(len(data)):
        for x in range(len(data[y])):
            if maxcount<len(data[y]):
                maxcount=len(data[x])
            if data[y][x]==0 or data[y][x]==' ':
                zero=zero+1
            add= add+ data[y][x]
            if x==len(data[y])-1:
                divide=add//(len(data[y])-zero)
                avgtime.append(divide)
                zero=0
                add=0
                divide=0

    for values in range(len(avgtime)):
        seconds=avgtime[values]
        seconds%=3600
        minutes=seconds//60
        seconds%=60
        avgtimec.append(("%d:%02d" % (minutes, seconds)))

    #spacing issue fix for average time out put
    for y in range(len(data)):
        numberofvr.append(maxcount-len(data[y]))

    for y in range(len(data)):
            for x in range(len(data[y])):
                seconds=data[y][x]
                seconds%=3600
                minutes=seconds//60
                seconds%=60
                time.append(("%d:%02d" % (minutes, seconds)))
                if len(time)==len(data[y]):
                    if y!=len(data)-1:
                        out_file.write(str(' '.join(time)))
                        out_file.write(' '*((5*(numberofvr[y]))+1)+'| ')
                        out_file.write(str(avgtimec[y])+'\n')
                    else:
                        out_file.write(str(' '.join(time)))
                    time.clear()
            if y==len(data)-2:
                out_file.write(str('-'*51)+'\n')
                
s_p=import_data('runner.txt')
export('runner-out.txt',s_p)
print("Process finished --- %s seconds ---" % (time.time() - start_time))

