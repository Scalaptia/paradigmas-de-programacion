import random

# Clase Cuenta
class Cuenta:
    def __init__(self, propietario = "", saldo = 0):
        self.numero_cuenta = random.randint(10000, 99999)
        self.propietario = propietario
        self.saldo = saldo

    def depositar(self, cantidad):
        if cantidad <= 0:
            print("Cantidad no valida")
            return
        
        if cantidad > 10000:
            print("Cantidad maxima superada (10000)")
            return

        self.saldo += cantidad

    def retirar(self, cantidad):
        if cantidad > self.saldo:
            print("Saldo insuficiente")
            return

        self.saldo -= cantidad

    def transferir(self, cantidad, cuenta_destino):
        if cantidad <= 0:
            print("Cantidad no valida")
            return

        if self == cuenta_destino:
            print("No se puede transferir a la misma cuenta")
            return
        
        if cantidad > self.saldo:
            print("Saldo insuficiente")
            return
        
        self.retirar(cantidad)
        cuenta_destino.depositar(cantidad)
        print("Transferencia realizada")    

    def mostrar_saldo(self):
        return self.saldo
    
    def __str__(self):
        return f"Num. Cuenta: {self.numero_cuenta}\tPropietario: {self.propietario}\tSaldo: {self.saldo}"