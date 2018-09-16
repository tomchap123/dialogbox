//Project:	CIS023_F2018_HW11 Tom Chaparas
//Module:	PartNoClass.h 
//Author:	Tom Chaparas
//Date:		September 16, 2018
//Purpose:	Base Class Header file

#pragma once
class PartNoClass
{
public:
	PartNoClass();
	~PartNoClass();

	void SetPartNo(TCHAR*);
	TCHAR* GetPartNo();

private:
	TCHAR szPartNo[100];				//stores 
};

