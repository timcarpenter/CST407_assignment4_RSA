// CST407_assignment4_RSA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>

using namespace std;

//to calculate the GDC of 'e' (encryption) and totient (Euler's totient formula)
int gcd(int e, int totient)
{
	int temp;
	while (1)
	{
		temp = e % totient;
		if (temp == 0)
			return totient;
		e = totient;
		totient = temp;
	}
}

int menu()
{
	int option = 0;
	cout << "***********************" << endl;
	cout << "****      RSA      ****" << endl;
	cout << "***********************" << endl;
	cout << "\n\n";

	cout << "Selections: [1/2/3]" << endl;
	cout << "  1. Encrypt" << endl
		<< "  2. Decrypt" << endl
		<< "  3. Exit" << endl
		<< "\n" 
		<< "Select: "; 

	cin >> option;

	return option;
}

void RSA(int option) //option: 1 = encrypt; 2 = decrypt
{
	//////////////////////////////////////////
	//  Defined variables

	double pt = 0;
	double ct = 0;
	double e = 0;
	double d = 0;
	double m = 0;

	//p & q = 2 prime numbers  //text.txt has prime number list
	double p = 11; //10009;	
	double q = 31; //10007;
	
	//n = public key quotient
	double n = p * q;
	
	//counter for gcd
	double counter;
	
	//Euler's Totient --> N = (p-1)(q-1)	
	double totient = (p - 1)*(q - 1);

	//k can be any arbitrary value	
	double k = 2;
	//////////////////////////////////////////
	
	if (option == 1) //if encrypting
	{
		//Get user input for plaintext value
		cout << "Type in a plaintext value: ";
		cin >> pt;
		cout << endl;
		//double pt = 5;

		//e = public key for encryption	
		cout << "Type in the encryption key (aka 'e'): ";
		cin >> e;
		cout << endl;
		//double e = 10037;
	}

	else if (option == 2) //if decrypting
	{
		//Get user input for encrypted value
		cout << "Type in a ciphertext value: ";
		cin >> ct;
		cout << endl;

		//d = private key decryption
		cout << "Type in decryption private key (aka 'd'): ";
		cin >> d;
		cout << endl;
		//choosing d such that it satisfies d*e = 1 + k * totient
		//d = (1 + (k*totient)) / e;
	}
	
	//checks for prime between e and totient which satisfies e>1
	while (e < totient) {
		counter = gcd(e, totient);
		if (counter == 1)
			break;
		else
			e++;
	}
	
	//Raise to power usage:  base^exponent 
	//Returns base raised to the power exponent :
	if (option == 1)
		ct = pow(pt, e);
	else if (option == 2)
		m = pow(ct, d);

	//fmod usage: fmod = numer - tquot * denom
	//Returns the floating - point remainder of numer / denom(rounded towards zero) :
	if (option == 1)
		ct = fmod(ct, n);
	else if (option ==2)
		m = fmod(m, n);

	if (option == 1)
	{
		cout << "Plaintext = " << pt;
		cout << "\n" << "p = " << p;
		cout << "\n" << "q = " << q;
		cout << "\n" << "n = pq = " << n;
		cout << "\n" << "totient = " << totient;
		cout << "\n" << "e = " << e;
		cout << "\n" << "Encrypted data = " << ct << endl;
	}
	else if (option == 2)
	{
		cout << "\n" << "Encrypted data = " << ct;
		cout << "\n" << "p = " << p;
		cout << "\n" << "q = " << q;
		cout << "\n" << "n = pq = " << n;
		cout << "\n" << "totient = " << totient;
		cout << "\n" << "d = " << d;
		cout << "\n" << "Original Message sent = " << m << endl;
	}
	//cout << "Plaintext = " << pt;
	//cout << "\n" << "p = " << p;
	//cout << "\n" << "q = " << q;
	//cout << "\n" << "n = pq = " << n;
	//cout << "\n" << "totient = " << totient;
	//cout << "\n" << "e = " << e;
	//cout << "\n" << "d = " << d;
	//cout << "\n" << "Encrypted data = " << ct;
	//cout << "\n" << "Original Message sent = " << m;
	cout << "\n\n";
	cin.clear();
}

int main()
{
	//////////////////////////////////////////
	//  Defined variables
	//menu option
	int option;
	//
	//////////////////////////////////////////
	cin.clear();
	do
	{

		option = menu();
		if (option == 1 || option == 2)
			RSA(option);
		else
			option = 3;
		cin.clear();
	} while (option != 3);

	cout << "\nExiting RSA program.\n";
	system("pause");

    return 0;
}

