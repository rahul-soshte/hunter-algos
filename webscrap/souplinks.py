from bs4 import BeautifulSoup

soup = BeautifulSoup(open("soupexample12.html"))

final_link = soup.p.a
final_link.decompose()

links = soup.find_all('a')

for link in links:
    names = link.contents[0]
    fullLink = link.get('href')
    print names
    print fullLink