import string



def list_maker(user_input):

    i = 0
    lastword = 0
    wordcounter = 0
    
    wordlist = []
    

    text = str(user_input) + str(" ")
    no_punct = ""
    k = 0
    for char in text:
            if not (char in string.punctuation) or (char == "." or char == "-"):
                no_punct += char
            k += 1





    for ch in no_punct:
            i += 1
            if ch == " ":
                wordlist.append(no_punct[lastword:i-1])
                wordcounter += 1
                if wordlist[wordcounter-1] == "":
                    del wordlist[wordcounter-1]
                    wordcounter -= 1
                lastword = i


    j = 0
    deletelist = []
    for ch in wordlist:
        deleting = False
        for let in ch:
            if let.isalpha() == True:
                deleting = True
        if deleting == True:
            print(str(wordlist[j]) + " isn't a number kiddo!")
            deletelist.append(j)
        j += 1
        
    reverselist = sorted(deletelist, key = lambda x: -x)


    for entry in reverselist:
        del wordlist[entry]

    return wordlist

def bubble_sort(numlist):
    altlist = 0
    list_length = len(numlist)
    complete = False
    while complete == False:    
        complete = True
        for i in range(0,list_length-1):
            if float(numlist[i+1]) < float(numlist[i]):
                num1 = numlist[i+1]
                num2 = numlist[i]
                numlist[i] = num1
                numlist[i+1] = num2
                print("Swapping " +str(num1) + " and " + str(num2)) 
                altlist += 1
                complete = False                

    return numlist,altlist


while 1:
    numberlist = list_maker(input())
    output,altlist = bubble_sort(numberlist)

    print(output)
    print("You made " + str(altlist) + " alterations to the list")
