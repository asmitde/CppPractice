/*
 * polynomial.h
 *
 *  Created on: Jan 18, 2012
 *      Author: asmit
 */


#include <iostream>
#include <cstdio>
using namespace std;

template <class P>
struct Node
	{
		P coefficient;
		P power;
		Node *highLink, *lowLink;

		Node(P c, P p, Node *hl = NULL, Node *ll = NULL)
		{
			coefficient = c;
			power = p;
			highLink = hl;
			lowLink = ll;
		}
	};

template <class P> class Polynomial
{
private:
	Node<P> *highTerm, *lowTerm;
	int noOfTerms;

public:

	Polynomial();										// Default Constructor
	Polynomial(P c, P p);								// Overloaded Constructor

	void addTerm(P c, P p);								

	Polynomial<P> operator+(Polynomial<P> &poly);		// + operator overload
	Polynomial<P> operator-(Polynomial<P> &poly);		// - operator overload
	Polynomial<P> operator*(Polynomial<P> &poly);		// * operator overload

	template <class FP> friend ostream &operator<<(ostream &pout, Polynomial<FP> &poly);
};

template <class P> Polynomial<P>::Polynomial()
{
	highTerm = NULL;
	lowTerm = NULL;
	noOfTerms = 0;
}

template <class P> Polynomial<P>::Polynomial(P c, P p)
{
	highTerm = lowTerm = new Node(c, p);
	noOfTerms = 1;
}

template <class P> void Polynomial<P>::addTerm(P c, P p)
{
	Node<P> *newTerm = new Node<P>(c, p);
	Node<P> *term = lowTerm, *prev = NULL;

	if(term == NULL)
	{
		highTerm = newTerm;
		lowTerm = newTerm;
		noOfTerms++;
		return;
	}

	bool flag = false;
	while(term != NULL)
	{
		if(term->power < p)
		{
			prev = term;
			term = term->highLink;
		}
		else if(term->power == p)
		{
			term->coefficient += c;
			return;
		}
		else
			break;
		flag = true;
	}

	if(!flag)
		lowTerm = newTerm;

	newTerm->lowLink = prev;
	newTerm->highLink = term;
	if(term != NULL)
		term->lowLink = newTerm;
	else
		highTerm = newTerm;
	if(prev != NULL)
		prev->highLink = newTerm;

	noOfTerms++;
}

template <class P> Polynomial<P> Polynomial<P>::operator+(Polynomial<P> &poly)
{
	P lp = lowTerm->power < poly.lowTerm->power ? lowTerm->power : poly.lowTerm->power;
	P hp = highTerm->power > poly.highTerm->power ? highTerm->power : poly.highTerm->power;
	Node<P> *t1 = lowTerm, *t2 = poly.lowTerm;
	Polynomial<P> spoly;

	for(int i = lp; i <= hp; i++)
	{
		P a = 0, b = 0, s;
		if(t1 != NULL && t1->power == i)
		{
			a = t1->coefficient;
			t1 = t1->highLink;
		}
		if(t2 != NULL && t2->power == i)
		{
			b = t2->coefficient;
			t2 = t2->highLink;
		}

		s = a + b;
		if(s != 0)
			spoly.addTerm(s, i);

	}
	
	return spoly;
}

template <class P> Polynomial<P> Polynomial<P>::operator-(Polynomial<P> &poly)
{
	P lp = lowTerm->power < poly.lowTerm->power ? lowTerm->power : poly.lowTerm->power;
	P hp = highTerm->power > poly.highTerm->power ? highTerm->power : poly.highTerm->power;
	Node<P> *t1 = lowTerm, *t2 = poly.lowTerm;
	Polynomial<P> spoly;

	for(int i = lp; i <= hp; i++)
	{
		P a = 0, b = 0, s;
		if(t1 != NULL && t1->power == i)
		{
			a = t1->coefficient;
			t1 = t1->highLink;
		}
		if(t2 != NULL && t2->power == i)
		{
			b = t2->coefficient;
			t2 = t2->highLink;
		}

		s = a - b;
		if(s != 0)
			spoly.addTerm(s, i);

	}

	return spoly;
}

template <class P> Polynomial<P> Polynomial<P>::operator*(Polynomial<P> &poly)
{
	Polynomial<P> prodPoly;
	Node<P> *term1 = lowTerm, *term2;

	while(term1 != NULL)
	{
		term2 = poly.lowTerm;
		while(term2 != NULL)
		{
			P prodc = term1->coefficient * term2->coefficient;
			P prodp = term1->power + term1->power;

			prodPoly.addTerm(prodc, prodp);
			term2 = term2->highLink;
		}

		term1 = term1->highLink;
	}

	return prodPoly;
}

template <class FP> ostream &operator<<(ostream &pout, Polynomial<FP> &poly)
{
	Node<FP> *term = poly.highTerm;
	bool flag = false;
	while(term != NULL)
	{
		if(flag)
		{
			pout<<" + ";
		}
		flag = true;
		pout<<term->coefficient<<"x^"<<term->power;
		term = term->lowLink;
	}

	return pout;
}

