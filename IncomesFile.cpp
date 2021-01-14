#include "IncomesFile.h"

void IncomesFile::deleteFile()
{

}

void IncomesFile::changeFilename()
{

}

vector<Income> IncomesFile::loadIncomesOfLoggedinUserFromFile()
{

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
    xml.AddElem( "Date", AuxiliaryMethods::convertIntToString(income.getDate()));
    xml.AddElem( "Item", income.getItem() );
    xml.AddElem( "Amount", income.getAmount() );
    xml.Save(getFileName());
}

int IncomesFile::getLastIncomeIdFromFile()
{

}
