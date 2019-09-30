import pandas as pd


x = pd.Series(range(100))
print(pd.cut(x, 50, labels=range(50)))