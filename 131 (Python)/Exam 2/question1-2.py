def import_data(filepath):
    voterdata=[]

    filepath = open('voterinfo.txt', 'r')
    for line in filepath:
        values=line.split()
        voter_id=values[0]
        candidadte_name=values[1]
        voterdata.append([voter_id,candidadte_name])
    return voterdata
def export(filepath,voterdata):
    out_file=open(filepath,'w')
    
    for y in range(len(voterdata)):
        out_file.write(str(' '.join((voterdata[y])))+'\n')
        
s_p=import_data('voterinfo.txt')
export('out.txt',s_p)