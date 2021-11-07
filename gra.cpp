#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

/*
POSSIBLE IMPROVEMENTS
- Polepszyć losowość wyciągania kart z decku. (Funkcja RandomCard)
- Dodać przycisk Double
- Zmienić AS na 11 lub 1 (jest tylko 11 teraz) 
- Dorobić oprawę graficzną
- Zrobić variable z procentem zwycięstwa dla kasyna (60%,70% itp.)
*/

//Globalne zmienne używane w grze
int money, x, PlayerValue, DealerValue, CardNumber, bet, action;
vector<int> Stash = {};
vector<int> PlayerCards = {};
vector<int> DealerCards = {};
bool PlayerDone;
string PlayerName;

//Struktura Decku kart
struct CardDeck
{
    string kolor;
    string karta;
    int value;
} Deck[52];

//Generowanie losowej karty z decku 52 kart
int RandomCard()
{
    int RandomCard = 1 + (rand() % 52);
    return RandomCard;
}

//Wyciąganie karty z decku (Dealer albo Player)
void PullCard(string PlayerType)
{
    //Zmienna sprawdzająca czy karta jest już na stole lub w stosie kart odrzuconych
    bool IfInStash = true;

    while (IfInStash == true)
    {
        CardNumber = RandomCard();
        if (Stash.size() > 0)
        {
            for (int i = 0; i < Stash.size(); i++)
            {
                if (Stash[i] == CardNumber)
                {
                    IfInStash == true;
                }
                else
                {
                    if (PlayerType == "Dealer")
                    {
                        DealerValue = DealerValue + Deck[CardNumber].value;
                        DealerCards.push_back(CardNumber);
                        Stash.push_back(CardNumber);
                        IfInStash == false;
                        return;
                    }
                    else
                    {
                        PlayerValue = PlayerValue + Deck[CardNumber].value;
                        PlayerCards.push_back(CardNumber);
                        Stash.push_back(CardNumber);
                        IfInStash == false;
                        return;
                    }
                }
            }
        }
        else
        {
            if (PlayerType == "Dealer")
            {
                DealerValue = DealerValue + Deck[CardNumber].value;
                DealerCards.push_back(CardNumber);
                Stash.push_back(CardNumber);
                IfInStash == false;
                return;
            }
            else
            {
                PlayerValue = PlayerValue + Deck[CardNumber].value;
                PlayerCards.push_back(CardNumber);
                Stash.push_back(CardNumber);
                IfInStash == false;
                return;
            }
        }
    }
}

//Pokazywanie kart na ręce (dealer albo gracz)
void ShowHand(string PlayerType)
{
    if (PlayerType == "Dealer")
    {
        cout << "Dealer cards: ";
        for (int i = 0; i < DealerCards.size(); i++)
        {
            cout << Deck[DealerCards[i]].karta << " " << Deck[DealerCards[i]].kolor << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Player cards: ";
        for (int i = 0; i < PlayerCards.size(); i++)
        {
            cout << Deck[PlayerCards[i]].karta << " " << Deck[PlayerCards[i]].kolor << " ";
        }
        cout << endl;
    }
}

//Pokazywanie salda gracza
void ShowMoney()
{
    cout << "Twoje saldo wynosi: " << money << endl;
}

//Aktualizacja pliku tekstowego z saldem graczy
void ChangeMoneyFile(int addedmoney)
{
    //Odczyt z pliku
    fstream data("./data.txt", ios::in);
    string myline;
    vector<string> lines = {};
    int i = 0;
    while (getline(data, myline))
    {
        string nickname = myline.substr(0, myline.find(' '));
        string money2 = myline.substr(myline.find(' '), myline.length());
        if (nickname == PlayerName)
        {
            string NewLine = nickname + " " + to_string(addedmoney);
            lines.push_back(NewLine);
        }
        else
        {
            lines.push_back(myline);
        }
        i++;
    }
    data.close();

    //Zapis zaktualizowanych danych
    fstream data2("./data.txt", ios::out);
    for (int i = 0; i < lines.size(); i++)
    {
        data2 << lines[i] << endl;
    }
    data2.close();
}

//Zakończenie gry (dealer albo gracz)
void EndGame(string PlayerType)
{
    if (PlayerType == "Dealer")
    {
        cout << "Tym razem sie nie udalo. Przegrywasz " << bet << " $" << endl;
        money = money - bet;
        ShowMoney();
        PlayerDone = true;
    }
    else if (PlayerType == "Player")
    {
        cout << "Gratulacje, wygrywasz " << bet << " $" << endl;
        money = money + bet;
        ShowMoney();
        PlayerDone = true;
    }
    else
    {
        cout << "Remis, nikt nie wygrywa" << endl;
        ShowMoney();
        PlayerDone = true;
    }
}

//Lista kolorów oraz figur
string kolory[4] = {"Pik", "Trefl", "Karo", "Kier"};
string karty[13] = {"As", "Krol", "Dama", "Walet", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
int Values[13] = {11, 10, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2};

//Start programu - funkcja main()
int main()
{

    //Pytamy gracza aby podał swój nickname
    cout << "Podaj swoj nickname" << endl;
    cin >> PlayerName;

    //Wczytanie pliku tekstowego z danymi graczy
    fstream data("./data.txt", ios::in);

    //Pobranie danych z pliku tekstowego
    if (data.good())
    {
        string myline, nickname, money2;
        bool PlayerFound = false;
        while (getline(data, myline) && PlayerFound == false)
        {
            nickname = myline.substr(0, myline.find(' '));
            money2 = myline.substr(myline.find(' '), myline.length());
            if (nickname == PlayerName)
            {
                PlayerFound = true;
                money = stoi(money2);
                cout << "Znaleziono gracza w bazie. Twoje saldo to: " << money << endl;
            }
            else
            {
                PlayerFound = false;
            }
        }
        data.close();

        //Jeśli gracz nie został znaleziony w bazie (Tworzymy nowego gracza z saldem 100 i dodajemy do bazy)
        if (PlayerFound == false)
        {
            fstream data("./data.txt", ios::app);
            cout << "Nowy gracz wprowadzony do bazy. Twoje saldo to: 100" << endl;
            string addnewline = PlayerName + " 100";
            data << addnewline << endl;
            money = 100;
            data.close();
        }
    }
    else
    //Jeśli plik tekstowy "data.txt" nie otwiera się
    {
        cout << "Nie udalo sie otworzyc bazy danych graczy" << endl;
        return 0;
    }

    //Rozpoczęcie gry, przywrócenie wartości do początkowych.
    x = 0;
    CardNumber = 0;
    //Budowanie Decku kart
    for (int i = 0; i < 52; i++)
    {
        Deck[i].karta = karty[i % 13];
        Deck[i].kolor = kolory[x];
        Deck[i].value = Values[i % 13];
        if ((i + 1) % 13 == 0)
        {
            x++;
        }
    }

    while (money > 0)
    {
        //Zerowanie wartości początkowych
        Stash = {};
        PlayerCards = {};
        DealerCards = {};
        PlayerValue = 0;
        DealerValue = 0;
        PlayerDone = false;

        cout << "Do you want to play blackjack? 1 - Yes, 2 - No" << endl;
        int ask;
        cin >> ask;
        if (ask == 1)
        {
            cout << "Place your bet" << endl;
            cin >> bet;
            //Jeśli gracz nie ma wystarczajaco pieniedzy
            if (bet > money)
            {
                cout << "You dont have enough money" << endl;
                return 0;
            }
        }
        else if (ask == 2)
        {
            cout << "Thanks for playing" << endl;
            ChangeMoneyFile(money);
            return 0;
        }
        else
        {
            cout << "You typed wrong number" << endl;
            ChangeMoneyFile(money);
            return 0;
        }

        cout << "You bet " << bet << " $. Let's begin." << endl;

        //Wywołanie funkcji wyciągania kart
        PullCard("Dealer");
        PullCard("Player");
        PullCard("Player");

        //Wywołanie funkcji pokazania kart
        ShowHand("Dealer");
        ShowHand("Player");
        if (PlayerValue != 21)
        {
            while (PlayerDone == false)
            {
                cout << "Do you want to push or stay? 1 - Push, 2 - Stay" << endl;
                cin >> action;
                if (action == 1)
                {
                    PullCard("Player");
                    ShowHand("Player");
                    if (PlayerValue > 21)
                    {
                        EndGame("Dealer");
                    }
                    else
                    {
                        PlayerDone = false;
                    }
                }
                else if (action == 2)
                {
                    while (DealerValue < 17)
                    {
                        PullCard("Dealer");
                    }
                    ShowHand("Dealer");
                    ShowHand("Player");
                    if (DealerValue >= 17)
                    {
                        if (DealerValue > 21)
                        {
                            EndGame("Player");
                        }
                        else
                        {
                            if (DealerValue > PlayerValue)
                            {
                                EndGame("Dealer");
                            }
                            else if (DealerValue < PlayerValue)
                            {
                                EndGame("Player");
                            }
                            else
                            {
                                EndGame("Draw");
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (DealerValue == 21 && PlayerValue == 21)
            {
                EndGame("Draw");
            }
            else
            {
                EndGame("Player");
            }
        }
    }
    //Zakończenie funkcji main()
    return 0;
}
