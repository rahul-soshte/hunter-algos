from bs4 import BeautifulSoup
import urllib2

url = "https://www.goodreads.com/quotes/tag/love"
page = urllib2.urlopen(url)
soup = BeautifulSoup(page.read())

for anchor in soup.find_all('a'):
    print(anchor.get('href', '/')) 