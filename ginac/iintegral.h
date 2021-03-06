/** @file iintegral.h
 *
 *  Interface to GiNaC's symbolic  iintegral. */

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

#ifndef GINAC_IINTEGRAL_H
#define GINAC_IINTEGRAL_H

#include "basic.h"
#include "ex.h"
#include "archive.h"

namespace GiNaC {

/** Symbolic iintegral. */
class iintegral : public basic
{
	GINAC_DECLARE_REGISTERED_CLASS(iintegral, basic)
	
	// other constructors
public:
	iintegral(const ex & x_, const ex & f_);
	
	// functions overriding virtual functions from base classes
public:
	unsigned precedence() const {return 45;}
	ex eval(int level=0) const;
	ex evalf(int level=0) const;
	int degree(const ex & s) const;
	int ldegree(const ex & s) const;
	ex eval_ncmul(const exvector & v) const;
	size_t nops() const;
	ex op(size_t i) const;
	ex & let_op(size_t i);
	ex expand(unsigned options = 0) const;
	exvector get_free_indices() const;
	unsigned return_type() const;
	return_type_t return_type_tinfo() const;
	ex conjugate() const;
	ex eval_integ() const;
	/** Save (a.k.a. serialize) object into archive. */
	void archive(archive_node& n) const;
	/** Read (a.k.a. deserialize) object from archive. */
	void read_archive(const archive_node& n, lst& syms);
protected:
	ex derivative(const symbol & s) const;
	ex series(const relational & r, int order, unsigned options = 0) const;

	// new virtual functions which can be overridden by derived classes
	// none
	
	// non-virtual functions in this class
protected:
	void do_print(const print_context & c, unsigned level) const;
	void do_print_latex(const print_latex & c, unsigned level) const;
public:
    
private:
	ex x;
	ex f;
};
GINAC_DECLARE_UNARCHIVER(iintegral); 

// utility functions

} // namespace GiNaC

#endif // ndef GINAC_IINTEGRAL_H
