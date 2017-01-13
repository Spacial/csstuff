#!/usr/bin/python3

def Anselmo(x,y):
    if y == 0:
        #print("-",x,y,":1")
        return 1
    if x == 0:
        #print("+",x,y,"=",x+2)
        return x+2
    if x == 1 and  y == 0:
        #print("!",x,y,">2")
        return 2
    #print("rec:",x,y)
    return Anselmo(Anselmo(x-1,y),y-1)

print('Anselmo : {}'.format(Anselmo(4,3)))
