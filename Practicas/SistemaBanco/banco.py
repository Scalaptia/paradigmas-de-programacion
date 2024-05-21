import cuenta
from cuenta_ahorro import CuentaAhorro

# Abstracción de un banco:
# Se encarga de almacenar los clientes, y de listarlos.
class Banco:
    def __init__(self):
        # Encapsulamiento de los clientes:
        # Se aplica el concepto de encapsulamiento para proteger los datos de los clientes del banco.
        self.clientes = []

    def agregar_cliente(self, cliente):
        self.clientes.append(cliente)

    def listar_clientes(self):
        for cliente in self.clientes:
            print(cliente)

    def iniciar_sesion(self, numero_cuenta):
        for cliente in self.clientes:
            if cliente.numero_cuenta == numero_cuenta:
                return cliente
        return None
    
    def registrar_cliente(self, nombre):
        cliente = cuenta.Cuenta(nombre)
        self.agregar_cliente(cliente)
        return cliente
    
    def registrar_cliente_ahorro(self, nombre, tasa_interes):
        cliente = CuentaAhorro(nombre, 0, tasa_interes)
        self.agregar_cliente(cliente)
        return cliente
    
    # Polimorfismo:
    # Se aplica polimorfismo para aplicar el interés a las cuentas de ahorro.
    # Aqui consideramos que el banco puede tener cuentas de ahorro y cuentas normales,
    # por lo que se aplica polimorfismo para aplicar el interés a las cuentas de ahorro.
    def aplicar_interes(self):
        for cliente in self.clientes:
            if isinstance(cliente, CuentaAhorro):
                cliente.depositar_interes()