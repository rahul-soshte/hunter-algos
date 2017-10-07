from bs4 import BeautifulSoup

soup = BeautifulSoup(open("/var/www/html/wtlab/index.html"))

print(soup.prettify())

