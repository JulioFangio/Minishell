#!/bin/bash
valgrind --suppressions=readline.supp --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./minishell