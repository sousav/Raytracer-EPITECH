/*
** key_handle.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Fri Mar 11 05:01:37 2016 victor sousa
** Last update Fri Mar 11 05:03:21 2016 victor sousa
*/

#include		"main.h"

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym      key,
			    void                *p)
{
  (void)p;
  if (key == BKS_ESCAPE && state == GO_UP)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
