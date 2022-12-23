A=1
E=5
I=9
O=15
U=21
Y=25
s=0

ch=input("donner ch ")
ch=ch.upper()#doit etre majuscule
for i in range (len(ch)):
    if ch[i]=="A":
        s=s+(i+1)*A
    elif ch[i]=="E":
        s=s+(i+1)*E  
    elif ch[i]=="I":
        s=s+(i+1)*I 
    elif ch[i]=="O":
        s=s+(i+1)*O
    elif ch[i]=="U":
        s=s+(i+1)*U
    elif ch[i]=="Y":
        s=s+(i+1)*Y
print(s)

        
