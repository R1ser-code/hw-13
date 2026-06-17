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
    Address()
    {
        city = "";
        street = "";
        house = 0;
        apartment = 0;
    }

    Address(std::string city, std::string street, int house, int apartment)
    {
        this->city = city;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }

    std::string getCity() const
    {
        return city;
    }

    std::string get_output_address() const
    {
        return city + ", " + street + ", " +
            std::to_string(house) + ", " +
            std::to_string(apartment);
    }
};

void sort(Address* addresses, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (addresses[j].getCity() > addresses[j + 1].getCity())
            {
                Address temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
    }
}

int main()
{
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (!fin.is_open())
    {
        std::cout << "Error opening file in.txt" << std::endl;
        return 1;
    }

    int count;
    fin >> count;
    fin.ignore();

    Address* addresses = new Address[count];

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

        addresses[i] = Address(city, street, house, apartment);
    }

    sort(addresses, count);

    fout << count << std::endl;

    for (int i = 0; i < count; i++)
    {
        fout << addresses[i].get_output_address() << std::endl;
    }

    delete[] addresses;

    fin.close();
    fout.close();

    return 0;
}