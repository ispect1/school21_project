# Corewar

Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode.

This project can be broken down into three distinctive parts:

- __The assembler:__ this is the program that will compile champions and translate them from the language written them in (assembly language) into “Bytecode”. Bytecode is a machine code, which will be directly interpreted by the virtual machine.
- __The virtual machine:__ It’s the “arena” in which champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. Obviously, the virtual machine should allow for numerous simultaneous processes.
- __The champion:__ It's necessary to create a simple champion just to prove the program functionality.

![Corewar](image/corewar2.gif)

How to run:

`git clone https://github.com/lokida9/school21_project.git 21_projects`

`cd 21_projects/corewar`

`make`

- `./asm [file.s]`

- `./corewar [-v | -dump N] [-a] [-n N] <champion1.cor> <...> `

  - `-v [--ninja]`	: Enables visualization

  - `-dump N`	: Dumps memory after N cycles

  - `-a`	: Prints output from 'aff' (Default is to hide it)

  - `-n N`	: Assigns id N to the player specified right after N
  - `-h`   : Details of the flags
  
### Visualization:
Corewar virtual machine visualization written using the SDL2 library. There are two visualization modes.
- Hidden (does not show memory): `-v --ninja`
- Open (virtual machine data visible) `-v`

### Example:
`./asm champs/helltrain.s`

`./corewar -v --ninja champs/helltrain.cor champs/helltrain.cor champs/helltrain.cor champs/helltrain.cor`
