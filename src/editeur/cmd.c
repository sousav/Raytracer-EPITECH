/*
** cmd.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Apr 26 10:04:58 2016 Ethan Kerdelhue
** Last update Mon May 16 13:57:10 2016 Philippe Lefevre
*/

#include		"main.h"

int			close_xml(t_prog *prog)
{
  (void) prog;
  my_printf(1, "let's close!\n");
  return (0);
}

int			quit_editor(t_prog *prog)
{
  (void) prog;
  free(prog->editor->cmd);
  my_printf(1, "exit editor!\n");
  return (0);
}

t_cmd			*init_cmd_end(t_cmd *cmd)
{
  cmd[6].index = "add_mat";
  cmd[6].ptr = &add_mat_s;
  cmd[6].desc = "ajoute un materiel selon plusieurs paramètres";
  cmd[7].ptr = &add_light_s;
  cmd[7].index = "add_light";
  cmd[7].desc = "ajoute une lumière selon plusieurs paramètres";
  cmd[8].index = "edit_obj";
  cmd[8].ptr = &edit_obj;
  cmd[8].desc = "edite les paramètres de l'objet selectionner";
  cmd[9].index = "edit_mat";
  cmd[9].ptr = &edit_mat;
  cmd[9].desc = "edite les paramètres du matériau selectionner";
  cmd[10].index = "edit_cam";
  cmd[10].ptr = &edit_cam;
  cmd[10].desc = "edite les paramètress de la caméra";
  cmd[11].index = "edit_light";
  cmd[11].ptr = &edit_light;
  cmd[11].desc = "edite les paramètres d'une lumière";
  cmd[12].index = "exit";
  cmd[12].ptr = &quit_editor;
  cmd[12].desc = "quitte le mode edition";
  cmd[13].index = "END";
  return (cmd);
}

t_cmd			*init_cmd(t_cmd *cmd)
{
  if ((cmd = malloc(sizeof(t_cmd) * 20)) == NULL)
    return (NULL);
  cmd[0].index = "help";
  cmd[0].ptr = &aff_help;
  cmd[0].desc = "affiche une aide pour l'utilisateur";
  cmd[1].index = "load_xml";
  cmd[1].ptr = &fill_struct;
  cmd[1].desc = "load un fichier .xml dans le shell";
  cmd[2].index = "aff_xml";
  cmd[2].ptr = &aff_xml;
  cmd[2].desc = "affiche le contenu du fichier xml actuel";
  cmd[3].index = "write_xml";
  cmd[3].ptr = &write_xml;
  cmd[3].desc = "ecrit le contenu actuellement load dans un fichier xml";
  cmd[4].index = "add_obj";
  cmd[4].ptr = &add_obj;
  cmd[4].desc = "ajoute un objet selon plusieurs type dans le fichier xml";
  cmd[5].index = "close_xml";
  cmd[5].ptr = &close_xml;
  cmd[5].desc = "ferme un fichier ouvert";
  return (init_cmd_end(cmd));
}

int			check_cmd(t_prog *prog)
{
  int			ret;
  int			i;

  i = 0;
  ret = -1;
  if (prog->editor->arg[0] == NULL)
    ret = ERR_NOSTR;
  while (my_strncmp(prog->editor->cmd[i].index, "END", 3) && ret == -1)
    {
      if (my_strncmp(prog->editor->cmd[i].index, prog->editor->arg[0],
		     my_strlen(prog->editor->cmd[i].index)) == 0)
	{
	  prog->editor->cmd[i].ptr(prog);
	  ret += 1;
	}
      i++;
    }
  return (ret);
}
