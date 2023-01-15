#pragma once

#include <vector>
#include <string>
#include <strHelp.h>
#include <fstream>
#include <algorithm>
using namespace std;

struct FirmInfo {

	string firmName;
	int firmRaschet;

	string toString() {
		string res;
		res = to_string(firmRaschet) + " " + firmName;
		return res;
	}
};

struct PrizeInfo {
	int prizeNum;
	string prizeName;
	FirmInfo firmInfo;


	string toString() {
		string res;
		res = to_string(prizeNum) + " " + prizeName + " " + firmInfo.toString();

		return res;
	}
};
class TPrizes {


public:
	TPrizes() {}

	~TPrizes() {}

	int allPrizesAmount; // N1+N2+N3;

	int s1, s2, s3;
	int n1, n2, n3;

	vector<string> prizeName;
	vector<int> diplomaNumber;
	vector<int> raschetNumber;
	vector<PrizeInfo> prizesInfo;

	vector<FirmInfo> firms;

	// NameFirm.txt
	void ReadFirm() {
		ifstream nameFirmFile("NameFirm.txt");

		vector<string> lines = StringHelper::readLinesFromFile(nameFirmFile);

		for (int index = 1; index < lines.size(); index++) {
			string curLine = lines[index];

			vector<string> elements = StringHelper::separateByDelimiter(curLine, { ' ' });

			string name = StringHelper::uniteVectorElements(StringHelper::getWithoutLastElements(elements, 1));

			int tempRaschetNumb = StringHelper::getOnlyNumbers(StringHelper::getLastElements(elements, 1))[0];



			firms.push_back(FirmInfo{ name, tempRaschetNumb });


		}
	}

	void fillPrizesInfo() {
		for (int index = 0; index < prizeName.size(); index++) {
			// По расчет номеру найти компанию
			int fRaschet = raschetNumber[index];
			string fName = "undefined";
			for (FirmInfo f : firms) {
				if (f.firmRaschet == fRaschet) {
					fName = f.firmName;
					break;
				}

			}
			prizesInfo.push_back(PrizeInfo{ diplomaNumber[index], prizeName[index], FirmInfo{fName, fRaschet} });
		}
	}

	void sortPrizesInfo() {
		int num = prizesInfo.size(); // amount of elements in array/container 
		for (int i = 0; i < num - 1; i++) {
			for (int j = 0; j < num - i - 1; j++) {
				if (prizesInfo[j].prizeNum > prizesInfo[j + 1].prizeNum) {
					// swap
					swap(prizesInfo[j], prizesInfo[j + 1]);

				}
				

				// compare and swap
			}
		}
	}

	void sortPrizesInfoByDefault() {
		sort(prizesInfo.begin(), prizesInfo.end(), [](PrizeInfo& p1, PrizeInfo& p2) {
			return p1.prizeNum < p2.prizeNum;
		});
	
	}

	// input
	// NamePrizes.txt
	friend ifstream& operator >> (ifstream& in, TPrizes& tClass)
	{	
		vector<string> lines;
		vector<int> sLine;
		vector<int> nLine;

		lines = StringHelper::readLinesFromFile(in);

		sLine = StringHelper::getOnlyNumbers(StringHelper::separateByDelimiter(lines[0], { ' ' }));

		nLine = StringHelper::getOnlyNumbers(StringHelper::separateByDelimiter(lines[1], { ' ' }));

		lines.erase(lines.begin() + 0, lines.begin() + 2);

		tClass.s1 = sLine[0];
		tClass.s2 = sLine[1];
		tClass.s3 = sLine[2];

		tClass.n1 = nLine[0];
		tClass.n2 = nLine[1];
		tClass.n3 = nLine[2];

		for (string curLine : lines) {

			vector<string> elements;
			vector<int> lastTwoNumbers;
			elements = StringHelper::separateByDelimiter(curLine, { ' ' });

			lastTwoNumbers = StringHelper::getOnlyNumbers(StringHelper::getLastElements(elements, 2));

			string name = StringHelper::uniteVectorElements(StringHelper::getWithoutLastElements(elements, 2));

			tClass.prizeName.push_back(name);
			tClass.diplomaNumber.push_back(lastTwoNumbers[0]);
			tClass.raschetNumber.push_back(lastTwoNumbers[1]);


		}



		return in;
	}

	// output
	friend ofstream& operator << (ofstream& of, TPrizes& tClass) {
		// ... operate with variable tClass !!! tClass.something[a]

		for (auto c: tClass.prizesInfo)
			of << c.toString() << endl;
		return of;
	}

	
	

};