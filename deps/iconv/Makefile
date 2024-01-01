<% return var("ICONV_CFLAGS") %> ?=
<% return var("ICONV_LDFLAGS") %> ?= -liconv

results.mk: Makefile
	truncate -s0 results.mk
	echo "LIB_CFLAGS += $(<% return var("ICONV_CFLAGS") %>)" >> results.mk
	echo "LIB_LDFLAGS += $(<% return var("ICONV_LDFLAGS") %>)" >> results.mk
