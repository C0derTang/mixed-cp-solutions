zodiac = ['Ox', 'Tiger', 'Rabbit', 'Dragon', 'Snake', 'Horse', 'Goat', 'Monkey', 'Rooster', 'Dog', 'Pig', 'Rat']

n = int(input())
phrases = [input().split() for _ in  range(n)]

cows = {'Bessie':0}
cow_z = {'Bessie':'Ox'}

for phrase in phrases:
    c1, p_n, sign, c2 = phrase[0], phrase[3], phrase[4], phrase[-1]

    cow_z[c1] = sign

    cows[c1] = cows[c2]
    if p_n[0] == 'p':
        if zodiac.index(sign) >= zodiac.index(cow_z[c2]):
            cows[c1] -= 12 - (zodiac.index(sign) - zodiac.index(cow_z[c2]))
        else:
            cows[c1] -= zodiac.index(cow_z[c2]) - zodiac.index(sign)
    else:
        if zodiac.index(sign) > zodiac.index(cow_z[c2]):
            cows[c1] += zodiac.index(sign) - zodiac.index(cow_z[c2])
        else:
            cows[c1] += 12 + (zodiac.index(sign) - zodiac.index(cow_z[c2]))

#print(cows)
print(abs(cows['Elsie']))