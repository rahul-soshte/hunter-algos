from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Firefox()
driver.get("http://www.pexels.com")
inputElement=driver.find_element_by_class_name("search__input")
inputElement.send_keys("nature")
inputElement.send_keys(Keys.ENTER)
#inputElement.submit()
