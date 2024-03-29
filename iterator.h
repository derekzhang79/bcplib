/* 
 * File:   iterator.h
 * Author: Yirui Zhang
 *
 * Created on November 1, 2012, 9:00 PM
 * 
 *  bcplib is a c library of common data structures and algorithms. Not like 
 *  glib, the main design of bcplib is to make all data structures independent, 
 *  which means user only need to include normally several non-system header 
 *  files to use a specific data structure or algorithm.
 *  Currently, bcplib is developed on gcc-4.
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

#ifndef ITERATOR_H
#define	ITERATOR_H
#include "lib_base.h"

DEFINE_CLASS(bcplib_iterator, iterator);

#define iterable_interface      iterator_t (*get_iterator)(id)

typedef bool (*iterator_has_next_t)(iterator);
typedef void* (*iterator_next_t)(iterator);
#define iterator_prototype      object_prototype;\
                                id host;\
                                id client;\
                                iterator_has_next_t has_next;\
                                iterator_next_t next;

typedef struct bcplib_iterator {
    iterator_prototype;
} iterator_t;


extern inline void iterator_init(id user_obj, id host, id first,
        iterator_has_next_t has_next, iterator_next_t next);

extern iterator iterator_create(id host, id first,
        iterator_has_next_t has_next, iterator_next_t next);
#endif	/* ITERATOR_H */

