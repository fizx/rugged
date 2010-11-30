/*
 * The MIT License
 *
 * Copyright (c) 2010 Scott Chacon
 * Copyright (c) 2010 Vicent Marti
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __H_RUGGED_BINDINGS__
#define __H_RUGGED_BINDINGS__

#include <ruby.h>

#include <assert.h>

#include <git/commit.h>
#include <git/tag.h>
#include <git/blob.h>
#include <git/common.h>
#include <git/errors.h>
#include <git/index.h>
#include <git/odb.h>
#include <git/oid.h>
#include <git/revwalk.h>
#include <git/repository.h>
#include <git/zlib.h>
#include <stdint.h>

/*
 * Initialization functions 
 */
void Init_rugged_object();
void Init_rugged_commit();
void Init_rugged_tree();
void Init_rugged_tag();
void Init_rugged_blob();
void Init_rugged_index();
void Init_rugged_repo();
void Init_rugged_revwalk();

void rugged_exception_check(int errorcode);

VALUE rb_git_object_init(git_otype type, int argc, VALUE *argv, VALUE self);

VALUE rugged_raw_read(git_repository *repo, const git_oid *oid);

VALUE rugged_person_c2rb(git_person *person);
VALUE rugged_object_c2rb(git_object *object);

void rugged_person_rb2c(VALUE rb_person, const char **name_out, const char **email_out, unsigned long *time_out);
git_object *rugged_object_rb2c(git_repository *repo, VALUE object_value, git_otype type);

#endif
