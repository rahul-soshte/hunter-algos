from bs4 import BeautifulSoup
import urllib2

url = "https://stupidsid.com/reader/operating-systems-1103/104475"
#page = urllib2.urlopen(url)
#soup = BeautifulSoup(page.read())

#hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
 #      'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
  #     'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
   #   'Accept-Language': 'en-US,en;q=0.8',
    #   'Connection': 'keep-alive'}
req = urllib2.Request(url, headers={'User-Agent' : "Firefox Browser"}) 
#req = urllib2.Request(url, headers=hdr)
page = urllib2.urlopen(req)
soup = BeautifulSoup(page.read())

print(soup.prettify())
#print soup.findAll("div", {"class": "quoteText"})
#list = soup.findAll('div', attrs={'id':'quoteText'})
#print len(list)

#for anchor in soup.find_all('a'):
 #   print(anchor.get('href', '/')) 
