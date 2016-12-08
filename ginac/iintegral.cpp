/** @file iintegral.cpp
 *
 *  Implementation of GiNaC's symbolic  iintegral. */

/*
 *  GiNaC Copyright (C) 1999-2009 Johannes Gutenberg University Mainz, Germany
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "iintegral.h"
#include "numeric.h"
#include "symbol.h"
#include "add.h"
#include "mul.h"
#include "power.h"
#include "inifcns.h"
#include "wildcard.h"
#include "archive.h"
#include "registrar.h"
#include "utils.h"
#include "operators.h"
#include "relational.h"

using namespace std;

namespace GiNaC {

GINAC_IMPLEMENT_REGISTERED_CLASS_OPT(iintegral, basic,
  print_func<print_dflt>(&iintegral::do_print).
  print_func<print_latex>(&iintegral::do_print_latex))


//////////
// default constructor
//////////

iintegral::iintegral()
		: 
		x((new symbol())->setflag(status_flags::dynallocated))
{}

//////////
// other constructors
//////////

// public
iintegral::iintegral(const ex & x_, const ex & f_)
		:  x(x_), f(f_)
{
	if (!is_a<symbol>(x)) {
		throw(std::invalid_argument("first argument of iintegral must be of type symbol"));
	}
}


//////////
// archiving
//////////

void iintegral::read_archive(const archive_node& n, lst& sym_lst)
{
	inherited::read_archive(n, sym_lst);
	n.find_ex("x", x, sym_lst);
	n.find_ex("f", f, sym_lst);
}

void iintegral::archive(archive_node & n) const
{
	inherited::archive(n);
	n.add_ex("x", x);
	n.add_ex("f", f);
}

//////////
// functions overriding virtual functions from base classes
//////////

void iintegral::do_print(const print_context & c, unsigned level) const
{
	c.s << "iintegral(";
	x.print(c);
	c.s << ",";
	f.print(c);
	c.s << ")";
}

void iintegral::do_print_latex(const print_latex & c, unsigned level) const
{
	string varname = ex_to<symbol>(x).get_name();
	if (level > precedence())
		c.s << "\\left(";
	c.s << "\\int";
	c.s << " d";
	if (varname.size() > 1)
		c.s << "\\," << varname << "\\:";
	else
		c.s << varname << "\\,";
	f.print(c,precedence());
	if (level > precedence())
		c.s << "\\right)";
}

int iintegral::compare_same_type(const basic & other) const
{
	GINAC_ASSERT(is_exactly_a<iintegral>(other));
	const iintegral &o = static_cast<const iintegral &>(other);

	int cmpval = x.compare(o.x);
	if (cmpval)
		return cmpval;
	
	return f.compare(o.f);
}

ex iintegral::eval(int level) const
{
	if ((level==1) && (flags & status_flags::evaluated))
		return *this;
	if (level == -max_recursion_level)
		throw(std::runtime_error("max recursion level reached"));

	ex eintvar = (level==1) ? x : x.eval(level-1);
	ex ef      = (level==1) ? f : f.eval(level-1);

	if (!ef.has(eintvar) && !haswild(ef))
		return ef;

	if (are_ex_trivially_equal(eintvar,x) && are_ex_trivially_equal(ef,f))
		return this->hold();
	return (new iintegral(eintvar, ef))
		->setflag(status_flags::dynallocated | status_flags::evaluated);
}

ex iintegral::evalf(int level) const
{
	ex ef;

	if (level==1) {
		ef = f;
	} else if (level == -max_recursion_level) {
		throw(runtime_error("max recursion level reached"));
	} else {
		ef = f.evalf(level-1);
	}


	if (are_ex_trivially_equal(f, ef))
		return *this;
	else
		return (new iintegral(x, ef))
			->setflag(status_flags::dynallocated);
}

int iintegral::degree(const ex & s) const
{
	return f.degree(s);
}

int iintegral::ldegree(const ex & s) const
{
	return f.ldegree(s);
}

ex iintegral::eval_ncmul(const exvector & v) const
{
	return f.eval_ncmul(v);
}

size_t iintegral::nops() const
{
	return 2;
}

ex iintegral::op(size_t i) const
{
	GINAC_ASSERT(i<2);

	switch (i) {
		case 0:
			return x;
		case 1:
			return f;
		default:
			throw (std::out_of_range("iintegral::op() out of range"));
	}
}

ex & iintegral::let_op(size_t i)
{
	ensure_if_modifiable();
	switch (i) {
		case 0:
			return x;
		case 1:
			return f;
		default:
			throw (std::out_of_range("iintegral::let_op() out of range"));
	}
}

ex iintegral::expand(unsigned options) const
{
	if (options==0 && (flags & status_flags::expanded))
		return *this;

	ex newf = f.expand(options);

	if (is_a<add>(newf)) {
		exvector v;
		v.reserve(newf.nops());
		for (size_t i=0; i<newf.nops(); ++i)
			v.push_back(iintegral(x, newf.op(i)).expand(options));
		return ex(add(v)).expand(options);
	}

	if (is_a<mul>(newf)) {
		ex prefactor = 1;
		ex rest = 1;
		for (size_t i=0; i<newf.nops(); ++i)
			if (newf.op(i).has(x))
				rest *= newf.op(i);
			else
				prefactor *= newf.op(i);
		if (prefactor != 1)
			return (prefactor*iintegral(x, rest)).expand(options);
	}

	if (are_ex_trivially_equal(f, newf)) {
		if (options==0)
			this->setflag(status_flags::expanded);
		return *this;
	}

	const basic & newint = (new iintegral(x, newf))
		->setflag(status_flags::dynallocated);
	if (options == 0)
		newint.setflag(status_flags::expanded);
	return newint;
}

ex iintegral::derivative(const symbol & s) const
{
	if (s==x)
	    return f;
}

unsigned iintegral::return_type() const
{
	return f.return_type();
}

return_type_t iintegral::return_type_tinfo() const
{
	return f.return_type_tinfo();
}

ex iintegral::conjugate() const
{
	ex conjf = f.conjugate().subs(x.conjugate()==x);

	if (are_ex_trivially_equal(f, conjf))
		return *this;

	return (new iintegral(x, conjf))
		->setflag(status_flags::dynallocated);
}

ex iintegral::eval_integ() const
{
	if (!(flags & status_flags::expanded))
		return this->expand().eval_integ();
	
	if (f==x)
		return x*x/2;
	if (is_a<power>(f) && f.op(0)==x) {
		if (f.op(1)==-1)
			return log(x);
		if (!f.op(1).has(x)) {
			ex primit = power(x,f.op(1)+1)/(f.op(1)+1);
			return primit;
		}
	}
	
	if (is_a<function>(f)) {
	    function fun = ex_to<function>(f);
	    // TODO: Change the signature.
        return fun.iintegral(ex_to<symbol>(x));	    
	}

	return *this;
}

GINAC_BIND_UNARCHIVER(iintegral);
} // namespace GiNaC
