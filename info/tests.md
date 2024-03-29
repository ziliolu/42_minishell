# Minishell Test List

## Builtins

### echo

- [x] `echo "Hello, World!"` # echo a simple message
- [x] `echo "Hello, World!" > output.txt` # echo a message and redirect output to a file
- [x] `echo -n "Hello, World!"` # echo with the -n option to suppress the newline
- [x] `echo -nnnnnnnnn "Hello, World!"` # echo with the -n option to suppress the newline
- [x] `echo "$HOME"` # echo the value of the HOME environment variable
- [x] `echo '$HOME'` # echo the literal string '$HOME'
- [x] `echo \`date\`` # echo the result of a command substitution

### cd

- [x] `cd /` # Change to the root directory
- [x] `cd /path/to/directory` # Change to an absolute path
- [x] `cd relative/path/to/directory` # Change to a relative path
- [x] `cd ~` # Change to the home directory
- [x] `cd -` # Change to the previous directory
- [x] `cd ..` # Change to the parent directory
- [x] `cd "` # minishell: unexpected EOF while looking for matching `"'
- [x] `cd non_existent_directory` # Try to change to a non-existent directory

### pwd

- [x] `pwd` # Show current working directory
- [x] `1. cd /path/to/some/directory` \ `2. pwd` # Verify if pwd displays the correct path after changing the directory.
- [x] `mkdir temp_directory` \ `cd temp_directory` \ `pwd` # Verify if pwd displays the correct path after creating a new directory and changing to it.

### export

- [x] `export` # List all environment variables
- [x] `export VAR=value` # Export a new variable
- [x] `export VAR="Hello, World!"` # Export a variable with spaces
- [x] `export $VAR=value` # Invalid syntax (starting with $)
- [x] `export $VAR` # Invalid syntax (starting with $)

### unset

- [x] `unset VAR` # Unset an existing variable
- [x] `unset NON_EXISTENT_VAR` # Unset a non-existent variable
- [x] `unset $VAR` # Invalid syntax (starting with $)

### env

- [x] `env` # Show current environment variables
- [x] `unset PATH ` \ `env ` # By unsetting path, the shell will no longer know where to look for commands and will not be able to display env

### exit

- [x] `exit` # Exit the shell without any exit status
- [x] `exit 0` # Exit the shell with exit status 0
- [x] `exit 42` # Exit the shell with exit status 42
- [x] `exit 999` # Exit the shell with an exit status out of range
- [x] `exit "721841284978472827829"` # Exit minishell with an alert (numeric argument required)
- [x] `exit --` # Double dash should stop option parsing
- [x] `exit -` # Should exit with '-'
- [x] `exit -10` # Negative exit status
- [x] `exit +10` # Positive exit status
- [x] `exit 0 | exit 1` # Should not exit and return 1 to exit_status
- [x] `exit 1 | exit 0` # Should not exit and return 0 to exit_status

## Redirections 

### output redirection '>'

- [x] `echo "Hello, World!" > output.txt` # Verify if the text "Hello, World!" is written to the file output.txt
- [x] `ls /path/to/some/directory > directory_list.txt` # Check if the output of the ls command is saved to the file directory_list.txt.
- [x] `cat < input.txt > output.txt` # Test redirecting the contents of input.txt to output.txt using the > operator
- [x] `echo "This will overwrite the file." > existing_file.txt` - Check if the contents of existing_file.txt are overwritten with the new text

### input redirection '<' 

- [x] `wc -l < input_file.txt` # Verify if the wc command correctly reads the input from input_file.txt
- [x] `sort < unsorted_list.txt > sorted_list.txt` # Check if the sort command reads from unsorted_list.txt and saves the sorted output to sorted_list.txt.
- [x] `grep "keyword" < text_file.txt` # Verify if the grep command can search for the keyword in text_file.txt.

### append output '>>'

- [x] `echo "This will be appended." >> existing_file.txt` # Verify if the text "This will be appended." is added to existing_file.txt.
- [x] `echo "Append this line." >> output.txt` # Check if the new line is appended to output.txt.
- [x] `ls >> dir_list.txt` # Test appending the output of the ls command to dir_list.txt.
- [x] `echo "Another line to append." >> existing_file.txt` # Check if the new line is appended to the existing content in existing_file.txt.

### heredoc '<<'
- [x] `wc -l << END` - Verify if the wc command reads input from the Here Document (input provided interactively)
- [x] `cat << EOF > new_file.txt` # Test creating a new file new_file.txt with input from the Here Document
- [x] `grep "pattern" << EOD > result.txt` - Check if the grep command filters input from the Here Document and saves the output to result.txt

## Pipes

- [x] `ls | grep "file.txt"` # Basic Pipe Test
- [x] `ls | grep "file.txt" > output.txt` # Pipe Test with Output Redirection
- [x] `grep "keyword" < input.txt | sort > output.txt` # Pipe Test with Input and Output Redirection
- [x] `ls | grep "file.txt" | wc -l` # Multiple Pipes Test
- [x] `echo "Hello, world!" | grep "Hello"` # Pipe Test with "echo" Command
- [ ] `ls file.txt 2> error.txt` # Error Redirection Test
- [ ] `ls file.txt > output_and_error.txt 2>&1` # Output and Error Redirection to the Same File Test
- [x] `ls > output.txt | grep "file"` # Output Redirection to File and Console Test
- [x] `grep "keyword" < input.txt | grep "another" | grep "final" > output.txt` # Input from File and Output to Console Test
- [x] `echo -n "This is a test." > text.txt | cat < text.txt` # Input and Output Redirection to the Same File with "echo" Command Test
- [x] `cat | cat | cat | ls`

## Double and single quotes 
