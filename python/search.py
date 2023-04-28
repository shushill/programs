from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.firefox.webdriver import FirefoxProfile
from selenium.webdriver.firefox.firefox_binary import FirefoxBinary

# create a new Firefox session
#profile = FirefoxProfile("/root/.mozilla/firefox/omyjphvl.default")
driver = webdriver.Firefox()
driver.implicitly_wait(30)
driver.maximize_window()

# Navigate to the application home page
driver.get("https://shushill.github.io")

# get the search textbox


# close the browser window
driver.quit()
