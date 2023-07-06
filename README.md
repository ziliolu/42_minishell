# Minishell

<p align="center">
  <img src="https://img.shields.io/github/languages/top/ziliolu/42_minishell?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/status-in%20process-yellow?style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/ziliolu/42_minishell?color=#FFFFFF&style=flat-square" />
</p>

Partner: [Ivo Marques](https://github.com/Pastilhex)

## Table of Contents

- [About](#about)
- [Features](#features)

## About

The Minishell project is a minimalistic shell implementation developed as part of the 42 curriculum. It aims to provide a basic shell environment capable of executing commands, handling environment variables, and supporting various shell features. The project is implemented using the C programming language and adheres to POSIX standards.

## Features

- Command execution and handling of basic shell commands.
- Support for environment variables and variable expansion.
- Basic signal handling and built-in signal commands.
- Redirection and pipes for input/output redirection and command chaining.
- Background process execution and management.
- Error handling and graceful error reporting.


## Tests

## ENV vs LOCAL VARIABLES

  sem a palavra export
    1. verificar se existe em alguma das listas
    2. alterar a informacao da lista que pertence ou criar um novo nó na list de vars

  com a palavra export
    1. verificar se existe no env
    2. alterar a info no env ou criar um novo nó no env

  se variavel ja existir no env, nao é possivel criar fora outra 
  com o mesmo nome e info diferente. 


 
##### Redirects w/wout here_docs

- [] ls > t1
- [] ls > t1 > t2
- [] ls > t1 > t2 > t2
- [] echo test > t1 << eof
- [] echo test << eof > t1

#### Quotes without redirects 

- [] ls -a ""-""l
- [] echo "o"ola"

#### Quotes with redirects

- []
- [X] ls >     "abcd"
- [X] ls >   "'abc'"
- [X]  ls >   'abcde'
- []     ls
- [X] ls    >     '"abc"'

#### ENV

-[] echo $path

ls -a
🔴 ls -l -a
🔴 ls --help
🔴 ls > "abc"

## EXPORT

- [] export name=maria=joao
- [] export name==maria
- []