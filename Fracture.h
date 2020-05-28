#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h>    // for STDOUT_FILENO
#include <stdlib.h>
#include <vector>
using namespace std;

struct Fracture
{
    winsize getSize()
    {
        winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
        return size;
    }

    int getWidth()
    {
        return getSize().ws_col;
        /* size.ws_row is the number of rows, size.ws_col is the number of columns. */
    };
    int getHeight()
    {
        return getSize().ws_row;
        /* size.ws_row is the number of rows, size.ws_col is the number of columns. */
    }
};

struct Screen
{
    vector<vector<char>> content = {{}};
    int width;
    int height;

    Screen(int width, int height)
    {
        content.resize(height);
        for (int i = 0; i < height; i++)
        {
            content[i].resize(width, ' ');
        }
        this->width = width;
        this->height = height;
    }

    void draw(int x, int y, char c)
    {
        content[y][x] = c;
        printf("AAA\n");
    }

    string getRow(int y)
    {
        string output_string;
        for (char c : content[y])
        {
            output_string += c;
        }
        return output_string;
    }

    vector<string> render()
    {
        vector<string> outvec{};
        for (int i = 0; i < height; i++)
        {
            outvec.push_back(getRow(i));
        }
        return outvec;
    }
};