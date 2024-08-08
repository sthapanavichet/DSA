#include <iostream>
#include <cstdlib>
#include <ctime>
#include "raylib.h"

using namespace std;

const int SCREENSIZE = 600;
const int GAMESIZE = 400;

struct Position
{
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

struct Node
{
    Position pos;
    Node *next;
    Node(int x, int y) : pos(x, y), next(nullptr) {}
};

class SnakeGame
{
private:
    Node *head, *tail;
    int size;
    Position food;
    bool gameOver;
    enum Direction
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Direction dir;
    float elapsedTime;
    float baseSpeed, speed;
    int score;
    char buf[100];

    bool isPositionOnSnake(int x, int y)
    {
        for (Node *current = head; current != nullptr; current = current->next)
        {
            if (current->pos.x == x && current->pos.y == y)
            {
                return true;
            }
        }
        return false;
    }



public:
    SnakeGame(int s, float sp) : size(s), baseSpeed(sp), speed(sp), gameOver(false), dir(STOP),elapsedTime(0), score(0)
    {
        head = tail = new Node(s / 2, s / 2);
        placeFood();
    }

    ~SnakeGame()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void placeFood()
    {
        do
        {
            food.x = rand() % size;
            food.y = rand() % size;
        } while (isPositionOnSnake(food.x, food.y)); // Ensure food does not spawn on the snake
    }

    void processInput()
    {
        if((IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)) and dir != DOWN) dir = UP;
        else if((IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)) and dir != RIGHT) dir = LEFT;
        else if((IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)) and dir != UP) dir = DOWN;
        else if((IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)) and dir != LEFT) dir = RIGHT;
    }

    void logic(float deltaTime)
    {
        elapsedTime += deltaTime;
        if (elapsedTime >= speed) {
            elapsedTime = 0;
            if (dir == STOP)
                return;

            int newX = head->pos.x;
            int newY = head->pos.y;
            switch (dir) {
                case LEFT:
                    newX--;
                    break;
                case RIGHT:
                    newX++;
                    break;
                case UP:
                    newY--;
                    break;
                case DOWN:
                    newY++;
                    break;
            }

            if (newX < 0 || newX >= size || newY < 0 || newY >= size || isPositionOnSnake(newX, newY)) {
                gameOver = true;
                return;
            }

            Node *newHead = new Node(newX, newY);
            newHead->next = head;
            head = newHead;

            if (newX == food.x && newY == food.y) {
                placeFood(); // Don't remove the tail, making the snake longer
                score += 1;
                speed = baseSpeed - score/200.0;  // increase speed as score gets higher
            } else {
                Node *prev = nullptr;
                for (Node *current = head; current->next != nullptr; current = current->next) {
                    prev = current;
                }
                if (prev != nullptr)
                    prev->next = nullptr;
                if (tail != nullptr)
                    delete tail;
                tail = prev;
            }

        }
    }

    void run() {
        while (!WindowShouldClose() && !gameOver) {
            processInput();
            logic(GetFrameTime());
            DrawMap();
        }
        const char* text = "Game Over!";
        int fontSize = 40;
        int textWidth = MeasureText(text, fontSize);

        // Draw text in the middle of the screen
        BeginDrawing();
        DrawText(text, (SCREENSIZE-textWidth) / 2, (SCREENSIZE-fontSize) / 2, fontSize, BLACK);
        EndDrawing();
        WaitTime(5);
    }

    int SquareCoord(int position) {
        return (100 + position * (GAMESIZE / size));
    }

    int CircleCoord(int position) {
        return 100 + position * (GAMESIZE / size) + GAMESIZE / size / 2;
    }

    void DrawMap() {
        BeginDrawing();

        // reset screen
        ClearBackground(RAYWHITE);

        // display score
        sprintf(buf, "Score: %d", score);
        DrawText(buf, 10, 10, 20, BLACK);

        // display food
        DrawCircle(CircleCoord(food.x), CircleCoord(food.y), (float)(GAMESIZE / size / 3), BLACK);

        // draw the game box
        DrawRectangleLines(SquareCoord(0), SquareCoord(0), GAMESIZE, GAMESIZE, BLACK);

        // draw the snake
        float squareSize = (float)(GAMESIZE / size);
        float spacing = squareSize / 8.0f;
        DrawRectangle(SquareCoord(head->pos.x) + spacing, SquareCoord(head->pos.y) + spacing, squareSize - 2 * spacing, squareSize - 2 * spacing, GRAY);

        for (Node *current = head->next; current != nullptr; current = current->next)
        {
            DrawRectangle(SquareCoord(current->pos.x) + spacing, SquareCoord(current->pos.y) + spacing, squareSize - 2 * spacing, squareSize - 2 * spacing, LIGHTGRAY);
        }
        EndDrawing();
    }
};

int main()
{
    srand(time(0)); // Initialize the random seed
    int size, speed;
    cout << "Enter the size of the map:";
    cin >> size;
    cout << "Enter the starting speed of the snake (1-10):";
    cin >> speed;
    SnakeGame game(size, 4.0/speed);
    InitWindow(SCREENSIZE, SCREENSIZE, "Snake");

    SetTargetFPS(60);
    game.DrawMap();

    // Main game loop
    game.run();

    // De-Initialization
    CloseWindow();

    return 0;
}




