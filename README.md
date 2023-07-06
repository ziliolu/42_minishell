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

# TESTS 

## LUIZA
- [] echo bonjour ; |
- [] echo bonjour | |
- [] |
- [] echo bonjour |;
- [] echo bonjour ; ls
- [] echo bonjour > test\ 1
- [] cd $HOME/Documents
- [] echo "\s" & echo "\s"
- [] echo >
- [] echo -n -n -nnnn -nnnnm
- [] cat /dev/random | head -n 1 | cat -e
- [] unset var1 # with undefined var1
- [] export "" et unset ""
- [] echo test > file test1
- [] $
- [] not_cmd bonjour > salut
- [] env puis export puis env # vars aren't sorted
- [] cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code
- [] cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code
- [] cat Makefile | grep pr | head -n 5 | hello (NA) # check status code
- [] echo bonjour >>> test
- [] echo bonjour > > out
- [] echo 2 >> out1 > out2
- [] echo 2 > out1 >> out2
- [] cat < test # with non-existent test
- [] export var; export var=test
- [] echo bonjour > $test # with test not defined
- [] file_name_in_current_dir
- [] cd ../../../../../.. ; pwd
- [] ctrl-C . 130 sur bin(ex : sleep 10)&line vide
- [] ctrl-\ .131 sur bin
- [] echo "bip | bip ; coyotte > < " "
- [] cat | cat | cat | ls # check outputs order
- [] $bla # with bla not defined
- [] export var ="cat Makefile | grep >"
- [] export "test=ici"=coucou
- [] c$var Makefile # with var=at
- [] $LESS$VAR
- [] /bin/echo bonjour
- [] not_cmd
- [] sleep 5 | exit
- [] echo bonjour > $test w/ t
- [] "exit retour a la ligne"
- [] minishell # binary not in path without "./" before
- [] cat diufosgid # check exit code
- [] exit # should return the last exit code value
- [] exit -10
- [] exit +10
- [] ;

## IVO
- [x] echo coucou |
- [x] echo "$HOME"
- [x] echo '$HOME'
- [] export
- [x] env # display is different for both commands
- [x] echo $HOME
- [] > log echo coucou
- [] echo hudifg d | | hugdfihd
- [] echo
- [x] echo simple
- [] echo -n simple
- [] echo ''
- [] echo ""
- [] echo "\"
- [x] echo "\n \n \n"
- [] echo "\n \n \\n"
- [] echo ;;
- [x] echo hi";" hihi
- [x] echo hi " ; " hihi
- [] cd
- [x] cd .
- [] cd ~
- [x] cd /
- [x] cd no_file
- [] cd a b c d
- [x] pwd a
- [x] pwd a b c d
- [] export LOL=lala ROR=rara
- [x] unset LOL ROR
- [x] export "HI= hi"
- [] export "HI =hi"
- [x] /bin/ls
- [x] # write something the press ctrl+c
- [x] # write something then press ctrl+d
- [x] # write something then press ctrl+\
- [x] echo $?
- [x] l^Ds
- [x] echo |
- [] | echo
- [] sort | ls # check output order
- [] cat < >
- [] cat < <
- [] cat > >
- [] > a ls > b < Makefile
- [] echo > a Hello World!
- [] > a echo Hello World!
- [x] cat < Makefile | grep gcc > output
- [] exit 0 | exit 1
- [] exit 1 | exit 0