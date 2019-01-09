#include <utility>

//
// Created by MaxBe on 09-Jan-19.
//

#include "PortFactory.h"
#include "exceptions/PortNotFoundException.h"

Port PortFactory::CreatePort(nostd::String port_name) {
    nostd::Array<Cargo> cargo_arr;

    //Assumed is that both files have the same first_row indicating all possible goods
    _fr.Open("goederen_prijzen.csv");
    const nostd::String* first_row {_fr.GetSpecificLine(nostd::String{})};
    const nostd::String* raw_prices_line {_fr.GetSpecificLine(port_name)};
    _fr.Close();
    _fr.Open("goederen_hoevelheid.csv");
    const nostd::String* raw_stock_line {_fr.GetSpecificLine(port_name)};

    if(first_row == nullptr || raw_prices_line == nullptr || raw_stock_line == nullptr) {
        throw PortNotFoundException("Port name could not be found in file");
    } else {
        nostd::Array<nostd::String> price_tokens = raw_prices_line->Tokenize(';');
        nostd::Array<nostd::String> stock_tokens = raw_stock_line->Tokenize(';');
        nostd::Array<nostd::String> first_row_tokens = first_row->Tokenize(';');
        //skip the first column
        for (int i = 1; i < first_row_tokens.size(); ++i) {
            nostd::String cargo_name {first_row_tokens[i]};
            nostd::String* split_price_ptr = price_tokens[i].Split('-');
            nostd::String* split_stock_ptr = stock_tokens[i].Split('-');
            nostd::Range price_range{atoi(split_price_ptr[0].c_str()), atoi(split_price_ptr[1].c_str())};
            nostd::Range stock_range{atoi(split_stock_ptr[0].c_str()), atoi(split_stock_ptr[1].c_str())};
            cargo_arr.addBack(Cargo{cargo_name, price_range.GetRandom(), stock_range.GetRandom()});
            delete[] split_price_ptr;
            delete[] split_stock_ptr;
        }
    }

    delete first_row;
    delete raw_prices_line;
    delete raw_stock_line;

    return Port();
}
