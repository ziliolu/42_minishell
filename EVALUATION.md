# Minishell

<p align="center">
  <img src="https://img.shields.io/github/languages/top/ziliolu/42_minishell?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/status-in%20process-yellow?style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/ziliolu/42_minishell?color=#FFFFFF&style=flat-square" />
</p>

Partner: [Ivo Marques](https://github.com/Pastilhex)

# Mandatory Part
## Compile
- make -n "-Wall -Wextra -Werror"
- make

## Simples Command & global variables
- [x] /bin/ls
- [x] /bin/pwd
- [x] #write nothing
- [x] #spaces
- [X] #tab

## Arguments
- [X] /bin/ls -la
- [X] /bin/echo 42porto
- [X] /bin/echo $HOME 42porto
- [X] /bin/find minishell

## echo
- [X] echo
- [x] echo 42porto
- [X] echo -n 42porto
- [X] $HOME
- [X] echo Ola eu sou o aluno $USERNAME da 42porto
- [X] echo -n Estou_a_gostar_do_

## exit
- [x] exit
- [x] exit 1
- [x] exit 255

## Return value of a process
- [x] /bin/echo 42porto
`execute echo $?`
- [x] /bin/ls /booom
`execute echo $?`
- [x] /bin/lss
`execute echo $?`
- [x] echo $? + $?
`execute echo $?`


## Signals
- Test the following commands in a empty prompt
- [X] Ctrl + C
- [X] Ctrl + \
- [X] Ctrl + D
- Test the following commands in a prompt with some text
- [X] Ctrl + \
- [X] Ctrl + D
- Test the command cat without arguments
- [ ] Ctrl + C
- [ ] Ctrl + \
- [ ] Ctrl + D

