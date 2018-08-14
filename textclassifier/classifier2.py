from NaiveBayes import  Pool
import os


# https://www.python-course.eu/text_classification_python.php

DClasses = ["Positive",  "Negative",  "Neutral"]

base = "learn2/"
p = Pool()
for i in DClasses:
    p.learn(base + i, i)

base = "test2/"
for i in DClasses:
    dir = os.listdir(base + i)
    for file in dir:
        res = p.Probability(base + i + "/" + file)
        print(i + ": " + file + ": " + str(res))