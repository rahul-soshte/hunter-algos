import urllib2, sys
from bs4 import BeautifulSoup

site= "https://www.pexels.com/search/nature/"
hdr = {'User-Agent': 'Mozilla/5.0'}
req = urllib2.Request(site,headers=hdr)
page = urllib2.urlopen(req)
soup = BeautifulSoup(page)
print soup