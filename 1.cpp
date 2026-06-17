#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(std::string city, std::string street, int house, int apartment)
    {
        this->city = city;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }

    std::string get_output_address() const
    {
        return city + ", " + street + ", " +
            std::to_string(house) + ", " +
            std::to_string(apartment);
    }
};

int main()
{
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    int count;
    fin >> count;
    fin.ignore();

    Address** addresses = new Address * [count];

    for (int i = 0; i < count; i++)
    {
        std::string city;
        std::string street;
        int house;
        int apartment;

        std::getline(fin, city);
        std::getline(fin, street);
        fin >> house;
        fin >> apartment;
        fin.ignore();

        addresses[i] = new Address(city, street, house, apartment);
    }

    fout << count << std::endl;

    for (int i = count - 1; i >= 0; i--)
    {
        fout << addresses[i]->get_output_address() << std::endl;
    }

    for (int i = 0; i < count; i++)
    {
        delete addresses[i];
    }

    delete[] addresses;

    fin.close();
    fout.close();

    return 0;
}