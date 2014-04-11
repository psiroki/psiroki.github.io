#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// az algorithm sort fuggvenye nem a C-ben megszokott komparatort
// varja, hanem egy olyan tipusu erteket, amit felparameterezhet
// ket osszehasonlitando ertekkel, es az eredmenynek akkor kell
// igaznak lennie, ha az elso kisebb volt, mint a masodik

// ez az ertek lehet egy sima fuggveny is, jelen esetben viszont
// inkabb egy operator()-t tamogato osztaly, mert a kapott ertekek
// alapjan a referencia mapben hivatkozott ertekeket fogjuk felhasznalni
// a rendezeshez

// az osztalyt a kiirasi sorrend megallapitasahoz fogjuk felhasznalni,
// ahol az egyes szavakat aszerint akarjuk rendezni a tombben, hogy
// hanyszor fordulnak elo
template<typename K, typename V> class LessByValue
{
	const map<K, V> &ref;
public:
	LessByValue(const map<K, V> &map): ref(map)
	{
	}
	
	// true-val kell visszaternie, ha a < b
	bool operator()(const K &a, const K &b)
	{
		// a typename kulcsszo itt kell, mert egyebkent a fordito
		// nem tudja, hogy a const_iterator egy tipus, vagy egy statikus
		// fuggveny vagy valtozo
		
		// nyugi, en sem tudtam, hogy itt most hasznalni kell,
		// csak azt, hogy ha pampog a fordito, akkor meg kell
		// probalni a typename kulcsszot beszurva is :)
		
		// a map find fuggvenye normal esetben egy map iteratort
		// ad vissza
		
		// mivel ez a map konstans, ezert nem sima, hanem
		// const_iteratort kapunk
		typename map<K, V>::const_iterator ai = ref.find(a);
		typename map<K, V>::const_iterator bi = ref.find(b);
		
		// ha nem talalja, akkor az iterator az end() erteket
		// adja vissza
		
		// elore vesszuk azokat, amik annyira ritkak, hogy a
		// mapbe se kerultek bele
		if(ai == ref.end())
			return bi != ref.end();
		if(bi == ref.end())
			return false;
		// az iterator egy pointerkent viselkedik, es egy
		// pair<string, int> tipusu ertekre mutat
		
		// ha a es b ugyanannyiszor fordul elo, akkor
		// rendezzuk lexikografikusan
		if(ai->second == bi->second)
			return a < b;
		return ai->second < bi->second;
	}
};

const char * const IGNORED_CHARS = ".,!?\"'()";

int main()
{
	ifstream input("donut.txt");
	// szo => hanyszor fordul elo osszerendeles
	map<string, int> words;
	// ebben fogjuk majd a szavakat az elofordulasi
	// szamuk szerint rendezni
	vector<string> order;
	while(!input.eof())
	{
		string word;
		// kiolvassuk a szot
		input >> word;
		// vesszuk az elso nem kozpontozo karaktert
		int first = word.find_first_not_of(IGNORED_CHARS);
		// vesszuk az utolso nem kozpontozo karaktert
		int last = word.find_last_not_of(IGNORED_CHARS);
		
		// ha talaltunk nem kozpontozo karaktert
		// a string::find... fuggvenyei string::npos erteket adnak
		// vissza, ha nem talaltak semmit
		if(first != string::npos && last != string::npos && first <= last)
		{
			word = word.substr(first, last-first+1);
			// a transform az elso ket parameterben kap ket forras iteratort
			// (az elsotol kezdve halad egeszen a masodikig)
			// a harmadik parametere az, ahova az eredmeny kerul
			// (ahogy lathato, siman megengedett, hogy ugyanaz legyen)
			// a forras minden elemere meghivja a negyedik parameterben megadott
			// fuggvenyt (vagy osztalyt, ami a megfelelo formaju operator()-t
			// tamogatja), es az eredmenyt kiirja
			
			// a tolower a std nevterben mar definialva van, ezert most
			// kulon jelolom, hogy a globalis nevter tolower fuggvenyere
			// gondoltam
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			// ha nem szerepel a szo a mapben
			if(words.find(word) == words.end())
			{
				// akkor ez az elso elofordulas
				words[word] = 1;
				// es akkor az order tombben sem szerepelt eddig,
				// az is tuti
				order.push_back(word);
			} else
			{
				// egyebkent noveljuk a map erteket
				++words[word];
			}
		}
	}
	
	// rendezzuk az order tombot aszerint, hogy a szo hanyszor fordul elo
	sort(order.begin(), order.end(), LessByValue<string, int>(words));
	
	// kiirjuk a vegeredmenyt
	for(vector<string>::iterator orderIt = order.begin(); orderIt != order.end(); ++orderIt)
	{
		map<string, int>::iterator it = words.find(*orderIt);
		if(it != words.end())
		{
			cout.width(4);
			cout << it->second << " " << it->first << endl;
		}
	}
	
	return 0;
}
