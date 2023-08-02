# Minishell Test List

## Builtins

### echo

- [ ] `echo "Hello, World!"` # echo a simple message
- [ ] `echo "Hello, World!" > output.txt` # echo a message and redirect output to a file
- [ ] `echo -n "Hello, World!"` # echo with the -n option to suppress the newline
- [ ] `echo "$HOME"` # echo the value of the HOME environment variable
- [ ] `echo '$HOME'` # echo the literal string '$HOME'
- [ ] `echo \`date\`` # echo the result of a command substitution
- [ ] `echo *` # echo files in the current directory (wildcard expansion)

### cd

- [ ] `cd /` # Change to the root directory
- [ ] `cd /path/to/directory` # Change to an absolute path
- [ ] `cd relative/path/to/directory` # Change to a relative path
- [ ] `cd ~` # Change to the home directory
- [ ] `cd -` # Change to the previous directory
- [ ] `cd ..` # Change to the parent directory
- [ ] `cd non_existent_directory` # Try to change to a non-existent directory

### pwd

- [ ] `pwd` # Show current working directory
- [ ] `1. cd /path/to/some/directory` \ `2. pwd` # Verify if pwd displays the correct path after changing the directory.
- [ ] `mkdir temp_directory` \ `cd temp_directory` \ `pwd` # Verify if pwd displays the correct path after creating a new directory and changing to it.

### export

- [ ] `export` # List all environment variables
- [ ] `export VAR=value` # Export a new variable
- [ ] `export VAR="Hello, World!"` # Export a variable with spaces
- [ ] `export $VAR=value` # Invalid syntax (starting with $)
- [ ] `export $VAR` # Invalid syntax (starting with $)
- [ ] `export -p` # Display all exported variables in a format that can be reused as input

### unset

- [ ] `unset VAR` # Unset an existing variable
- [ ] `unset NON_EXISTENT_VAR` # Unset a non-existent variable
- [ ] `unset $VAR` # Invalid syntax (starting with $)

### env

- [ ] `env` # Show current environment variables
- [ ] `unset PATH ` \ `env ` # By unsetting path, the shell will no longer know where to look for commands and will not be able to display env

### exit

- [ ] `exit` # Exit the shell without any exit status
- [ ] `exit 0` # Exit the shell with exit status 0
- [ ] `exit 42` # Exit the shell with exit status 42
- [ ] `exit 999` # Exit the shell with an exit status out of range
- [ ] `exit "721841284978472827829"` # Exit minishell with an alert (numeric argument required)
- [ ] `exit --` # Double dash should stop option parsing
- [ ] `exit -` # Should exit with '-'
- [ ] `exit -10` # Negative exit status
- [ ] `exit +10` # Positive exit status
- [ ] `exit 0 | exit 1` # Should not exit and return 1 to exit_status
- [ ] `exit 1 | exit 0` # Should not exit and return 0 to exit_status

## Redirections 

### Output redirection '>'

- [ ] `echo "Hello, World!" > output.txt` # Verify if the text "Hello, World!" is written to the file output.txt
- [ ] `ls /path/to/some/directory > directory_list.txt` # Check if the output of the ls command is saved to the file directory_list.txt.








