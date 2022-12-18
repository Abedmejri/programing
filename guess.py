import random
#user guess number of computer 
def guess(x):
    random_number=random.randint(1,x)
    guess=0
    while(guess!=random_number):
        guess=int(input('guess number '))
        if(guess<random_number):
            print("is to low")
        elif(guess>random_number):
            print("is to high")
        
    print("yay,congrats")
#computer guess number of user 
def computer_guess(x):
    low = 1
    high = x
    feedback = ''
    while(feedback!='c'):
        guess = random.randint(low,high)
        feedback = input(f"is {guess} to high (H),(L) low,(C)correct ?".lower())
        if feedback=='h':
            high = guess-1
        if feedback == "l":
            low = guess+1
    print('yay computer guess your number')
    
guess(10)
computer_guess(10)