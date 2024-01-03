import pandas as pd 
from sklearn.preprocessing import MinMaxScaler
import math 
import numpy as np   
from sklearn import metrics , svm
from sklearn.linear_model import LinearRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split , cross_val_score
import matplotlib.pyplot as plt 
from sklearn.preprocessing import StandardScaler 
from sklearn.neighbors import KNeighborsClassifier

file_url = "https://raw.githubusercontent.com/krahul2024/dsa-acad/usacoCodes/dm/datasets/data.csv"
ch_data = pd.read_csv(file_url , index_col=0) 
ch_data=ch_data.dropna()

ch_data['Sex'] = ch_data['Sex'].replace({'M': 0, 'F': 1})                                # Male: 0, Female: 1
ch_data['Ascites'] = ch_data['Ascites'].replace({'N': 0, 'Y': 1})                      # N: 0, Y: 1
ch_data['Drug'] = ch_data['Drug'].replace({'D-penicillamine': 0, 'Placebo': 1})       # D-penicillamine: 0, Placebo: 1
ch_data['Hepatomegaly'] = ch_data['Hepatomegaly'].replace({'N': 0, 'Y': 1})            # N: 0, Y: 1
ch_data['Spiders'] = ch_data['Spiders'].replace({'N': 0, 'Y': 1})                      # N: 0, Y: 1
ch_data['Edema'] = ch_data['Edema'].replace({'N': 0, 'Y': 1, 'S': -1})                 # N: 0, Y: 1, S: -1
ch_data['Status'] = ch_data['Status'].replace({'C': 0, 'CL': 1, 'D': -1})

ch_data.describe()

def z_score_normalization(data):
    mean = np.mean(data)
    std = np.std(data)
    normalized_data = (data - mean) / std
    return normalized_data


numerical_columns = ch_data.select_dtypes(include=np.number).columns
ch_data[numerical_columns] = ch_data[numerical_columns].apply(z_score_normalization)


ch_data.describe()

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import f1_score

threshold_low = 0.5
threshold_medium = 1.5

ch_data['Stage_Class'] = pd.cut(ch_data['Stage'], bins=[-float('inf'),0.2 ,0.8, float('inf')],
                                labels=['Low', 'Medium', 'High'])


X = ch_data.drop(['Stage', 'Stage_Class'], axis=1) 
y = ch_data['Stage_Class']


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


knn = KNeighborsClassifier()


knn.fit(X_train, y_train)

y_pred = knn.predict(X_test)

cm = metrics.confusion_matrix(y_test, y_pred)
tn, fp, fn, tp = cm.ravel()
f1_score = tp/(tp+0.5*(fp + fn))
print('f1 score: ' ,f1_score )
