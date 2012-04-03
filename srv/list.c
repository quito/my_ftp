/*
** list.c for  in /home/quito/projet_tmp/my_ftp/srv
** 
** Made by pierre collet
** Login   <collet_p@epitech.net>
** 
** Started on  Mon Apr  2 16:43:46 2012 pierre collet
** Last update Mon Apr  2 16:43:46 2012 pierre collet
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include <sys/types.h>
#include <sys/wait.h>

void		waiting_for_pid(t_list *list)
{
  int		status;

  while (list)
    {
      if (waitpid((long int)(list->data), &status, 0) == -1)
	perror("waitpid");
      list = list->next;
    }
}

t_list		*push_back_list(t_list *list, void *data)
{
  t_list	*prev;
  t_list	*new;
  t_list	*begin;

  prev = NULL;
  begin = list;
  while (list)
    {
      prev = list;
      list = list->next;
    }
  new = malloc(sizeof(*new));
  if (!new)
    {
      fprintf(stderr, "Cannot perform a Malloc!\n");
      return (begin);
    }
  new->data = data;
  new->next = NULL;
  if (!prev)
    begin = new;
  else
    prev->next = new;
  return (begin);
}

void		freelist(t_list *list)
{
  t_list	*tmp;

  tmp = NULL;
  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
}
