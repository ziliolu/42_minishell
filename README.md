# Push Swap

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
   minishell$ ls -l | wc > "file1" >> 'file2' << eof
```
##### Step 1. Identifying Tokens

- Lexer looks for specific patterns or special characters that help identify different parts of your command. It groups these parts together to create individual tokens. Let's see how it breaks down the example command:

##### Step 2. Understanding Token Type

| Token Type  | Description                                             | Example      |
|-------------|---------------------------------------------------------|--------------|
| `word`        | Represents command names, options, and file names.     | 'ls', '-l', 'wc', 'eof' |
| w_space     | Represents white spaces used for command separation.   | N/A          |
| pipeline    | Represents the pipe symbol used to connect commands.   | ' \| '       |
| redir_out   | Represents the output redirection symbol '>'.          | '>'          |
| d_redir_out | Represents the double output redirection symbol '>>'.  | '>>'         |
| redir_in    | Represents the input redirection symbol '<'.           | '<'          |
| heredoc     | Represents the heredoc symbol '<<' used for input.     | '<<'         |


<img src="https://github.com/ziliolu/42_minishell/blob/main/info/lexer.png?raw=true"/>
  


## Parser

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
