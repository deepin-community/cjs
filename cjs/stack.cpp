/* -*- mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; -*- */
// SPDX-License-Identifier: MIT OR LGPL-2.0-or-later
// SPDX-FileCopyrightText: 2009 Red Hat, Inc.

#include <config.h>

#include <stdio.h>  // for stderr

#include <glib-object.h>
#include <glib.h>

#include <js/TypeDecls.h>
#include <js/friend/DumpFunctions.h>

#include "cjs/context.h"
#include "cjs/jsapi-util.h"

void
gjs_context_print_stack_stderr(GjsContext *context)
{
    JSContext *cx = (JSContext*) gjs_context_get_native_context(context);

    g_printerr("== Stack trace for context %p ==\n", context);
    js::DumpBacktrace(cx, stderr);
}

void
gjs_dumpstack(void)
{
    GjsSmartPointer<GList> contexts = gjs_context_get_all();
    GList *iter;

    for (iter = contexts; iter; iter = iter->next) {
        GjsAutoUnref<GjsContext> context(GJS_CONTEXT(iter->data));
        gjs_context_print_stack_stderr(context);
    }
}
