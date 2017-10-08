from bs4 import BeautifulSoup
import urllib2

url = "https://www.goodreads.com/author/quotes/9810.Albert_Einstein"
page = urllib2.urlopen(url)
soup = BeautifulSoup(page.read())
#print(soup.prettify())
print soup.findAll("div", {"class": "quoteText"})
#list = soup.findAll('div', attrs={'id':'quoteText'})
#print len(list)

#for anchor in soup.find_all('a'):
 #   print(anchor.get('href', '/')) 
