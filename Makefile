all: simple_test unit_rinit_indiv unit_rinit_gen unit_rinit_exp

simple_test: simple_test.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_rinit_indiv: unit_rinit_indiv.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_rinit_gen: unit_rinit_gen.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_rinit_exp: unit_rinit_exp.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
