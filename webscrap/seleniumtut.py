#!/usr/bin/env python

from selenium import webdriver

browser = webdriver.Firefox( executable_path='/opt/geckodriver');                                                                             
browser.get('http://www.ubuntu.com/')
