#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Client.h"
#include "Instructor.h"

class Lesson
{
public:
	Lesson();
	Lesson(Client client, Instructor intstructor, std::string data, std::string time, int paymentstatus);
	~Lesson();

	Client Getclient() const;
	Instructor Getintstructor() const;
	std::string Getdata() const;
	std::string Gettimes() const;
	int Getpaymentstatus() const;
	void Input();
	void Print() const;
	void Setpaymentstatus(int paymentstatus);

private:
	Client client;
	Instructor intstructor;
	std::string data;
	std::string time;
	int paymentstatus;

	bool CheckArguments(Client client, Instructor intstructor, std::string data, std::string time, int paymentstatus);
};

bool Lesson::CheckArguments(Client client, Instructor intstructor, std::string data, std::string time, int paymentstatus) {
	return paymentstatus > 0 && paymentstatus < 3;
}


Lesson::Lesson()
{
	client = Client();
	intstructor= Instructor();
	data="Не указано";
	time = "Не указано";
	paymentstatus = 0;
}


Lesson::Lesson(Client client, Instructor intstructor, std::string data, std::string time, int paymentstatus)
{
	this->client = client;
	this->intstructor = intstructor;
	this->data = data;
	this->time = time;
	this->paymentstatus = paymentstatus;
}

Lesson::~Lesson()
{
}


Client Lesson::Getclient() const {
	return client;
}

Instructor Lesson::Getintstructor() const {
	return intstructor;
}

std::string Lesson::Getdata() const {
	return data;
}
std::string Lesson::Gettimes() const {
	return time;
}
int Lesson::Getpaymentstatus() const {
	return paymentstatus;
}
void Lesson::Setpaymentstatus(int paymentstatus) {
	this->paymentstatus = paymentstatus;
}

void Lesson::Input() {
	Client client;
	Instructor intstructor;
	std::string data;
	std::string time;
	int paymentstatus;
	std::cout << "\tВвод данных об уроке\n";
	client.Input();
	intstructor.Input();
	std::cout << "Введите дату: ";
	while (getchar() != '\n');
	std::getline(std::cin, data);
	std::cout << "Введите время: ";
	std::getline(std::cin, time);
	std::cout << "Введите статус оплаты(1-оплачено, 2- не оплачено): ";
	std::cin >> paymentstatus;
	if (CheckArguments(client, intstructor, data, time, paymentstatus)) {
		this->client = client;
		this->intstructor = intstructor;
		this->data = data;
		this->time = time;
		this->paymentstatus = paymentstatus;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

void Lesson::Print() const {
	std::cout << "\tИнформация об уроке\n";
	std::cout <<"Дата: " << this->data << "\tВремя: " << this->time<<"\tCтатус оплаты(1-оплачено, 2- не оплачено): " << this->paymentstatus << "\n\n";
}