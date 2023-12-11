$(VPFX)_ICONV_CFLAGS ?= -liconv
$(VPFX)_ICONV_LDFLAGS ?=

results.mk: Makefile
	truncate -s0 results.mk
	echo "LIB_CFLAGS += $($(VPFX)_ICONV_CFLAGS)" >> results.mk
	echo "LIB_LDFLAGS += $($(VPFX)_ICONV_LDFLAGS)" >> results.mk
