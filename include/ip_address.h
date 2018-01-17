/*
 * header file for FreeS/WAN library functions
 * Copyright (C) 1998, 1999, 2000  Henry Spencer.
 * Copyright (C) 1999, 2000, 2001  Richard Guy Briggs
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/lgpl.txt>.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
 * License for more details.
 *
 */

#ifndef IP_ADDRESS_H
#define IP_ADDRESS_H

struct lswlog;

/*
 * The type IP_ADDRESS is shared between KLIPS (kernel module) and
 * PLUTO.  Its definition is burried in the common include file
 * "libreswan.h".
 *
 * This header contains declarations for userland specific extensions.
 * Their implementation is found in libswan.a.
 *
 * When KLIPS goes away, the definition of IP_ADDRESS et.al., can be
 * moved here.
 */

int portof(const ip_address *src);
void setportof(int port, ip_address *dst);
struct sockaddr *sockaddrof(const ip_address *src);
size_t sockaddrlenof(const ip_address *src);

/* RFC 1886 old IPv6 reverse-lookup format is the bulkiest */
typedef struct {
	char private_buf[ADDRTOT_BUF]; /* defined in libreswan.h */
} ipstr_buf;
const char *ipstr(const ip_address *src, ipstr_buf *b);
const char *sensitive_ipstr(const ip_address *src, ipstr_buf *b);

/* See: ipstr() / sensitive_ipstr() */
size_t lswlog_ip(struct lswlog *buf, const ip_address *ip);
size_t lswlog_sensitive_ip(struct lswlog *buf, const ip_address *ip);

#endif
