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

//Encapsulation

class BankAccount {
    #balance = 0;

    deposit(amount) {
        this.#balance += amount;
        return this.#balance;
    }

    getBalance() {
        return `$ ${this.#balance}`;
    
    }
}

let account = new BankAccount() 
//console.log(account.getBalance());

// Abstraction

class CoffeMachine{
    start() {
        //call DB
        //filter value
        return `Starting the coffee machine...`;
    }

    brewCoffee() {
        //complex calculation 
        return `Brewing coffee...`;
    }

    pressStartButton() {
       let messageOne = this.start();
       let messageTwo = this.brewCoffee();
       return `${messageOne} \n${messageTwo}`;
    }
}

let myMachine = new CoffeMachine();
//console.log(myMachine.start());
//console.log(myMachine.brewCoffee());
//console.log(myMachine.pressStartButton());


// Polymorphism : the abiliy of something to have or to be displayed in more than one form

class Bird {
    fly() {
        return `Flying...`;
    }
}

class Penguin extends Bird {
    fly() {
        return `Penguins can't fly....`;
    }
}

let bird = new Bird();
let penguin = new Penguin();

//console.log(bird.fly());
//console.log(penguin.fly());

// static method : these are special methods which can only be called by the class

class Calculator {
    static add(a, b) {
        return a + b;
    }
}

let miniCalc = new Calculator();
console.log(Calculator.add(2,3))