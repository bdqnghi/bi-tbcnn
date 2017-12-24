#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import string
import subprocess
import dnsmasq

HEADER_DEFAULT = """# Default DNS settings
#
"""

HOST_CHARS = string.ascii_letters + string.digits + '.' + '_' + '-'
NAME_PATH = "/etc/env.d/01hostname"
CMD_ENV = "/sbin/update-environment"
HOSTS_PATH = "/etc/hosts"

RESOLV_USER = "/etc/resolv.default.conf"

MSG_ERR_INVLCHRSHSNM = {"en": "Invalid character(s) '%s' found in hostname.",
                        "tr": "Bilgisayar adında geçersiz karakter(ler) ('%s') bulundu.",
                        }

# Network.Stack methods

def getNameServers(): INDENT
    servers = []
    if not os.access(RESOLV_USER, os.R_OK): INDENT
        return servers
DEDENT     for line in file(RESOLV_USER): INDENT
        line = line.strip()
        if line.startswith("nameserver"): INDENT
            ip = line.split()[1]
            if ip not in servers: INDENT
                servers.append(ip)
DEDENT DEDENT DEDENT     return servers

DEDENT def setNameServers(nameservers, searchdomain): INDENT
    f = file(RESOLV_USER, "w")
    f.write(HEADER_DEFAULT)

    for server in nameservers: INDENT
        f.write("nameserver %s\n" % server)

DEDENT     if searchdomain: INDENT
        f.write("searchdomain %s\n" % searchdomain)

DEDENT     f.close()

DEDENT def registerNameServers(ifname, nameservers, searchdomain): INDENT
    dnsMasq = dnsmasq.DnsMasq()
    for server in nameservers: INDENT
        dnsMasq.registerNameServer(ifname, server)
DEDENT     dnsMasq.clearCache()

DEDENT def unregisterNameServers(ifname, nameservers, searchdomain): INDENT
    dnsMasq = dnsmasq.DnsMasq()
    dnsMasq.unregisterNameServers(ifname)
    dnsMasq.clearCache()

DEDENT def flushNameCache(): INDENT
    dnsMasq = dnsmasq.DnsMasq()
    dnsMasq.clearCache()

DEDENT def getHostName(): INDENT
    cmd = subprocess.Popen(["/usr/bin/hostname"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    a = cmd.communicate()
    if a[1] == "": INDENT
        return a[0].rstrip("\n")
DEDENT     return ""

DEDENT def setHostName(hostname): INDENT
    if not hostname: INDENT
        return
DEDENT     invalid = filter(lambda x: not x in HOST_CHARS, hostname)
    if len(invalid) > 0: INDENT
        fail(_(MSG_ERR_INVLCHRSHSNM) % ("".join(invalid)))

    # hostname
DEDENT     if os.path.exists(NAME_PATH): INDENT
        import re
        f = file(NAME_PATH)
        data = f.read()
        f.close()
        data = re.sub('HOSTNAME="(.*)"', 'HOSTNAME="%s"' % hostname, data)
DEDENT     else: INDENT
        data = 'HOSTNAME="%s"\n' % hostname
DEDENT     f = file(NAME_PATH, "w")
    f.write(data)
    f.close()

    # hosts
    f = file(HOSTS_PATH)
    data = f.readlines()
    f.close()
    f = file(HOSTS_PATH, "w")
    flag = 1
    for line in data: INDENT
        if line.startswith("127.0.0.1"): INDENT
            line = "127.0.0.1 localhost %s\n" % hostname
            flag = 0
DEDENT         f.write(line)
DEDENT     if flag: INDENT
        f.write("127.0.0.1 localhost %s\n" % hostname)
DEDENT     f.close()

    # update environment
    os.system(CMD_ENV)
DEDENT 
