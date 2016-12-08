#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T11:01:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Differ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ginac/parser/lexer.cpp \
    ginac/parser/parse_binop_rhs.cpp \
    ginac/parser/parse_context.cpp \
    ginac/parser/parser.cpp \
    ginac/parser/parser_compat.cpp \
    ginac/polynomial/chinrem_gcd.cpp \
    ginac/polynomial/collect_vargs.cpp \
    ginac/polynomial/cra_garner.cpp \
    ginac/polynomial/divide_in_z_p.cpp \
    ginac/polynomial/gcd_uvar.cpp \
    ginac/polynomial/mgcd.cpp \
    ginac/polynomial/mod_gcd.cpp \
    ginac/polynomial/optimal_vars_finder.cpp \
    ginac/polynomial/pgcd.cpp \
    ginac/polynomial/primpart_content.cpp \
    ginac/polynomial/upoly_io.cpp \
    ginac/add.cpp \
    ginac/archive.cpp \
    ginac/basic.cpp \
    ginac/clifford.cpp \
    ginac/color.cpp \
    ginac/constant.cpp \
    ginac/ex.cpp \
    ginac/excompiler.cpp \
    ginac/expair.cpp \
    ginac/expairseq.cpp \
    ginac/exprseq.cpp \
    ginac/factor.cpp \
    ginac/fail.cpp \
    ginac/fderivative.cpp \
    ginac/idx.cpp \
    ginac/iintegral.cpp \
    ginac/indexed.cpp \
    ginac/inifcns.cpp \
    ginac/inifcns_gamma.cpp \
    ginac/inifcns_nstdsums.cpp \
    ginac/inifcns_trans.cpp \
    ginac/integral.cpp \
    ginac/lst.cpp \
    ginac/matrix.cpp \
    ginac/mul.cpp \
    ginac/ncmul.cpp \
    ginac/normal.cpp \
    ginac/numeric.cpp \
    ginac/operators.cpp \
    ginac/power.cpp \
    ginac/print.cpp \
    ginac/pseries.cpp \
    ginac/registrar.cpp \
    ginac/relational.cpp \
    ginac/remember.cpp \
    ginac/symbol.cpp \
    ginac/symmetry.cpp \
    ginac/tensor.cpp \
    ginac/utils.cpp \
    ginac/wildcard.cpp \
    ginac/function.cpp \
    ginac/parser/builtin_fcns.cpp

HEADERS  += mainwindow.h \
    ginac/parser/debug.h \
    ginac/parser/lexer.h \
    ginac/parser/parse_context.h \
    ginac/parser/parser.h \
    ginac/polynomial/chinrem_gcd.h \
    ginac/polynomial/collect_vargs.h \
    ginac/polynomial/cra_garner.h \
    ginac/polynomial/debug.h \
    ginac/polynomial/divide_in_z_p.h \
    ginac/polynomial/euclid_gcd_wrap.h \
    ginac/polynomial/eval_point_finder.h \
    ginac/polynomial/eval_uvar.h \
    ginac/polynomial/gcd_euclid.h \
    ginac/polynomial/heur_gcd_uvar.h \
    ginac/polynomial/interpolate_padic_uvar.h \
    ginac/polynomial/mod_gcd.h \
    ginac/polynomial/newton_interpolate.h \
    ginac/polynomial/normalize.h \
    ginac/polynomial/optimal_vars_finder.h \
    ginac/polynomial/pgcd.h \
    ginac/polynomial/poly_cra.h \
    ginac/polynomial/prem_uvar.h \
    ginac/polynomial/primes_factory.h \
    ginac/polynomial/remainder.h \
    ginac/polynomial/ring_traits.h \
    ginac/polynomial/smod_helpers.h \
    ginac/polynomial/sr_gcd_uvar.h \
    ginac/polynomial/upoly.h \
    ginac/polynomial/upoly_io.h \
    ginac/add.h \
    ginac/archive.h \
    ginac/assertion.h \
    ginac/basic.h \
    ginac/class_info.h \
    ginac/clifford.h \
    ginac/color.h \
    ginac/compiler.h \
    ginac/constant.h \
    ginac/container.h \
    ginac/crc32.h \
    ginac/ex.h \
    ginac/excompiler.h \
    ginac/expair.h \
    ginac/expairseq.h \
    ginac/exprseq.h \
    ginac/factor.h \
    ginac/fail.h \
    ginac/fderivative.h \
    ginac/flags.h \
    ginac/ginac.h \
    ginac/hash_map.h \
    ginac/hash_seed.h \
    ginac/idx.h \
    ginac/iintegral.h \
    ginac/indexed.h \
    ginac/inifcns.h \
    ginac/integral.h \
    ginac/lst.h \
    ginac/matrix.h \
    ginac/mul.h \
    ginac/ncmul.h \
    ginac/normal.h \
    ginac/numeric.h \
    ginac/operators.h \
    ginac/power.h \
    ginac/print.h \
    ginac/pseries.h \
    ginac/ptr.h \
    ginac/registrar.h \
    ginac/relational.h \
    ginac/remember.h \
    ginac/structure.h \
    ginac/symbol.h \
    ginac/symmetry.h \
    ginac/tensor.h \
    ginac/tostring.h \
    ginac/utils.h \
    ginac/wildcard.h \
    ginac/function.h \
    ginac/parser/default_reader.tpl \
    ginac/config.h \
    ginac/parse_context.h \
    ginac/parser.h \
    ginac/version.h

FORMS    += mainwindow.ui

QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig
PKGCONFIG += cln
INCLUDEPATH += ginac

mac {
  PKG_CONFIG = /usr/local/bin/pkg-config
}

DISTFILES += \
    ginac/parser/builtin_fcns.def
