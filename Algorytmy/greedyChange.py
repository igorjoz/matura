denominationsOfMoney = [10, 5, 2, 1]
change = 377
currentDenominationIndex = 0
currentDenomination = denominationsOfMoney[currentDenominationIndex]
givenDenominations = []

print(change)

while change > 0:
    if currentDenomination <= change:
        change -= currentDenomination
        givenDenominations.append(currentDenomination)
    else:
        currentDenominationIndex += 1
        currentDenomination = denominationsOfMoney[currentDenominationIndex]
print(givenDenominations)

result = ""
for givenDenomination in givenDenominations:
    result += str(givenDenomination) + ";"
print(result)
