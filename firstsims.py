#!/usr/bin/env python

e=0

print "all: datadir/alldone.txt"
print "datadir/madedir.txt:"
print "	mkdir -p `dirname $@`"
print "	touch $@"

names = []
for n in [1000,10000]:
    for f in [1000, 10000]:
        for g in [50, 200, 500]:
            for s in [.1, 1]:
                for p in [0, 0.01, 0.1]:
                    for v in [.1, 1]:
                        for q in [.8, 1, 1.2, 1.4, 1.8]:
                            for a in [0, 1, 2, 3, 4, 5, 8]:
                                for t in [0, .0001, .001, .01, .1]:
                                    for i in xrange(50):
                                        name = "datadir/sim_n%d_f%d_g%d_s%f_p%f_v%f_q%f_a%d_t%f_e%f_i%f.txt.gz" % (n,f,g,s,p,v,q,a,t,e,i)
                                        command = "./simple_test  -n %d -f %d -g %d -s %f -p %f -v %f -q %f -a %d -t %f -e %d"  % (n,f,g,s,p,v,q,a,t,e)
                                        print name + ": datadir/madedir.txt"
                                        print "	" + command + " | gzip -c > $@"
                                        e += 1
                                        names.append(name)

print "datadir/alldone.txt: " + " ".join(names)
            
#usage: ./simple_test [options]
#
#argument   description
#-n         Population size (default=10)
#-m         Mean initial body size (default=10)
#-s         Initial body size standard deviation (default=1)
#-p         Initial probability of carnivore (default = 0)
#-v         Standard deviation body size change (default = 1)
#-f         Total food (default=120)
#-q         Ratio of carnivore to herbivore for eating (default = 1)
#-a         Number of tries carnivore has to eat (default = 2)
#-t         Probability of carnivore-herbivore transition (default=0)
#-g         Number of generations (default = 5)
#-h         Random seed unsigned integer (default = 0)
#-h         Print this help text
