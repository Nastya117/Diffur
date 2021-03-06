/*
 *  -*- buffer-read-only: t -*- vi: set ro:
 * 
 * DO NOT EDIT THIS FILE   (builtin_fcns.cpp)
 * 
 * It has been AutoGen-ed  Tuesday February 17, 2009 at 02:55:03 PM CET
 * From the definitions    builtin_fcns.def
 * and the template file   default_reader.tpl
 *
 * If you want to change this file, edit either `builtin_fcns.def' or
 * `default_reader.tpl' file, and run the following command:
 *
 * autogen -T default_reader.tpl builtin_fcns.def
 */
#include "parse_context.h"
#include "power.h"
#include "operators.h"
#include "inifcns.h"

namespace GiNaC
{

static ex log_reader(const exvector& ev)
{
	return GiNaC::log(ev[0]);
}
static ex exp_reader(const exvector& ev)
{
	return GiNaC::exp(ev[0]);
}
static ex sin_reader(const exvector& ev)
{
	return GiNaC::sin(ev[0]);
}
static ex cos_reader(const exvector& ev)
{
	return GiNaC::cos(ev[0]);
}
static ex tan_reader(const exvector& ev)
{
	return GiNaC::tan(ev[0]);
}
static ex asin_reader(const exvector& ev)
{
	return GiNaC::asin(ev[0]);
}
static ex acos_reader(const exvector& ev)
{
	return GiNaC::acos(ev[0]);
}
static ex atan_reader(const exvector& ev)
{
	return GiNaC::atan(ev[0]);
}
static ex sinh_reader(const exvector& ev)
{
	return GiNaC::sinh(ev[0]);
}
static ex cosh_reader(const exvector& ev)
{
	return GiNaC::cosh(ev[0]);
}
static ex tanh_reader(const exvector& ev)
{
	return GiNaC::tanh(ev[0]);
}
static ex asinh_reader(const exvector& ev)
{
	return GiNaC::asinh(ev[0]);
}
static ex acosh_reader(const exvector& ev)
{
	return GiNaC::acosh(ev[0]);
}
static ex atanh_reader(const exvector& ev)
{
	return GiNaC::atanh(ev[0]);
}
static ex atan2_reader(const exvector& ev)
{
	return GiNaC::atan2(ev[0], ev[1]);
}
static ex Li2_reader(const exvector& ev)
{
	return GiNaC::Li2(ev[0]);
}
static ex Li3_reader(const exvector& ev)
{
	return GiNaC::Li3(ev[0]);
}
static ex zetaderiv_reader(const exvector& ev)
{
	return GiNaC::zetaderiv(ev[0], ev[1]);
}
static ex Li_reader(const exvector& ev)
{
	return GiNaC::Li(ev[0], ev[1]);
}
static ex S_reader(const exvector& ev)
{
	return GiNaC::S(ev[0], ev[1], ev[2]);
}
static ex H_reader(const exvector& ev)
{
	return GiNaC::H(ev[0], ev[1]);
}
static ex lgamma_reader(const exvector& ev)
{
	return GiNaC::lgamma(ev[0]);
}
static ex tgamma_reader(const exvector& ev)
{
	return GiNaC::tgamma(ev[0]);
}
static ex beta_reader(const exvector& ev)
{
	return GiNaC::beta(ev[0], ev[1]);
}
static ex factorial_reader(const exvector& ev)
{
	return GiNaC::factorial(ev[0]);
}
static ex binomial_reader(const exvector& ev)
{
	return GiNaC::binomial(ev[0], ev[1]);
}
static ex Order_reader(const exvector& ev)
{
	return GiNaC::Order(ev[0]);
}
static ex sqrt_reader(const exvector& ev)
{
	return GiNaC::sqrt(ev[0]);
}
static ex pow_reader(const exvector& ev)
{
	return GiNaC::pow(ev[0], ev[1]);
}
static ex power_reader(const exvector& ev)
{
	return GiNaC::power(ev[0], ev[1]);
}

const prototype_table& get_default_reader()
{
	using std::make_pair;
	static bool initialized = false;
	static prototype_table reader;
	if (!initialized) {

		reader[make_pair("log", 1)] = log_reader;
		reader[make_pair("exp", 1)] = exp_reader;
		reader[make_pair("sin", 1)] = sin_reader;
		reader[make_pair("cos", 1)] = cos_reader;
		reader[make_pair("tan", 1)] = tan_reader;
		reader[make_pair("asin", 1)] = asin_reader;
		reader[make_pair("acos", 1)] = acos_reader;
		reader[make_pair("atan", 1)] = atan_reader;
		reader[make_pair("sinh", 1)] = sinh_reader;
		reader[make_pair("cosh", 1)] = cosh_reader;
		reader[make_pair("tanh", 1)] = tanh_reader;
		reader[make_pair("asinh", 1)] = asinh_reader;
		reader[make_pair("acosh", 1)] = acosh_reader;
		reader[make_pair("atanh", 1)] = atanh_reader;
		reader[make_pair("atan2", 2)] = atan2_reader;
		reader[make_pair("Li2", 1)] = Li2_reader;
		reader[make_pair("Li3", 1)] = Li3_reader;
		reader[make_pair("zetaderiv", 2)] = zetaderiv_reader;
		reader[make_pair("Li", 2)] = Li_reader;
		reader[make_pair("S", 3)] = S_reader;
		reader[make_pair("H", 2)] = H_reader;
		reader[make_pair("lgamma", 1)] = lgamma_reader;
		reader[make_pair("tgamma", 1)] = tgamma_reader;
		reader[make_pair("beta", 2)] = beta_reader;
		reader[make_pair("factorial", 1)] = factorial_reader;
		reader[make_pair("binomial", 2)] = binomial_reader;
		reader[make_pair("Order", 1)] = Order_reader;
		reader[make_pair("sqrt", 1)] = sqrt_reader;
		reader[make_pair("pow", 2)] = pow_reader;
		reader[make_pair("power", 2)] = power_reader;
		initialized = true;
	}
	return reader;
}
} // namespace GiNaC

