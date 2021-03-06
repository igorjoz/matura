def liczba_odkryta(liczba):
    pom = liczba
    while pom > 0:
        cyfra = pom % 10
        pom //= 10      
        if cyfra != 0 and liczba % cyfra != 0:
            return False
    return True

print(liczba_odkryta(222))
