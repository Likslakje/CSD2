# Markov chain test

# State space = set of events (input)
# Parameter space = parameters given to Markov chain (algorythm)
# n-th order Markov chains -> smoothed n-grams -> interpolation between n-th and n+1-th

import random

kickLength = 8
kick = []
kickPatern = []
newKickPatern = []

# put a number (defined by kickLength) of ranfom values in the kick array
# EX: <5 = no kick, >5 = play kick
for i in range(kickLength):
    kick.append(round(random.random(), 2))
print(kick)

# make the random values into a fake step on/off patern
for i in range(kickLength):
    if kick[i] < 0.5:
        kickPatern.append(0)
    elif kick[i] >= 0.5:
        kickPatern.append(1)
print(kickPatern)

# analasys to feed to markovchain
# What's the chance that: a 0 is followed by a 0
#                         a 0 is followed by a 1
#                         a 1 is followed by a 0
#                         a 1 is followed by a 1

zeroZero = 0
zeroOne = 0
oneZero = 0
oneOne = 0

zeroZeroPer = 0
zeroOnePer = 0
oneZeroPer = 0
oneOnePer = 0

for i in range(kickLength - 1): # -1 because the last element doesnt have anything to compare to
    if kickPatern[i] == 0 and kickPatern[i + 1] == 0:
            zeroZero += 1
            zeroZeroPer = (zeroZero/kickLength) * 100
    elif kickPatern[i] == 0 and kickPatern[i + 1] == 1:
            zeroOne += 1
            zeroOnePer = (zeroOne/kickLength) * 100
    elif kickPatern[i] == 1 and kickPatern[i + 1] == 0:
            oneZero += 1
            OneZeroPer = (oneZero/kickLength) * 100
    elif kickPatern[i] == 1 and kickPatern[i + 1] == 1:
            oneOne += 1
            oneOnePer = (oneOne/kickLength) * 100

# Make a new kick patern with the chance for each step
# First we give the new kick patern a random starting value, so the chance algorythm can start
newKickPatern.append(random.randrange(0, 2))
i = 0
for i in range(kickLength):
    if newKickPatern[i] == 0:
        chanceChoice = random.randrange(0, zeroZeroPer + zeroOnePer) # pick a number
        if chanceChoice < zeroZeroPer:
            newKickPatern.append(0)
        elif chanceChoice >= zeroZeroPer:
            newKickPatern.append(1)
    elif newKickPatern[i] == 1:
        chanceChoice = random.randrange(0, oneZeroPer + oneOnePer)
        #if chanceChoice < on
    i += 1