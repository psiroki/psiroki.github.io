#include <iostream>

using namespace std;

// SD: statikus destruktor
class SDA
{
public:
	inline SDA() { cout << "\tSDA()" << endl; }
	inline ~SDA() { cout << "\t~SDA()" << endl; }
};

class SDB: public SDA
{
public:
	inline SDB() { cout << "\tSDB()" << endl; }
	inline ~SDB() { cout << "\t~SDB()" << endl; }
};

// VD: statikus destruktor
class VDA
{
public:
	inline VDA() { cout << "\tVDA()" << endl; }
	virtual ~VDA();
};

VDA::~VDA()
{
	cout << "\t~VDA()" << endl;
}

class VDB: public VDA
{
public:
	inline VDB() { cout << "\tVDB()" << endl; }
	virtual ~VDB();
};

VDB::~VDB()
{
	cout << "\t~VDB()" << endl;
}

int main()
{
	cout << "SDA *sda = new SDB():" << endl;
	SDA *sda = new SDB();
	cout << "delete sda:" << endl;
	delete sda;
	
	cout << "SDB *sdb = new SDB():" << endl;
	SDB *sdb = new SDB();
	cout << "delete sdb:" << endl;
	delete sdb;
	
	cout << "VDB *vdb = new VDB():" << endl;
	VDB *vdb = new VDB();
	cout << "delete vdb:" << endl;
	delete vdb;
	
	cout << "VDA *vda = new VDB():" << endl;
	VDA *vda = new VDB();
	cout << "delete vda:" << endl;
	delete vda;
	
	return 0;
}
