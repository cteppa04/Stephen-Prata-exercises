#pragma once
#ifndef HEADER_H_
#define HEADER_H_

namespace SALES
{
	class Sales
	{
	private:
		enum {QUARTERS = 4};
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales();
		Sales(const double ar[], int n = QUARTERS);
		void setSales();
		void showSales() const;
	};
}

#endif // !HEADER_H_