// CST407_assignment4_RSA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>

using namespace std;

//to calculate the GDC of 'e' (encryption) and totient (Euler's totient formula)
unsigned long long gcd(unsigned long long e, unsigned long long totient)
{
	unsigned long long temp;
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

unsigned long long loop()
{
	unsigned long long number, exp, mod, result = 1;

	char continu = 'y';

	while (continu == 'y')
	{
		result = 1;

		cout << "Enter number, exp, and mod" << endl;
		cin >> number >> exp >> mod;


		for (int i = 0; i < exp; i++)
		{

			result = (result * number) % mod;

		}
		//cout << result;
		//cout << "\nType 'Y' to continue";
		//cin >> continu;
	}

	return result;
}

void RSA(int option) //option: 1 = encrypt; 2 = decrypt
{
	//////////////////////////////////////////
	//  Defined variables

	unsigned long long pt = 0;
	unsigned long long ct = 0;
	unsigned long long e = 0;
	unsigned long long d = 0;
	unsigned long long m = 0;
	unsigned long long k = 0;

	//////p & q = 2 prime numbers  //text.txt has prime number list
	//unsigned long long p = 47;	//11; //10009;	
	//unsigned long long q = 71;	//31; //10007;
	//e = 79; //for use if not using user input //
	//d = 1019;
	//k = 45;

	////p & q = 2 prime numbers  //text.txt has prime number list
	unsigned long long p = 10009;	
	unsigned long long q = 10007;
	e = 11; //for use if not using user input 
	d = 11;
	k = 385;

	//unsigned long long p = 107;	
	//unsigned long long q = 109;	
	//e = 7;  
	//d = 3271;
	//k = 2;

	//unsigned long long p = 197;		
	//unsigned long long q = 199;	
	//e = 881;  //d=881
	//unsigned long long k = 2;

	//n = public key quotient
	unsigned long long n = p * q;
	
	//counter for gcd
	double counter;
	
	//Euler's Totient --> N = (p-1)(q-1)	
	unsigned long long totient = (p - 1)*(q - 1);


	
	if (option == 1) //if encrypting
	{
		//Get user input for plaintext value
		cout << "Type in a plaintext value: ";
		cin >> pt;
		cout << endl;
		//double pt = 5;

		//////e = public key for encryption	
		////cout << "Type in the encryption key (aka 'e'): ";
		////cin >> e;
		////cout << endl;
	}

	else if (option == 2) //if decrypting
	{
		//Get user input for encrypted value
		cout << "Type in a ciphertext value: ";
		cin >> ct;
		cout << endl;

		//d = private key decryption
		//cout << "Type in decryption private key (aka 'd'): ";
		//cin >> d;
		//cout << endl;
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
		cout << "\n" << "n = " << n;
		cout << "\n" << "totient = " << totient;
		cout << "\n" << "e = " << e;
		cout << "\n" << "Encrypted data = " << ct << endl;
	}
	else if (option == 2)
	{
		cout << "\n" << "Encrypted data = " << ct;
		cout << "\n" << "p = " << p;
		cout << "\n" << "q = " << q;
		cout << "\n" << "n = " << n;
		cout << "\n" << "totient = " << totient;
		cout << "\n" << "d = " << d;
		cout << "\n" << "Original Message sent = " << m << endl;
	}

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

