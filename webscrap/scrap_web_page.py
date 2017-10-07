from bs4 import BeautifulSoup
import urllib2

url = "https://stackoverflow.com/questions/45687034/how-to-change-layout-when-rotate"
page = urllib2.urlopen(url)
soup = BeautifulSoup(page.read())

for anchor in soup.find_all('a'):
    print(anchor.get('href', '/')) 