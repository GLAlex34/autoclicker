#include "strmanip.h"

string_manipulation::Array<std::string> * output = nullptr;
string_manipulation::Array<std::string> * buffer = nullptr;

int string_manipulation::size(std::string input_str)
{
    int i = 0;

    while(input_str[i] != '\0')
        i++;

    return i;
} 

std::string string_manipulation::char_to_string(const char * input)
{
    int i = 0;
    std::string output = "";

    while(input[i] != '\0')
    {
        output += input[i];

        i++;
    }

    return output;
}

std::string string_manipulation::char_to_string(char * input)
{
    int i = 0;
    std::string output = "";

    while(input[i] != '\0')
    {
        output += input[i];

        i++;
    }

    return output;
}

string_manipulation::Array<std::string> & string_manipulation::split(std::string arr, char c)
{
    int size = 1;
    int i = 0;

    while(arr[i] != '\0')
    {
        if(arr[i] == c)
            size++;

        i++;
    }
        
    i = 0;
    std::string * aux = new std::string[size];
    int j = 0;

    while(arr[i] != '\0')
    {
        if(arr[i] != c)
            aux[j] += arr[i];
        else
        {
            if(aux[j] != "")
                j++;

            if(arr[i + 1] == '\0')
                j--;
        }

        i++;
    }

    output = new Array<std::string>(aux, j + 1);
    output->set_addr(output);
    buffer = output;
    
    return * output;
}

std::string string_manipulation::replace(std::string arr, std::string to_replace, std::string c)
{
    std::string output = "";
    std::string aux_str = "";
    int i = 0, j = 0, k = 0, z = 0, aux_i = 0;
    bool start_replace = false;
    int to_replace_size;

    while(arr[i] != '\0')
    {
            aux_str = "";
            start_replace = false;

            if(arr[i] == to_replace[0])
            {
                aux_i = i;

                to_replace_size = size(to_replace);

                while(aux_i - i < to_replace_size)
                {
                    if(arr[aux_i] != '\0')
                        aux_str += arr[aux_i];
                    else
                    {
                        aux_str = "";
                        break;
                    }

                    aux_i++;
                }

                if(aux_str == to_replace)
                {
                    i += to_replace_size - 1;
                    aux_str = "";
                    start_replace = true;
                }
            }
        
        if(!start_replace)
            output += arr[i];

        if(start_replace)
            output += c;

        i++;
    }

    return output;
}

std::string string_manipulation::replace(std::string arr, std::string to_replace[], int len, std::string c)
{
    std::string output = "";
    std::string aux_str = "";
    int i = 0, j = 0, k = 0, z = 0, aux_i = 0;
    bool start_replace = false;
    int to_replace_size;

    while(arr[i] != '\0')
    {
        while(z < len)
        {
            aux_str = "";
            start_replace = false;

            if(arr[i] == to_replace[z][0])
            {
                aux_i = i;

                to_replace_size = size(to_replace[z]);

                while(aux_i - i < to_replace_size)
                {
                    if(arr[aux_i] != '\0')
                        aux_str += arr[aux_i];
                    else
                    {
                        aux_str = "";
                        break;
                    }

                    aux_i++;
                }

                if(aux_str == to_replace[z])
                {
                    i += to_replace_size - 1;
                    aux_str = "";
                    start_replace = true;

                    break;
                }
            }

            z++;
        }
        
        if(!start_replace)
            output += arr[i];

        if(start_replace)
            output += c;

        i++;
        z = 0;
    }

    return output;
}

std::string string_manipulation::replace(std::string arr, std::string to_replace[], int len, std::string c[])
{
    std::string output = "";
    std::string aux_str = "";
    int i = 0, j = 0, k = 0, z = 0, aux_i = 0;
    bool start_replace = false;
    int to_replace_size;

    while(arr[i] != '\0')
    {
        while(z < len)
        {
            aux_str = "";
            start_replace = false;

            if(arr[i] == to_replace[z][0])
            {
                aux_i = i;

                to_replace_size = size(to_replace[z]);

                while(aux_i - i < to_replace_size)
                {
                    if(arr[aux_i] != '\0')
                        aux_str += arr[aux_i];
                    else
                    {
                        aux_str = "";
                        break;
                    }

                    aux_i++;
                }

                if(aux_str == to_replace[z])
                {
                    i += to_replace_size - 1;
                    aux_str = "";
                    start_replace = true;

                    break;
                }
            }

            z++;
        }
        
        if(!start_replace)
            output += arr[i];

        if(start_replace)
            output += c[z];

        i++;
        z = 0;
    }

    return output;
}

std::string string_manipulation::replace_duplicate(std::string input_string, std::string to_replace, std::string replace_with)
{
    int i = 0, j = 0, aux_i = 0;
    bool start_replace = false;
    std::string check_str = "";
    std::string output = "";

    while(input_string[i] != '\0')
    {
        start_replace = false;

        if(input_string[i] == to_replace[0])
            start_replace = true;

        if(start_replace)
        {
            aux_i = i;

            while(to_replace[j] != '\0')
            {
                if(input_string[aux_i] != '\0' && input_string[aux_i] == to_replace[j])
                    check_str += to_replace[j];
                else
                {
                    check_str = "";
                    break;
                }

                aux_i++;
                j++;
            }
        }

        if(!start_replace || check_str == "")
            output += input_string[i];

        if(check_str != "")
        {
            if(input_string[i + 1] != to_replace[0])
                output += replace_with;

            check_str = "";
        }

        i++;
        j = 0;
    }

    return output;
}

std::string string_manipulation::read(std::string str)
{
    std::string output = "";
    std::ifstream fout;
    fout.open(str);

    char c = fout.get();

    while(fout.good())
    {
        output += c;

        c = fout.get();
    }

    fout.close();

    return output;
}

void string_manipulation::write(std::string file, std::string output, std::string mode, bool newline)
{
    std::ofstream fin;
    fin.open(file, ( mode == "trunc" ? std::fstream::trunc : ( mode == "app" ? std::fstream::app : std::fstream::out )));

    fin << output << ( newline == true ? "\n" : "");

    fin.close();
}

int string_manipulation::grep(std::string str, std::string key)
{
    int i = 0;
    int j = 0;
    bool check = false;
    int response = 0;

    while(str[i] != '\0')
    {
        if(str[i] == key[j])
        {
            check = true;
        }
        else
            if(key[j] != '\0')
            {
                check = false;
                j = 0;
            }

        i++;
        if(check && key[j] != '\0')
            j++;

        if(str[i] == '\0' && key[j] != '\0')
            response = 0;

        if(str[i] == '\0' && key[j] == '\0' && check)
            response = 1;
    }

    return response;
}

void string_manipulation::clear()
{
    delete buffer;
}