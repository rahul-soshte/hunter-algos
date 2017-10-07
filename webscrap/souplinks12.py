from bs4 import BeautifulSoup
import csv

soup = BeautifulSoup (open("soupexample12.html"))

final_link = soup.p.a
final_link.decompose()

f = csv.writer(open("soupexample12.csv", "w"))
f.writerow(["Name", "Link"]) # Write column headers as the first line

links = soup.find_all('a')
for link in links:
    names = link.contents[0]
    fullLink = link.get('href')

    f.writerow([names, fullLink])

