let computer = { cpu: 12 }
let lenevo = {
    scrreen: "HD",
    __proto__: computer,
 }
let tomHardware = {};

//console.log(`lenevo`,computer.__proto__);


let genericCar = { tyres: 4 }

let tesla = {
    driver: "AI"
}
Object.setPrototypeOf(tesla, genericCar);
console.log(`tesla`,Object.getPrototypeOf(tesla));
