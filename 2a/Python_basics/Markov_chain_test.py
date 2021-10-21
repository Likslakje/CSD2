# Markov chain test

# State space = set of events (input)
# Parameter space = parameters given to Markov chain (algorythm)
# n-th order Markov chains -> smoothed n-grams -> interpolation between n-th and n+1-th

import random

kickLength = 4
sixteenthNote = 0.125 # 1 mesure had 16 sixteenth notes
eighthNote = 0.5
quarterNote = 1
halfNote = 2
wholeNote = 4
noteOptions = [sixteenthNote, eighthNote, quarterNote, halfNote, wholeNote]
kick = []
kickPatern = []
newKickPatern = []

# put a number (defined by kickLength) of ranfom values in the kick array
# EX: <5 = no kick, >5 = play kick
# for i in range(kickLength):
#     kick.append(random.randrange(1, 16))
# print(kick)

# make the random values into a fake step on/off patern
# for i in range(kickLength):
#     if kick[i] < 0.5:
#         kickPatern.append(0)
#     elif kick[i] >= 0.5:
#         kickPatern.append(1)
# print(kickPatern)

# analasys to feed to markovchain
# What's the chance that: a 0 is followed by a 0
#                         a 0 is followed by a 1
#                         a 1 is followed by a 0
#                         a 1 is followed by a 1

for i in range(kickLength):
    #for the number of steps, append notevalues to the kickpatern array based on a random generator
    #possible values are sixteenthNote, eighthNote, quarterNote, halfNote, wholeNote
    noteValuePick = random.random()
    if noteValuePick <= 1/5:
        kickPatern.append(sixteenthNote)
    elif noteValuePick > 1/5 and noteValuePick <= (1/5)*2:
        kickPatern.append(eighthNote)
    elif noteValuePick > (1/5)*2 and noteValuePick <= (1/5)*3:
        kickPatern.append(quarterNote)
    elif noteValuePick > (1/5)*3 and noteValuePick <= (1/5)*4:
        kickPatern.append(halfNote)
    elif noteValuePick > (1/5)*4:
        kickPatern.append(wholeNote)

note_to_note_transistion_times = {
    '0.125_0.125': 0,
    '0.125_0.5': 0,
    '0.125_1': 0,
    '0.125_2': 0,
    '0.125_4': 0,
    '0.5_0.125': 0,
    '0.5_0.5': 0,
    '0.5_1': 0,
    '0.5_2': 0,
    '0.5_4': 0,
    '1_0.125': 0,
    '1_0.5': 0,
    '1_1': 0,
    '1_2': 0,
    '1_4': 0,
    '2_0.125': 0,
    '2_0.5': 0,
    '2_1': 0,
    '2_2': 0,
    '2_4': 0,
    '4_0.125': 0,
    '4_0.5': 0,
    '4_1': 0,
    '4_2': 0,
    '4_4': 0
}

note_to_note_transistion_per = {
    '0.125_0.125': 0,
    '0.125_0.5': 0,
    '0.125_1': 0,
    '0.125_2': 0,
    '0.125_4': 0,
    '0.5_0.125': 0,
    '0.5_0.5': 0,
    '0.5_1': 0,
    '0.5_2': 0,
    '0.5_4': 0,
    '1_0.125': 0,
    '1_0.5': 0,
    '1_1': 0,
    '1_2': 0,
    '1_4': 0,
    '2_0.125': 0,
    '2_0.5': 0,
    '2_1': 0,
    '2_2': 0,
    '2_4': 0,
    '4_0.125': 0,
    '4_0.5': 0,
    '4_1': 0,
    '4_2': 0,
    '4_4': 0
}

def probability_per_note_times():
    #This function calculates the probability of a transition from a note value to the next note value
    #First we take an element and the next element out of the kickPatern array
    #We compare the transition between these two elements and add a +1 one to the right dictionary key
    #This function works with a slow loop (kickPatern)
    #an intermediate loop (noteValueFist)
    #and a fast loop (noteValueSecond)
    kickPaternIndex = 0
    noteValueFirst = 0
    noteValueSecond = 0
    for kickPaternIndex in range(len(kickPatern) - 1):
        #print('kickParn', kickPatern[kickPaternIndex], kickPatern[kickPaternIndex + 1])
        for noteValueFirst in range(len(noteOptions)):
            #print('noteOptionFirst', noteOptions[noteValueFirst])
            for noteValueSecond in range(len(noteOptions)):
                #print('noteOptionSecond', noteOptions[noteValueSecond])
                if kickPatern[kickPaternIndex] == noteOptions[noteValueFirst] and kickPatern[kickPaternIndex + 1] == noteOptions[noteValueSecond]:
                    dictKey = str(noteOptions[noteValueFirst]) + "_" + str(noteOptions[noteValueSecond])
                    note_to_note_transistion_times[dictKey] += 1
                    noteValueSecond += 1
        noteValueFirst += 1
    kickPaternIndex += 1
probability_per_note_times()

def probability_per_note_per():
    #This fuction transforms the number of times a note_to_note transistion occurs, to a precentage
    for i in range(len(note_to_note_transistion_times)):
        transistionTimesKey = list(note_to_note_transistion_times.keys())[i]
        transistionTimesValue = list(note_to_note_transistion_times.values())[i]
        note_to_note_transistion_per[transistionTimesKey] = (transistionTimesValue / (kickLength - 1)) * 100
probability_per_note_per()

def new_patern():
    newNoteValuePick = random.random()
    if newNoteValuePick <= 1/5:
        newKickPatern.append(sixteenthNote)
    elif newNoteValuePick > 1/5 and newNoteValuePick <= (1/5)*2:
        newKickPatern.append(eighthNote)
    elif newNoteValuePick > (1/5)*2 and newNoteValuePick <= (1/5)*3:
        newKickPatern.append(quarterNote)
    elif newNoteValuePick > (1/5)*3 and newNoteValuePick <= (1/5)*4:
        newKickPatern.append(halfNote)
    elif newNoteValuePick > (1/5)*4:
        newKickPatern.append(wholeNote)
    
    for i in range(kickLength):
        pass

new_patern()

print(note_to_note_transistion_times)
print(note_to_note_transistion_per)
print(newKickPatern)
print(len(note_to_note_transistion_times))