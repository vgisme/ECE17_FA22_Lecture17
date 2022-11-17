//
// Created by Vikash Gilja on 11/17/22.
//
#include <iostream>

enum class ShapeTypes {Circle, Square, Rectangle};

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() { std::cout << "Deleting a shape\n";};
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing a circle\n";}
    ~Circle() { std::cout << "Deleting a circle\n"; }
};

class Square : public Shape {
public:
    void draw() override { std::cout << "Drawing a square\n";}
    ~Square() { std::cout << "Deleting a square\n"; }
};

class Rectangle : public Shape {
public:
    void draw() override { std::cout << "Drawing a rectangle\n";}
    ~Rectangle() { std::cout << "Deleting a rectangle\n"; }
};

class ShapeFactory {
public:
    Shape* getShape(ShapeTypes aShapeType) {
        switch(aShapeType) {
            case ShapeTypes::Rectangle:
                return new Rectangle();
            case ShapeTypes::Circle:
                return new Circle();
            case ShapeTypes::Square:
                return new Square;
        }
    }
};

int main() {
    Shape* shape;
    ShapeFactory shapeFactory;

    shape = shapeFactory.getShape(ShapeTypes::Circle);
    shape->draw();

    delete shape;
}