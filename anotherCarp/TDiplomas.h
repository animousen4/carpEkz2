#pragma once
#include <string>
#include <vector>
#include <strHelp.h>
using namespace std;
struct Item {
	string itemName;
	int price;
};

struct PriceListData {
	
	int raschetNum;
	vector<Item> items;

};
class TDiplomas {

public:
	int diplomas;
	int itemsCount;
	vector<PriceListData> priceList;


	TDiplomas() {}

	~TDiplomas() {}



	// input
	// PriceList.txt
	friend ifstream& operator >> (ifstream& in, TDiplomas& tClass)
	{
		vector<string> lines = StringHelper::readLinesFromFile(in);

		vector<string>::iterator currLine = lines.begin();

		vector<PriceListData> priceListDataList;
		while (currLine != lines.end()) {

			PriceListData curPriceListData = PriceListData{ stoi(*currLine), {} };
			currLine++;
			while (!StringHelper::isNumber(*currLine)) {
				
				vector<string> rawLine = StringHelper::separateByDelimiter(*currLine, { ' ' });
				curPriceListData.items.push_back(Item{ rawLine[0], stoi(rawLine[1])});
				currLine++;
			}

			priceListDataList.push_back(curPriceListData);
			
		}

		tClass.priceList = priceListDataList;

		return in;
	}


	// output
	friend ofstream& operator << (ofstream& of, TDiplomas& tClass) {
		// ... operate with variable tClass !!! tClass.something[a]

		
		return of;
	}
};
