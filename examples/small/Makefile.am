SUBDIRS =
EXTRA_DIST = log4j.properties c.xml c2.xml c3.xml b.xsd c.xsd easypo.xml EasyPO.xsd
INCLUDES = -I ${top_builddir}/src -I ${top_srcdir}/src -I ${top_srcdir}/src/xmlbeansxx -I ${top_builddir}/src/xmlbeansxx
LDADD = ../../src/xmlbeansxx/libxmlbeansxx.la

SCHEMAS_XSD = ${srcdir}/c.xsd ${srcdir}/EasyPO.xsd
SCHEMAS_CPP = c.cpp EasyPO.cpp
SCHEMAS_H = c.h EasyPO.h

BUILT_SOURCES = $(SCHEMAS_CPP) $(SCHEMAS_H)

$(SCHEMAS_CPP) $(SCHEMAS_H): ${top_builddir}/generator/stamp-build $(SCHEMAS_XSD)
	${top_builddir}/generator/target/xmlbeansxx-gen/bin/xmlbeansxx-gen $(SCHEMAS_XSD)


#parse xpaths parse2 valid testEasyPO
noinst_PROGRAMS = create xpaths simple_types parse parse2 testEasyPO valid

create_SOURCES = create.cpp
nodist_create_SOURCES = $(SCHEMAS_CPP) $(SCHEMAS_H)

parse2_SOURCES = parse2.cpp
nodist_parse2_SOURCES = $(SCHEMAS_CPP) $(SCHEMAS_H)

valid_SOURCES = valid.cpp
nodist_valid_SOURCES = $(SCHEMAS_CPP) $(SCHEMAS_H)

testEasyPO_SOURCES = testEasyPO.cpp
nodist_testEasyPO_SOURCES = $(SCHEMAS_CPP) $(SCHEMAS_H)

parse_SOURCES = parse.cpp
xpaths_SOURCES = xpaths.cpp
simple_types_SOURCES = simple_types.cpp

MOSTLYCLEANFILES = $(SCHEMAS_CPP) $(SCHEMAS_H)
