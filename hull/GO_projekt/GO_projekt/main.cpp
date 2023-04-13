#include <SFML/Graphics.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <iostream>
#include <stack>
#include <stdlib.h>


using namespace std;
using namespace sf;

struct Point
{
    int x, y;
};


Point p0;


Point next(stack<Point>& S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}


void swap(Point& p1, Point& p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}


int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y);
}



int orient(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}


int comp(const void* vp1, const void* vp2)
{
    Point* p1 = (Point*)vp1;
    Point* p2 = (Point*)vp2;


    int o = orient(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}


void convexHull(Point points[], int n, int t, int tab[], int tab2[])
{



    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;


        if ((y < ymin) || (ymin == y &&
            points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }


    swap(points[0], points[min]);


    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), comp);


    int m = 1;
    for (int i = 1; i < n; i++)
    {

        while (i < n - 1 && orient(p0, points[i],
            points[i + 1]) == 0)
            i++;


        points[m] = points[i];
        m++;
    }


    if (m < 3) return;


    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);


    for (int i = 3; i < m; i++)
    {

        while (S.size() > 1 && orient(next(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }



    cout << "Punkty nalezace do otoczki: " << endl;


    while (!S.empty())
    {


        Point p = S.top();


        tab[t] = p.x;
        tab2[t] = p.y;

        cout << "Punkt : " << "(" << tab[t] << ", " << tab2[t] << ")" << endl;

        t++;
        S.pop();
    }






    RenderWindow okno3(VideoMode(1000, 1000), "otoczka wypukla");

    while (okno3.isOpen())
    {
        Event event;
        while (okno3.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                okno3.close();

        }
        okno3.clear();

        sf::Vector2u windowSize = okno3.getSize();
        sf::Texture texture;
        texture.create(windowSize.x, windowSize.y);

        RectangleShape P1(Vector2f(5, 5));
        RectangleShape P2(Vector2f(5, 5));
        RectangleShape P3(Vector2f(5, 5));
        RectangleShape P4(Vector2f(5, 5));
        RectangleShape P5(Vector2f(5, 5));
        RectangleShape P6(Vector2f(5, 5));
        RectangleShape P7(Vector2f(5, 5));
        RectangleShape P8(Vector2f(5, 5));
        RectangleShape P9(Vector2f(5, 5));
        RectangleShape P10(Vector2f(5, 5));




        P1.setPosition(700, 800);
        P2.setPosition(400, 900);
        P3.setPosition(200, 60);
        P4.setPosition(0, 0);
        P5.setPosition(800, 70);
        P6.setPosition(500, 500);
        P7.setPosition(300, 200);
        P8.setPosition(100, 300);
        P9.setPosition(200, 200);
        P10.setPosition(100, 400);

        P1.setFillColor(Color(150, 50, 250));
        P2.setFillColor(Color(150, 50, 250));
        P3.setFillColor(Color(150, 50, 250));
        P4.setFillColor(Color(150, 50, 250));
        P5.setFillColor(Color(150, 50, 250));
        P6.setFillColor(Color(150, 50, 250));
        P7.setFillColor(Color(150, 50, 250));
        P8.setFillColor(Color(150, 50, 250));
        P9.setFillColor(Color(150, 50, 250));
        P10.setFillColor(Color(150, 50, 250));

        P1.setOutlineThickness(4);
        P1.setOutlineColor(sf::Color(250, 150, 100));
        P2.setOutlineThickness(4);
        P2.setOutlineColor(sf::Color(250, 150, 100));
        P3.setOutlineThickness(4);
        P3.setOutlineColor(sf::Color(250, 150, 100));
        P4.setOutlineThickness(4);
        P4.setOutlineColor(sf::Color(250, 150, 100));
        P5.setOutlineThickness(4);
        P5.setOutlineColor(sf::Color(250, 150, 100));
        P6.setOutlineThickness(4);
        P6.setOutlineColor(sf::Color(250, 150, 100));
        P7.setOutlineThickness(4);
        P7.setOutlineColor(sf::Color(250, 150, 100));
        P8.setOutlineThickness(4);
        P8.setOutlineColor(sf::Color(250, 150, 100));
        P9.setOutlineThickness(4);
        P9.setOutlineColor(sf::Color(250, 150, 100));
        P10.setOutlineThickness(4);
        P10.setOutlineColor(sf::Color(250, 150, 100));

        okno3.draw(P1);
        okno3.draw(P2);
        okno3.draw(P3);
        okno3.draw(P4);
        okno3.draw(P5);
        okno3.draw(P6);
        okno3.draw(P7);
        okno3.draw(P8);
        okno3.draw(P9);
        okno3.draw(P10);

        VertexArray lines(LinesStrip, t + 1);


        //linie ³¹cz¹ce kolejne wierzcho³ki otoczki

        for (int i = 0; i < t; i++) {

            lines[i].position = Vector2f(tab[i], tab2[i]);


        }

        //linia ³¹cz¹ca ostatni wierzcho³ek z pierwszym

        Vertex linia[2] =
        {


            Vertex(Vector2f(tab[0], tab2[0]), Vector2f(tab[t - 1], tab2[t - 1]))

        };





        okno3.draw(lines);
        okno3.draw(linia, 2, Lines);

        // sf::Vector2u windowSize = okno3.getSize();
        // sf::Texture texture;
      //   texture.create(windowSize.x, windowSize.y);
        texture.update(okno3);
        sf::Image screenshot = texture.copyToImage();
        screenshot.saveToFile("screen.png");



        okno3.display();



    }





}




int main()
{
    int* tab = new int[100];
    int* tab2 = new int[100];
    int t = 0;




    Point points[] = { {700,800},{400,900},{200,60},{0,0},{800,70},{500,500},
      {300,200},{100,300},{200,200},{100,400} };
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n, t, tab, tab2);






    return 0;



}