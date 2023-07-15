# Minishell
​
<p align="center">
  <img src="https://img.shields.io/github/languages/top/ziliolu/42_minishell?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/status-in%20process-yellow?style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/ziliolu/42_minishell?color=#FFFFFF&style=flat-square" />
</p>
​
Partner: [Ivo Marques](https://github.com/Pastilhex)
​

# Mandatory Part
## Compile
- make -n "-Wall -Wextra -Werror"
- make
​
## Simples Command & global variables
- [x] /bin/ls
- [x] /bin/pwd
- [x] #write nothing
- [x] #spaces
- [X] #tab
​
## Arguments
- [X] /bin/ls -la
- [X] /bin/echo 42porto
- [X] /bin/echo $HOME 42porto
- [X] /bin/find minishell
​
## echo
- [X] echo
- [x] echo 42porto
- [X] echo -n 42porto
- [X] $HOME
- [X] echo Ola eu sou o aluno $USERNAME da 42porto
- [X] echo -n Estou_a_gostar_do_
​
## exit
- [x] exit
- [x] exit 1
- [x] exit 255
​
## Return value of a process
- [x] /bin/echo 42porto
`execute echo $?`
- [x] /bin/ls /booom
`execute echo $?`
- [x] /bin/lss
`execute echo $?`
- [x] echo $? + $?
`execute echo $?`
​
​
## Signals
- Test the following commands in a empty prompt
- [X] Ctrl + C
- [X] Ctrl + \
- [X] Ctrl + D
- Test the following commands in a prompt with some text
- [X] Ctrl + \
- [X] Ctrl + D
- Test the command cat without arguments
- [x] Ctrl + C
- [x] Ctrl + \
- [x] Ctrl + D
​
## Double Quotes
- [x] "Just a simple test"
- [x] echo "cat lol.c | cat > lol.c"
- [x] echo "$HOME"
- [x] echo "HOME"$HOME"HOME
- [x] cd "$HOME"
- [x] ls "-l" "-a"
- [x] ls "-l""-a"
​
## Single Quotes
- [x] ls '-la'
- [ ] ls '' # export school=42lisboa bestschool=42porto
- [x] ls ' '
- [ ] ls > 'txt' 
- [ ] ls > "'txt'"
​
## env
- [x] env
- [x] printenv -0
​
## export
- [x] school=42
- [x] export school=42porto 
- [x] export school=42lisboa bestschool=42porto
​
## unset
- [x] unset school
- [x] unset bestschool
- [ ] env
​
## cd
- [x] cd $HOME
- [x] cd ~
- [x] cd Documents
- [x] cd Docs
- [x] cd .
- [x] cd ..
​
## pwd
- [x] /bin/pwd
- [x] pwd -LP
​
## Relative Path
- [x] /bin/cd .././../
- [x] /bin/cd ~/../../home/
​
## Environment path
- [x] ls
- [ ] unset $PATH
- [ ] Set the path $PATH="any/path/at/your/choice"
​
## Redirection
- [ ] 
- [ ] 
- [ ] 
- [ ] 
​
## Pipes
- [ ] 
- [ ] 
- [ ] 
- [ ] 
​
## Go Crazy and history
- [ ] Type a command line, then use Ctrl+C and tpress "Enter". The buffershoul be clean and there should be nothing left to execute.
- [ ] Can we navigate through  history using Up and Down? Can we retry some command?
- [ ] Execute commands that should not work like 'dsbskjhslkjh'. Ensure minishell doesn't crash and prints an error.
- [ ] 'cat | cat | ls' should behave in "normal way".
- [ ] Try to execute a long command with a ton of arguments.
- [ ] Have fun with that beautiful minishell and enjoy it!
- [ ] ls -l -a -F | grep a | wc -l > txt
- [ ] ls -l -a -F | grep a | grep o | wc -l > new >> eof
​
​
## Environment variables
- [x] echo $HOME `test with other variables`
- [ ] Check that $ is interpreted as an environment variable.
- [ ] Check that double quotes interpolate $.
- [ ] Check that USER exists. Otherwise, set it.
- [ ] echo "$USER" should print the value of the USER variable.
​
# Bonus
## And, Or
Use &&, || and parenthesis with commands and ensure minishell behaves the same way bash does. 
​
## Wildcard
- Use wildcards in arguments in the current working directory.
​
## Surprise! (or not...)
`Set User environment variable`
- [x] echo "'$USER'" should print USER variable
- [x] echo '"$USER"' should print "$USER" variable

## LUIZA
- [] echo "\n \n \n"
- [] echo \n \n \n
- [] echo "\n \n \\n"
- [] exit # should return the last exit code value
- [x] cat <<
- [x] echo bonjour ; |
- [x] echo bonjour | |
- [x] |
- [x] echo bonjour |;
- [x] echo bonjour ; ls
- [x] echo bonjour > test\ 1 (nao tratar)
- [x] cd $HOME/Documents
- [x] echo >
- [x] echo -n -n -nnnn -nnnnm
- [x] cat /dev/random | head -n 1 | cat -e
- [x] unset var1 # with undefined var1
- [x] export ""
- [x] echo test > file test1
- [x] $
- [x] not_cmd bonjour > salut
- [x] env puis export puis env # vars aren't sorted
- [x] echo bonjour >>> test
- [x] echo bonjour > > out
- [x] echo 2 >> out1 > out2
- [x] echo 2 > out1 >> out2
- [x] cat < test # with non-existent test
- [x] export var; export var=test
- [x] echo bonjour > $test # with test not defined
- [x] file_name_in_current_dir
- [x] cd ../../../../../.. ; pwd
- [x] ctrl-C . 130 sur bin(ex : sleep 10)&line vide
- [x] ctrl-\ .131 sur bin
- [x] echo "bip | bip ; coyotte > < " "
- [x] cat | cat | cat | ls # check outputs order
- [x] $bla # with bla not defined
- [x] export var ="cat Makefile | grep >"
- [x] export "test=ici"=coucou
- [x] c$var Makefile # with var=at
- [x] $LESS$VAR
- [x] /bin/echo bonjour
- [x] not_cmd
- [x] sleep 5 | exit
- [x] echo bonjour > $test w/ t
- [x] "exit retour a la ligne"
- [x] minishell # binary not in path without "./" before
- [x] cat diufosgid # check exit code
- [x] exit -10
- [x] exit +10
- [x] ;
- [x] cat < >
- [x] cat < <
- [x] cat > >
- [x] > a ls > b < Makefile
- [x] echo > a Hello World!
- [x] > a echo Hello World!
- [x] echo coucou |
- [x] echo "$HOME"
- [x] echo '$HOME'
- [x] export
- [x] env # display is different for both commands
- [x] echo $HOME
- [x] > log echo coucou
- [x] echo hudifg d | | hugdfihd
- [x] echo
- [x] echo simple
- [x] echo -n simple
- [x] echo ''
- [x] echo ""
- [x] echo ;;
- [x] echo hi";" hihi
- [x] echo hi " ; " hihi
- [x] cd
- [x] cd .
- [x] cd ~
- [x] cd /
- [x] cd no_file
- [x] cd a b c d
- [x] pwd a
- [x] pwd a b c d
- [x] export LOL=lala ROR=rara
- [x] unset LOL ROR
- [x] export "HI= hi"
- [x] export nome=
- [x] export "HI =hi"
- [x] /bin/ls
- [x] # write something the press ctrl+c
- [x] # write something then press ctrl+d
- [x] # write something then press ctrl+\
- [x] echo $?
- [x] l^Ds
- [x] echo |
- [x] | echo
- [x] sort | ls # check output order
- [x] cat < Makefile | grep gcc > output
- [x] exit 0 | exit 1
- [x] exit 1 | exit 0

