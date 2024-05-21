from cuenta import Cuenta 

# Herencia de la clase Cuenta:  
# Aprovechamos la clase Cuenta para crear una cuenta de ahorro
# la cual "hereda" todos los métodos y atributos de la clase Cuenta
# y además agrega un nuevo atributo "tasa_interes", y un nuevo método "calcular_interes"
# y "depositar_interes".
class CuentaAhorro(Cuenta):
    def __init__(self, propietario = "", saldo = 0, tasa_interes = 0.02):
        super().__init__(propietario, saldo) # Llamamos al constructor de la clase padre
        self.tasa_interes = tasa_interes

    def calcular_interes(self):
        return self.saldo * self.tasa_interes

    def depositar_interes(self):
        interes = self.calcular_interes()
        self.depositar(interes)

    # Polimorfismo:
    # Aplicamos polimorfismo para sobreescribir el método __str__ de la clase padre Cuenta
    def __str__(self):
        return f"Num. Cuenta: {self.numero_cuenta}\tPropietario: {self.propietario}\tSaldo: {self.saldo}\tTasa de Interes: {self.tasa_interes}"