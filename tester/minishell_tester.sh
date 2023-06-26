#!/home/pastilhex/Desktop/CommonCore42/42_minishell/minishell
ls

execute_commands=true

if [ "$execute_commands" = true ]; then
    ls
	if [ $? -eq 0 ]; then
		echo "comando1 executado com sucesso."
	else
		echo "Erro na execução do comando1."
	fi
	echo olá
	if [ $? -eq 0 ]; then
		echo "comando1 executado com sucesso."
	else
		echo "Erro na execução do comando1."
	fi
fi


