var assert = require('assert');

// Retorna o valor de delta

var delta = function(a, b, c) {

  return b * b -4 * a * c;

}

// Retorna o valor da primeira raiz

var raiz1 = function(a, b, c) {

  return (-b + Math.sqrt(delta(a, b, c))) / 2 * a;

}

// Retorna o valor da segunda raiz

var raiz2 = function(a, b, c) {

  return (-b - Math.sqrt(delta(a, b, c))) / 2 * a;

}

//

// Testes

//

try {

  var a = 1; b = 0; c = -16;

  assert.equal(64, delta(a, b, c));

  assert.equal(4, raiz1(a, b, c));

  assert.equal(-4, raiz2(a, b, c));

} catch(e) {

  XPTO2.log(e);

}

