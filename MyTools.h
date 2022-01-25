#pragma once

#include <stdint.h>
#include <string>
//#include <fstream>


namespace MyTools {

    // ������� ������ �� 0 �� 15
    enum ConsoleColor
    {
        CC_Black = 0,
        CC_Blue,
        CC_Green,
        CC_Cyan,
        CC_Red,
        CC_Magenta,
        CC_Brown,
        CC_LightGray,
        CC_DarkGray,
        CC_LightBlue,
        CC_LightGreen,
        CC_LightCyan,
        CC_LightRed,
        CC_LightMagenta,
        CC_Yellow,
        CC_White
    };

	//=============================================================================================

	void ClrScr();

	void __fastcall GotoXY(double x, double y);

	uint16_t GetMaxX();

	uint16_t GetMaxY();

    void SetColor(ConsoleColor color);

	//=============================================================================================

	//void __fastcall OpenLogFile(const std::string& FN);

	//void CloseLogFile();

	//void __fastcall WriteToLog(const std::string& str);

	//void __fastcall WriteToLog(const std::string& str, int n);

	//void __fastcall WriteToLog(const std::string& str, double d);

	//=============================================================================================

    class FileLoggerSingleton         // ���������� Singleton   ;     ���������� ������� - � MyTools.cpp
    {                                 // � ������ SBomber.cpp � SBomberProject.cpp ������ ����:
    public:                           // "MyTools::FileLoggerSingleton::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");"
        static FileLoggerSingleton& getInstance()
        {
            static FileLoggerSingleton theInstance;
            return theInstance;
        }

        void __fastcall OpenLogFile(const std::string& FN);
        void CloseLogFile();
        void __fastcall WriteToLog(const std::string& str);
        void __fastcall WriteToLog(const std::string& str, int n);
        void __fastcall WriteToLog(const std::string& str, double d);

    private:
        FileLoggerSingleton() { }
        FileLoggerSingleton(const FileLoggerSingleton& root) = delete;
        FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;
    };

    //=============================================================================================

    class LoggerSingleton         // ���������� Proxy, "������" ��� FileLoggerSingleton   ;     ���������� ������� - � MyTools.cpp
    {                             // � ������ SBomber.cpp � SBomberProject.cpp ������ ����:
    public:                       // "MyTools::LoggerSingleton::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");"
        static int n_page;
        static LoggerSingleton& getInstance()
        {
            static LoggerSingleton theInstance;
            return theInstance;
        }

        void __fastcall OpenLogFile(const std::string& FN) { FileLoggerSingleton::getInstance().OpenLogFile(FN); }
        void CloseLogFile() { FileLoggerSingleton::getInstance().CloseLogFile(); }

        void __fastcall WriteToLog(const std::string str);
        void __fastcall WriteToLog(const std::string str, int n);
        void __fastcall WriteToLog(const std::string str, double d);

    private:
        LoggerSingleton() { }
        LoggerSingleton(const LoggerSingleton& root) = delete;
        LoggerSingleton& operator=(const LoggerSingleton&) = delete;

        std::string get_note_number() {  // �������� ����� ������, ����� �������������� � ������ � �������������
            std::string nump = std::to_string(n_page);
            ++n_page;
            return nump;
        }

    };

    //=============================================================================================
};