function Person(name, age) {
  this.name = name;
  this.age = age;
}

function car(make, model) {
  this.make = make;
  this.model = model;
}

//these are constructor functions

let myCar = new car("Toyota", "Camry");
//console.log(myCar);

let myNewCar = new car("Honda", "Civic");
//console.log(myNewCar);

let person1 = new Person("Alice", 30);
//console.log(person1);

//this(it provides the context,it refers to the newly created object) and new have internal linking that makes it possible to use the variables

function Tea(type) {
  this.type = type;
  this.describe = function () {
    console.log(`This is a ${this.type} tea.`);
  };
}

let lemonTea = new Tea("Lemon");
// console.log(lemonTea.describe());

function Animal(species) {
  this.species = species;
}

Animal.prototype.sound = function () {
  return `The ${this.species} makes a sound.`;
};

let dog = new Animal("Dog");
console.log(dog.sound());

let cat = new Animal("cat");
console.log(cat.sound());

function Drink(name) {
    if(!new.target) {
        throw new Error("Constructor must be called with 'new' keyword");
    }
    this.name = name;
}
let tea = new Drink("tea")
let coffee = new Drink("coffee")

console.log(tea);
console.log(coffee);

