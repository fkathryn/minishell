/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:05:00 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 15:08:58 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <sys/stat.h>

# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m\e[1m"
# define CLEAN "\e[1;1H\e[2J"
# define CMD_NOT_FOUND ": command not found"
# define IS_A_DIR ": is a directory"
# define NOT_A_DIR ": Not a directory"
# define P_DEN ": Permission denied"
# define SHELL "minishell: "
# define SHELL_EXIT "minishell: exit: "
# define NO_FILE_DIR ": No such file or directory"
# define STDIN_IS_A_DIR ": stdin: Is a directory"

typedef struct	s_env
{
	char		*name;
	char		*value;
}				t_env;

typedef struct	s_fd
{
	int			needed_fork;
	int			was_redir;
	int			was_fork;
	int			stdin_read;
	int			stdout_write;
	int			back_redir;
}				t_fd;

/*
** buildins
*/

int				check_variable(char **cmd, char *param, int i);
int				check_builtins(char **cmd, t_list **env, t_fd *fd_pipe);
int				check_dir(char *file);
int				my_cd(char **cmd, t_list **env);
int				my_echo(char **cmd, char *strlowcase);
int				my_env(t_list *env, char *strlowcase);
void			print_export(t_list *env);
int				check_export(char **cmd, t_list **env);
int				my_pwd(char *strlowcase);
int				check_unset(char **cmd, t_list **env);
int				my_exit(char **cmd, t_fd *fd_pipe);

/*
** errors
*/

void			ft_error_errno_exit(void);
void			error_is_a_dir(char *param);
void			error_perm_denied(char *param);
void			error_no_file_or_dir(char *param);
void			error_cmd_not_found(char *param);
void			error_from_errno(char *param);
void			error_not_a_dir(char *param);
int				error_home_not_set(void);
void			error_num_arg_required(char *param, int num);
void			error_syntax_unexpected_token(void);
void			error_exit_many_args(void);

/*
** check_path.c
*/

char			*check_path(char *path, char **cmd);
char			*parse_path(char **cmd, t_list *env, int *flag);
int				is_it_path(char **cmd, char **true_path);

/*
** check_tokens.c
*/

int				check_dir_in_begin(char **line);
int				check_redirs(char **line);
int				check_back_redirs(char **line);

/*
** commands.c
*/

void			run_command(char **cmd, t_list **env, t_fd *fd_pipe);
void			my_fork(char **cmd, t_list **env, t_fd *fd_pipe);

/*
** directions.c
*/

void			get_pipe_fd(char **line, t_fd *fd_pipe);
void			get_redir_fd(char **line, t_fd *fd_pipe, t_list *env, char **cmd);

/*
** directions_utils.c
*/

int				check_back_redir_file(char **cmd, char *file_name);

/*
** env.c
*/

char			**env_to_strstr(t_list *env);
void			free_env(t_list *lst);
void			env_sort(t_list **begin_list);
int				add_env(t_list **lst, char *name, char *value);
void			init_env(t_list **lst, char **env);


/*
** lookup_env.c
*/

char			*lookup_env(char **line, t_list *env);

/*
** parse_arg.c and parse_line.c
*/

char			*parse_argument(char **line, t_list *env);
char			**parse_line(char **line, t_fd *fd_pipe, t_list *env);

/*
** utils.c
*/

void			write_prompt(void);
void			prepare_program(int ac, char **av, t_list **env, char **ev);
void			settings_after_separator(t_fd *fd_pipe, char **line);
void			set_status(int status);

/*
** signal.c
*/

void			ft_sigint(int sig);
void			ft_quit(int sig);
void			ft_no_usinput(void);

/*
** global
*/

int				g_status;
int				g_flag;
int				g_fd;
int				g_redir_error;
int				g_flag_redir;

#endif
