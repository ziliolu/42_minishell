# Minishell Test List

## echo

- [x] `echo "Hello, World!"` # echo a simple message
- [ ] `echo "Hello, World!" > output.txt` # echo a message and redirect output to a file
- [ ] `echo -n "Hello, World!"` # echo with the -n option to suppress the newline
- [ ] `echo -e "Line1\nLine2"` # echo with the -e option to interpret escape characters
- [ ] `echo "$HOME"` # echo the value of the HOME environment variable
- [ ] `echo '$HOME'` # echo the literal string '$HOME'
- [ ] `echo \`date\`` # echo the result of a command substitution
- [ ] `echo *` # echo files in the current directory (wildcard expansion)

## cd

- [ ] `cd /` # Change to the root directory
- [ ] `cd /path/to/directory` # Change to an absolute path
- [ ] `cd relative/path/to/directory` # Change to a relative path
- [ ] `cd ~` # Change to the home directory
- [ ] `cd -` # Change to the previous directory
- [ ] `cd ..` # Change to the parent directory
- [ ] `cd non_existent_directory` # Try to change to a non-existent directory

## pwd

- [ ] `pwd` # Show current working directory
- [ ] `pwd -L` # Resolve symbolic links (default behavior)
- [ ] `pwd -P` # Do not resolve symbolic links

## export

- [ ] `export` # List all environment variables
- [ ] `export VAR=value` # Export a new variable
- [ ] `export VAR="Hello, World!"` # Export a variable with spaces
- [ ] `export $VAR=value` # Invalid syntax (starting with $)
- [ ] `export $VAR` # Invalid syntax (starting with $)
- [ ] `export -p` # Display all exported variables in a format that can be reused as input

## unset

- [ ] `unset VAR` # Unset an existing variable
- [ ] `unset NON_EXISTENT_VAR` # Unset a non-existent variable
- [ ] `unset $VAR` # Invalid syntax (starting with $)
- [ ] `unset -v VAR` # Unset the variable VAR (same as unset VAR)

## env

- [ ] `env` # Show current environment variables
- [ ] `env -i` # Run with an empty environment, should display nothing
- [ ] `env -u VAR` # Unset a specific environment variable

## exit

- [ ] `exit` # Exit the shell without any exit status
- [ ] `exit 0` # Exit the shell with exit status 0
- [ ] `exit 42` # Exit the shell with exit status 42
- [ ] `exit 999` # Exit the shell with an exit status out of range
- [ ] `exit "non_numeric_value"` # Exit with a non-numeric value
- [ ] `exit --` # Double dash should stop option parsing
- [ ] `exit -` # Should exit with '-'
- [ ] `exit -10` # Negative exit status
- [ ] `exit +10` # Positive exit status
- [ ] `exit 0 | exit 1` # Test exit status with pipes
- [ ] `exit 1 | exit 0` # Test exit status with pipes

