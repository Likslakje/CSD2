# Markov chain test

# State space = set of events (input)
# Parameter space = parameters given to Markov chain (algorythm)
# n-th order Markov chains -> smoothed n-grams -> interpolation between n-th and n+1-th

import random

kickLength = 8
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
print(kickPatern)

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
    'sixteenthNote_sixteenthNote_per' : 0,
    'sixteenthNote_eighthNote_per' : 0,
    'sixteenthNote_quarterNote_per' : 0,
    'eighthNote_sixteenthNote_per' : 0,
    'eighthNote_eighthNote_per' : 0,
    'eighthNote_quarterNote_per ': 0,
    'quarterNote_sixteenthNote_per' : 0,
    'quarterNote_eighthNote_per' : 0,
    'quarterNote_quarterNote_per' : 0
}

kickPaternIndex = 0
for kickPaternIndex in range(len(kickPatern) - 1):
    print('kickParn', kickPatern[kickPaternIndex], kickPatern[kickPaternIndex + 1])
    noteValueFirst = 0
    print('noteOptionFirst', noteOptions[noteValueFirst])
    for noteValueSecond in range(len(noteOptions)):
        print('noteOptionSecond', noteOptions[noteValueSecond])
        if kickPatern[kickPaternIndex] == noteOptions[noteValueFirst] and kickPatern[kickPaternIndex + 1] == noteOptions[noteValueSecond]:
            dictKey = str(noteOptions[noteValueFirst]) + "_" + str(noteOptions[noteValueSecond])
            note_to_note_transistion_times[dictKey] += 1
        noteValueFirst += 1
    kickPaternIndex += 1
print(note_to_note_transistion_times)

    # if kickPatern[i] == sixteenthNote and kickPatern[i + 1] == sixteenthNote:
    #     note_to_note_transistion_times['sixteenthNote_sixteenthNote'] += 1
    # if kickPatern[i] == sixteenthNote and kickPatern[i + 1] == eighthNote:
    #     note_to_note_transistion_times['sixteenthNote_eighthNote'] += 1
    # if kickPatern[i] == sixteenthNote and kickPatern[i + 1] == quarterNote:
    #     note_to_note_transistion_times['sixteenthNote_quarterNote'] += 1
    # if kickPatern[i] == sixteenthNote and kickPatern[i + 1] == halfNote:
    #     note_to_note_transistion_times['sixteenthNote_halfNote'] += 1
    # if kickPatern[i] == sixteenthNote and kickPatern[i + 1] == halfNote:
    #     note_to_note_transistion_times['sixteenthNote_halfNote'] += 1
    

    # if kickPatern[i] == eighthNote and kickPatern[i + 1] == sixteenthNote:
    #     note_to_note_transistion_times['eighthNote_sixteenthNote'] += 1
    # if kickPatern[i] == eighthNote and kickPatern[i + 1] == eighthNote:
    #     note_to_note_transistion_times['eighthNote_eighthNote'] += 1
    # if kickPatern[i] == eighthNote and kickPatern[i + 1] == quarterNote:
    #     note_to_note_transistion_times['eighthNote_quarterNote'] += 1

    # if kickPatern[i] == quarterNote and kickPatern[i + 1] == sixteenthNote:
    #     note_to_note_transistion_times['quarterNote_sixteenthNote'] += 1
    # if kickPatern[i] == quarterNote and kickPatern[i + 1] == eighthNote:
    #     note_to_note_transistion_times['quarterNote_eighthNote'] += 1
    # if kickPatern[i] == quarterNote and kickPatern[i + 1] == quarterNote:
    #     note_to_note_transistion_times['quarterNote_quarterNote'] += 1

    # if kickPatern[i] == halfNote and kickPatern[i + 1] == sixteenthNote:
    #     note_to_note_transistion_times['halfNote_sixteenthNote'] += 1
    # if kickPatern[i] == halfNote and kickPatern[i + 1] == eighthNote:
    #     note_to_note_transistion_times['halfNote_eighthNote'] += 1
    # if kickPatern[i] == halfNote and kickPatern[i + 1] == quarterNote:
    #     note_to_note_transistion_times['halfNote_quarterNote'] += 1
print(note_to_note_transistion_times)