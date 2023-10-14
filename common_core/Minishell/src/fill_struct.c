/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:16:39 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/18 16:05:06 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	ft_tabremrdir(t_main *main, int n)
{
	int		j;

	j = 0;
	while (main->cline[n].argv[j])
	{
		if (ft_is_chev(main->cline[n].argv[j], 0))
		{
			free(main->cline[n].argv[j]);
			free(main->cline[n].argv[j + 1]);
			while (main->cline[n].argv[j + 2])
			{
				main->cline[n].argv[j] = main->cline[n].argv[j + 2];
				j++;
			}
			main->cline[n].argv[j] = NULL;
			j = 0;
			continue ;
		}
		j++;
	}
	return (0);
}

static int	ft_getrdircount(t_main *main, int n)
{
	int	incount;
	int	outcount;
	int	j;
	int	size;

	incount = 0;
	outcount = 0;
	j = 0;
	while (main->cline[n].argv[j])
	{
		size = ft_strlen(main->cline[n].argv[j]);
		if (!size)
			size = 1;
		if (!ft_strncmp(main->cline[n].argv[j], "<", size))
			incount++;
		else if (!ft_strncmp(main->cline[n].argv[j], ">", size))
			outcount++;
		else if (!ft_strncmp(main->cline[n].argv[j], ">>", size))
			outcount++;
		j++;
	}
	main->cline[n].rin = incount;
	main->cline[n].rout = outcount;
	return (0);
}

static int	ft_fillstruct2(t_comm *comm, int n, int in, int out)
{
	if (!ft_strncmp(comm->argv[n], "<", -1))
	{
		comm->file_in[in].flags = O_RDONLY;
		comm->file_in[in].name = ft_strdup(comm->argv[n + 1]);
		if (!comm->file_in[in].name)
			return (3);
		return (1);
	}
	if (!ft_strncmp(comm->argv[n], ">", -1))
	{
		comm->file_out[out].flags = O_CREAT | O_TRUNC | O_WRONLY;
		comm->file_out[out].name = ft_strdup(comm->argv[n + 1]);
		if (!comm->file_out[out].name)
			return (3);
		return (2);
	}
	if (!ft_strncmp(comm->argv[n], ">>", -1))
	{
		comm->file_out[out].flags = O_CREAT | O_APPEND | O_WRONLY;
		comm->file_out[out].name = ft_strdup(comm->argv[n + 1]);
		if (!comm->file_out[out].name)
			return (3);
		return (2);
	}
	return (0);
}

static int	ft_fillstruct1(t_comm *comm)
{
	int	n;
	int	in;
	int	out;
	int	r;

	n = -1;
	in = 0;
	out = 0;
	comm->file_in[in].fd = 0;
	comm->file_out[out].fd = 1;
	while (comm->argv[++n])
	{
		r = ft_fillstruct2(comm, n, in, out);
		if (r == 3)
			return (1);
		else if (r == 1)
			in++;
		else if (r == 2)
			out++;
	}
	return (0);
}

int	ft_fillstruct(t_main *main)
{
	int	n;

	n = 0;
	while (main->cline[n].line)
	{
		main->cline[n].pid = 0;
		ft_getrdircount(main, n);
		main->cline[n].file_in
			= (t_file *)malloc(sizeof(t_file) * (main->cline[n].rin + 1));
		if (!main->cline[n].file_in)
			return (1);
		main->cline[n].file_out
			= (t_file *)malloc(sizeof(t_file) * (main->cline[n].rout + 1));
		if (!main->cline[n].file_out)
			return (1);
		if (ft_tabcheck(main))
			return (1);
		if (ft_fillstruct1(&main->cline[n]))
			return (1);
		if (ft_tabremrdir(main, n))
			return (1);
		n++;
	}
	return (0);
}
