# Markov chain test

# State space = set of events (input)
# Parameter space = parameters given to Markov chain (algorythm)
# n-th order Markov chains -> smoothed n-grams -> interpolation between n-th and n+1-th

import random

kickLength = 8
sixteenthNote = 0.125 # 1 mesure had 16 sixteenth notes
eightthNote = 0.5
quarterNote = 1
kick = []
kickPatern = [1, 0.5, 1, 0.125, 1, 0.5, 1, 0.125]
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

sixteenthNote_sixteenthNote = 0
sixteenthNote_eigtthNote = 0
sixteenthNote_quarterNote = 0
eightthNote_sixteenthNote = 0
eightthNote_eightthNote = 0
eightthNote_quarterNote = 0
quarterNote_sixteenthNote = 0
quarterNote_eightthNote = 0
quarterNote_quarterNote = 0

sixteenthNote_sixteenthNote_per = 0
sixteenthNote_eigtthNote_per = 0
sixteenthNote_quarterNote_per = 0
eightthNote_sixteenthNote_per = 0
eightthNote_eightthNote_per = 0
eightthNote_quarterNote_per = 0
quarterNote_sixteenthNote_per = 0
quarterNote_eightthNote_per = 0
quarterNote_quarterNote_per = 0

for i in range(len(kickPatern)):
    if kickPatern[i] == sixteenthNote and kickPatern[i + 1] == sixteenthNote:
        sixteenthNote_sixteenthNote += 1