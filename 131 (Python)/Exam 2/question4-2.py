def import_data(file):
    voterdata=[]
    roosevelt=0
    corregan=0
    parker=0
    watson=0
    swallow=0
    debs=0
    voteridn=[]
    in_file = open('voterinfo.txt', 'r')
    for line in in_file:
        values=line.split()
        voter_id=values[0]
        candidadte_name=values[1]
        voterdata.append([voter_id,candidadte_name])
        duplicate = list(set(tuple(sorted(y)) for y in voterdata))
        for l in voteridn:
                if voter_id!= l:
                    voteridn.append(l)
                else:
                    duplicate[line].remove
                    
        if candidadte_name=='roosevelt':
            roosevelt=roosevelt+1

        elif candidadte_name=='corregan':
            corregan=corregan+1

        elif candidadte_name=='parker':
            parker=parker+1

        elif candidadte_name=='watson':
            watson=watson+1

        elif candidadte_name=='swallow':
            swallow=swallow+1

        elif candidadte_name=='debs':
            debs=debs+1
        for duplicate in in_file:
            
        if voter_id==
    for y in duplicate:
        print(str(y))
    print('rosevelt',roosevelt)
    print('corregan',corregan)
    print('parker',parker)
    print('watson',watson)
    print('swallow',swallow)
    print('debs',debs)
s_p=import_data('voterinfo.txt')
#import_data(s_p)
#question 3 get data from tuple[1] and then set that two a new list. Have a for loop to check if each value is equal from the for loop and have a new 2d array for the names and score.Each the loop goes threw it check if the person is there if not it appends a new person and score. Then adds scores to the value.
#qustion 4 check tuple[0] in the 2d list then have a new list in which stores vales that are not equal to the previous values if they are remove that list.
