dict = {"a" : "b", "b" : "c", "c" : "d", "d" : "e", "e" : "f", "f" : "g", "g" : "h", "h" : "i", "i" : "j", "j" : "k", "k" : "l", "l" : "m", "m" : "n", "n" : "o", "o" : "p", "p" : "q", "q" : "r", "r" : "s", "s" : "t", "t" : "u", "u" : "v", "v" : "w", "w" : "x", "x" : "y", "y" : "z", "z" : "a"}

name1 = ""
name2 = ""
def decrypt(txt):
  output = ""
  for char in txt:
    if char in dict:
      output += list(dict.keys())[list(dict.values()).index(char)]
  txt = output
  return txt

def encrypt(txt):
  output = ""
  for char in txt:
    if char in dict:
      output += dict[char]
  txt = output
  return txt

namea = input("input first person's name: ")
nameb = input("input second person's name: ")

if (namea.lower() == decrypt(name1) and nameb.lower() == decrypt("name2") or nameb.lower() == decrypt(name2) and namea.lower() == decrypt(name1)):
  chance = 100
  
else:
  namea = len(namea)
  nameb = len(nameb)
  if namea * nameb > 100:
    factor = namea * nameb + namea+nameb
  else:
    factor = 100
  chance = (factor - namea * nameb)
print(chance)
