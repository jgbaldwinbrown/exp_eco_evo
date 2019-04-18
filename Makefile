all: simple_test unit_tests/unit_rinit_indiv unit_tests/unit_rinit_gen unit_tests/unit_rinit_exp unit_tests/unit_reproduce_indiv unit_tests/unit_reproduce_generation unit_tests/unit_carn_eat unit_tests/unit_carn_search_and_eat unit_tests/unit_all_carn_search_and_eat unit_tests/unit_getshuf unit_tests/unit_all_herb_eat unit_tests/unit_all_starve unit_tests/unit_run_gen unit_tests/unit_run_exp big_test

simulator.o: simulator.c simulator.h
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm -c $<
simple_test.o: simple_test.c
	gcc -Wall -c $<
simple_test: simple_test.o simulator.o
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_rinit_indiv.o: unit_tests/unit_rinit_indiv.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -c $< -o $@
unit_tests/unit_rinit_indiv: unit_tests/unit_rinit_indiv.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_rinit_gen.o: unit_tests/unit_rinit_gen.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_rinit_gen: unit_tests/unit_rinit_gen.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_rinit_exp.o: unit_tests/unit_rinit_exp.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_rinit_exp: unit_tests/unit_rinit_exp.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_reproduce_indiv.o: unit_tests/unit_reproduce_indiv.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_reproduce_indiv: unit_tests/unit_reproduce_indiv.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_reproduce_generation.o: unit_tests/unit_reproduce_generation.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_reproduce_generation: unit_tests/unit_reproduce_generation.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_carn_eat.o: unit_tests/unit_carn_eat.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_carn_eat: unit_tests/unit_carn_eat.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_carn_search_and_eat.o: unit_tests/unit_carn_search_and_eat.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_carn_search_and_eat: unit_tests/unit_carn_search_and_eat.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_all_carn_search_and_eat.o: unit_tests/unit_all_carn_search_and_eat.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_all_carn_search_and_eat: unit_tests/unit_all_carn_search_and_eat.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_all_herb_eat.o: unit_tests/unit_all_herb_eat.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_all_herb_eat: unit_tests/unit_all_herb_eat.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_all_starve.o: unit_tests/unit_all_starve.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_all_starve: unit_tests/unit_all_starve.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_getshuf.o: unit_tests/unit_getshuf.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -c $< -o $@
unit_tests/unit_getshuf: unit_tests/unit_getshuf.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -Wpedantic -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_run_gen.o: unit_tests/unit_run_gen.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -c $< -o $@
unit_tests/unit_run_gen: unit_tests/unit_run_gen.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
unit_tests/unit_run_exp.o: unit_tests/unit_run_exp.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -c $< -o $@
unit_tests/unit_run_exp: unit_tests/unit_run_exp.o simulator.o
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
big_test.9: big_test.c
	gcc -Wall -I/Users/jbaldwin/Documents/git_repositories/exp_eco_evo -c $< -o $@
big_test: big_test.o simulator.o
	gcc -Wall -I/opt/local/include -L/opt/local/lib -lgsl -lgslcblas -lm $^ -o $@
