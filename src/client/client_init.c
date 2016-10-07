/*
** client.c for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/src/client/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue May 10 22:52:42 2016 Gaëtan Léandre
** Last update Sat May 21 20:02:03 2016 Philippe Lefevre
*/

#include		"main.h"

SOCKET			init_connection()
{
  SOCKET		sock;
  SOCKADDR_IN		sock_addr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      my_printf(2, "Erreur de socket\n");
      return (-1);
    }
  sock_addr.sin_addr.s_addr = inet_addr("93.9.51.53");
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(PORT);
  if (connect(sock, (SOCKADDR*)&sock_addr, sizeof(sock_addr)) == -1)
    {
      my_printf(2, "Pas de connection\n");
      return (-1);
    }
  return (sock);
}
