include $(top_srcdir)/Makefile.decl
NULL =

AM_CFLAGS = \
	-DG_LOG_DOMAIN=\"fsodevice.vibrator_ledclass\" \
	$(NULL)
AM_VALAFLAGS =

modlibexecdir = $(libdir)/cornucopia/modules/fsodevice
modlibexec_LTLIBRARIES = vibrator_ledclass.la
vibrator_ledclass_la_SOURCES = plugin.vala
vibrator_ledclass_la_VALAFLAGS = \
	--basedir $(top_srcdir) \
	--vapidir $(top_srcdir)/fsoframework \
	--pkg glib-2.0 \
	--pkg fso-glib-1.0 \
	--pkg fsoframework-2.0 \
	$(DEBUG_VALAFLAGS) \
	$(NULL)
vibrator_ledclass_la_CFLAGS = \
	-I$(top_srcdir) \
	$(FSO_CFLAGS) \
	$(DEBUG_CFLAGS) \
	$(NULL)
vibrator_ledclass_la_LIBADD = \
	$(FSO_LIBS) \
	$(top_builddir)/src/lib/libfsodevice.la \
	$(NULL)
vibrator_ledclass_la_LDFLAGS = -no-undefined -module -avoid-version
# vibrator_ledclass_la_LIBTOOLFLAGS = --tag=disable-static

CLEANFILES =
MAINTAINERCLEANFILES = \
  Makefile.in \
  $(NULL)
