# NanoTekSpice
Second year Epitech project.

The NanoTekSpice is a basic electronic circuit simulator. It loads a circuit from a configuration file and allows you to simulate its operation.

## Requirements

- Make
- A compiler that supports C++17 or newer

## Compilation and Installation

```bash
make
```

## Usage

```bash
./nanotekspice <file_name>
```

Available commands :

* `exit` : closes the program.
* `display` : prints the value of all outputs.
* `input=value` : changes the value of an input. This does not apply to `Clock`, `False` and `True`.
* `simulate` : runs the simulation.
* `loop` : continuously runs the simulation until SIGINT is received.

## Circuits

### Location

Some configuration files are located in the `./circuits` directory. You can use one of them or create your own.

### Syntax

```
# Declare your components into the 'chipsets' section...
.chipsets:

# <chipset> <name>
# The name is up to you
# Example :
input   i1
output  s1
4081    and

# ...then link them within the 'links' section
.links:

# <chipset_name1>:<pin1> <chipset_name2>:<pin2>
# Example :
i1:1    and:1
s1:1    and:3
```
