# Exp_Eco_Evo

This program performs a Wright-Fisher-like simulation of a population of individuals.
These individuals vary along the axes of body size and carnivory. Carnivorous
individuals eat only herbivorous individuals that are smaller than the carnivore
by a fixed amount (parameter `-q`). Total population size is always fixed.

# Dependencies

The following programs and libraries are required to build exp_eco_evo:

- `gcc`
- `make`
- The GNU scientific library

# Installation

```sh
make
```

# Usage

```
usage: ./simple_test [options]

argument   description
-n         Population size (default=10)
-m         Mean initial body size (default=10)
-s         Initial body size standard deviation (default=1)
-p         Initial probability of carnivore (default = 0)
-v         Standard deviation body size change (default = 1)
-f         Total food (default=120)
-q         Ratio of carnivore to herbivore for eating (default = 1)
-a         Number of tries carnivore has to eat (default = 2)
-t         Probability of carnivore-herbivore transition (default=0)
-g         Number of generations (default = 5)
-e         Random seed unsigned integer (default = 0)
-h         Print this help text
```

# Output

Output is tabular, with one line per individual. The output lines correspond to the following traits:

