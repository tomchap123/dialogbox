//Project:	CIS023_F2018_HW11 Tom Chaparas
//Module:	QuantityClass.cpp
//Author:	Tom Chaparas
//Date:		September 16, 2018
//Purpose:	Implementation file for QuantityClass.h

#include "stdafx.h"
#include "QuantityClass.h"


QuantityClass::QuantityClass()
{
}

QuantityClass::~QuantityClass()
{
}

void QuantityClass::SetQuantity(int iInput)
{
	iQuantity = iInput;
}

int QuantityClass::GetQuantity()
{
	return iQuantity;
}

