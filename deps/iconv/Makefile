<% return var("CFLAGS") %> ?=
<% return var("LDFLAGS") %> ?=

results.mk: Makefile
	truncate -s0 results.mk
	echo "LIB_CFLAGS += $(<% return var("CFLAGS") %>)" >> results.mk
	echo "LIB_LDFLAGS += $(<% return var("LDFLAGS") %>)" >> results.mk
