from bs4 import BeautifulSoup
import urllib2

#soup = BeautifulSoup(open("soupexample12.html"))
url = "https://www.pexels.com/search/nature/"
page = urllib2.urlopen(url)
soup = BeautifulSoup(page.read())

final_link = soup.p.a
final_link.decompose()

links = soup.find_all('a')

for link in links:
    names = link.contents[0]
    fullLink = link.get('href')
    print names
    print fullLink