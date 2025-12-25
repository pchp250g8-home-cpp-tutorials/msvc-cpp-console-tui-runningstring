// RunningString.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define PDC_DLL_BUILD
#pragma warning(disable : 4996)
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <ctime>
#include <curses.h>
#include <tuicpp.hpp>

int main(int argc, char* argv[])
{
    initscr();
    curs_set(0);
    auto pc = tuicpp::Window::limits();
    tuicpp::PlainWindow mainWindow(pc.first, pc.second, 0, 0);
    mainWindow.clear();
    mainWindow.nodelay(true);
    std::string strSpaces(80, 32);
    std::string strLine("Hello World!!! Running String!!! Press Any Key To Exit!!!");
    strLine = strSpaces + strLine + strSpaces;
    auto nCounter = 0;
    auto nStrLen = strLine.length() - 80;
    using namespace std::chrono_literals;
    do
    {
        strSpaces = strLine.substr(nCounter, 80);
        mainWindow.mvprintf(10, 10, "%s", strSpaces.c_str());
        mainWindow.refresh();
        std::this_thread::sleep_for(140ms);
        nCounter++;
        if (nCounter >= nStrLen) nCounter = 0;
    } while (mainWindow.getc() == ERR);
    endwin();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
