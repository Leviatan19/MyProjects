alfabet="AĄBCĆDEĘFGHIJKLŁMNŃOÓPRSŚTUWYZŹŻ"

# Zadanie polega na odszyfrowanie fragmentu powieści "Lalka", który został zaszyfrowany szyfrem Vigenera pewnym pięcioliterowym kluczem

def zlicz(tekst):               # funkcja zlicz zlicza wszystkie polskie znaki, które wystąpiły w tekście
  ile=[0]*32
  for znak in tekst:
    if znak in alfabet:
      poz=alfabet.index(znak)
      ile[poz]+=1
  return ile

def cezar(napis, klucz):        # funkcja cezar szyfruje napis przesuwając każdy znak tekstu o wartość klucza
    abc="AĄBCĆDEĘFGHIJKLŁMNŃOÓPRSŚTUWYZŹŻ"
    abcd="aąbcćdeęfghijklłmnńoóprsśtuwyzźż"
    result=""
    regula=str.maketrans(abc, abc[klucz:]+abc[:klucz])      # przekształcenie starego alfabetu na nowy alfabet zgodnie z kluczem
    regula2=str.maketrans(abcd, abcd[klucz:]+abcd[:klucz])
    for litera in napis:
        if litera in abc:
            result=result+litera.translate(regula)          # szyfrowanie zgodnie z nowym alfabetem
        elif litera in abcd:
            result=result+litera.translate(regula2)
        else:
            result=result+litera
    return result
    
def piaty(tekst, start):        #f unkcja piąty wypisuje co piąty znak z tekstu, zaczynając od znaku start(liczba z zakresu od 0 do 4)
  l=0
  dane=""
  for x in tekst:
    if (l-start)%5==0:
      dane=dane+x
    l+=1
  return dane

def maks(tablica):              # funkcja maksimum zwraca indeks z tablicy, który miał największą wartość
    maksimum=tablica[0]
    for x in tablica:
        if x>maksimum:
            maksimum=x
    return tablica.index(maksimum)
  
plik=open('tekst2.txt', 'r')    # wczytanie obu plików i zliczenie wszystkich liter z obu plików
tekst2=plik.read()
ile2=zlicz(tekst2)
plik=open('lalka.txt', 'r')
lalka=plik.read().upper()
ile=zlicz(lalka)

przes_teksta=maks(ile)-maks(zlicz(piaty(tekst2.upper(), 0)))    # maks(zlicz(piaty(tekst2.upper(), 0))) to jest ustalenie, który znak wystąpił najczęściej w tekście, składającym się z co piątej litery zaszyfrowanego tekstu(.upper sprawia, że wszystkie litery są wielkie)
przes_tekstb=maks(ile)-maks(zlicz(piaty(tekst2.upper(), 1)))    # maks(ile) - maks(to powyżej) ustala nam literę szyfru, gdzie maks(ile) to indeks litery najczęściej występujący w lalce(praktycznie zawsze w polskich tekstach jest to litera "A")
przes_tekstc=maks(ile)-maks(zlicz(piaty(tekst2.upper(), 2)))    # analogicznie dla 5 fragmentów tekstu
przes_tekstd=maks(ile)-maks(zlicz(piaty(tekst2.upper(), 3)))
przes_tekste=maks(ile)-maks(zlicz(piaty(tekst2.upper(), 4)))
teksta=cezar(piaty(tekst2, 0),przes_teksta)                     # szyfrowanie 5 fragmentów tekstu zgodnie ze znalezionym kluczem, odpowiednio dla każdego fragmentu
tekstb=cezar(piaty(tekst2, 1),przes_tekstb)
tekstc=cezar(piaty(tekst2, 2),przes_tekstc)
tekstd=cezar(piaty(tekst2, 3),przes_tekstd)
tekste=cezar(piaty(tekst2, 4),przes_tekste)
v=""
# Try i except są potrzebne, gdyż pętla for dla len(teksta)-1 nie wydrukuje ostatnich 4 liter tekstu przez IndexError
for x in range(0, len(teksta)):
    v=v+teksta[x]
    try:
        v=v+tekstb[x]
    except IndexError:
        pass
    try:
        v=v+tekstc[x]
    except IndexError:
        pass
    try:
        v=v+tekstd[x]
    except IndexError:
        pass
    try:
        v=v+tekste[x]
    except IndexError:
        pass

print(v)

