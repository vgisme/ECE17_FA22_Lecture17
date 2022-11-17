//
// Created by Vikash Gilja on 11/17/22.
//
#include <iostream>

enum class ShapeTypes {Circle, Square, Rectangle};
bool print_destructor = false;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() { if(print_destructor) std::cout << "~Deleting a shape\n";};
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing a circle\n";}
    ~Circle() { if(print_destructor) std::cout << "~Deleting a circle\n"; }
};

class Square : public Shape {
public:
    void draw() override { std::cout << "Drawing a square\n";}
    ~Square() { if(print_destructor) std::cout << "~Deleting a square\n"; }
};

class Rectangle : public Shape {
public:
    void draw() override { std::cout << "Drawing a rectangle\n";}
    ~Rectangle() { if(print_destructor) std::cout << "~Deleting a rectangle\n"; }
};

class RedShapeDecorator : public Shape {
public:
    RedShapeDecorator(Shape* aShape) {
        decoratedShape = aShape;
    }

    ~RedShapeDecorator() { if(print_destructor) std::cout << "~Deleting the red decoration\n"; }

    void draw() override {
        decoratedShape->draw();
        setRedBorder();
    }
private:
    Shape* decoratedShape;
    void setRedBorder() { std::cout << "Making the border red\n";}
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

    std::cout << "Let's decorate the shape!\n";

    Shape* decoratedShape = new RedShapeDecorator(shape);
    decoratedShape->draw();

    delete shape;
    delete decoratedShape;
}