/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:35 by rugrigor          #+#    #+#             */
/*   Updated: 2023/12/25 15:12:55 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

# define STDIN 0
# define STDOUT 1

typedef struct s_lexer
{
	char			*kw;
	char			*id;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}				t_lexer;

typedef struct s_tree
{
	char			*_or;
	char			*_cmd;
	char			*_and;
	char			*_file;
	char			*_word;
	char			*_pipe;
	char			*_redir;
	char			*_option;
	struct s_tree	*next;
	struct s_tree	*prev;
}				t_tree;

typedef struct s_pipex
{
	pid_t	pid;
	int		**fd;
	int		index;
	int		cmd_cnt;
	int		cmd_crnt;
	int		pipes_cnt;
}				t_pipex;

typedef struct s_ms
{
	int					x;
	int					c1;
	int					c2;
	int					bb;
	int					num;
	int					dol;
	int					ord;
	int					err;
	int					dol2;
	int					user;
	int					j_rep;
	int					fd[2];
	int					kloun;
	int					p_err;
	int					index;
	int					prior;
	int					bonus;
	int					bonus2;
	int					pipe_cmd;
	int					bool_word;
	int					export_plus;
	int					_stdin_backup_;
	int					_stdout_backup_;
	char				*path;
	char				*args;
	char				**str;
	char				**envp;
	char				*my_cmd;
	char				*wd_tmp;
	char				*args_old;
	long long			exit_num;
	t_tree				*tree[OPEN_MAX];
	struct sigaction	sa;
}				t_ms;

int		eng(t_ms *ms);
int		env(t_ms *ms);
int		handler(void);
int		handler2(void);
int		cd(t_ms *ms, int j);
int		bonus_file(t_ms *ms);
int		pipe_check(t_ms *ms);
int		exec_one_cmd(t_ms *ms);
int		check_built(char *str);
int		check_for_eq(char *str);
int		spaces(t_ms *ms, int i);
int		engine(t_ms *ms, int n);
int		exit_mode_cut(t_ms *ms);
int		simbol(t_ms *ms, int i);
int		echo(t_ms *ms, int flag);
int		perr(char *str, t_ms *ms);
int		child_doc(char **cmd_args);
int		my_write(char *str, int i);
int		exit_mode(int n, t_ms *ms);
int		dol_count(char *str, int i);
int		exit4(t_ms *ms, char **cmd);
int		tabzz(t_ms *ms, int i, int c);
int		check_var(char *str, t_ms *ms);
int		get_cmd(char *path, char *cmd);
int		cmd_find(t_ms *ms, char **cmd);
int		check_var(char *str, t_ms *ms);
int		pars_err(char *error, t_ms *ms);
int		parser(t_lexer *lexer, t_ms *ms);
int		o_space2(t_ms *ms, int i, int n);
int		wildcard(t_ms *ms, int i, int x);
int		o_space3(t_ms *ms, int i, int n);
int		my_exit(int n, int mod, t_ms *ms);
int		is_plus(t_ms *ms, int i, int plus);
int		exec_builtin(t_ms *ms, char **cmd);
int		space_help(t_ms *ms, int x, int n);
int		ft_export3(t_ms *ms, int i, int j);
int		my_write2(t_ms *ms, char **cmd_args);
int		ft_unset(t_ms *ms, char **str, int i);
int		ft_export(t_ms *ms, char **str, int i);
int		std_dup(t_ms *ms, char **file, int fd);
int		my_dup2(int read, int write, t_ms *ms);
int		my_dup2(int read, int write, t_ms *ms);
int		dol_prep(t_ms *ms, int i, int x, int y);
int		ft_export2(t_ms *ms, char **str, int i);
int		heredoc_find(t_ms *ms, char **cmd_args);
int		ft_chdir2(t_ms *ms, char *ptr, char *vp);
int		operator_distribute(t_ms *ms, char *opr);
int		open_files(t_ms *ms, char **file, int fd);
int		ft_export_env(t_ms *ms, char **str, int i);
int		pwd(t_ms *ms, int mod, int i, char *oldpwd);
int		out_dup(t_ms *ms, t_pipex *pipex, char **cmd);
int		err(char *error, char *str, t_ms *ms, int type);
int		heredoc(char *str, int file, char *tmp, char *tmp2);
int		child_builtin(t_ms *ms, t_pipex *pipex, char **cmd);
int		word_distribute(t_lexer **lexer, t_ms *ms, char *word);
int		child_dup(t_ms	*ms, t_pipex *pipex, char **cmd, int fd);
char	*pwd2(t_ms *ms);
char	*exit_num(t_ms *ms);
char	*in_find(char **cmd);
char	*out_find(char **cmd);
char	**caching(char **str);
char	*get_next_line(int fd);
char	*cmd_builder(t_ms *ms);
char	**redir_cut(char **cmd);
char	*dol_check(t_ms *ms, char *ptr);
char	**ex_1(char **cmd, int i, int j);
char	*cmd_build(t_ms *ms, char *word);
char	*ft_join(char *str, char *str2, int i);
char	*dol2(char *ptr, char *str, int i, int n);
char	*str_replace2(t_ms *ms, char *str, char **tmp, int i);
char	*dollar2(t_ms *ms, char *ptr, int n, char *ft);
char	*dollar4(t_ms *ms, char *ft2, char *ptr, int n);
char	*priority2(t_ms *ms, char *str, char *ptr, int n);
char	*cd2_help(char *vp, char *ptr, char *buff, char *tmp);
char	*str_replace(t_ms *ms, char *str, char *str1, char *str2);
void	chdir4(t_ms *ms);
void	main_sig(t_ms *ms);
void	ft_search(t_ms *ms);
void	goto_start(t_ms *ms);
void	doublefree(char **str);
void	ft_free2(t_ms *ms, int i);
void	pipe_close(t_pipex *pipex);
void	ctrld(char *line, t_ms *ms);
void	goto_start2(t_ms *ms, int i);
void	bonus_dup(t_ms *ms, int pid);
void	cat_exit(t_ms *ms, char *str);
void	heredoc2(int file, char *tmp);
void	pipe_open(t_pipex *pipex, t_ms *ms);
void	file_cmd(t_ms *ms, int i, char *tmp);
void	pipex(t_ms *ms, char **argv, int num);
void	lstadd_back(t_lexer **lst, t_lexer *new);
void	tree_add_back(t_tree **tree, t_tree *new);
void	tokenizer(t_ms *m, t_lexer **lexer, int i);
void	ft_concat(t_ms *ms, char *cmd, int i, char *tmp);
void	dol_prep4(t_ms *ms, int i, char *ptr, char *ptr2);
void	append2(t_ms *ms, int i, char **tmp, char *tmp_s);
void	child_help2(t_ms *ms, t_pipex *pipex, char *argv);
t_lexer	*lstnew(void);
t_tree	*tree_new(void);

int	g_glob;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif