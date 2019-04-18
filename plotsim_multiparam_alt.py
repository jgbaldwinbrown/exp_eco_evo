#!/usr/bin/env python3

import sys
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import re

paths = [x.rstrip('\n') for x in sys.stdin]

nameparse = re.compile(r'sim_(.*)\.txt.gz')

for iterator, p in enumerate(paths):
    fname = p.split('/')[-1]
    fname2 = nameparse.sub(r'\1', fname)
    sname = fname2.split('_')
    sname2 = []
    for i in sname:
        var = i[0]
        val = float(i[1:])
        #try:
        #    val = int(i[1:])
        #except ValueError:
        #    val = float(i[1:])
        sname2.append((var, val))
    tempdata = pd.read_csv(p, sep='\t', names=["Generation", "Individual", "Carnivore", "Size", "Food required", "Alive", "Food eaten"])
    final_gen = tempdata.Generation.unique()[-1]
    tempdata2 = tempdata.loc[tempdata["Generation"] == final_gen]
    for var, val in sname2:
        tempdata[var] = [val for x in range(tempdata.shape[0])]
    if iterator==0:
        data = tempdata
    else:
        data = pd.concat([data, tempdata])
    
#for i in data.Generation.unique():
#    mydat = data.loc[data["Generation"] == i]
#    sns.distplot(mydat.Size)
#    plt.show()
#    plt.clf()
    
g = sns.FacetGrid(data, row="f", col="t")
g = g.map(plt.hist, "Size")
plt.savefig(sys.argv[1], format='pdf')
plt.clf()
#g = sns.FacetGrid(mydat, col="time",  row="smoker")
#g = g.map(plt.hist, "total_bill")
    

#0	0	0	9.214614	9.214614	1	12.000000
#0	1	0	9.098913	9.098913	1	12.000000
#0	2	0	11.110537	11.110537	1	12.000000
#0	3	0	8.708719	8.708719	1	12.000000
#0	4	0	10.845745	10.845745	1	12.000000
#0	5	0	10.723284	10.723284	1	12.000000
#0	6	0	6.863515	6.863515	1	12.000000
#0	7	0	10.272029	10.272029	1	12.000000
#0	8	0	11.263050	11.263050	1	12.000000
#0	9	0	9.474342	9.474342	1	12.000000
#
#madedir.txt
#sim_n1000_f1000000_g200_s0.100000_p0.100000_v0.100000_q1.000000_a2_t0.010000_e800.000000_i0.000000.txt.gz
