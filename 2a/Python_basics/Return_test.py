# def add(a, b):
#     return a + b

# def sub(a, b):
#     return a - b

# def times(a, b):
#     return a * b

# def div(a, b):
#     return a - b

# # def chooseFormula(chosenFormula):
# #     if chosenFormula == 1:
# #         return add
# #     elif chosenFormula == 2:
# #         return sub
# #     elif chosenFormula == 3:
# #         return times
# #     elif chosenFormula == 4:
# #         return div

# # choice = int(input("Choose formula; 1 = add, 2 = sub, 3 = times, 4 = div "))

# # func = chooseFormula(choice)
# a = int(input("Set a "))
# b = int(input("Set b "))
# result = add(a, b)
# print(result)
bpm = 120
print(bpm)

def bpm_choice(): 
    #functie voor de y/n vraag voor bpm
    print("Default BPM is set to 120, would you like to change the BPM (y/n): ")
    bpmChoice = input()
    if bpmChoice == "n" :
        bpm = 120
    elif bpmChoice == "y" :
        bpm = int(input("Enter a new BPM: " ))
    else :
        print("Please enter valid input, 'y' or 'n' only")
        bpm_choice() #als input niet matched dan voer de functie choice opnieuw uit
    return bpm


while True:
    userInput = str(input("Type bpm : "))
    bpm = bpm_choice()
    print(bpm)
    