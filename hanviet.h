/* libhangul
 * Copyright (C) 2004 - 2007 Choe Hwanjin
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef libhanviet_hanviet_h
#define libhanviet_hanviet_h

#ifdef __cplusplus
extern "C" {
#endif

/* hanviet.c */
typedef struct _Hanviet Hanviet;
typedef struct _HanvietList HanvietList;
typedef struct _HanvietTable HanvietTable;

HanvietTable*  hanviet_table_load(const char *filename);
HanvietList*   hanviet_table_match_exact(const HanvietTable* table, const char *key);
HanvietList*   hanviet_table_match_prefix(const HanvietTable* table, const char *key);
HanvietList*   hanviet_table_match_suffix(const HanvietTable* table, const char *key);
void         hanviet_table_delete(HanvietTable *table);

int          hanviet_list_get_size(const HanvietList *list);
const char*  hanviet_list_get_key(const HanvietList *list);
const Hanviet* hanviet_list_get_nth(const HanvietList *list, unsigned int n);
const char*  hanviet_list_get_nth_key(const HanvietList *list, unsigned int n);
const char*  hanviet_list_get_nth_value(const HanvietList *list, unsigned int n);
const char*  hanviet_list_get_nth_comment(const HanvietList *list, unsigned int n);
void         hanviet_list_delete(HanvietList *list);

const char*  hanviet_get_key(const Hanviet* hanviet);
const char*  hanviet_get_value(const Hanviet* hanviet);
const char*  hanviet_get_comment(const Hanviet* hanviet);

#ifdef __cplusplus
}
#endif

#endif /* libhanviet_hanviet_h */
