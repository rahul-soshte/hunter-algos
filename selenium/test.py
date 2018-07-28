from selenium import webdriver
from selenium.webdriver.common.keys import Keys
user = "rahul.soshte47@gmail.com"
pwd = "9321187149"

driver = webdriver.Firefox()
driver.get("http://127.0.0.1/html/emipay")
assert "EMI Pay" in driver.title
elem = driver.find_element_by_id("email")
elem.send_keys(user)
elem = driver.find_element_by_id("pass")
elem.send_keys(pwd)
#elem.send_keys(Keys.RETURN)
#driver.close()
login_button= driver.find_element_by_id("login")
login_button.click()