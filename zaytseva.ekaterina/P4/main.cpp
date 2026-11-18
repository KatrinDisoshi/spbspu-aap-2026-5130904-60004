#include <iostream>
#include <new>

namespace zaytseva
{
  char* replaceSymbol(const char* source, char symb1, char symb2, char* result);
}

int main()
{
  const int initialMaxSize = 16;
  int maxSize = initialMaxSize;
  int length = 0;
  char* str = nullptr;
  char* result = nullptr;
  try
  {
    str = new char[maxSize + 1];
    std::cout << "Enter a string:\n";
    while (true)
    {
      const int ch = std::cin.get();
      if (ch == EOF || ch == '\n')
      {
        break;
      }
      if (length >= maxSize)
      {
        char* const newStr = new char[maxSize * 2 + 1];
        for (int i = 0; i < length; i++)
        {
          newStr[i] = str[i];
        }
        delete[] str;
        str = newStr;
        maxSize = maxSize * 2;
      }
      str[length] = ch;
      ++length;
    }
    str[length] = '\0';
    char symb1 = '\0';
    char symb2 = '\0';
    std::cout << "Enter the symbols. First, the one to be replaced.\n";
    std::cin >> symb1 >> symb2;
    result = new char[length + 1];
    std::cout << zaytseva::replaceSymbol(str, symb1, symb2, result) << "\n";
    delete[] result;
    delete[] str;
    return 0;
  }
  catch (const std::bad_alloc&)
  {
    delete[] result;
    delete[] str;
    std::cerr << "Memory error!\n";
    return 1;
  }
}

namespace zaytseva
{
  char* replaceSymbol(const char* source, char symb1, char symb2, char* result)
  {
    int written = 0;
    for (int i = 0; source[i] != '\0'; i++)
    {
      if (source[i] == symb1)
      {
        result[written] = symb2;
      }
      else
      {
        result[written] = source[i];
      }
      ++written;
    }
    result[written] = '\0';
    return result;
  }
}
