outputFile = open("wyniki6.txt", "w")

with open("dane.txt", "r") as inputFile:
    lines = []
    for line in inputFile.readlines():
        line = list(map(lambda x: int(x), line.split()))
        lines.append(line)
    # print(lines)

    # 1.
    minValue = lines[0][0]
    maxValue = lines[0][0]
    for line in lines:
        for num in line:
            if num < minValue:
                minValue = num
            if num > maxValue:
                maxValue = num
    outputFile.write("6.1.:\nnajjasniejszy: ")
    outputFile.write(str(maxValue))
    outputFile.write("\nnajciemniejszy: ")
    outputFile.write(str(minValue))
    outputFile.write("\n\n")

    # 2.
    brokenLinesCounter = 0
    for line in lines:
        for i in range(160):
            if line[i] != line[320 - i - 1]:
                brokenLinesCounter += 1
                break
    outputFile.write("6.2.:\n")
    outputFile.write(str(brokenLinesCounter))
    outputFile.write("\n\n")

    # 3.
    contrastingPixelsCounter = 0
    linesExtended = [322 * [-1]]
    # print(linesExtended)
    for line in lines:
        newLine = line.copy()
        newLine.insert(0, -1)
        newLine.append(-1)
        linesExtended.append(newLine)
    linesExtended.append(322 * [-1])
    print(linesExtended)
    for i in range(1, 200):
        for j in range(1, 321):
            if (abs(linesExtended[i][j] - linesExtended[i - 1][j]) > 128 and linesExtended[i - 1][j] != -1)\
                    or (abs(linesExtended[i][j] - linesExtended[i + 1][j]) > 128 and linesExtended[i + 1][j] != -1)\
                    or (abs(linesExtended[i][j] - linesExtended[i][j - 1]) > 128 and linesExtended[i][j - 1] != -1)\
                    or (abs(linesExtended[i][j] - linesExtended[i][j + 1]) > 128 and linesExtended[i][j + 1] != -1):
                contrastingPixelsCounter += 1
    # print(contrastingPixelsCounter)
    outputFile.write("6.3.:\n")
    outputFile.write(str(contrastingPixelsCounter))
    outputFile.write("\n\n")

    # 4.
    longestStreak = 0
    for i in range(320):
        currentNum = lines[0][i]
        currentStreak = 1
        for j in range(1, 200):
            if lines[j][i] == currentNum:
                currentStreak += 1
            else:
                currentNum = lines[j][i]
                currentStreak = 1
            if currentStreak > longestStreak:
                longestStreak = currentStreak
    # print(longestStreak)
    outputFile.write("6.4.:\n")
    outputFile.write(str(longestStreak))
    outputFile.write("\n")
