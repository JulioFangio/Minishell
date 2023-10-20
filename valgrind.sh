#!/bin/bash
valgrind --suppressions=readline.supp --trace-children=yes --track-origins=yes -s --leak-check=full --show-leak-kinds=all ./minishell