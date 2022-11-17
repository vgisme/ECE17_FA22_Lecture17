//
// Created by Vikash Gilja on 11/17/22.
//
#include <iostream>

enum class ShapeTypes {Circle, Square, Rectangle};

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing a circle\n";}
};

class Square : public Shape {
public:
    void draw() override { std::cout << "Drawing a square\n";}
};

class Rectangle : public Shape {
public:
    void draw() override { std::cout << "Drawing a rectangle\n";}
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
    std::unique_ptr<Shape> shape;
    ShapeFactory shapeFactory;

    shape = std::unique_ptr<Shape>(shapeFactory.getShape(ShapeTypes::Square));
    shape->draw();

}