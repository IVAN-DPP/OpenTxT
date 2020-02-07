import pandas as pd
from fanalysis.ca import CA
import numpy as np
from numpy import genfromtxt


df= pd.read_table("../datos1.txt", header=0,index_col=0, delimiter="\n", encoding="utf-8")


my_data=genfromtxt("../datos1.txt",delimiter=" ",skip_header=1)

my_ca = CA(row_labels=df.index.values, col_labels=df.columns.values)
my_ca.fit(my_data)
print(my_ca.eig_)
my_ca.plot_eigenvalues()

my_ca.mapping_col(num_x_axis=1,num_y_axis=2)
