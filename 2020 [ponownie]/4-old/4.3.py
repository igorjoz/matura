# number - string
pairs = []

equal_num_and_len = []
min_num = 10000  # założenie: każda dana liczba z pliku musi być mniejsza od 10000
min_pairs = []
min_strings = []

# min_str = "zzzzzzzzzzzzzzzzzzzzzzzzzzz" # założenie: każdy dany string z pliku musi być mniejszy od "zzzzzzzzzzzzzzzzzzzzzzzzzzz"

data_file = open("pary.txt", "r")

if data_file.readable():

    scope_test = 196

    output = open("4.3.txt", "w")
    # print(data_file.read())
    file_lines = data_file.readlines()
    # print(file_lines)

    for line in file_lines:
        number = int(line.split()[0])
        string = line.split()[1]
        str_length = len(string)
        pairs.append([number, string, str_length])

    print(pairs)

    for pair in pairs:
        # print(pair[0], pair[1], pair[2])
        if pair[0] == pair[2]:
            equal_num_and_len.append([pair[0], pair[1], pair[2]])
            if pair[0] < min_num:
                min_num = pair[0]

    print(equal_num_and_len)

    for pair in equal_num_and_len:
        if pair[0] == min_num:
            min_pairs.append([pair[0], pair[1], pair[2]])
            min_strings.append(pair[1])
    print(min_pairs)
    min_string = min(min_strings)
    answer_index = min_strings.index(min_string)
    answer = min_pairs[answer_index]
    print(min(min_strings), answer)

    output.write(str(answer[0]))
    output.write(" ")
    output.write(str(answer[1]))
    output.write("\n")

    output.close()
else:
    print("problem z plikiem")

data_file.close()


# Para (liczba1, słowo1) jest mniejsza od pary (liczba2, słowo2), gdy:
# – liczba1 < liczba2,
# albo
# – liczba1 = liczba2 oraz słowo1 jest w porządku alfabetycznym mniejsze od słowo2.
