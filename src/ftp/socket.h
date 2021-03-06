/*
 * socket.h --
 *
 * Yet Another FTP Client
 * Copyright (C) 1998-2001, Martin Hedenfalk <mhe@stacken.kth.se>
 * Copyright (C) 2012, Sebastian Ramacher <sebastian+dev@ramacher.at>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version. See COPYING for more details.
 */

#ifndef _socket_h_included
#define _socket_h_included

#include "syshdr.h"
#include "host.h"

typedef struct Socket_ Socket;

Socket *sock_create(void);
void sock_destroy(Socket *sockp);

bool sock_connect_host(Socket *sockp, Host *hp);
bool sock_connect_addr(Socket *sockp, const struct sockaddr* sa, socklen_t salen);
void sock_copy(Socket *tosock, const Socket *fromsock);
bool sock_connected(const Socket *sockp);
bool sock_accept(Socket *sockp, const char *mode, bool pasvmode);
bool sock_listen(Socket *sockp, int family);
void sock_throughput(Socket *sockp);
void sock_lowdelay(Socket *sockp);
const struct sockaddr* sock_local_addr(Socket *sockp);
const struct sockaddr* sock_remote_addr(Socket *sockp);
ssize_t sock_read(Socket *sockp, void *buf, size_t num);
ssize_t sock_write(Socket *sockp, void *buf, size_t num);
int sock_get(Socket *sockp); /* get one character */
int sock_put(Socket *sockp, int c); /* put one character */
int sock_unget(Socket *sockp, int c);
int sock_vprintf(Socket *sockp, const char *str, va_list ap);
int sock_printf(Socket *sockp, const char *str, ...) YAFC_PRINTF(2, 3);
int sock_flush(Socket *sockp);
int sock_telnet_interrupt(Socket *sockp);
int sock_getsockname(Socket *sockp, struct sockaddr_storage* sa);

int sock_krb_vprintf(Socket *sockp, const char *str, va_list ap);
int sock_krb_printf(Socket *sockp, const char *str, ...) YAFC_PRINTF(2, 3);
ssize_t sock_krb_read(Socket *sockp, void *buf, size_t num);
ssize_t sock_krb_write(Socket *sockp, void *buf, size_t num);
int sock_krb_flush(Socket *sockp);

FILE* sock_sin(Socket* sockp);
FILE* sock_sout(Socket* sockp);
int sock_handle(Socket* sockp);

#endif
