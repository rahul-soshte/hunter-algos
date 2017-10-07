from bs4 import BeautifulSoup

soup = BeautifulSoup (open("soupexample12.html"))

final_link = soup.p.a
final_link.decompose()

trs = soup.find_all('tr')
for tr in trs:
    print tr

