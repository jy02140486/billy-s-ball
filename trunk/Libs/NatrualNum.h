#ifndef NAUTRUALNUM_H
#define NAUTRUALNUM_H

class NatrualNum
{
public:
	int val;
	int maximun;
	NatrualNum(int valref,int max);
	NatrualNum(int max);
	bool plusable(int addnum);
	bool minusable(int minnum);
	void minus(int minnum);
	void plus(int addnum);
protected:
private:
};
#endif