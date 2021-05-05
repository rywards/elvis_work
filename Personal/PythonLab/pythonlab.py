#! /usr/bin/python
# Function to get the past tense of an inputted
# English word
#
# Ryan Edwards
special = ["c", "w", "x", "y"]
vowels = ["a", "e", "i", "o", "u"]

def past_tense(inString):

    if (inString [-2] not in vowels and inString[-1] == "y"):
        return inString[0:-1] + "ied"
    if (inString[-1] == "e"):
        return inString + "d"
    if (inString[-1] == "c"):
        return inString + "ked"
    if (inString == "run"):
        return "ran"
    if (inString == "buy"):
        return "bought"
    if (inString[-2] in vowels and inString[-1] not in special):
        return inString + inString[-1] + "ed"
    return inString + "ed"



print(past_tense("jump"))
print(past_tense("laugh"))
print(past_tense("run"))
print(past_tense("plan"))
print(past_tense("shop"))
print(past_tense("buy"))
print(past_tense("follow"))
print(past_tense("agree"))
print(past_tense("change"))
print(past_tense("decide"))
print(past_tense("copy"))
print(past_tense("study"))
print(past_tense("panic"))
print(past_tense("attack"))
print(past_tense("play"))
print(past_tense("mimic"))
