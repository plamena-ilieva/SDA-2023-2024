#include <iostream>
#include <queue>
#include <vector>

struct Position
{
    int x;
    int y;

    Position(int x, int y)
        : x(x), y(y) {}

    bool operator==(const Position& rhs)
    {
        return x == rhs.x && y == rhs.y;
    }

    Position& operator+=(const Position& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    friend Position operator+(Position lhs, const Position& rhs)
    {
        lhs += rhs;
        return lhs;
    }
};

struct Square
{
    Position pos;
    int steps;

    Square(Position pos, int steps)
        : pos(pos), steps(steps) {}
};

bool isInBounds(Position pos, int n)
{
    return pos.x >= 1 && pos.x <= n &&
        pos.y >= 1 && pos.y <= n;
}

int stepsKnightProblem(Position knight, Position end, int n)
{
    // Валидни движения на коня
    int statesCount = 8;
    std::vector<Position> states{ {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2},
                                 {1, -2}, {1, 2}, {2, -1}, {2, 1} };

    // Матрица за отбелязване на посетените полета от дъската
    std::vector<std::vector<bool>> visited(n + 1);

    // В началото всички полета без началната позиция са непосетени
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i <= n; i++)
        {
            visited[i].resize(n + 1, false);
        }
    }

    // Единственото посетено поле е това, от което започваме - 
    // началната позиция на коня
    visited[knight.x][knight.y] = true;

    // Създаваме опашка, в която добавяме всяко непосетено поле, което достигнем
    std::queue<Square> q;

    // Първото посетено поле е това, от което започваме
    // До него сме достигнали с 0 стъпки, затова steps = 0
    q.push(Square(knight, 0));

    // Докато опашката не е празна, можем да намерим (най-къс) път до дестинацията
    while (!q.empty())
    {
        // Текущото поле е на върха на опашката.
        // Това е полето, до която сме стигнали с най-малък брой ходове (стъпки),
        // защото полетата се добавят в опашката по ред на достигане.
        Square current = q.front();

        // Идея: Ще обходим всички полета, до които можем да достигнем от текущото.
        // С това ще изчерпаме възможностите за това поле, затова го махаме от опашката.
        q.pop();

        // Ако позицията на текущото поле отговаря на позицията, която искаме да достигнем,
        // то връщаме броя на стъпките, с които е било достигнато.
        if (current.pos == end)
        {
            return current.steps;
        }

        // Финалната позиция не е била текущата.
        // Добавяме в опашката всички позиции, които могат да бъдат достигнати
        // с една стъпка от текущото поле.
        // Валидните стъпки/движения са изброени в states. 
        for (int i = 0; i < statesCount; i++)
        {
            // Правим отместването от текущата позиция, което е определено от states[i]
            Position pos(current.pos + states[i]);

            // Ако:
            // 1. новата позиция е в рамките на дъската и
            // 2. не е била вече посетена (т.е. не е бил намерен по-къс път до нея на предна стъпка),
            // то отбелязваме позицията като посетена, а полето добавяме в опашката със стъпките,
            // с които е било достигнато.
            // Това са стъпките, с които е било достигнато текущото поле + 1.
            if (isInBounds(pos, n) && !visited[pos.x][pos.y])
            {
                visited[pos.x][pos.y] = true;
                q.push(Square(pos, current.steps + 1));
            }
        }
    }

    return -1;
}

int main()
{
    int N = 30;
    Position startN(1, 1);
    Position endN(30, 30);
    std::cout << stepsKnightProblem(startN, endN, N) << std::endl;

    int M = 8;
    Position startM(1, 1);
    Position endM(8, 8);
    std::cout << stepsKnightProblem(startM, endM, M) << std::endl;

    return 0;
}