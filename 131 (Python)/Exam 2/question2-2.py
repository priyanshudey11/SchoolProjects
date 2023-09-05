def import_data(filepath):
    old_voterdata=[]
    temp=[]
    new_voterdata=[]
    filepath = open('voterinfo.txt', 'r')
    for line in filepath:
        values=line.split()
        voter_id=values[0]
        candidadte_name=values[1]
        old_voterdata.append([voter_id,candidadte_name])
    print(len(old_voterdata))
    for i in range(len(old_voterdata)):
        if old_voterdata[i][0] not in temp:
            temp.append(old_voterdata[i][0])
            new_voterdata.append(old_voterdata[i])
    print(len(new_voterdata))
    return new_voterdata
def export(filepath,new_voterdata):
    out_file=open(filepath,'w')
    for y in range(len(new_voterdata)):
        out_file.write(str(' '.join((new_voterdata[y])))+'\n')
        
s_p=import_data('voterinfo.txt')
export('out.txt',s_p)