from bs4 import BeautifulSoup

soup = BeautifulSoup(open("/var/www/html/wtlab/index.html"))

links = soup.find_all('a')

for link in links:
    print link