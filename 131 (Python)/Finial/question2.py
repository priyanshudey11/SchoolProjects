word1= input("Please enter the first word: ")
word2=input("Please enter the secound word: ")
if word1>word2:
    wordcount=len(word1)
else:
    wordcount=len(word2)
    count=0
for x in range(wordcount):
    if word1[x]==word2[x]:
        count+=1
print("the words"+word1+"and"+word2+"have 3 letters in the same position.")
    