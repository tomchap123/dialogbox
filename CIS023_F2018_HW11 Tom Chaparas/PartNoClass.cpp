//Project:	CIS023_F2018_HW11 Tom Chaparas
//Module:	PartNoClass.cpp 
//Author:	Tom Chaparas
//Date:		September 16, 2018
//Purpose:	Implementation file for PartNoClass.h

#include "stdafx.h"
#include "PartNoClass.h"


PartNoClass::PartNoClass()
{
}

PartNoClass::~PartNoClass()
{
}

void PartNoClass::SetPartNo(TCHAR* szInput)
{
	_tcscpy_s(szPartNo, szInput);   //store input in szPartNo
}

TCHAR* PartNoClass::GetPartNo()
{
	return szPartNo;
}
