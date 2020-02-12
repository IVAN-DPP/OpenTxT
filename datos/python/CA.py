import pandas as pd
from fanalysis.ca import CA
import numpy as np
from sklearn import preprocessing
import matplotlib
#matplotlib.rc('xtick', labelsize=2)
#matplotlib.rc('ytick', labelsize=2)
matplotlib.rc('font',size=10)



df= pd.read_table("DatosP1.txt",header=0 ,index_col=0, sep=" ", encoding="utf-8")
#print(df)
my_data=df.values
new_my_data=np.delete(my_data,my_data.shape[1]-1,axis=1)
#col_labels=np.delete(df.columns.values,df.columns.values.shape[0]-1,None)
#print(df.columns.values.shape[0])

  
my_ca = CA(row_labels=df.index.values, col_labels=np.delete(df.columns.values,df.columns.values.shape[0]-1,None))

my_ca.fit(new_my_data)
#print(my_ca.eig_)
#print(my_ca.col_topandas())
#print(df.columns.values)
#print(my_ca.row_coord_)
#my_ca.plot_eigenvalues()

my_ca.plot_col_contrib(num_axis=1)
my_ca.plot_row_contrib(num_axis=1)
my_ca.plot_col_contrib(num_axis=2)
my_ca.plot_row_contrib(num_axis=2)
#my_ca.plot_row_contrib(num_axis=1)

my_ca.mapping_row(num_x_axis=1,num_y_axis=2,figsize=(10,8))
#X= my_ca.row_contrib_[:,0]*10000
#Y= my_ca.row_contrib_[:,1]*10000
#matplotlib.pyplot.plot(X,Y,'o')

#matplotlib.pyplot.show()
