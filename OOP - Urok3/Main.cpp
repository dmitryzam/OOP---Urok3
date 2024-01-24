#include<iostream>
#include<string>

class Cassa {
private:
	std::string name;
	int money_;

public:
	Cassa():money_(0){}

	int CurrentMoney() {	// - возможность просматривать в кассе денежку
		return money_;
	}

	void CashIn(int money) {	// - внесение денежки в кассу
		this->money_ += money;
	}

	void CashOut(int money) {	// - извлечение денежки из кассы
		if (money > money_) {
			std::cerr << "not enough money\n";
			return;
		}

		this->money_ -= money;
	}

	int Exchange(int ticket, int money) {	// - выдача сдачи
		if (money < ticket) {
			std::cerr << "not enough money for operation\n";
			return money;
		}
		if (money_ < money - ticket) {
			std::cerr << "not enough money return change\n";
		}

		money_ += ticket;
		return money - ticket;
	}

};

int main() {
	setlocale(LC_ALL, "RU");
	int n;

	Cassa var1; // - создали экземпляр класса Cassa
	Cassa var2;
	Cassa var3;

	var1.CashIn(1000);

	std::cout << "first cassa has " << var1.CurrentMoney() << '\n';
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	std::cout << "=================\n\n";


	// Попробуем взять денежку с обоих касс:
	var1.CashOut(2000);
	std::cout << "first cassa has " << var1.CurrentMoney() << '\n';
	var1.CashOut(200);
	std::cout << "first cassa has " << var1.CurrentMoney() << '\n';
	std::cout << "=================\n\n";
	var2.CashOut(10);
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	var1.CashOut(0);
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	std::cout << "=================\n\n";
	// Попробуем оплатить в 2-ой кассе:
	std::cout << "Оплата во 2-ой кассе:\n";
	int change = 0;
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	change = var2.Exchange(100, 20);
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	std::cout << "change is - " << change << '\n';
	std::cout << "=================\n\n";
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	change = var2.Exchange(100, 120);
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	std::cout << "change is - " << change << '\n';
	std::cout << "=================\n\n";
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	change = var2.Exchange(100, 100);
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	std::cout << "change is - " << change << '\n';
	std::cout << "=================\n\n";
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	change = var2.Exchange(10, 20);
	std::cout << "second cassa has " << var2.CurrentMoney() << '\n';
	std::cout << "change is - " << change << '\n';
	std::cout << "=================\n\n";


	return 0;
}