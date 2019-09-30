from time import time
from sklearn import datasets
from lightgbm import LGBMClassifier
from xgboost import XGBClassifier
from sklearn.ensemble import GradientBoostingClassifier

dataset = datasets.load_digits()
x = dataset.data
y = dataset.target

print("The train data size:", x.shape)

start_time_point = time()
clf1 = LGBMClassifier()
clf1.fit(x, y)
print("The LightGBM model train model take time:", time()-start_time_point)

start_time_point = time()
clf2 = GradientBoostingClassifier()
clf2.fit(x, y)
print("The GBDT model train model take time:", time()-start_time_point)

start_time_point = time()
clf3 = XGBClassifier()
clf3.fit(x, y)
print("The XGBOST model train model take time:", time()-start_time_point)