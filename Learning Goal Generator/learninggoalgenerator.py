import random
from random import randint
import time
percentg = randint(90, 100)
percentg = str(percentg)
randassign = input("Enter assignment example: The map quiz >>>")
time.sleep(1)
finished = False
while finished == False:
  goals = ["I will complete most of my homework in class", 
  "I will be focused in class " + percentg + "% of the time", 
  "I will be resourceful in class.", 
  "I will be strategic in class for maximum learning", 
  "I will communicate effectively with the teacher to finish " + randassign + ".", 
  "I will manage my time to make sure I finish " + randassign + ".", 
  "I will be knowledgeable.", 
  "I will be motivated " + percentg + "% of the time.",
  "I will listen to the teacher to learn"]
  print(random.choice(goals))
  choices = input("Are you satisfied with your answer? Yes/No ")
  choices = choices.lower()
  if (choices == 'yes'):
    finished = True
    break
  else :
    print("generating new result...")
