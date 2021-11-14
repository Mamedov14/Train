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
	int numberTrain;						// номер поезда.
	std::string startStation;				// начальная станция.
	std::string endStation;					// конечная станция.

	int arrivalHour;						// часы прибытия.
	int arrivalMinutes;						// минуты прибытия.

	int departureHour;						// часы отправления.
	int departureMinutes;					// минуты отправления.

	int arrivalDay;							// день прибытия
	int arrivalMonth;						// месяц прибытия 

	int departureDay;						// день отправления
	int departureMonth;						// месяц отправления 

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
	std::cout << "Введите номер поезда: ";
	std::cin >> numberTrain;
	std::cout << "Введите начальную станцию: ";
	std::cin >> startStation;
	std::cout << "Введите конечную станцию: ";
	std::cin >> endStation;
	std::cout << "Введите день отправления: ";
	std::cin >> departureDay;
	std::cout << "Введите месяц отправления: ";
	std::cin >> departureMonth;
	std::cout << "Введите день прибытия: ";
	std::cin >> arrivalDay;
	std::cout << "Введите месяц прибытия: ";
	std::cin >> arrivalMonth;

	if (startStation == "Воронеж") {
		std::cout << "Введите часы отправления поезда в Воронеж: ";
		std::cin >> departureHour;
		std::cout << "Введите минуты отправления поезда в Воронеж: ";
		std::cin >> departureMinutes;
	}
	else if (endStation == "Воронеж") {
		std::cout << "Введите часы прибытия поезда в Воронеж: ";
		std::cin >> arrivalHour;
		std::cout << "Введите минуты прибытия поезда в Воронеж: ";
		std::cin >> arrivalMinutes;
	}
	else {
		std::cout << "Введите часы отправления поезда из Воронежа: ";
		std::cin >> departureHour;
		std::cout << "Введите минуты отправления поезда из Воронежа: ";
		std::cin >> departureMinutes;
		std::cout << "Введите часы прибытия поезда в Воронеж: ";
		std::cin >> arrivalHour;
		std::cout << "Введите минуты прибытия поезда в Воронеж: ";
		std::cin >> arrivalHour;
	}
}

void Train::infoTrain() {
	std::cout << "\nПоезд №" << numberTrain;
	std::cout << "\nНачальная станция: " << startStation;
	std::cout << "\nКонечная станция: " << endStation;
	std::cout << "\nДата отправления: " << departureDay << "." << departureMonth;
	std::cout << "\nДата прибытия: " << arrivalDay << "." << arrivalMonth;;
	if (startStation == "Воронеж") {
		std::cout << "\nОтправка поезда из Воронежа: " << departureHour << ":" << departureMinutes;
	}
	else if (endStation == "Воронеж") {
		std::cout << "\nПрибытие поезда в Воронеж: " << arrivalHour << ":" << arrivalMinutes;
	}
	else {
		std::cout << "\nПрибытие поезда в Воронеж: " << arrivalHour << ":" << arrivalMinutes;
		std::cout << "\nОтправка поезда из Воронежа: " << departureHour << ":" << departureMinutes;
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
			std::cout << "Все поезда:\n";
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
			if (str == "Поезд") {
				/* Пример того, что находится  в .txt файле.
							Поезд
							3
							Липецк
							Москва
							15 12
							15 12
							10 15
							20 29
				*/

				// взял из файла номер поезда.
				int number;
				f >> number;
				f << std::endl;
				// взял из файла начало маршрута.
				std::string start;
				std::getline(f, start);
				// взял из файла конец маршрута.
				std::string end;
				std::getline(f, end);
				// взял из файла даты.
				int arrivalDay, arrivalMonth, departureDay, departureMonth;
				f >> arrivalDay;
				f >> arrivalMonth;
				f >> departureDay;
				f >> departureMonth;
				// взял из файла время.
				int arrivalHour{}, arrivalMinutes{}, departureHour{}, departureMinutes{};
				if (start == "Воронеж") {
					f >> departureHour;
					f >> departureMinutes;
				}
				else if (end == "Воронеж") {
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
	std::cout << std::endl << std::endl << "БАЗА ДАННЫХ!\n";
	int day, month;
	std::cout << "Введите день и месяц, чтобы узнать какие поезда были на станции Воронеж "
		<< "в конкретный день:\n";
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
		std::cout << "В этот день поездов не было на стации Воронеж!";
	}
}

void Train::outputDataBase() {
	std::cout << "Вся информация из Базы Данных!\n";
	bool temp = false;
	for (int i = 0; i < dataBase.size(); i++) {
		dataBase[i].infoTrain();
		temp = true;
	}
	if (!temp) {
		std::cout << "А тут пусто))";
	}
}

void Train::deleteInfoDataBase() {
	int number;
	std::cout << "\nВведите номер поезда информацию которого хотите удалить: ";
	std::cin >> number;
	for (int i = 0; i < dataBase.size(); i++) {
		if (number == dataBase[i].numberTrain) {
			dataBase.erase(dataBase.begin() + i);
		}
		if (!dataBase.size() == 0) {
			dataBase[i].infoTrain();
		}
		else {
			std::cout << "Вы всё удалили, теперь тут пусто))";
		}
	}
}

void Train::changeTrainFields() {
	int number;
	std::cout << "\nВведите номер поезда поля которого хотите изменить: ";
	std::cin >> number;

	std::cout << "\nИзменять номер поезда ЗАПРЕЩЕНО!\n";
	std::cout << "1. Начальную станцию\n";
	std::cout << "2. Конечную станцию\n";
	std::cout << "3. Дату отправления\n";
	std::cout << "4. Дату прибытия\n";
	std::cout << "5. Время отправления\n";
	std::cout << "6. Время прибытия\n";

	int check;
	std::cout << "\nВведите поле которое хотите изменить: ";
	std::cin >> check;

	if (check == 1) {
		std::string start;
		std::cout << "Введите новую начальную станцию: ";
		std::cin >> start;
		for (int i = 0; i < dataBase.size(); i++) {
			if (number == dataBase[i].numberTrain) {
				dataBase[i].setStartStation(start);
			}
		}
	}
	else if (check == 2) {
		std::string end;
		std::cout << "Введите новую конечную станцию: ";
		std::cin >> end;
		for (int i = 0; i < dataBase.size(); i++) {
			if (number == dataBase[i].numberTrain) {
				dataBase[i].setEndStation(end);
			}
		}
	}
	else if (check == 3) {
		int day, month;
		std::cout << "Введите новую дату отправления(день и месяц): ";
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
		std::cout << "Введите новую дату прибытия(день и месяц): ";
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
		std::cout << "Введите новое время отправления(часы и минуты): ";
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
		std::cout << "Введите новое время прибытия(часы и минуты): ";
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
		std::cout << "Такого пункта нет!";
	}

	std::cout << "Ваш вабранный поезд, который был изменён:\n";
	bool temp = false;
	for (int i = 0; i < dataBase.size(); i++) {
		if (number == dataBase[i].numberTrain) {
			dataBase[i].infoTrain();
			temp = true;
		}
	}
	if (!temp) {
		std::cout << "В базе данных пусто, Вы ничего не можете изменить!";
	}
}

void Train::outoutTrainNumber() {
	int number;
	std::cout << "Введите номер поезда: ";
	std::cin >> number;
	for (int i = 0; i < dataBase.size(); i++) {
		if (number == dataBase[i].numberTrain) {
			std::cout << "Маршрут: " << dataBase[i].startStation << " - " << dataBase[i].endStation;
		}
	}
}

void Train::outputParkingTime() {
	for (int i = 0; i < dataBase.size(); i++) {
		std::cout << "\nПоезд №" << dataBase[i].numberTrain;
		std::cout << "\nВремя стоянки в Воронеже: " <<
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
	std::cout << "\nМеню!\n";
	std::cout << "1. Посмотеть какие поезда имеются.\n";
	std::cout << "2. Посмотреть поезда, которые были в конкретный день в Воронеже.\n";
	std::cout << "3. Посмотреть, что в базе данных.\n";
	std::cout << "4. Удалить информацию из базы данных\n";
	std::cout << "5. Редактировать поля.\n";
	std::cout << "6. Вывести маршрут по номеру поезда.\n";
	std::cout << "7. Вывести время стоянки поезда в Воронеже.\n";
	std::cout << "8. Сортировать по времени отправления со станции Воронеж.\n";
	std::cout << "9. Выйти из меню.\n";
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
