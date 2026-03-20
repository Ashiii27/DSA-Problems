let car = {
    make: "toyota",
    model: "camry",
    year: 2020,

    start: function () {
        return `The ${this.year} ${this.make} ${this.model} is starting.`
    }
}

//console.log(car.start());

//constructor function

function Person(name, age) {
    this.name = name;
    this.age = age;
}

let person1 = new Person("Alice", 30);
let person2 = new Person("Bob", 25);

//console.log(person1.name); // Output: Alice
//console.log(person2.age);  // Output: 25

//prototype chain

Person.prototype.greet = function() {
    return `Hello, my name is ${this.name} and I am ${this.age} years old.`;
};

//console.log(person1.greet()); // Output: Hello, my name is Alice and I am 30 years old.
//console.log(person2.greet()); // Output: Hello, my name is Bob and I am 25 years old.

class Vehicle {
    constructor(make, model, year) {
        this.make = make;
        this.model = model;
        this.year = year;
    }

    start() {
        return `The ${this.year} ${this.make} ${this.model} is starting.`;
    }
}

class Car extends Vehicle {
    drive() {
        return `The ${this.year} ${this.make} ${this.model} is driving.`; //inheritence example
    }
}

let myCar = new Car("toyota", "camry", 2020);
//console.log(myCar.start());
//console.log(myCar.drive());

let vehOne= new Vehicle("Honda", "Civic", 2020);
//console.log(vehOne.start());

