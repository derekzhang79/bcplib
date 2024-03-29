/* 
 * File:   list.h
 * Author: Yirui Zhang
 *
 * Created on November 1, 2012, 5:56 PM
 * 
 *  bcplib is a OO c library of common data structures and algorithms. 
 *  The philosophy of bcplib is to build a easy-to-use, easy-to-extend library.
 *  And I also try to make all modules independent so that user may only need
 *  a very limit subset of bcplib to run a specific module.
 * 
 *  Copyright (C) <2012>  <Yirui Zhang>
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIST_H
#define	LIST_H
#include "collection.h"

DEFINE_CLASS(bcplib_list, list);

typedef void (*list_add_at_t)(id, size_t, void*);
typedef void* (*list_get_t)(id, size_t);
typedef void* (*list_set_t)(id, size_t, void*);
typedef void* (*list_remove_at_t)(id, size_t);
typedef size_t(*list_index_of_t)(id, void*);
typedef size_t(*list_last_index_of_t)(id, void*);
#define list_prototype  collection_prototype;\
                        list_add_at_t add_at;\
                        list_get_t get;\
                        list_set_t set;\
                        list_remove_at_t remove_at;\
                        list_index_of_t index_of;\
                        list_last_index_of_t last_index_of

typedef struct bcplib_list {
    list_prototype;
} list_t;

inline void list_init(id, comparator,
        collection_add_t,
        collection_add_all_t,
        collection_remove_t,
        collection_remove_all_t,
        collection_clear_t,
        collection_size_t,
        collection_is_empty_t,
        collection_contains_t,
        collection_contains_all_t,
        // list functions
        list_add_at_t,
        list_get_t,
        list_set_t,
        list_remove_at_t,
        list_index_of_t,
        list_last_index_of_t);
#endif	/* LIST_H */

