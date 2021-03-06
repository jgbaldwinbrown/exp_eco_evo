#!/usr/bin/env python3

import sys
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data = pd.read_csv(sys.argv[1], sep='\t', names=["Generation", "Individual", "Carnivore", "Size", "Food required", "Alive", "Food eaten"])
for i in data.Generation.unique():
    mydat = data.loc[data["Generation"] == i]
    sns.distplot(mydat.Size)
    plt.show()
    plt.clf()
    

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
