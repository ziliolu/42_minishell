# Minishell

<p align="center">
  <img src="https://img.shields.io/github/languages/top/ziliolu/42_push_swap?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/score-100%20%2F%20100-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/status-finished-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/ziliolu/42_push_swap?color=#FFFFFF&style=flat-square" />
</p>

## Table of Contents

- [About](#about)
- [Lexer](#lexer)
- [Parser](#parser)
- [Installation](#installation)
- [Usage](#usage)
- [Testers](#testers)
- [Disclaimer](#disclaimer)

## About

This project is part of the curriculum at 42 school and aims to sort a stack of integers using a limited set of operations. The goal is to develop an efficient sorting algorithm that can arrange the stack in ascending order using the fewest number of moves possible.

This README file will guide you through the project, explaining the algorithm used, how to install and run the program, and how to contribute to its development.

[Click here](https://github.com/ziliolu/42_push_swap/blob/main/push_swap.pdf) to access the complete subject of this project.

## Lexer - Tokenization Overview
In Minishell, building a lexer is a powerful strategy that helps break down your input commands into smaller meaningful units called `tokens.` Tokens are like the individual pieces of a puzzle that Minishell uses to understand and execute your commands correctly. Let's go through an example to understand tokenization better:

Example command:
```bash
ls -l | wc > "file1" >> 'file2' << eof
```
### Step 1. Identifying Tokens

Lexer looks for specific patterns or special characters that help identify different parts of your command. It groups these parts together to create individual tokens. Let's see how it breaks down the example command:

<img src="https://github.com/ziliolu/42_minishell/blob/main/info/lexer.png?raw=true"/>

#### -> Understanding Tokens <-

| Status         | Description                                                                                     | Example                                               |
|----------------|-------------------------------------------------------------------------------------------------|-------------------------------------------------------|
| `general`        | Represents the general/default parsing mode outside any quotes.                                 | Parsing a regular command or options.                |
| `in_dquote`    | Represents the parsing mode when inside double quotes (").                                      | Parsing a string where variables are expanded: "Hello, $name!"  |
| `in_squote`    | Represents the parsing mode when inside single quotes (').                                      | Parsing a string as-is, where variables are not expanded: 'Hello, $name!' |

| Token Type  | Description                                             | Example      |
|-------------|---------------------------------------------------------|--------------|
| `word`        | Represents command names, options, and file names      | 'ls', '-l', 'wc', 'eof' |
| `env`         | Represents environment or local variables              | '$USER', '$HOME', '$name' | 
| `w_space`     | Represents white spaces used for command separation    | N/A          |
| `pipeline`    | Represents the pipe symbol used to connect commands    | ' \| '       |
| `redir_out`   | Represents the output redirection                      | '>'          |
| `d_redir_out` | Represents the double output redirection               | '>>'         |
| `redir_in`    | Represents the input redirection                       | '<'          |
| `heredoc`     | Represents heredoc symbol                              | '<<'         |


## Parser
Once the input is tokenized, the parser's job is to recognize the boundaries between separate commands. In our example, we have three commands: `ls -l`, `grep Make`, `wc`, and the redirects associated with wc.

The parser identifies each command based on the presence of the pipe symbol '|'. It groups the tokens before and after each pipe to form individual commands.

For each command, the parser creates a data structure to represent it. In our case, we use a `t_command` structure. Take a look at the table below:

| Command Number | Type       | Command Arguments      | Redirects                             |
|----------------|------------|------------------------|---------------------------------------|
| 0              | CMD        | cmd->args[0] = "ls"    | No redirects                          |
|                |            | cmd->args[1] = "-l"    |                                       |
|                |            |                        |                                       |
| 1              | PIPELINE   | cmd->args[0] = "|"     | No redirects                          |
|                |            |                        |                                       |
| 2              | CMD        | cmd->args[0] = "grep"  | No redirects                          |
|                |            | cmd->args[1] = "Make"  |                                       |
|                |            |                        |                                       |
| 3              | PIPELINE   | cmd->args[0] = '|'     | No redirects                          |
|                |            |                        |                                       |
| 4              | CMD        | cmd->args[0] = "wc"    | redir_out - "file1"                   |
|                |            |                        | d_redir_out - 'file2'                 |
|                |            |                        | redir_in - "eof"                      |


> **⚠️** Redirects are elements that belong to the specific command in
> which they are found. In the given example, the redirects are associated
> with the `wc` command.They are not new commands and will be represented
> by the structure's array `t_redirs` found inside `t_command`.

## Installation

To install and run Minishell, follow these steps:

1. Clone the repository:
   ```bash
   git clone git@github.com:ziliolu/42_minishell.git
2. Navigate to the project directory:
   ```bash
   cd 42_minishell
3. Compile the program by running the following command:
   ```bash
   make 
   
## Usage 
To use Minishell, follow these steps:

1. Execute the program
   ```bash
   ./minishell
2. Now you can use as a normal shell and execute the commands you want such as `ls`, `mkdir`, `cd`, `pwd`, `cat`, `echo` and much more :) 

## Testers 

1. [Minishell Test List](https://github.com/o-reo/push_swap_visualizer) provides a detailed list for testing the program with different number of commands, quotes, pipes and redirections.

## Disclaimer

Maybe you could notice a different coding style.
At 42 we need to follow some rules according to the coding standard of the school such as:

```bash
- No for, do while, switch, case or goto 
- No functions with more than 25 lines 
- No more than 5 functions per each file
- No more than 5 variables in the same function
- No assigns and declarations assigns in the same line
```
[Click here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf) to read the norm file of 42 school. 
