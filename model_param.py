#!/opt/anaconda3/envs/icingForecast/bin/python

import joblib


model = joblib.load("/opt/workspace/project/icingForecast/cache/model/LGBMClassifier.model")
# print(dir(model))
print(model.get_params())