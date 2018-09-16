//Project:	CIS023_F2018_HW11 Tom Chaparas
//Module:	DescriptionClass.h 
//Author:	Tom Chaparas
//Date:		September 16, 2018
//Purpose:	Derived Class Header file

#pragma once
#include "PartNoClass.h"
class DescriptionClass :
	public PartNoClass
{
public:
	DescriptionClass();
	~DescriptionClass();

	void SetDescription(TCHAR*);
	TCHAR* GetDescription();
	


private:
	TCHAR szDescription[100];
};

