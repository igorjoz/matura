phrases = []

data_file = open("pary.txt", "r")

if data_file.readable():
    output = open("4.2.txt", "w")
    # print(data_file.read())
    file_lines = data_file.readlines()
    # print(file_lines)

    for line in file_lines:
        phrases.append(line.split()[1])

    # phrases = ["klllllllrtmmmwer"]

    print(phrases)
    for phrase in phrases:

        counter = 0
        prev_letter = ""
        max_counter = 0
        max_letter = ""

        new_letter = True
        first_of_phrase = True

        for letter in phrase:

            if first_of_phrase:
                counter = 1
                prev_letter = letter
                first_of_phrase = False
            else:
                if prev_letter == letter:
                    counter += 1
                elif prev_letter != letter:
                    if counter > max_counter:
                        max_counter = counter
                        max_letter = prev_letter
                    counter = 1
                    prev_letter = letter

            if counter > max_counter:
                max_counter = counter
                max_letter = letter

        print(max_letter, max_counter)
        for i in range(max_counter):
            output.write(max_letter)
        output.write(" ")
        output.write(str(max_counter))
        output.write("\n")

    output.close()
else:
    print("problem z plikiem")

data_file.close()
