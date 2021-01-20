#include "IncomesFile.h"

void IncomesFile::deleteFile()
{

}

void IncomesFile::changeFilename()
{

}

vector<Income> IncomesFile::loadIncomesOfLoggedInUserFromFile(int id)
{
    Income income;
    vector<Income> incomes;
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if(!fileExists) {
        cout << "Can't open file. File doesn't exist." << endl;
        system("pause");
    } else {
        string singleUserData = "";
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            singleUserData = xml.GetData();
            income.setIncomeId(atoi(singleUserData.c_str()));
            xml.FindElem("UserId");
            singleUserData = xml.GetData();
            income.setUserId(atoi(singleUserData.c_str()));
            xml.FindElem("Date");
            singleUserData = xml.GetData();
            income.setDate(singleUserData);
            xml.FindElem("Item");
            singleUserData = xml.GetData();
            income.setItem(singleUserData);
            xml.FindElem("Amount");
            singleUserData = xml.GetData();
            income.setAmount(singleUserData);
            incomes.push_back(income);
            xml.OutOfElem();
        }
    }
    return incomes;
}

Income IncomesFile::getIncomeData()
{

}

void IncomesFile::setLastIncomeId()
{

}

int IncomesFile::getLastIncomeId()
{

}

void IncomesFile::addIncomeToFile(Income income)
{
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Incomes" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Income" );
    xml.IntoElem();
    xml.AddElem( "IncomeId", AuxiliaryMethods::convertIntToString(income.getIncomeId()));
    xml.AddElem( "UserId", AuxiliaryMethods::convertIntToString(income.getUserId()));
    xml.AddElem( "Date", income.getDate());
    xml.AddElem( "Item", income.getItem() );
    xml.AddElem( "Amount", income.getAmount() );
    xml.Save(getFileName());
}

int IncomesFile::getLastIncomeIdFromFile()
{

}
