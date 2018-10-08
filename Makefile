all: simple_test unit_rinit_indiv unit_rinit_gen unit_rinit_exp unit_reproduce_indiv unit_reproduce_generation unit_carn_eat unit_carn_search_and_eat unit_all_carn_search_and_eat unit_getshuf unit_all_herb_eat unit_all_starve unit_run_gen unit_run_exp

simple_test: simple_test.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_rinit_indiv: unit_rinit_indiv.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_rinit_gen: unit_rinit_gen.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_rinit_exp: unit_rinit_exp.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_reproduce_indiv: unit_reproduce_indiv.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_reproduce_generation: unit_reproduce_generation.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_carn_eat: unit_carn_eat.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_carn_search_and_eat: unit_carn_search_and_eat.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_all_carn_search_and_eat: unit_all_carn_search_and_eat.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_all_herb_eat: unit_all_herb_eat.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_all_starve: unit_all_starve.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_getshuf: unit_getshuf.c simulator.h
	gcc -Wall -Wpedantic -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_run_gen: unit_run_gen.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
unit_run_exp: unit_run_exp.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $< -o $@
