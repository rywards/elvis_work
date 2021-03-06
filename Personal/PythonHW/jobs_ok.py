# Python HW
# Derek Ledford, Ryan Edwards
# program to check that shift assignments are good

# main jobs_ok function
# takes in the shift list and attribute list
# iterates through and runs the function checks
def jobs_ok(shiftList, attributeList):
    if(not check_dupes_in_list_of_list(shiftList)):
        for shift in shiftList:
            if(not phones_ok(get_attributes_from_name(shift[0], attributeList)) or
               not phones_ok(get_attributes_from_name(shift[1], attributeList)) or
               not computers_ok(get_attributes_from_name(shift[2], attributeList)) or
               not network_ok(get_attributes_from_name(shift[3], attributeList))):
                return False
        return True
    return False

# function that checks for dupes in the list
def check_dupes_in_list(listIn):
    if(listIn[0] != listIn[1] and listIn[0] != listIn[2] and listIn[0] != listIn[3] and
       listIn[1] != listIn[2] and listIn[1] != listIn[3] and
       listIn[2] != listIn[3]):
        return False
    else:
        return True

# function checks for dupes in the list of lists
# manually checks every element
# assumes correct input
def check_dupes_in_list_of_list(listIn):
    if(not check_dupes_in_list(listIn[0]) and not check_dupes_in_list(listIn[1])
       and not check_dupes_in_list(listIn[2]) and not check_dupes_in_list(listIn[3])):
        if(listIn[0][0] not in listIn[1] and listIn[0][0] not in listIn[2] and listIn[0][0] not in listIn[3]
           and listIn[0][1] not in listIn[1] and listIn[0][1] not in listIn[2] and listIn[0][1] not in listIn[3]
           and listIn[0][2] not in listIn[1] and listIn[0][2] not in listIn[2] and listIn[0][2] not in listIn[3]
           and listIn[0][3] not in listIn[1] and listIn[0][3] not in listIn[2] and listIn[0][3] not in listIn[3]
           and listIn[1][0] not in listIn[2] and listIn[1][0] not in listIn[3]
           and listIn[1][1] not in listIn[2] and listIn[1][1] not in listIn[3]
           and listIn[1][2] not in listIn[2] and listIn[1][2] not in listIn[3]
           and listIn[1][3] not in listIn[2] and listIn[1][3] not in listIn[3]
           and listIn[2][0] not in listIn[3]
           and listIn[2][1] not in listIn[3]
           and listIn[2][2] not in listIn[3]
           and listIn[2][3] not in listIn[3]):
            return False
        else:
            return True

    else:
        return True

# functions to check each attribute
# expects proper input
def phones_ok(attributesIn):
    return attributesIn[1] == 1

def computers_ok(attributesIn):
    return attributesIn[2] == 1

def network_ok(attributesIn):
    return attributesIn[3] == 1

# function gets each person's attribute
# expects proper input
def get_attributes_from_name(name, attributesListIn):
    for profile in attributesListIn:
        if name == profile[0]:
            return profile
