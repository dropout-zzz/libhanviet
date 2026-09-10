#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hanviet.h"

int
main(int argc, char **argv)
{
  HanvietList *(*fn)(const HanvietTable *, const char *);
  HanvietTable *tbl;
  HanvietList *lst;
  int n;
  int i;
  const Hanviet *hv;

  if (argc != 3)
  {
usage:
    printf("usage: %s <EXACT|PREFIX|SUFFIX> <query>\n", argv[0]);
    return 1;
  }

  if (!strcmp(argv[1], "EXACT"))
    fn = hanviet_table_match_exact;
  else if (!strcmp(argv[1], "PREFIX"))
    fn = hanviet_table_match_prefix;
  else if (!strcmp(argv[1], "SUFFIX"))
    fn = hanviet_table_match_suffix;
  else
    goto usage;

  tbl = hanviet_table_load(getenv("HANVIET_DICT"));
  if (!tbl)
  {
    printf("could not load table\n");
    return 1;
  }

  lst = fn(tbl, argv[2]);
  if (!lst)
    goto out;

  n = hanviet_list_get_size(lst);

  for (i = 0; i < n; i++)
  {
    hv = hanviet_list_get_nth(lst, i);

    printf("%s:%s:%s\n",
           hanviet_get_key(hv),
           hanviet_get_value(hv),
           hanviet_get_comment(hv));
  }

  hanviet_list_delete(lst);

out:
  hanviet_table_delete(tbl);
}
