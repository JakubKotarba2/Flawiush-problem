#include<iostream>

using namespace std;

struct wezel
{
	int wartosc;
	struct wezel* nastepny, * poprzedni;
}
*start;


int main()
{
	int n = 0, i = 1;
	start = NULL;
	wezel* p, * tmp;
	cin >> n;

	if (n <= 0) cout << "Zle dane!";
	else if (n == 1) cout << n;
	else
	{
		p = start;

		start = new wezel;
		p = start;
		p->wartosc = i;


		for (i = 2; i <= n; i++)
		{
			p->nastepny = new wezel;
			p->nastepny->poprzedni = p;
			p = p->nastepny;
			p->wartosc = i;
			p->nastepny = NULL;
		}

		p->nastepny = start;
		start->poprzedni = p;

		int y = 0;
		p = start->nastepny;

		do {
			cout << "\nwywalam " << p->wartosc;
			tmp = p->nastepny;
			p->poprzedni->nastepny = tmp;
			tmp->poprzedni = p->poprzedni;
			delete p;

			p = tmp;
			p = p->nastepny;
			y++;
		} while (y != n - 1);
		cout << "\nPozostaje: " << p->wartosc;

	}
}