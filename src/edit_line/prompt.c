/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:16:22 by rvievill          #+#    #+#             */
/*   Updated: 2017/04/17 11:59:29 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"
#include <time.h>
#include "env.h"
#include <sys/utsname.h>

void				path(void)
{
	char			*pwd;
	char			*home;
	char			*tmp;
	char			*new_path;

	new_path = NULL;
	tmp = NULL;
	pwd = getenvline("PWD=");
	ft_putstr_fd(GREEN, 2);
	if (!(home = getenvline("HOME=")) && pwd)
		ft_putstr_fd(pwd, 2);
	else if (home && pwd && (tmp = ft_strstr(pwd, home)))
		ft_putstr_fd(new_path = ft_strjoin("~", tmp + ft_strlen(home)), 2);
	else if (pwd)
		ft_putstr_fd(new_path = ft_strdup(ft_strrchr(pwd, '/')), 2);
	else
		ft_putstr_fd(new_path = ft_strdup("no_where"), 2);
	ft_strdel(&home);
	ft_strdel(&pwd);
	ft_strdel(&new_path);
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(" ]", 2);
	ft_putstr_fd(DFL, 2);
}

void				user(void)
{
	char			*user;
	struct utsname	post;
	char			*p;
	char			*tmp;

	ft_putstr_fd(RED, 2);
	ft_putstr_fd("[ ", 2);
	ft_putstr_fd(GREEN, 2);
	if (!(user = getenvline("USER")))
		ft_putstr_fd("Anonymous", 2);
	else
	{
		ft_putstr_fd(user, 2);
		ft_strdel(&user);
	}
	ft_putchar_fd('@', 2);
	uname(&post);
	if ((tmp = ft_strchr(post.nodename, '.')))
		*tmp = '\0';
	p = ft_strdup(post.nodename);
	ft_putstr_fd(p, 2);
	ft_putstr_fd(": ", 2);
	ft_strdel(&p);
}

void				arrow(void)
{
	ft_putstr_fd(GREEN, 2);
	ft_putstr_fd("-> ", 2);
	ft_putstr_fd(DFL, 2);
}

void				ft_time(void)
{
	char			*time_cur;
	time_t			t;

	time(&t);
	time_cur = ft_strsub(ctime(&t), 11, 5);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("[ ", 2);
	ft_putstr_fd(GREEN, 2);
	ft_putstr_fd(time_cur, 2);
	ft_putstr_fd(DFL, 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(" ] ", 2);
	ft_putstr_fd(DFL, 2);
	ft_strdel(&time_cur);
}

void				prompt(void)
{
	ft_time();
	user();
	path();
	arrow();
}
