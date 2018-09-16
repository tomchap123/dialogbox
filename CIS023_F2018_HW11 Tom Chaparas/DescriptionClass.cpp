//Project:	CIS023_F2018_HW11 Tom Chaparas
//Module:	DescriptionClass.cpp 
//Author:	Tom Chaparas
//Date:		September 16, 2018
//Purpose:	Implementation file for DescriptionClass.h

#include "stdafx.h"
#include "DescriptionClass.h"


DescriptionClass::DescriptionClass()
{
}

DescriptionClass::~DescriptionClass()
{
}

void DescriptionClass::SetDescription(TCHAR *szInput)
{
	_tcscpy_s(szDescription, szInput);			//store input in szDescription
}

TCHAR * DescriptionClass::GetDescription()
{
	return szDescription;
}


