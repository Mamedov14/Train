#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>

class Train;

std::vector<Train> saveTrains;
std::vector<Train> dataBase;

void MainMenu();
int getVariant(int count);

class Train {
private:
	int numberTrain;						// ����� ������.
	std::string startStation;				// ��������� �������.
	std::string endStation;					// �������� �������.

	int arrivalHour;						// ���� ��������.
	int arrivalMinutes;						// ������ ��������.

	int departureHour;						// ���� �����������.
	int departureMinutes;					// ������ �����������.

	int arrivalDay;							// ���� ��������
	int arrivalMonth;						// ����� �������� 

	int departureDay;						// ���� �����������
	int departureMonth;						// ����� ����������� 

public:
	void createdTrain();
	void infoTrain();
	static void load(const std::string& file);
	static void trainInVoronezh();
	static void outputDataBase();
	static void deleteInfoDataBase();
	static void changeTrainFields();
	static void outoutTrainNumber();
	static void outputParkingTime();
	static void sort();

	Train(int numberTrain, std::string startStation, std::string endStation,
		int arrivalDay, int arrivalMonth, int departureDay, int departureMonth,
		int arrivalHour = 0, int arrivalMinutes = 0, int departureHour = 0, int departureMinutes = 0)
	{
		this->numberTrain = numberTrain;
		this->startStation = startStation;
		this->endStation = endStation;

		this->arrivalHour = arrivalHour;
		this->arrivalMinutes = arrivalMinutes;

		this->departureHour = departureHour;
		this->departureMinutes = departureMinutes;

		this->arrivalDay = arrivalDay;
		this->arrivalMonth = arrivalMonth;

		this->departureDay = departureDay;
		this->departureMonth = departureMonth;
	}

	Train() {

	}

	~Train() {

	}

	// set
	std::string setStartStation(std::string startStation) {
		this->startStation = startStation;
		return startStation;
	}
	std::string setEndStation(std::string endStation) {
		this->endStation = endStation;
		return endStation;
	}
	int setDepartureDateDay(int day) {
		this->departureDay = day;
		return day;
	}
	int setDepartureDateMonth(int month) {
		this->departureMonth = month;
		return month;
	}
	int setArrivalDateDay(int day) {
		this->arrivalDay = day;
		return day;
	}
	int setArrivalDateMonth(int month) {
		this->arrivalMonth = month;
		return month;
	}
	int setDepartureTimeHour(int hour) {
		this->departureHour = hour;
		return hour;
	}
	int setDepartureTimeMinutes(int minutes) {
		this->departureMinutes = minutes;
		return minutes;
	}
	int setArrivalTimeHour(int hour) {
		this->arrivalHour = hour;
		return hour;
	}
	int setArrivalTimeMinutes(int minutes) {
		this->arrivalMinutes = minutes;
		return minutes;
	}


};

void Train::createdTrain() {
	std::cout << "������� ����� ������: ";
	std::cin >> numberTrain;
	std::cout << "������� ��������� �������: ";
	std::cin >> startStation;
	std::cout << "������� �������� �������: ";
	std::cin >> endStation;
	std::cout << "������� ���� �����������: ";
	std::cin >> departureDay;
	std::cout << "������� ����� �����������: ";
	std::cin >> departureMonth;
	std::cout << "������� ���� ��������: ";
	std::cin >> arrivalDay;
	std::cout << "������� ����� ��������: ";
	std::cin >> arrivalMonth;

	if (startStation == "�������") {
		std::cout << "������� ���� ����������� ������ � �������: ";
		std::cin >> departureHour;
		std::cout << "������� ������ ����������� ������ � �������: ";
		std::cin >> departureMinutes;
	}
	else if (endStation == "�������") {
		std::cout << "������� ���� �������� ������ � �������: ";
		std::cin >> arrivalHour;
		std::cout << "������� ������ �������� ������ � �������: ";
		std::cin >> arrivalMinutes;
	}
	else {
		std::cout << "������� ���� ����������� ������ �� ��������: ";
		std::cin >> departureHour;
		std::cout << "������� ������ ����������� ������ �� ��������: ";
		std::cin >> departureMinutes;
		std::cout << "������� ���� �������� ������ � �������: ";
		std::cin >> arrivalHour;
		std::cout << "������� ������ �������� ������ � �������: ";
		std::cin >> arrivalHour;
	}
}

void Train::infoTrain() {
	std::cout << "\n����� �" << numberTrain;
	std::cout << "\n��������� �������: " << startStation;
	std::cout << "\n�������� �������: " << endStation;
	std::cout << "\n���� �����������: " << departureDay << "." << departureMonth;
	std::cout << "\n���� ��������: " << arrivalDay << "." << arrivalMonth;;
	if (startStation == "�������") {
		std::cout << "\n�������� ������ �� ��������: " << departureHour << ":" << departureMinutes;
	}
	else if (endStation == "�������") {
		std::cout << "\n�������� ������ � �������: " << arrivalHour << ":" << arrivalMinutes;
	}
	else {
		std::cout << "\n�������� ������ � �������: " << arrivalHour << ":" << arrivalMinutes;
		std::cout << "\n�������� ������ �� ��������: " << departureHour << ":" << departureMinutes;
	}
}


int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int variant;
	do {
		MainMenu();
		variant = getVariant(9);
		switch (variant)
		{
		case 1: {
			std::cout << "��� ������:\n";
			Train::load("C:/Users/vagif/source/repos/Train/Train/allTrainRuns.txt");
			for (int i = 0; i < saveTrains.size(); i++) {
				saveTrains[i].infoTrain();
			}

			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		case 2: {
			Train::trainInVoronezh();
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		case 3: {
			Train::outputDataBase();
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		case 4: {
			Train::deleteInfoDataBase();
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		case 5: {
			Train::changeTrainFields();
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		case 6: {
			Train::outoutTrainNumber();
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		case 7: {
			Train::outputParkingTime();
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		case 8: {
			Train::sort();
			for (int i = 0; i < dataBase.size(); i++) {
				dataBase[i].infoTrain();
			}
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		}
		}

		if (variant != 9) {
			system("pause");
		}
	} while (variant != 9);


	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}

void Train::load(const std::string& file) {

	std::string str;
	std::fstream f;
	f.open("allTrainRuns.txt");

	if (!f) {
		std::cout << "Error!";
	}

	if (f.is_open()) {
		while (getline(f, str)) {
			if (str == "�����") {
				/* ������ ����, ��� ���������  � .txt �����.
							�����
							3
							������
							������
							15 12
							15 12
							10 15
							20 29
				*/

				// ���� �� ����� ����� ������.
				int number;
				f >> number;
				f << std::endl;
				// ���� �� ����� ������ ��������.
				std::string start;
				std::getline(f, start);
				// ���� �� ����� ����� ��������.
				std::string end;
				std::getline(f, end);
				// ���� �� ����� ����.
				int arrivalDay, arrivalMonth, departureDay, departureMonth;
				f >> arrivalDay;
				f >> arrivalMonth;
				f >> departureDay;
				f >> departureMonth;
				// ���� �� ����� �����.
				int arrivalHour{}, arrivalMinutes{}, departureHour{}, departureMinutes{};
				if (start == "�������") {
					f >> departureHour;
					f >> departureMinutes;
				}
				else if (end == "�������") {
					f >> arrivalHour;
					f >> arrivalMinutes;
				}
				else {
					f >> arrivalHour;
					f >> arrivalMinutes;
					f >> departureHour;
					f >> departureMinutes;
				}
				// 
				Train train(
					number, start, end,
					arrivalDay, arrivalMonth, departureDay, departureMonth,
					arrivalHour, arrivalMinutes, departureHour, departureMinutes);
				//train.infoTrain();
				saveTrains.push_back(train);
			}
		}
		f.close();
	}
}

void Train::trainInVoronezh() {
	std::cout << std::endl << std::endl << "���� ������!\n";
	int day, month;
	std::cout << "������� ���� � �����, ����� ������ ����� ������ ���� �� ������� ������� "
		<< "� ���������� ����:\n";
	std::cin >> day;
	std::cin >> month;
	bool check = false;
	for (int i = 0; i < saveTrains.size(); i++) {
		if ((day == saveTrains[i].arrivalDay && month == saveTrains[i].arrivalMonth) ||
			(day == saveTrains[i].departureDay && month == saveTrains[i].departureMonth)) {
			dataBase.push_back(saveTrains[i]);
			dataBase.back().infoTrain();
			check = true;
		}
	}
	if (!check) {
		std::cout << "� ���� ���� ������� �� ���� �� ������ �������!";
	}
}

void Train::outputDataBase() {
	std::cout << "��� ���������� �� ���� ������!\n";
	bool temp = false;
	for (int i = 0; i < dataBase.size(); i++) {
		dataBase[i].infoTrain();
		temp = true;
	}
	if (!temp) {
		std::cout << "� ��� �����))";
	}
}

void Train::deleteInfoDataBase() {
	int number;
	std::cout << "\n������� ����� ������ ���������� �������� ������ �������: ";
	std::cin >> number;
	for (int i = 0; i < dataBase.size(); i++) {
		if (number == dataBase[i].numberTrain) {
			dataBase.erase(dataBase.begin() + i);
		}
		if (!dataBase.size() == 0) {
			dataBase[i].infoTrain();
		}
		else {
			std::cout << "�� �� �������, ������ ��� �����))";
		}
	}
}

void Train::changeTrainFields() {
	int number;
	std::cout << "\n������� ����� ������ ���� �������� ������ ��������: ";
	std::cin >> number;

	std::cout << "\n�������� ����� ������ ���������!\n";
	std::cout << "1. ��������� �������\n";
	std::cout << "2. �������� �������\n";
	std::cout << "3. ���� �����������\n";
	std::cout << "4. ���� ��������\n";
	std::cout << "5. ����� �����������\n";
	std::cout << "6. ����� ��������\n";

	int check;
	std::cout << "\n������� ���� ������� ������ ��������: ";
	std::cin >> check;

	if (check == 1) {
		std::string start;
		std::cout << "������� ����� ��������� �������: ";
		std::cin >> start;
		for (int i = 0; i < dataBase.size(); i++) {
			if (number == dataBase[i].numberTrain) {
				dataBase[i].setStartStation(start);
			}
		}
	}
	else if (check == 2) {
		std::string end;
		std::cout << "������� ����� �������� �������: ";
		std::cin >> end;
		for (int i = 0; i < dataBase.size(); i++) {
			if (number == dataBase[i].numberTrain) {
				dataBase[i].setEndStation(end);
			}
		}
	}
	else if (check == 3) {
		int day, month;
		std::cout << "������� ����� ���� �����������(���� � �����): ";
		std::cin >> day;
		std::cin >> month;
		for (int i = 0; i < dataBase.size(); i++) {
			if (number == dataBase[i].numberTrain) {
				dataBase[i].setDepartureDateDay(day);
				dataBase[i].setDepartureDateMonth(month);
			}
		}
	}
	else if (check == 4) {
		int day, month;
		std::cout << "������� ����� ���� ��������(���� � �����): ";
		std::cin >> day;
		std::cin >> month;
		for (int i = 0; i < dataBase.size(); i++) {
			if (number == dataBase[i].numberTrain) {
				dataBase[i].setArrivalDateDay(day);
				dataBase[i].setArrivalDateMonth(month);
			}
		}
	}
	else if (check == 5) {
		int hour, minutes;
		std::cout << "������� ����� ����� �����������(���� � ������): ";
		std::cin >> hour;
		std::cin >> minutes;
		for (int i = 0; i < dataBase.size(); i++) {
			if (number == dataBase[i].numberTrain) {
				dataBase[i].setDepartureTimeHour(hour);
				dataBase[i].setDepartureTimeMinutes(minutes);
			}
		}
	}
	else if (check == 6) {
		int hour, minutes;
		std::cout << "������� ����� ����� ��������(���� � ������): ";
		std::cin >> hour;
		std::cin >> minutes;
		for (int i = 0; i < dataBase.size(); i++) {
			if (number == dataBase[i].numberTrain) {
				dataBase[i].setArrivalTimeHour(hour);
				dataBase[i].setArrivalTimeMinutes(minutes);
			}
		}
	}
	else {
		std::cout << "������ ������ ���!";
	}

	std::cout << "��� ��������� �����, ������� ��� ������:\n";
	bool temp = false;
	for (int i = 0; i < dataBase.size(); i++) {
		if (number == dataBase[i].numberTrain) {
			dataBase[i].infoTrain();
			temp = true;
		}
	}
	if (!temp) {
		std::cout << "� ���� ������ �����, �� ������ �� ������ ��������!";
	}
}

void Train::outoutTrainNumber() {
	int number;
	std::cout << "������� ����� ������: ";
	std::cin >> number;
	for (int i = 0; i < dataBase.size(); i++) {
		if (number == dataBase[i].numberTrain) {
			std::cout << "�������: " << dataBase[i].startStation << " - " << dataBase[i].endStation;
		}
	}
}

void Train::outputParkingTime() {
	for (int i = 0; i < dataBase.size(); i++) {
		std::cout << "\n����� �" << dataBase[i].numberTrain;
		std::cout << "\n����� ������� � ��������: " <<
			abs(dataBase[i].departureHour - dataBase[i].arrivalHour) << ":" <<
			abs(dataBase[i].departureMinutes - dataBase[i].arrivalMinutes);
	}
}

void Train::sort() {
	for (int i = 0; i < dataBase.size(); i++) {
		for (int j = 0; j < dataBase.size() - i - 1; j++) {
			if (dataBase[j].departureHour > dataBase[j + 1].departureHour) {
				std::swap(dataBase[j], dataBase[j + 1]);
			}
			else if (dataBase[j].departureHour == dataBase[j + 1].departureHour &&
				dataBase[j].departureMinutes > dataBase[j + 1].departureMinutes) {
				std::swap(dataBase[j], dataBase[j + 1]);
			}
		}
	}
}


void MainMenu() {
	system("cls");
	std::cout << "\n����!\n";
	std::cout << "1. ��������� ����� ������ �������.\n";
	std::cout << "2. ���������� ������, ������� ���� � ���������� ���� � ��������.\n";
	std::cout << "3. ����������, ��� � ���� ������.\n";
	std::cout << "4. ������� ���������� �� ���� ������\n";
	std::cout << "5. ������������� ����.\n";
	std::cout << "6. ������� ������� �� ������ ������.\n";
	std::cout << "7. ������� ����� ������� ������ � ��������.\n";
	std::cout << "8. ����������� �� ������� ����������� �� ������� �������.\n";
	std::cout << "9. ����� �� ����.\n";
}

int getVariant(int count) {
	int variant;
	std::string str;
	std::cin >> str;

	variant = std::stoi(str); // string to integer!
	while (variant < 1 || variant > count) {
		std::cout << "\n";
		std::cin >> str;
		variant = std::stoi(str);
	}

	return variant;
}
