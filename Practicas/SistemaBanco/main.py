import banco
import cuenta
import os

banco = banco.Banco()

def MenuAdmin():
    while True:
        os.system('clear')
        print("1.- Agregar cliente")
        print("2.- Listar clientes")
        print("3.- Salir")
        opcion = input("Opcion: ")
        os.system('clear')

        if opcion == "1":
            nombre = input("Nombre: ")
            saldo = float(input("Saldo: "))
            cliente = cuenta.Cuenta(nombre, saldo)
            banco.agregar_cliente(cliente)
        elif opcion == "2":
            banco.listar_clientes()
            input("Presione Enter para continuar...")
        elif opcion == "3":
            break
        else:
            print("Opcion no valida")
            input("Presione Enter para continuar...")

def MenuUsuario(usuario):
    while True:
        os.system('clear')
        print(f"Bienvenido {usuario.propietario} - {usuario.numero_cuenta}")
        print("1.- Depositar")
        print("2.- Retirar")
        print("3.- Transferir")
        print("4.- Mostrar saldo")
        print("5.- Salir")
        opcion = input("Opcion: ")
        os.system('clear')

        if opcion == "1":
            cantidad = float(input("Cantidad: "))
            usuario.depositar(cantidad)
            print("Deposito realizado")
            input("Presione Enter para continuar...")
        elif opcion == "2":
            cantidad = float(input("Cantidad: "))
            usuario.retirar(cantidad)
            print("Retiro realizado")
            input("Presione Enter para continuar...")
        elif opcion == "3":
            cuenta_destino = int(input("Cuenta destino: "))
            cantidad = float(input("Cantidad: "))
            for cliente in banco.clientes:
                if cliente.numero_cuenta == cuenta_destino:
                    usuario.transferir(cantidad, cliente)
                    print("Transferencia realizada")
                    input("Presione Enter para continuar...")
                    break
            else:
                print("Cuenta destino no encontrada")
                input("Presione Enter para continuar...")
        elif opcion == "4":
            print(f"Saldo: {usuario.mostrar_saldo()}")
            input("Presione Enter para continuar...")
        elif opcion == "5":
            break
        else:
            print("Opcion no valida")
            input("Presione Enter para continuar...")
        
def RegistrarUsuario():
    nombre = input("Nombre: ")
    cliente = cuenta.Cuenta(nombre)
    banco.agregar_cliente(cliente)
    print(f"Usuario {cliente.propietario} registrado con el numero de cuenta {cliente.numero_cuenta}")
    input("Presione Enter para continuar...")

def IniciarSesion():
    nombre = input("Nombre: ")
    for cliente in banco.clientes:
        if cliente.propietario == nombre:
            print("Sesion iniciada")
            input("Presione Enter para continuar...")
            return cliente
    print("Usuario no encontrado")
    input("Presione Enter para continuar...")

def MenuInicio():
    while True:
        os.system('clear')
        print("1.- Ingresar como administrador")
        print("2.- Iniciar sesion")
        print("3.- Registrar usuario")
        print("4.- Salir")
        opcion = input("Opcion: ")
        os.system('clear')

        if opcion == "1":
            MenuAdmin()
        elif opcion == "2":
            usuario = IniciarSesion()
            if usuario:
                MenuUsuario(usuario)
        elif opcion == "3":
            RegistrarUsuario()
        elif opcion == "4":
            break
        else:
            print("Opcion no valida")
            input("Presione Enter para continuar...")

MenuInicio()