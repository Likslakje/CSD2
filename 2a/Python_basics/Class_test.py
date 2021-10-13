# maak een class
class MyClass:
    x = 5

# maak een variable gevuld met class
p1 = MyClass()

# print van de variable gevuld met class, de waarde van x
print(p1.x)

# class maken met de __init__ function, self. = this. in JS
# values meegeven aan class via de __init__()
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

p2 = Person('Mila', 20)

print(p2.name)
print(p2.age)

# gebruik values uit de class in functies binnen de class
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def lets_print(naamprinten):
        print('Hoi mijn naam is ' + naamprinten.name)

# geef 2 values mee aan de class Person
p2 = Person('Mila', 20)

# voer de functie lets_print() binnen de class Person uit
p2.lets_print()