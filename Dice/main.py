import random

completed = False

while(completed == False):
  print(random.randint(1,6))
  answer = input("Would you like to roll again? ('y' or 'n')")
  if(answer == "n"):
    completed = True
