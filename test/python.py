#!/usr/bin/env python
# coding=utf-8
# Author: darkdream
# Created Time: 2014年07月07日 星期一 18时53分00秒


import urllib
import urllib2

url = 'http://songtaste.com/song/3816/'

htlm = urllib2.urlopen(url)
temp = htlm.read();
print temp

f = open('temp.txt','w')

f.write(temp)
f.close()
