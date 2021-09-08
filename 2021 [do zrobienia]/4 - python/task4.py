with open("instrukcje.txt", "r") as file:
    lines = list(map(lambda line: line.strip(), file.readlines()))
    message = ""

    maxInstructionChainName = ""
    maxInstructionChainValue = 0
    currentInstructionChainName = ""
    currentInstructionChainValue = 0

    # addInstructionLettersValues = ["0" * 100]
    addInstructionLettersValues = [0] * 100

    for line in lines:
        instruction, value = line.split()

        # 4.2 ---
        if instruction == currentInstructionChainName:
            currentInstructionChainValue += 1
        else:
            currentInstructionChainName = instruction
            currentInstructionChainValue = 1

        if currentInstructionChainValue >= maxInstructionChainValue:
            maxInstructionChainName = currentInstructionChainName
            maxInstructionChainValue = currentInstructionChainValue
        # -------

        # 4.3 ---
        if instruction == "DOPISZ":
            addInstructionLettersValues[ord(value)] += 1
        # -------

        print(instruction, value)
        if instruction == "DOPISZ":
            message = message + value
        elif instruction == "ZMIEN":
            message = message[:-1] + value
        elif instruction == "USUN":
            message = message[:-1]
        elif instruction == "PRZESUN":
            index = 0
            for letter in message:
                if letter == value:
                    letterOrder = ord(letter)
                    if 65 <= letterOrder < 90:
                        newLetter = chr(letterOrder + 1)
                    else:
                        newLetter = "A"
                    message = message[:index] + newLetter + message[index + 1:]
                    break
                index += 1
        print(message)
    length = len(message)
    print("4.1:", length)
    print("4.2:", maxInstructionChainName, maxInstructionChainValue)
    print("4.3:", chr(addInstructionLettersValues.index(max(addInstructionLettersValues))), max(addInstructionLettersValues))
    print("4.4:", message)

