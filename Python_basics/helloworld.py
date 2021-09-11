print('type name')
username = input ('')
print( 'Hello', username + '!')
import inquirer #library die user interaction makkelijker maakt
questions = [
  inquirer.List('mood', #begin de lijst mood
                message='How are you feeling today?',
                choices=['Great', 'Could be better', 'Terrible'],
            ),
]
answers = inquirer.prompt(questions) #het geselecteerde antwoord is answers
if answers['mood'] == 'Great': #als het antwoord van de lijst mood, great is, dan...
    print('Good to hear!')
elif answers['mood'] == 'Could be better':
    print('I am sure things will be alright.')
else:
    print(':(')