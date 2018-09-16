//Project:	CIS023_F2018_HW11 Tom Chaparas
//Module:	QuantityClass.h
//Author:	Tom Chaparas
//Date:		September 16, 2018
//Purpose:	Header file for QuantityClass

#pragma once
#include "PartNoClass.h"
class QuantityClass :
	public PartNoClass
{
public:
	QuantityClass();
	~QuantityClass();

	void SetQuantity(int);
	int GetQuantity();

private:
	int iQuantity;
};

