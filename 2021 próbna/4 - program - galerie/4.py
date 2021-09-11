galleriesQuantity = 140
data = []
countries = []
countriesGalleriesCounter = {}

with open("galerie.txt", "r") as inputFile:
    for line in inputFile.readlines():
        line = line.split()
        countryId, city, *nums = line
        nums = list(map(lambda x: int(x), nums))
        # print(countryId, city, nums)
        data.append([countryId, city, nums])
        if countryId not in countries:
            countries.append(countryId)

# 4.1
print(countries)
for country in countries:
    countriesGalleriesCounter[country] = 0

for line in data:
    print(line[0], line[1], line[2])
    countriesGalleriesCounter[line[0]] += 1

with open("wynik4_1.txt", "w") as output1:
    for country, value in countriesGalleriesCounter.items():
        print(country, value)
        output1.write(country + " " + str(value) + "\n")

# 4.2 a) i b)
citySurfaceSum = {}
cityShopsSum = {}

with open("wynik4_2a.txt", "w") as output2a:
    for line in data:
        sumOfSurface = 0
        sumOfShops = 0
        for i in range(0, 140, 2):
            if line[2][i] != 0:
                sumOfSurface += line[2][i] * line[2][i + 1]
                sumOfShops += 1
            else:
                break

        citySurfaceSum[line[1]] = sumOfSurface
        cityShopsSum[line[1]] = cityShopsSum
        output2a.write(line[1] + " " + str(citySurfaceSum[line[1]]) + " " + str(sumOfShops) + "\n")
        print(line[1], citySurfaceSum[line[1]], sumOfShops)

# b)
maxValue = 0
maxCity = ""
minValue = 100000  # max integer
minCity = ""

for city, value in citySurfaceSum.items():
    if value > maxValue:
        maxValue = value
        maxCity = city
    elif value < minValue:
        minValue = value
        minCity = city

print("\n")
print(maxCity, maxValue)
print(minCity, minValue)
print("\n")

with open("wynik4_2b.txt", "w") as output2b:
    output2b.write(str(maxCity) + " " + str(maxValue) + "\n")
    output2b.write(str(minCity) + " " + str(minValue) + "\n")

# 4.3
maxDiffTypes = 0
maxDiffCity = ""
minDiffTypes = 1000000
minDiffCity = ""

for line in data:
    shopSurfaces = set()
    differentType = 0
    for i in range(0, 140, 2):
        if line[2][i] != 0:
            shopSurfaces.add(line[2][i] * line[2][i + 1])
        else:
            break
    print(line[1], shopSurfaces)
    differentType = len(shopSurfaces)
    print(line[1], differentType)
    if differentType > maxDiffTypes:
        maxDiffTypes = differentType
        maxDiffCity = line[1]
    elif differentType < minDiffTypes:
        minDiffTypes = differentType
        minDiffCity = line[1]

with open("wynik4_3.txt", "w") as output3:
    output3.write(maxDiffCity + " " + str(maxDiffTypes) + "\n")
    output3.write(minDiffCity + " " + str(minDiffTypes) + "\n")
