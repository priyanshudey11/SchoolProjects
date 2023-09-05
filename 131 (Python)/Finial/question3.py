# This function searches for the given word in the given puzzle. The function returns a
# tuple of the form (row, column) where
#
#    row    : the starting row of the word (-1 if the word is not found)
#    column : the starting column of the word (-1 if the word is not found)
#
# This operation only looks for words in a left-to-right manner. (Other directions
# will be added in the next problem.)
#
def find_word(word):

    # implement this function

    puzzle = ["agcrsvvfdszijcefhmzjweyneg",
            "qjxoyuoholjfshprojectjdevu",
            "dadvnklbxbvvjusguwoymjztvc",
            "bvdgjqyyqefnepvlbifbpnkzld",
            "uaxhlhipauewaleilxgmfomzkl",
            "nvnpbqlcjtjkwlftehdmuivhmz",
            "ljfimiuywagvpcdtpwzcqxglwp",
            "vqwewjgostkcjtxetyawgznaka",
            "fbkxtcrpwvhykhwckjpacciiey",
            "mlsehkvjsozfjzehehksgzmmnc",
            "urlvdrsxzimoqqwnixalzdmuyx",
            "hnoitamrofnifofofuhjwkaivl",
            "rwiaznypjqyyqydlhehbtbrlep",
            "zhnohgdcsgcdqlvordljeegdam",
            "lktpmvgpmejzznzgulhzabojmp",
            "ecatczmvstzfgfoyimyghlrcia",
            "sxfhnyqwicgxspoisnabwypjzo",
            "azjbuonpsvehqzzmtilhutwmnx",
            "bnciecsmanagementardjgqlxg",
            "aonbdbgvgkzgzsoucermloqfer",
            "tzstgifijhzdymxzygvgdtfvjc",
            "ahopogscienceghebvcmerjdob",
            "dvbrqpxjohoyawfypirejtmsvs",
            "xokfsjmukkeuejvwbssxocnhoe",
            "wpbtsbmiecfneeqbwukannwiqn",
            "qjanldbiplpysfbyuclpsdiovl"]
    #horzontal 
    colum=0
    row=0
    for x in range(len(puzzle)):
        if word in puzzle[x]:
            colum=x
    row=puzzle[colum].find(word[0])
    #veritical
    columns = []
    temp = []
    for col in range(len(puzzle[0])):
        columns.append( [puzzle[row][col] for row in  
        range(len(puzzle))])
        for y in range(0, len(puzzle)):
            column = [puzzle[x][y] for x in range(len(puzzle))]
            temp.append(column)

        for row in temp:
            l=temp.index(row)
            rows = ''.join(row)
            found_at = rows.find(word)
            #collums was to find the 
            row=rows.find(word[0])
            
    #digonal
    digonaltop=[puzzle[i][i] for i in range(len(puzzle))]
    #turns all of the things into a
    digonaltop=''.join(str(e)for e in digonaltop)
    if word in digonaltop:
        colum =digonaltop.find(word[0])
    #bottomw left to right           
    digonalbottom=[puzzle[i][len(puzzle)-i-1] for i in range(len(puzzle))]
    digonalbottom=''.join(str(e)for e in digonaltop)
    if word in digonalbottom:
        colum=digonaltop.find(word[0])
    #Was trying to figure out a reqursion string where it would go back and find the collums so if it was on row 14 it would count from the top if it was bottom to top on and vice versa
    
    print(col,row)
word=input('Please enter a word: ')
find_word(word)
