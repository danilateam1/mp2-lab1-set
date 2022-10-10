#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
    this->MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet& s) : BitField(s.MaxPower)
{
    this->MaxPower = s.MaxPower;
    this->BitField = s.BitField;
}

// конструктор преобразования типа
TSet::TSet(const TBitField& bf) : BitField(bf.GetLength())
{
    this->MaxPower = bf.GetLength();
    this->BitField = bf;
}

TSet::operator TBitField()
{
    TBitField res(this->MaxPower);
    res = this->BitField;
    return res;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    if (BitField.GetBit(Elem) == 1)
        return 1;
    else
        return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet& s) // присваивание
{
    if (*this == s)
        return *this;
    this->MaxPower = s.MaxPower;
    this->BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet& s) const // сравнение
{
    if (this->MaxPower != s.MaxPower)
        return 0;
    else if ((this->MaxPower == s.MaxPower) && (this->BitField == s.BitField))
        return 1;
    return 0;
}

int TSet::operator!=(const TSet& s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet& s) // объединение
{

    TSet res(this->MaxPower > s.MaxPower ? this->MaxPower : s.MaxPower);
    res.BitField = this->BitField | s.BitField;
    return res;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet res(this->MaxPower);
    res.BitField = this->BitField;
    res.InsElem(Elem);
    return res;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet res(this->MaxPower);
    res.BitField = this->BitField;
    res.DelElem(Elem);
    return res;
}

TSet TSet::operator*(const TSet& s) // пересечение
{
    TSet res(this->MaxPower > s.MaxPower ? this->MaxPower : s.MaxPower);
    res.BitField = this->BitField & s.BitField;
    return res;
}

TSet TSet::operator~(void) // дополнение
{
    TSet res(this->MaxPower);
    res.BitField = ~this->BitField;
    return res;
}

// перегрузка ввода/вывода
istream& operator>>(istream& istr, TSet& s) // ввод
{
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
    ostr << s.BitField;
    return ostr;
}